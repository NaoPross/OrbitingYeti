cd ..
mkdir build/debug
cmake -DCMAKE_BUILD_TYPE=Debug -H. -G "MinGW Makefiles" -Bbuild/debug
cmake --build build/debug -- clean all
pause
