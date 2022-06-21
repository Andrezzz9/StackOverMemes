mkdir .\build\3rdparty\opencv
cd build\3rdparty\opencv
cmake -G "Visual Studio 17 2022" -DBUILD_opencv_python3=OFF -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF -DBUILD_EXAMPLES=OFF -DBUILD_opencv_apps=OFF -DOPENCV_EXTRA_MODULES_PATH=../../../3rdparty/opencv_contrib/modules ../../../3rdparty/opencv
cmake --build .  --config debug --target install -j4
cd ..\..\
cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug ../
pause