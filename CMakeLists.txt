cmake_minimum_required(VERSION 3.21)
project(sahara)

file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)
file(GLOB_RECURSE TEST_HEADERS test/*.h test/*.hpp)
file(GLOB_RECURSE TEST_SOURCES test/*.cpp test/*.cc)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS locale )
find_package(fmt CONFIG REQUIRED)

add_library(${PROJECT_NAME} SHARED ${CPP_HEADERS} ${CPP_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE $<${WIN32}: bcrypt>)
install(TARGETS sahara DESTINATION lib EXPORT sahara-config)
install(DIRECTORY include/ DESTINATION include/sahara FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
install(EXPORT sahara-config NAMESPACE sahara:: DESTINATION lib/cmake/sahara)
