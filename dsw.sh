#!/bin/bash

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

if [ "0$(echo $SNAME | grep MM)" != "0" ] || [ "0$(echo $SNAME | grep Mark)" != "0" ]; then # If running on my personal machine
    if [ $1 == "new" ]; then
        echo "Using new ntuples!"
        DD_VBS_REDUCED="/mnt/e/Research/ntuples/NEW/ntuples"
        DatasetInpFile="./lists/datasets_2016.json"
    elif [ $1 == "old" ]; then
        echo "Using old ntuples!"
        DD_VBS_REDUCED="/mnt/e/Research/ntuples/vbs_ww_old"
        DatasetInpFile="./lists/oldData.json"
        if [ $2 == "laptop" ]; then
            echo "Using old laptop files"
            DD_VBS_REDUCED="/mnt/c/users/markm/documents/Grad_School/Year_2.0/Research/ntuples_old/HaddedFiles/vbs_ww"
        fi
    else
        echo "You didn't specify so I'm using the new ntuples"
        # DD_VBS_REDUCED="/mnt/e/Research/ntuples/NEW/ntuples"
    fi
    # conda activate root_env # Start the ROOT environment - nevermind, this only works as long as the script runs
fi

if [ ! -d $DD_VBS_REDUCED ]; then
    echo "Data folder $DD_VBS_REDUCED does not exists."
    echo "Please set the correct root folder (DD_VBS_REDUCED) for the reduced ntuples and rerun:" 
    echo "source dsw.sh" 
    #return 0;
fi

OS_RELEASE="$(cat /etc/redhat-release | awk '{print $NF}' | sed 's/(//g' | sed 's/)//g')"
OS_ARCH="$(uname -a | awk '{print $14}')"
echo "OS_RELEASE = $OS_RELEASE, OS_ARCH = $OS_ARCH"

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

echo "Creating link to data files as "
# Sometimes run into issues with the links if the data changes location you'll get a lot of errors from this script. Check that what gets printed out (skim -> $DD_VBS_REDUCED) points to the proper folder
# If it doesn't you have to delete the folder with the skims in it
for skim in $SKIMS; do 
    if [ ! -d skimrqs/$skim ]; then /bin/mkdir -p skimrqs/$skim; fi; # -p option creates the parent directories as needed
    echo "skim = $skim"
    if [ ! -L skims/$skim ]; then
        rm skims/$skim  
        echo "skims/$skim -> $DD_VBS_REDUCED"
        if [ "$skim" = "vbs_ww" ] ; then ln -s $DD_VBS_REDUCED/ skims/$skim; fi;
        if [ "$skim" = "vbs_wz"  ] ; then ln -s $DD_VBS_REDUCED/vbs_wz  skims/$skim; fi;
        if [ "$skim" = "vbs_zz" ] ; then ln -s $DD_VBS_REDUCED/vbs_zz skims/$skim; fi;
    else 
        ls -l skims/$skim
    fi;

