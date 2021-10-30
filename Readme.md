
Templatized version of  [BogCyg's](https://github.com/BogCyg/BookCpp) EmptyPro sample. 
This is a GitHub template for starting a Cmake/C++ template for Mac, Linux or Windows.

Works great with Clion but can be used with any IDE that supports Cmake.

No need to fork or clone this repo directly, just click "Use this template" and clone locally. 

#Instructions:
 
Assuming your project is named "MyPro", proceed as follows:

1. After clicking use this template clone your repo and name it "MyPro".

2. In the ./MyPro/CMakeLists.txt find the line
set( PROJECT_NAME EmptyPro )
and change "EmptyPro" to the name of your project, i.e. "MyPro" in our example
set( PROJECT_NAME MyPro )

3. Copy/create ALL your source files to the ./MyPro/src
and ALL headers to the ./MyPro/include

4. Build your project in accordance with the common scheme (below).

=================================
To build a project do as follows:

1. Depending on your OS change directory to the one:
build_win
build_linux
build_mac

2. Open terminal and set current directory to the above one.

3. type 
cmake ..

4. Go to the build_xxx directory and launch your project.




