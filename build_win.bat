mkdir .\build\3rdparty\opencv
cd build\3rdparty\opencv
REM cmake -G "Visual Studio 17 2022" -DBUILD_SHARED_LIBS=OFF -DOPENCV_EXTRA_MODULES_PATH=../../../3rdparty/opencv_contrib/modules ../../../3rdparty/opencv
REM cmake --build .  --target install -j4
REM cmake --build .  --config debug --target install -j4
cd ..\..\
cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug ../
pause