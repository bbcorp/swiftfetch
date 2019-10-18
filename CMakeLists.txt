# We want recent cmake version
cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Release)
enable_language(CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE})



project(SwiftFetch)
# The version number
set(Client_VERSION_MAJOR 0)
set(Client_VERSION_MINOR 1)

add_definitions(-DASIO_STANDALONE)
if(UNIX)
	message( STATUS "UNIX: Add GNU C++ 14 flag" )
	add_definitions(-std=c++14)
	message( STATUS "UNIX: Add -Werror flag" )
	add_definitions(-Werror)
	message( STATUS "UNIX: Add -pedantic flag" )
	add_definitions(-pedantic)
	if(CMAKE_BUILD_TYPE STREQUAL Debug)
			message( STATUS "UNIX: Add definition DEBUG" )
			add_definitions(-D_DEBUG)
	else(CMAKE_BUILD_TYPE STREQUAL Debug)
			message( STATUS "UNIX: Add definition NDEBUG" )
			add_definitions(-DNDEBUG)
	endif(CMAKE_BUILD_TYPE STREQUAL Debug)
elseif(MSVC)
	if(CMAKE_BUILD_TYPE STREQUAL Release)
		message( STATUS "WIN32/MSVC: Add definition /SUBSYSTEM:windows" )
		add_definitions(-D/SUBSYSTEM:windows)
		message( STATUS "WIN32/MSVC: Add definition /ENTRY:mainCRTStartup" )
		add_definitions(-D/ENTRY:"mainCRTStartup")
    endif(CMAKE_BUILD_TYPE STREQUAL Release)
	message( STATUS "WIN32/MSVC: Add definition WINVER=0x0601 and _WIN32_WINNT=0x0601" )
	add_definitions(-DWINVER=0x0601 -D_WIN32_WINNT=0x0601)
	message( STATUS "WIN32/MSVC: Add definition warning level 4" )
	add_definitions(-DW4)
endif(UNIX)

include_directories(include)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../library/lib/${CMAKE_GENERATOR_PLATFORM})

file(GLOB SRCS src/*.cpp)

add_executable(switchfetch ${SRCS})

## No library needed for now
#if(UNIX)
#	target_link_libraries(Client sfml-graphics sfml-window sfml-system sfml-audio pthread)
#else(UNIX)
#	target_link_libraries(Client sfml-graphics sfml-window sfml-system sfml-audio)
#endif(UNIX)
