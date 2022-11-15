# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/lib/cs225/HSLAPixel.cpp"
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/*.cpp")
set(OLD_GLOB
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/dfs.cpp"
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/dijkstra.cpp"
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/graph.cpp"
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/landalgo.cpp"
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/src/stronglyconnected.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:88 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/tests/correctOutputTests.cpp"
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/tests/dfsTests.cpp"
  "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/tests/graphTests.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/CMakeFiles/cmake.verify_globs")
endif()
