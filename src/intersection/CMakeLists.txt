file(GLOB SOURCES *.cpp)
   
add_executable(intersection ${SOURCES})

#link the rectangle_lib library
target_link_libraries(intersection rectangle_lib)
