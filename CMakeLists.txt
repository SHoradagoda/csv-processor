cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(csv_processor)

enable_language(C)
enable_language(CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    )

add_library(
        csv_proc
        src/csv_processor.cpp
        src/empty_column_finder.cpp src/empty_column_finder.h src/utils.cpp src/utils.h src/file_stripper.cpp src/file_stripper.h)

set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
    csv_proc_tests
    test/main.cpp
        test/csv_processor_strip_columns.cpp
        test/empty_column_finder_test.cpp test/file_stripper_test.cpp)


add_dependencies(csv_proc_tests googletest)

target_link_libraries(
    csv_proc_tests
    googletest
    csv_proc
    pthread
)

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/csv_proc_test)
