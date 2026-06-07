cmake_minimum_required(VERSION 3.16)
project(todoApp)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCE_FILES "src/*.cpp" "src/headers/*.h")
add_executable(todoApp ${SOURCE_FILES})

target_include_directories(
  todoApp
  PRIVATE src/headers
)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "todoApp Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for todoApp
set(todoApp_Version_Major 0)
set(todoApp_Version_Minor 1)
set(todoApp_Version_Patch 0)
set(todoApp_Version_Status "-dev")
set(PROJECT_VERSION
  "${todoApp_Version_Major}.${todoApp_Version_Minor}.${todoApp_Version_Patch}${todoApp_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")


