#!/bin/bash

#   Initial script to run in the frame work.
#   Purpose: 
#       - Does a system check to see if your running the code on the Fermilab LPC, the NIU NICADD cluster, or on a personal machine
#       - Sets up ROOT and CUDA if you're on a cluster (doesn't if you're on a personal machine)
#       - Creates links to the data files
#       - Writes vbsSamples.cc
#   Usage:
#       ./dsw.sh "location/of/data" "year" "dataset_2016.xml"

# ------------------------------------------------------------------- Start System Check ----------------------------------------------------------------------------------------------

DD_VBS_REDUCED="/eos/uscms/store/user/rsingh/wv_vbs_ntuples/WVJJTree_2020_Dec_12"
SNAME="$(uname -a | awk '{print $2}')" # System name
if [ "0$(echo  $SNAME | grep fnal)" != "0" ]; then # If the system name is from Fermilab, use these setup conditions
    DD_VBS_REDUCED="/eos/uscms/store/user/rsingh/wv_vbs_ntuples/WVJJTree_2020_Dec_12" # OLD "/uscms_data/d1/lpchzz4leptons/serguei/data/vbs_reduced_2016"
    export SUREPO="/uscms/home/serguei/lpchzz4leptons/serguei/contrib"
    export ROOT_DIR=$SUREPO//root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7
    export ROOTSYS=$SUREPO/root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7
    export CPATH=$ROOTSYS/include:$CPATH
    export LD_LIBRARY_PATH=$ROOTSYS/lib64:${LD_LIBRARY_PATH}
    export LIBRARY_PATH=$ROOTSYS/lib:${LIBRARY_PATH}
    export PATH=$ROOTSYS/bin:${PATH}
    source /cvmfs/cms-lpc.opensciencegrid.org/sl7/gpu/Setup.sh
fi
#
if [ "0$(echo  $SNAME | grep cn)" != "0" ] || [ "0$(echo  $SNAME | grep gaea)" != "0" ] && [ "0$(cat  /etc/hosts | grep gaea)" != "0" ]; then
    DD_VBS_REDUCED="/data1/serguei/cms/archive/vbs_reduced_2016"
    module load root/root-6.10.08-SL7-x64-cuda-7.5
fi

if [ "0$(echo  $SNAME | grep suv)" != "0" ]; then
    DD_VBS_REDUCED="/work/cmsdata/vbs_reduced_2016"
    module load root/root-6.10.08-SL7-x64
    module load root/root-6.10.08-SL7-x64-cvmfs
fi

# If running on my personal machine - First condition is windows, second is, well... Manjaro Linux
if [ "0$(echo $SNAME | grep MM)" != "0" ] || [ "0$(echo $SNAME | grep Mark)" != "0" ]; then 
    Ntuple_loc="/mnt/$1"
    DatasetInpFile="./datasets/$3"
    #DD_VBS_REDUCED="/mnt/$1" # d/2016/haddedFiles (g if on my desktop) - If using the data stored on a flash drive, don't forget to mount it (_ = some letter) use:~$ mkdir /mnt/_ ~$ sudo mount -t drvfs _: /mnt/_
    #DatasetInpFile="./datasets/datasets_$2.json"
elif [ "0$(echo $SNAME | grep Manjaro)" != "0" ]; then
    Ntuple_loc="/mnt/Storage/Research/ntuples/NEW"
    #DD_VBS_REDUCED="/mnt/Storage/Research/ntuples/NEW/$2/haddedFiles"
    DatasetInpFile="./datasets/$3"
    #DatasetInpFile="./datasets/datasets_$2.json"
fi

if [ ! -d $Ntuple_loc ]; then
    echo "Data folder $Ntuple_loc does not exists."
    echo "Please set the correct root folder for the reduced ntuples and rerun:" 
    echo "  source dsw.sh" 
    #return 0;
fi

OS_RELEASE="$(cat /etc/redhat-release | awk '{print $NF}' | sed 's/(//g' | sed 's/)//g')"
OS_ARCH="$(uname -a | awk '{print $14}')"
# echo "OS_RELEASE = $OS_RELEASE, OS_ARCH = $OS_ARCH"

#At nicadd
if [ "0$(echo  $SNAME | grep nicadd)" != "0" ] &&  [ "0$ROOTSYS" == "0" ]; then 
    if [ "$OS_RELEASE" == "Boron" ]; then 
    #we are on SL5.5 or on SL5.8 system
    module load root/root-v4.04.02-fc1-i386
    elif [ "$OS_RELEASE" == "Carbon" ] || [ "$OS_RELEASE" == "Santiago" ]; then 
        #we are on SL6.X system
        echo "module load root/root-5.34.34-SL6-x64"
        module load root/root-5.34.34-SL6-x64
    elif  [ "$OS_RELEASE" == "Nitrogen" ]; then 
        #we are on SL7.X system
        module load root/root-6.10.08-SL7-x64-cuda-7.5
    fi
