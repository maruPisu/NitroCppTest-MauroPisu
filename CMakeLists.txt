cmake_minimum_required(VERSION 3.0.2)

set(CMAKE_CXX_STANDARD 14)

project(RectangleIntersections)

#check the existance of rapidjson
unset(RAPIDJSON_INCLUDE_DIR CACHE)
find_path(
    RAPIDJSON_INCLUDE_DIR
    NAMES "rapidjson/document.h"
    PATHS "${CMAKE_FRAMEWORK_PATH}/include"
)
if(NOT RAPIDJSON_INCLUDE_DIR)
	message(FATAL_ERROR "rapidjson not found")
endif()

# put the runtime target files in the root of the build tree
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

#copy the testfiles
file(COPY testfiles DESTINATION ${CMAKE_BINARY_DIR})
