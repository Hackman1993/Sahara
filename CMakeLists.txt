cmake_minimum_required(VERSION 3.21)
project(libsahara)

file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)
file(GLOB_RECURSE TEST_HEADERS test/*.h test/*.hpp)
file(GLOB_RECURSE TEST_SOURCES test/*.cpp test/*.cc)

set(CMAKE_CXX_STANDARD 20)
find_package(Boost REQUIRED locale unit_test_framework)
find_package(fmt CONFIG REQUIRED)
include_directories(include)
include_directories(${Boost_INCLUDE_DIRS})

add_library(libsahara ${CPP_HEADERS} ${CPP_SOURCES})
target_link_libraries(libsahara PRIVATE Boost::locale)

add_executable(libsahara_test ${TEST_HEADERS} ${TEST_SOURCES} )
target_link_libraries(libsahara_test PRIVATE libsahara Boost::locale Boost::unit_test_framework fmt::fmt-header-only)
