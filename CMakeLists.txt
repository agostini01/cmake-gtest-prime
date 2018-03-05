# ############################################################################
# Developed by https://github.com/agostini01
# License LGPL v3.0
# ############################################################################

cmake_minimum_required (VERSION 3.5)

# Change project name
#set(PROJECT_NAME <TODO>)
set(PROJECT_NAME MYPROJ)

project(${PROJECT_NAME} CXX)

# In order to have a shorter name for other variables ${PN} is defined
set(PN ${PROJECT_NAME})

# Change the output binary name
#set(BINARY_NAME <TODO>)
set(BINARY_NAME ${PN})



# #####################################
# External Packages
# -------------------------------------

find_package(Threads REQUIRED)



# #####################################
# CMAKE OPTIONS
# -------------------------------------

# Declare some CMAKE -D<option>
option(BUILD_INCLUDE_TESTS 
  "Generate build targets for the ${PN} unit tests." ON)
option(BUILD_SILENCE_WARNINGS 
  "Compile with silent warnings." OFF)
option(BUILD_WARNINGS_AS_ERRORS 
  "During compilation, warning are treated as errors." OFF)




# #####################################
# Compilation flags
# -------------------------------------

# Set some compilation options
set(CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -std=c++14")
# Compilation flags based on cmake -Doptions
if( BUILD_WARNINGS_AS_ERRORS )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pedantic-errors")
  set(BUILD_SILENCE_WARNINGS OFF)
endif()
if( NOT BUILD_SILENCE_WARNINGS )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal -Wold-style-cast")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address") # Memory leaks
endif()



# #####################################
# CMake folders
# -------------------------------------

# put executables in the 'bin' folder and libraries in the 'lib'
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_TESTS_OUTPUT_DIRECTORY   ${CMAKE_BINARY_DIR}/test)

# Set Cmake module Path to increase cmake functionality
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
# Set the `source` and `include` directories used by other CMakeLists.txt files
set(${PN}_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(${PN}_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

add_subdirectory (src) 
add_subdirectory (include) 
add_subdirectory (lib)

# Include directories
include_directories(include)



# #####################################
# Enable GTest
# -------------------------------------

# Enable GTest
if( BUILD_INCLUDE_TESTS )
  # Adding this subdirectory will trigger gtest installation
  add_subdirectory (test)
  enable_testing ()
endif()
