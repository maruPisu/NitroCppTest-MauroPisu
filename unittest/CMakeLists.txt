file(GLOB SOURCES *.cpp)
   
   
add_executable(test_rectangle ${SOURCES})

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 

target_link_libraries(test_rectangle ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} rectangle_lib)

add_test(NAME t_rectangle COMMAND test_rectangle)
