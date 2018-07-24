file(GLOB SOURCES *.cpp)

project(rectangle_lib)
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