# Create reqlists 
    COMBINED_SKIM="cmbvbs_vv"
    /bin/rm -rf  skimrqs/$skim/*.lst > /dev/null 2>&1 # remove skimrqs/vbs_ww/something.lst (/dev/null 2>&1 forces no output. 2>&1 forces any possible error message (2) into the stdout stream (1))
    /bin/rm -rf  skimrqs/$COMBINED_SKIM/*.lst > /dev/null 2>&1

# This file is where the information like xsec (cross section) and nMCgen come from 
    #SamplesInpFile="./macros/cplots/DibosonBoostedElMuSamples13TeV_2019_03_23_03h56.txt"
    #DatasetInpFile="./lists/datasets_2016.json"
    if [ $1 == "old" ]; then
        DatasetInpFile="./lists/oldData.json"
    elif [ $1 == "new" ]; then
        DatasetInpFile="./lists/datasets_2016.json"
    fi
    SamplesOutfile="vbsSamples.cpp"
    echo "Creating $SamplesOutfile"
    if [ -f $SamplesOutfile ]; then /bin/rm -f $SamplesOutfile; fi;
    cat >>  $SamplesOutfile <<EOF
#include "vbsSamples.hpp"
//
void getSamples(std::vector<Sample*>& dataSamples, std::vector<Sample*>& sglSamples, std::vector<Sample*>& bkgSamples){
//==============================
//Generated by the dsw.sh script
//==============================
EOF

# WV_EWK->VBS_EWK | Diboson->VBS_QCD | top->Top | Wjets->WJets_HT | Zjets->DYJets_HT
    #LISTREQ="$(cat $SamplesInpFile | grep data | grep -v "#" | awk '{print $1"--"$2}'  | sed 's/\.\/data\///g' | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g')"
    # Make one big list of all of the file names and the group they belong to
    Groups="data EWK QCD Top WJets ZJets"
    for group in $Groups; do
        if [ "$group" == "data" ]; then
            TempListData="$(cat $DatasetInpFile | grep Data | awk '{print $2}' | sed 's/"//g' | sed 's/^/data--/g' | sed 's/_noDup//g')"
        elif [ "$group" == "EWK" ]; then
            TempListEWK="$(cat $DatasetInpFile | grep $group | grep -v VBS_EWK | awk '{print $2}' | sed 's/"//g' | sed 's/^/WV_EWK--/g')"
        elif [ "$group" == "QCD" ]; then
            TempListQCD="$(cat $DatasetInpFile | grep $group | grep -v VBS_QCD | awk '{print $2}' | sed 's/"//g' | sed 's/^/Diboson--/g')"
        elif [ "$group" == "Top" ]; then
            TempListTop="$(cat $DatasetInpFile | grep name | grep -v EWK | grep -v QCD | grep -v WJetsToLNu_HT | grep -v DY | grep -v Data | awk '{print $2}' | sed 's/"//g' | sed 's/^/top--/g')"
        elif [ "$group" == "WJets" ]; then
            TempListWjets="$(cat $DatasetInpFile | grep $group | grep -v WJets_HT | grep -v TT | awk '{print $2}' | sed 's/"//g' | sed 's/^/Wjets--/g')"
        elif [ "$group" == "ZJets" ]; then
            TempListZjets="$(cat $DatasetInpFile | grep Jets | grep -v DYJets | grep -v WJets | awk '{print $2}' | sed 's/"//g' | sed 's/^/Zjets--/g')"
        fi
    done

    LIST="$(echo $TempListData $TempListEWK $TempListQCD $TempListTop $TempListWjets $TempListZjets)"
    echo "List made"
    #LIST=$LISTREQ
# --------------------------------------------------------------- Start - Temporary work around zone - Start ------------------------------------------------------------------------------
# Issue with testing, the json file the script is pulling the data from tells it to look for all of the files, but since that's 400GB worth of data
# I don't have it stored locally, meaning the script is looking for files that don't exist. Work around idea for this is to look at the skims that got made
# and only include the LISTREQ variables that show up on that list, then make that a tempLISTREQ
#
# Ugh that works but only solves half the problem, I have to apply the above code to group these temp lists, otherwise the Sample() doesn't have a group and just the smpl twice 
if [ $1 == "new" ]; then
    echo "Don't forget to remove the temporary work around for reading the skims when you move to the proper data files"
    echo ""
    skim_folder="skims/vbs_ww"
    tempLISTREQ=()
    for f in $skim_folder/*.root; do
        samp="$(echo ${f} | sed 's/skims\/vbs_ww\///g' | sed 's/_01.root//g' | sed 's/.root//g')"
        #echo $samp
        #echo ""
        if [[ "$samp" == *"Data"* ]]; then
            add="$(echo $samp | sed 's/^/data--/g')"
        elif [[ "$samp" == *"WJets"* ]]; then
            add="$(echo $samp | sed 's/^/Wjets--/g')"
        elif [[ "$samp" == *"DYJets"* ]]; then
            add="$(echo $samp | sed 's/^/Zjets--/g')"
        elif [[ "$samp" == *"EWK_LO_SM"* ]]; then
            add="$(echo $samp | sed 's/^/WV_EWK--/g')"
        elif [[ "$samp" == *"QCD_LO_SM"* ]]; then
            add="$(echo $samp | sed 's/^/Diboson--/g')"
        elif [[ "$samp" == *"TTTo"* ]]; then
            add="$(echo $samp | sed 's/^/top--/g')"
        elif [[ "$samp" == *"aQGC"* ]]; then
            add="$(echo $samp | sed 's/^/aQGC--/g')"
        else
            echo "------------- Not sure what I'm looking at here ---------------"
            echo ""
        fi
        tempLISTREQ+=($add)
    done
    LIST=${tempLISTREQ[@]}
fi

# ---------------------------------------------------------------- End - Temporary work around zone - End ---------------------------------------------------------------------------------
    sid_sgl="100"
    sid_color="910"
    signal="ewk";

    for req in $LIST; do
        #echo "$req"
        grp="$(echo $req | sed 's/--/ /g'| awk '{print $1}')"  
        smpl="$(echo $req | sed 's/'${grp}'--//g')"
        #echo $grp $smpl  
        #echo "===== req_${req}.lst"
        #echo  skims/$skim/*${smpl}*root
        #ls -l skims/$skim/WWTree*${smpl}*root  | awk '{print $NF}'

        if  [ "$grp" == "data" ];     then
            #cat $DatasetInpFile | grep $smpl | grep -v "#" | awk '{print "dataSamples.push_back( new Sample(\""$1"\",\t  \""$2"\",\t    1,\t  1,  gid_data,  gid_data,   "$7",  "$5",  "$6") );"  }'   | sed 's/\.\/data\///g' | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g' >> $SamplesOutfile
            cat $DatasetInpFile | grep $smpl | grep -v "#" | awk '{print "dataSamples.push_back( new Sample(\"'${grp}'\",\t "$2" ,\t 1,\t 1,\t gid_data, gid_data,\t" $14 ",\t" $8 ",\t" $11") );" }' | sed 's/_noDup//g' >> $SamplesOutfile
            #echo ls -l skims/$skim/${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_data.lst
            ls -l skims/$skim/${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_data.lst

        elif [ "$grp" == "CH_WZToLL_M500" ] || [ "$grp" == "CH_WZToLNu_M500" ]  || [ "$grp" == "DCH_WW_M500" ]; then

            if  [ "$signal" == "higgs" ]; then
            cat $SamplesInpFile | grep $smpl | grep -v "#" | awk '{print "sglSamples.push_back( new Sample(\""$1"\",\t  \""$2"\",\t    "$3",\t  1, gid_sgl,  '${sid_sgl}',  '${sid_color}',  "$5",  "$6") );"  }'   | sed 's/\.\/data\///g'  | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g'  >> $SamplesOutfile
            let sid_sgl=${sid_sgl}+1;
            #echo =${sid_sgl}
            #echo ls -l skims/$skim/${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_sgl.lst
            ls -l skims/$skim/${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_sgl.lst
            fi

        else

            if  [ "$grp" == "WV_EWK" ]; then # WV_EWK

                if  [ "$signal" != "ewk" ]; then 
                    cat $DatasetInpFile | grep $smpl | grep -v "#" | awk '{print "bkgSamples.push_back( new Sample(\"'${grp}'\",\t  "$2",\t"$5",\t  1,  gid_'${grp}',  1100,   "$14",\t"$8",\t"$11") );"  }'   | sed 's/\.\/data\///g' | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g'  >> $SamplesOutfile
                else
                    ls -l skims/$skim/${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_sgl.lst
                    cat $DatasetInpFile | grep $smpl | grep -v "#" | awk '{print "sglSamples.push_back( new Sample(\"'${grp}'\",\t "$2",\t"$5",\t  1, gid_sgl,  '${sid_sgl}',\t'${sid_color}',\t"$8",\t"$11") );"  }'   | sed 's/\.\/data\///g'  | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g'  >> $SamplesOutfile
                    let sid_sgl=${sid_sgl}+1;
                fi

            else
                #all samples with *ext*
                #ls -l skims/$skim/WWTree*${smpl}*root  | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_bkg.lst
                cat $DatasetInpFile | grep $smpl | grep -v "#" | awk '{print "bkgSamples.push_back( new Sample(\"'${grp}'\",\t  "$2",\t"$5",\t  1,  gid_'${grp}',  1100,   "$14",\t "$8",\t  "$11") );"  }'   | sed 's/\.\/data\///g' | sed 's/\.root//g'  | sed 's/W+/W/g'  | sed 's/Z+/Z/g'  >> $SamplesOutfile
                #echo ls -l skims/$skim/${smpl}*root | grep -v "_ext" | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_bkg.lst
                ls -l skims/$skim/${smpl}*root | grep -v "_ext" | awk '{print $NF}' >>  skimrqs/$skim/rqs_${req}_bkg.lst

            fi
        fi

    done

    echo "}" >> $SamplesOutfile
    #
    #return 0;

    LISTREQ="$(ls -1 skimrqs/$skim/*bkg.lst)"
    cat $LISTREQ >  skimrqs/$skim/all_bkg.lst
    #
done
echo "Done writing $SamplesOutfile"
#
if [ ! -d skimrqs/$COMBINED_SKIM ]; then /bin/mkdir -p skimrqs/${COMBINED_SKIM}; fi;

/bin/rm -rf  skimrqs/${COMBINED_SKIM}/*.lst > /dev/null 2>&1

#LISTREQ_VBS_ALL="$(ls -1 skimrqs/vbs*/rqs_*_ewk.lst)"
#LISTREQ_VBS_AGQC_ALL="$(ls -1 skimrqs/vbs*/rqs_*_aqgc.lst)"
#
#LISTREQ_DATA="$(ls -1 skimrqs/vbs*/rqs_data*.lst)"
#LISTREQ_WplusJets="$(ls -1 skimrqs/vbs*/rqs_WplusJets_bkg.lst)"
#LISTREQ_ZplusJets="$(ls -1 skimrqs/vbs*/rqs_ZplusJets_bkg.lst)"
#LISTREQ_diBosons="$(ls -1 skimrqs/vbs*/rqs_diBosons_bkg.lst)"
#LISTREQ_Top="$(ls -1 skimrqs/vbs*/rqs_top_bkg.lst)"

