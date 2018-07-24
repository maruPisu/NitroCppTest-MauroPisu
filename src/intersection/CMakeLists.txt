file(GLOB SOURCES *.cpp)
   
add_executable(intersection ${SOURCES})

target_link_libraries(intersection rectangle_lib)
