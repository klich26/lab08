file(GLOB TEST_SOURCES *.cpp)

add_executable(run_tests ${TEST_SOURCES})

target_link_libraries(run_tests
    banking
    gtest
    gmock
    gtest_main
)

add_test(NAME all_tests COMMAND run_tests)
