git submodule init
git submodule update

"c:\Program Files\CMake\bin\cmake.exe" ^
  -H. ^
  -Boutput_64 ^
  -G"Visual Studio 16 2019" ^
  %*
pause