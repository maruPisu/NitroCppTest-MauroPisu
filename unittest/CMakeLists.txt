file(GLOB SOURCES *.cpp)
      
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 

#generates a different test for each file .cpp in this folder
foreach(file ${SOURCES})
	get_filename_component(TEST_NAME ${file} NAME_WE)

	add_executable(${TEST_NAME} ${file})

	target_link_libraries(${TEST_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} rectangle_lib)

	add_test(NAME _${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
