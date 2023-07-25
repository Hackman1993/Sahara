cmake_minimum_required(VERSION 3.21)
project(sahara)
set(SAHARA_VERSION 1.0.1)
include(CMakePackageConfigHelpers)

file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)

file(GLOB_RECURSE CPP_TESTS test/*.cpp test/*.cc)

find_package(Boost REQUIRED COMPONENTS locale)
find_package(fmt REQUIRED)
find_package(date REQUIRED)
find_package(spdlog CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC ${CPP_HEADERS} ${CPP_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE $<${WIN32}: bcrypt> fmt::fmt date::date date::date-tz spdlog::spdlog)

configure_package_config_file(cmake/template/sahara.in.cmake
        sahara-config.cmake
        INSTALL_DESTINATION ./)
write_basic_package_version_file(
        ${PROJECT_NAME}-config-version.cmake
        VERSION ${SAHARA_VERSION}
        COMPATIBILITY ExactVersion)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION share/sahara)
install(TARGETS ${PROJECT_NAME}
        EXPORT sahara-targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

install(DIRECTORY include/ DESTINATION include/sahara FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
install(EXPORT sahara-targets NAMESPACE sahara:: DESTINATION share/${PROJECT_NAME})

add_executable(${PROJECT_NAME}-test ${CPP_TESTS})
target_include_directories(${PROJECT_NAME}-test PRIVATE include)
target_link_libraries(${PROJECT_NAME}-test PRIVATE ${PROJECT_NAME} sahara spdlog::spdlog)
