cmake_minimum_required(VERSION 3.10)

# Project name and version
project(List VERSION 1.0)

# Set the output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add the library (shared/dynamic)
add_library(list SHARED src/list.cpp)

# Specify include directories using generator expressions
target_include_directories(list PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

# Set version properties for the library (SONAME)
set_target_properties(list PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Add installation rules
install(TARGETS list
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Install header files
install(FILES src/list.hpp DESTINATION include)
