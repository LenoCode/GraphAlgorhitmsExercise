project(GrphAlgo)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR}
            ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#Define testing
enable_testing()



add_executable(basic_graph_impl_test unit_tests/graph_impl/basic/v1/basic_graph_impl_test.cpp include/core_header.h
                                    ../include/graph_impl/basic/v1/basic_graph_adj_list_repo.h)


add_executable(basic_graph_linked_list_test  unit_tests/graph_impl/basic/v1/basic_graph_impl_linked_list_test.cpp
        include/core_header.h
        ../include/graph_impl/basic/v1/basic_graph_adj_list_repo.h)

target_include_directories(basic_graph_impl_test PUBLIC include)

target_include_directories(basic_graph_linked_list_test PUBLIC include)

target_link_libraries(
        basic_graph_impl_test
        GTest::gtest_main
        graph
)

target_link_libraries(
        basic_graph_linked_list_test
        GTest::gtest_main
        graph
)

include(GoogleTest)

gtest_discover_tests(basic_graph_impl_test)
gtest_discover_tests(basic_graph_linked_list_test)