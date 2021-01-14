#Note:: to compile with cuda please edit add after if(CUDA_FOUND), line 58 of
#/opt/nicadd/archive/root/root-6.10.08/tmva/tmva/CMakeLists.txt  
#CUDA_INCLUDE_DIRECTORIES("${CMAKE_BINARY_DIR}/include") 
source /cvmfs/oasis.opensciencegrid.org/osg/modules/lmod/5.6.2/init/bash
module load  cmake/3.8.0
#source /cvmfs/cms-lpc.opensciencegrid.org/sl7/gpu/Setup.sh
CUDA_HOME="/cvmfs/cms-lpc.opensciencegrid.org/sl7/usr/local/cuda"
#
cmake  /uscms/home/serguei/lpchzz4leptons/serguei/archive/root/root-6.10.08 -DCMAKE_INSTALL_PREFIX=/uscms/home/serguei/lpchzz4leptons/serguei/contrib/root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7 -Dtmva=ON -Dimt=true    -Dcuda=ON -DCUDA_TOOLKIT_ROOT_DIR=${CUDA_HOME}
cmake --build . -- -j8
cmake --build . --target install
#
#Note due to missing link one need manually compile
#cd /uscms/home/serguei/lpchzz4leptons/serguei/build/root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7/graf2d/asimage
# /usr/bin/c++ -fPIC  -pipe -m64  -Wshadow -Wall -W -Woverloaded-virtual -fsigned-char -fPIC -pthread -std=c++11 -O2 -g -DNDEBUG  -Wl,--no-undefined -shared -Wl,-soname,libASImage.so -o ../../lib/libASImage.so CMakeFiles/ASImage.dir/G__ASImage.cxx.o CMakeFiles/ASImage.dir/src/TASImage.cxx.o CMakeFiles/ASImage.dir/src/TASPluginGS.cxx.o -Wl,-rpath,/uscms/home/serguei/lpchzz4leptons/serguei/build/root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7/lib: ../../lib/libAfterImage.a /usr/lib64/libfreetype.so /usr/lib64/libgif.so.4.1.6 /usr/lib64/libtiff.so /usr/lib64/libpng.so /usr/lib64/libz.so /usr/lib64/libjpeg.so /usr/lib64/libSM.so /usr/lib64/libICE.so /usr/lib64/libX11.so /usr/lib64/libXext.so /usr/lib64/libz.so ../../lib/libGraf.so /usr/lib64/libjpeg.so /usr/lib64/libSM.so /usr/lib64/libICE.so /usr/lib64/libX11.so /usr/lib64/libXext.so ../../lib/libHist.so ../../lib/libMatrix.so ../../lib/libMathCore.so ../../lib/libRIO.so ../../lib/libThread.so ../../lib/libCore.so
# /usr/bin/c++ -fPIC  -pipe -m64  -Wshadow -Wall -W -Woverloaded-virtual -fsigned-char -fPIC -pthread -std=c++11 -O2 -g -DNDEBUG  -Wl,--no-undefined -shared -Wl,-soname,libASImageGui.so -o ../../lib/libASImageGui.so CMakeFiles/ASImageGui.dir/G__ASImageGui.cxx.o CMakeFiles/ASImageGui.dir/src/TASPaletteEditor.cxx.o -Wl,-rpath,/uscms/home/serguei/lpchzz4leptons/serguei/build/root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7/lib: ../../lib/libAfterImage.a /usr/lib64/libfreetype.so /usr/lib64/libgif.so.4.1.6 /usr/lib64/libtiff.so /usr/lib64/libpng.so /usr/lib64/libz.so /usr/lib64/libjpeg.so /usr/lib64/libSM.so /usr/lib64/libICE.so /usr/lib64/libX11.so /usr/lib64/libXext.so /usr/lib64/libz.so ../../lib/libGui.so ../../lib/libASImage.so /usr/lib64/libjpeg.so /usr/lib64/libSM.so /usr/lib64/libICE.so /usr/lib64/libX11.so /usr/lib64/libXext.so ../../lib/libGpad.so ../../lib/libGraf.so ../../lib/libHist.so ../../lib/libMatrix.so ../../lib/libMathCore.so ../../lib/libRIO.so ../../lib/libThread.so ../../lib/libCore.so