#cat ${LISTREQ_VBS_ALL}         >  skimrqs/${COMBINED_SKIM}/rqs_vbs_vv_ewk.lst
#cat ${LISTREQ_VBS_AGQC_ALL}    >  skimrqs/${COMBINED_SKIM}/rqs_vbs_vv_aqgc.lst
#cat ${LISTREQ_DATA}       >  skimrqs/${COMBINED_SKIM}/rqs_data.lst
#cat ${LISTREQ_WplusJets}  >  skimrqs/${COMBINED_SKIM}/rqs_WplusJets_bkg.lst
#cat ${LISTREQ_ZplusJets}  >  skimrqs/${COMBINED_SKIM}/rqs_ZplusJets_bkg.lst
#cat ${LISTREQ_diBosons}   >  skimrqs/${COMBINED_SKIM}/rqs_diBosons_bkg.lst
#cat ${LISTREQ_Top}        >  skimrqs/${COMBINED_SKIM}/rqs_top_bkg.lst
#
#cat skimrqs/vbs_ww/rqs_data.lst
#
if [ -d reqlists ]; then /bin/rm -r reqlists; fi;
ln -s ./skimrqs/vbs_ww reqlists
echo "Done!"
echo ""
echo "Next run ./write_vbsDL.sh with the appropriate arguments"