@PACKAGE_INIT@

include(CMakeFindDependencyMacro)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_dependency(Boost REQUIRED COMPONENTS locale)
find_dependency(fmt REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/sahara-targets.cmake)
if(@Boost_FOUND@)
  include_directories(${Boost_INCLUDE_DIRS})
endif()