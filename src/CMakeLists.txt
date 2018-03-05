# ############################################################################
# Developed by https://github.com/agostini01
# License LGPL v3.0
# ############################################################################
# #####################################
# Example Library
# -------------------------------------

#Library sources
set(OTHER_SRCS
  ${${PN}_SOURCE_DIR}/Example.cpp
  ${${PN}_INCLUDE_DIR}/Example.h
  )

# Declare the library
add_library(${PN}Example STATIC
  ${OTHER_SRCS}
  )

# Specify here the include directories exported by this library
target_include_directories(${PN}Example PUBLIC
  ${${PN}_INCLUDE_DIR}
  )

# Specify here the libraries this library depends on
#target_link_libraries(${PN}
#  ${PN}Example2
#  )



# #####################################
# Driver Program
# -------------------------------------

# Executable sources
set(MAIN_SRCS
  ${${PN}_SOURCE_DIR}/main.cpp
  )

# Declare the executable
add_executable(${BINARY_NAME}
  ${MAIN_SRCS}
  )

# Specify here the libraries this program depends on
target_link_libraries (${BINARY_NAME} LINK_PUBLIC 
  ${PN}Example
  )

#install(TARGETS ${BINARY_NAME} DESTINATION bin)

