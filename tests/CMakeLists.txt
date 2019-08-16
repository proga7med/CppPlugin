
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")
mark_as_advanced(
	BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
	gmock_build_tests gtest_build_samples gtest_build_tests
	gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)


add_executable(GCPPTests testlib.cpp)
target_include_directories(GCPPTests PRIVATE "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(GCPPTests PRIVATE gtest gmock gtest_main GCPP)
add_test(NAME GCPPTests COMMAND GCPPTests)
set_target_properties(GCPPTests PROPERTIES FOLDER tests)

