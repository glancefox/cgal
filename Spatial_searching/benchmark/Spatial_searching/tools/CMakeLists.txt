# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( tools_ )

cmake_minimum_required(VERSION 3.1)

find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include(${CGAL_USE_FILE})
  include_directories (BEFORE "../include")

  create_single_source_cgal_program( "points_in_bbox.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

