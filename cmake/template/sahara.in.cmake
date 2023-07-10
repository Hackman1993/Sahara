@PACKAGE_INIT@

include(CMakeFindDependencyMacro)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_dependency(Boost REQUIRED COMPONENTS locale)
find_dependency(fmt REQUIRED)
message(STATUS "BOOST:" "@Boost_FOUND@")
if(@Boost_FOUND@)
  include_directories(${Boost_INCLUDE_DIRS})