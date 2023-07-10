cmake_minimum_required(VERSION 3.21)
project(sahara)

file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)
file(GLOB_RECURSE TEST_HEADERS test/*.h test/*.hpp)
file(GLOB_RECURSE TEST_SOURCES test/*.cpp test/*.cc)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS locale unit_test_framework url)
find_package(fmt CONFIG REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_library(sahara STATIC ${CPP_HEADERS} ${CPP_SOURCES})
add_library(bbc::dda ALIAS sahara)
target_link_libraries(sahara PRIVATE Boost::locale bcrypt)
install(TARGETS sahara DESTINATION lib EXPORT sahara-targets)
install(DIRECTORY include/ DESTINATION include/sahara FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
install(EXPORT sahara-targets NAMESPACE sahara:: DESTINATION lib/cmake/sahara)
message(STATUS ${HELLO} ${sahara-targets})

#add_executable(libsahara_test ${TEST_HEADERS} ${TEST_SOURCES} )
#target_link_libraries(libsahara_test PRIVATE sahara Boost::unit_test_framework Boost::locale fmt::fmt ws2_32 )
