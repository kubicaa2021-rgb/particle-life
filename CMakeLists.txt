cmake_minimum_required(VERSION 3.16)
project(particleLife)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(particleLife 
  src/main.cpp
  src/headers/particle.h
  src/headers/windowHelper.h
  src/headers/vector2.h
  src/headers/settings.h
  src/headers/drawUtils.h
)

find_package(SDL3 REQUIRED)

target_include_directories(
  particleLife
  PRIVATE src/headers
)

target_link_libraries(
  particleLife
  SDL3::SDL3
)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "particleLife Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for particleLife
set(particleLife_Version_Major 0)
set(particleLife_Version_Minor 1)
set(particleLife_Version_Patch 0)
set(particleLife_Version_Status "-dev")
set(PROJECT_VERSION
  "${particleLife_Version_Major}.${particleLife_Version_Minor}.${particleLife_Version_Patch}${particleLife_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")


