project(sahara)
include(CMakePackageConfigHelpers)
cmake_minimum_required(VERSION 3.21)

file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)
file(GLOB_RECURSE TEST_HEADERS test/*.h test/*.hpp)
file(GLOB_RECURSE TEST_SOURCES test/*.cpp test/*.cc)

set(CMAKE_CXX_STANDARD 20)

configure_package_config_file(cmake/template/sahara.in.cmake sahara-config.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})
add_library(${PROJECT_NAME} SHARED ${CPP_HEADERS} ${CPP_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE $<${WIN32}: bcrypt>)

install(TARGETS ${PROJECT_NAME}
        EXPORT sahara-targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY include/ DESTINATION include/sahara FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
install(EXPORT sahara-targets NAMESPACE sahara:: DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})
