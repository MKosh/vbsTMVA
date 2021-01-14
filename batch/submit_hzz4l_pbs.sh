#!/bin/bash 
#
JOBNAME="hzz4l_pbs"
if [ "0$1" != "0" ]; then 
  JOBNAME="$JOBNAME_$1"
fi
#
DATE="$(date | sed 's/:/ /g' | awk '{print $2$3"_"$4_$5_$6}')"
PACKAGE_NAME="hzztmva_dev"
WORKDIR="$PWD"
SOURCEDIR="$WORKDIR/${PACKAGE_NAME}"
OUTPUTDIR="$WORKDIR/pbs_batch"
#
JOBOUTDIR="$OUTPUTDIR/${JOBNAME}_$DATE"
LOGDIR="$JOBOUTDIR/log"
#
#BATCH_DIR="$WORKDIR/${JOBNAME}_$DATE"
BATCH_DIR="/disk/$USER/${JOBNAME}_$DATE"
#
SCRIPT_NAME="run_$JOBNAME"
RUNSCRIPT="$SCRIPT_NAME.sh"
CMDSCRIPT="$SCRIPT_NAME.pbs"
#
if [ ! -d $LOGDIR ]; then
 mkdir -p $LOGDIR
fi
#
if [ ! -d $OUTPUTDIR/$JOBOUTDIR ]; then
 mkdir -p $JOBOUTDIR
fi
#
#Write script to run on a remote node
if [ -f $RUNSCRIPT ]; then
   /bin/rm -f $RUNSCRIPT 
fi
#
JOBTARFILE="${JOBNAME}_${DATE}.tgz"
#
tar -czf $JOBTARFILE  ./$PACKAGE_NAME
/bin/cp -rfvp  $JOBTARFILE  $JOBOUTDIR/


cat > $RUNSCRIPT  <<EOF
#!/bin/bash
#
mkdir -p  $BATCH_DIR
rsync -av $SOURCEDIR $BATCH_DIR/
#
echo "User \$USER at node \$HOSTNAME"
echo "Load root and cuda modules"
module load root/root-6.10.08-SL7-x64-cuda-7.5
module load cuda/cuda-7.5 
#
mkdir -p  $BATCH_DIR
cd $BATCH_DIR
cp -rfvp  $WORKDIR/$JOBTARFILE  $BATCH_DIR/
tar -xzf   $JOBTARFILE
cd $PACKAGE_NAME
#
echo "Running job"
source dsw.sh
root -b -q ./hzzTMVAClassification.C\(\"hzz_4mu\",\"BDT,MLPBFGS,DNN_GPU\"\) 
root -b -q ./hzzTMVAClassificationApplication.C\(\"hzz_4mu\",\"BDT,MLPBFGS,DNN_GPU\"\)
#
###
echo "Job finished"
cd $BATCH_DIR
rsync -av * $JOBOUTDIR/
cd /disk
#
/bin/ls -l  $BATCH_DIR
/bin/rm -rf $BATCH_DIR
#
EOF
#
chmod 755 $RUNSCRIPT 
#Prepare pbs command file
cat > $CMDSCRIPT  <<EOF
####################
##PBS command file
##
####################
#!/bin/bash
#-PBS script to run namd appication
## How to run:
#	Interactive:
#		qsub -I[ -v option_list ]
#	Batch:
#		qsub [ - option_list ] namd_test_mpi.pbs
#
# where option_list is a comma-separated list of a combination of the
# following key/value pairs:
#	output=<output_directory>
# 
# --------------------------------------------------------------------------
#
#-PBS-Directives-start (to be customized by user, as minimum project, account, e-mail )
#
#Specify the queue
#--PBS -q medium
#
#User's project 
#PBS -A admin 
#
#Name of my job
#PBS -N  $JOBNAME
#
#Defines the user name under which the job is to run on the execution system.
#If unset, the user list defaults to the user who is running qsu
#
#-----PBS -u username
#
#PBS -l nodes=1:gpus=1:ppn=1,walltime=24:00:00
#
#Merge standard output and standard error into standard output file (PBS -j oe)
#PBS -j oe
#
#Output permissions
#PBS -W umask=022
#
#Send me email when my job aborts, begins, or ends (PBS -m abe)
#PBS -m e
#
#Email address
#-----PBS -M account@niu.edu
#
#Additional options
# Where to write stderr:
#--PBS -e myprog.err
# 
# Where to write stdout: 
#--PBS -o myprog.out
#
#Shell to use
#-PBS -S /bin/bash
#
#-PBS-Directives-end
#
#============================
#===Remote script starts here 
#
echo "PBS environment"
env | grep PBS
#
# Extract numeric part of PBS_JOBID
echo "Submitted by user $USER"
JOBID="\$(echo \$PBS_JOBID | tr '.' ' ' | awk '{print \$1}' )"
JOBDIR="\$PWD"
echo "JOBID= \$JOBID"
echo "JOBDIR= \$JOBDIR"
#
cd \$JOBDIR
#
LOGFILE="$LOGDIR/${JOBNAME}_\$JOBID.log"
# Output base directory
if [ "\$output" == "" ]
then
   OUTDIR=$JOBOUTDIR
else
   OUTDIR=\$output
fi
echo "PBS_O_WORKDIR =  \$PBS_O_WORKDIR"
cd \$PBS_O_WORKDIR

#
echo " "
echo "Job started on `hostname` at `date`"
echo " "
#
echo "./$RUNSCRIPT \$JOBID > \$LOGFILE"
echo " "
./$RUNSCRIPT  \$JOBID > \$LOGFILE  2>&1


#User can consider save output in   \$OUTDIR/
#/bin/mv       \$LOGFILE                \$OUTDIR/
/bin/cp -rfvp \$PBS_JOBNAME.o\$JOBID   \$OUTDIR/
#
echo " "
echo "Job Ended at `date`"
echo " "
#

EOF
#
echo "Submitting job $CMDSCRIPT"
/bin/cp -rfp $CMDSCRIPT  $LOGDIR/
/bin/cp -rfp $RUNSCRIPT  $LOGDIR/
sleep 5
qsub $CMDSCRIPT
echo "Job stat will be written to $LOGDIR"
echo "To check job status please run :"
echo "qstat -u $USER" 
echo "#------------#"
#
