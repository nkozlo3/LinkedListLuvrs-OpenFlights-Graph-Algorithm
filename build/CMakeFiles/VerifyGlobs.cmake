# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/*.cpp")
set(OLD_GLOB
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/dfs.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:130 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/tests/*.cpp")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/CMakeFiles/cmake.verify_globs")
endif()