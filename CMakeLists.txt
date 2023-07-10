cmake_minimum_required(VERSION 3.21)
project(sahara)
set(SAHARA_VERSION 1.0.1)
include(CMakePackageConfigHelpers)

file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)

find_package(Boost REQUIRED locale)
find_package(fmt REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} SHARED ${CPP_HEADERS} ${CPP_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE $<${WIN32}: bcrypt> fmt::fmt-header-only)

configure_package_config_file(cmake/template/sahara.in.cmake ${CMAKE_CURRENT_BINARY_DIR}/sahara-config.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME} NO_SET_AND_CHECK_MACRO)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        VERSION ${SAHARA_VERSION}
        COMPATIBILITY SameMajorVersion)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/beicode-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/beicode-config-version.cmake
        DESTINATION " ${CMAKE_INSTALL_DATADIR}/sahara")

install(TARGETS ${PROJECT_NAME}
        EXPORT sahara-targets)

install(DIRECTORY include/ DESTINATION include/sahara FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
install(EXPORT sahara-targets NAMESPACE sahara:: DESTINATION lib/cmake/${PROJECT_NAME})
