file(GLOB SOURCES *.cpp)
add_library(rectangle_lib ${SOURCES})
target_include_directories(rectangle_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})