fi

if [ "0$ROOTSYS" == "0" ]; then
    echo "Please setup ROOT"
    echo ""
    #return 0;
fi

echo "System check done!"
# ------------------------------------------------------------------- End System Check -------------------------------------------------------------------------------------------

#
#if [ ! -d ./bin ]; then  /bin/mkdir -p ./bin; fi
#cd limit_calc
#./build.sh >/dev/null 2>&1
#/bin/cp -rvp limit_calc ../bin/
#cd ..
#export PATH=$PWD/bin:$PATH

# ------------------------------------------------------------------- Start here --------------------------------------------------------------------------------------------------

SKIMS="vbs_ww"
COMBINED_SKIM="cmbvbs_vv"
skim_folder=$SKIMS
data_foler=""

if [[ "$2" == "1111" ]]; then
    skim_folder=$COMBINED_SKIM
    data_folder="$Ntuple_loc/Run2"
fi

echo "Creating link to data files as "
# Sometimes run into issues with the links if the data changes location you'll get a lot of errors from this script. Check that what gets printed out (skim -> $DD_VBS_REDUCED) points to the proper folder
# If it doesn't you have to delete the folder with the skims in it
for skim in $SKIMS; do 
    List=$(cat $DatasetInpFile | grep sample | grep -v \!-- | sed 's|"||g' | awk '{print $3"--"$7"--"$9}' | sed 's/_noDup//g')
    years=$(cat $DatasetInpFile | grep year= | grep -v \!-- | awk '{print $3}' | sed 's|"||g' | uniq | sort)

    if [ ! -d skimrqs/$skim_folder ]; then /bin/mkdir -p skimrqs/$skim_folder; fi; # -p option creates the parent directories as needed
    echo "skim = $skim"
    if [ ! -d skims/$skim ]; then
        rm skims/$skim
        mkdir skims/$skim
        echo "Working Directory:"  
        echo "  skims/$skim -> $Ntuple_loc"
        for yr in $years; do
            if [ "$skim" = "vbs_ww" ] ; then ln -s $Ntuple_loc/$yr/haddedFiles skims/$skim/$yr; fi;
        done
        if [[ "$data_folder" != "" ]]; then ln -s $data_folder skims/$skim/Run_2; fi;
    else 
        ls -l skims/$skim
    fi;

    # Create reqlists 
    

    /bin/rm -rf skimrqs/$skim/*.lst > /dev/null 2>&1 # remove skimrqs/vbs_ww/something.lst (/dev/null 2>&1 forces no output. 2>&1 forces any possible error message (2) into the stdout stream (1))
    /bin/rm -rf skimrqs/$COMBINED_SKIM/*.lst > /dev/null 2>&1 # both had /bin/rm -rf skimrqs...

    # This file is where the information like xsec (cross section) and nMCgen come from 
    #SamplesInpFile="./macros/cplots/DibosonBoostedElMuSamples13TeV_2019_03_23_03h56.txt"
    SamplesOutfile="vbsSamples.hpp"
    echo "Creating $SamplesOutfile"
    if [ -f $SamplesOutfile ]; then /bin/rm -f $SamplesOutfile; fi;
    cat >>  $SamplesOutfile <<EOF
#ifndef VBS_SAMPLES_H
#define VBS_SAMPLES_H

void getSamples(std::vector<Sample*>& dataSamples, std::vector<Sample*>& sglSamples, std::vector<Sample*>& bkgSamples){
//==============================
//Generated by the dsw.sh script
//==============================
EOF

# WV_EWK->VBS_EWK | Diboson->VBS_QCD | top->Top | Wjets->WJets_HT | Zjets->DYJets_HT

# ---------------------------------------------------------------- End - Temporary work around zone - End ---------------------------------------------------------------------------------
    sid_sgl="100"
    sid_color="910"
    signal="ewk";

    for req in $List; do
        yr="$(echo $req | sed 's|--| |g' | awk '{print $1}')"
        grp="$(echo $req | sed 's|--| |g' | awk '{print $2}')"  # Save the list of groups as grp
        smpl="$(echo $req | sed 's|--| |g' | awk '{print $3}')" # Save the list of samples as smpl
        xsec="$(cat $DatasetInpFile | grep $smpl | grep $yr | awk '{print $11}' | sed 's|"||g')"
        nMC="$(cat $DatasetInpFile | grep $smpl | grep $yr | awk '{print $13}' | sed 's|"||g')"
        nMCneg="$(cat $DatasetInpFile | grep $smpl | grep $yr | awk '{print $15}' | sed 's|"||g')"
        color="$(cat $DatasetInpFile | grep $smpl | grep $yr | awk '{print $17}' | sed 's|"||g')"

        if  [ "$grp" == "data" ]; then
            #if [[ "$2" == "1111" ]]; then
            #    rm skimrqs/$skim_folder/rqs_data--Data_data.lst > /dev/null 2>&1
            #    ls -l skims/$skim/Run_2/Data*root | awk '{print $NF}' >> skimrqs/$skim_folder/rqs_data--Data_data.lst
            #    cat $DatasetInpFile | grep $smpl | grep $yr | grep -v \!-- | awk '{print "dataSamples.push_back( new Sample(\"1111\", \"'${grp}'\", \"Data\", 1, 1, gid_data, gid_data, '${color}', "'${nMC}'", "'${nMCneg}'") );" }' | sed 's/_noDup//g' >> $SamplesOutfile
            #else
                ls -l skims/$skim/${yr}/${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim_folder/rqs_data--Data_data.lst
                cat $DatasetInpFile | grep $smpl | grep $yr | grep -v \!-- | awk '{print "dataSamples.push_back( new Sample(\"'${yr}'\", \"'${grp}'\", \"'${smpl}'\", 1, 1, gid_data, gid_data, '${color}', "'${nMC}'", "'${nMCneg}'") );" }' | sed 's/_noDup//g' >> $SamplesOutfile
            #fi
        else
            if  [[ "$grp" == "VBS_EWK" || "$grp" == "WV_EWK" ]]; then # WV_EWK
                if  [ "$signal" != "ewk" ]; then 
                    cat $DatasetInpFile | grep $smpl | grep $yr | grep -v \!-- | awk '{print "bkgSamples.push_back( new Sample(\"'${yr}'\", \"'${grp}'\", \"'${smpl}'\", '${xsec}', 1, gid_'${grp}', 1100, '${color}', '${nMC}', '${nMCneg}') );"  }'   | sed 's/\.\/data\///g' | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g'  >> $SamplesOutfile
                else
                    ls -l skims/$skim/$yr/${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim_folder/rqs_${req}_sgl.lst
                    cat $DatasetInpFile | grep $smpl | grep $yr | grep -v \!-- | awk '{print "sglSamples.push_back( new Sample(\"'${yr}'\", \"'${grp}'\", \"'${smpl}'\", '${xsec}', 1, gid_sgl, '${sid_sgl}', '${sid_color}', '${nMC}', '${nMCneg}') );"  }'   | sed 's/\.\/data\///g' | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g'  >> $SamplesOutfile
                    let sid_sgl=${sid_sgl}+1;
                fi

            else
                #all samples with *ext*
                #ls -l skims/$skim/WWTree*${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_bkg.lst
                cat $DatasetInpFile | grep $smpl | grep $yr | grep -v \!-- | awk '{print "bkgSamples.push_back( new Sample(\"'${yr}'\", \"'${grp}'\", \"'${smpl}'\", '${xsec}', 1, gid_'${grp}', 1100, '${color}', '${nMC}', '${nMCneg}') );"  }'   | sed 's/\.\/data\///g' | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g'  >> $SamplesOutfile
                #echo ls -l skims/$skim/${smpl}*root | grep -v "_ext" | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_bkg.lst
                ls -l skims/$skim/${yr}/${smpl}*root | grep -v "_ext" | awk '{print $NF}' >>  skimrqs/$skim_folder/rqs_${req}_bkg.lst

            fi
        fi

    done

    echo "}" >> $SamplesOutfile
    echo "#endif" >> $SamplesOutfile
    #return 0;

    LISTREQ="$(ls -1 skimrqs/$skim_folder/*bkg.lst)"
    cat $LISTREQ > skimrqs/$skim_folder/all_bkg.lst

done
echo "Done writing $SamplesOutfile"

#if [ ! -d skimrqs/$COMBINED_SKIM ]; then /bin/mkdir -p skimrqs/${COMBINED_SKIM}; fi;
#/bin/rm -rf  skimrqs/${COMBINED_SKIM}/*.lst > /dev/null 2>&1

if [ -d reqlists ]; then /bin/rm -r reqlists; fi;
ln -s ./skimrqs/$skim_folder reqlists

echo "Done!"
echo ""
echo "Next run ./write_vbsDL.sh with the appropriate arguments"