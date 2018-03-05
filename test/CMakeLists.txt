# ############################################################################
# Developed by https://github.com/agostini01
# License LGPL v3.0
# ############################################################################

# Install gtest - from a cmake.module
include(gtest)
enable_testing ()



# #####################################
# Include tests
# -------------------------------------

file(GLOB TEST_SRCS *.cpp)

ADD_EXECUTABLE(${PN}tests ${TEST_SRCS})

TARGET_LINK_LIBRARIES(${PN}tests
  ${PN}Example # TODO Libraries must be added here for the tests
  libgtest
  libgmock
  )

add_test(
  NAME                ${PN}tests 
  COMMAND             ${PN}tests
  WORKING_DIRECTORY   ${CMAKE_TESTS_OUTPUT_DIRECTORY}
  )
