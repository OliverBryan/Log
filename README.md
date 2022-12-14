# Log
An extremely basic logging utility used by some of my projects. Writes log messages to the console and files with a few other utilities. (Note: this only works on windows)

## To use
This project is meant to be used with CMake. To use it you just have to modify your CMakeLists.txt file. I recommend using the FetchContent module to make everything easy. 

First, make sure to tell CMake to export all symbols and build the library as a dll (if you want a static library instead, just skip this step):

    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
	set(BUILD_SHARED_LIBS TRUE)

Then, add the following to your CMakeLists.txt file:

    include(FetchContent)
    FetchContent_Declare(
	    Log
	    GIT_REPOSITORY https://github.com/OliverBryan/Log.git
	    GIT_TAG main
	)
	FetchContent_MakeAvailable(Log)

Finally, don't forget to link it into your project:

    target_link_libraries(ProjectName Log)

## Example

	#include "Log.hpp"

	int main() {
		// initialize the log
		Log::init("log.txt");

		// default log function
		Log::logStatus("status update");
		
		// use a different color (see Console.hpp for valid colors)
		Log::logStatus("new color", ConsoleColor::NeonBlue);
		
		// log an error (just changes the color to red)
		Log::logError("error");

		// close the log (don't forget to do this or it may not write to the file correctly)
		Log::close();
	}
