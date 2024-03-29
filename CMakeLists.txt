cmake_minimum_required(VERSION 3.10)

# Assignment Information (these are the *only* things you need to change here between assignments)
set(assignment_name "final") # Name of the assignment
set(assignment_entrypoints "main") # Entrypoints to run the program
set(assignment_clean_rm "") # Generated files that should be removed with "make clean"
set(assignment_container "fa22") # Container we are targetting
project("Graphs")

# Add color support to our messages.
# See: https://stackoverflow.com/questions/18968979/how-to-get-colorized-output-with-cmake
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColorReset   "${Esc}[m")
  set(ColorBold    "${Esc}[1m")
  set(ColorRed     "${Esc}[31m")
  set(ColorGreen   "${Esc}[32m")
  set(ColorYellow  "${Esc}[33m")
  set(ColorBlue    "${Esc}[34m")
  set(ColorMagenta "${Esc}[35m")
  set(ColorCyan    "${Esc}[36m")
  set(ColorWhite   "${Esc}[37m")
endif()

# Specify C++ compiler and linker.
if(NOT DEFINED EWS)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    set(CMAKE_LINKER "/usr/bin/clang++")
else()
    set(CMAKE_C_COMPILER "/software/llvm-6.0.1/bin/clang")
    set(CMAKE_CXX_COMPILER "/software/llvm-6.0.1/bin/clang++")
    set(CMAKE_LINKER "/software/llvm-6.0.1/bin/clang++")

    # Add other required flags for EWS.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
endif()

# Specify C++ Standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify Debug build.
set(CMAKE_BUILD_TYPE Debug)

# Specify warnings for all builds.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

# Specify debug symbols and no optimizations for Debug builds.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -O0 -gdwarf-4")

# Specify additional clean files.
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_CLEAN_FILES "${assignment_clean_rm}")

# Add Catch2.
# Note: Ubuntu 20.04 LTS does not have Catch2 on apt
# See: https://github.com/catchorg/Catch2/issues/1383
if(NOT DEFINED EWS)
    find_package(Catch2 REQUIRED)
else()
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
    )

    FetchContent_MakeAvailable(Catch2)

    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()

# Path definitions.
set(lib_dir ${CMAKE_SOURCE_DIR}/lib)
set(src_dir ${CMAKE_SOURCE_DIR}/src)
set(tests_dir ${CMAKE_SOURCE_DIR}/tests)
set(entry_dir ${CMAKE_SOURCE_DIR}/entry)

# Run CMakeLists in lib_dir to build our required libraries.
add_subdirectory(${lib_dir})

# Run CMakeLists in src_dir to build the student's code.
add_subdirectory(${src_dir})

# Add the Catch2 entrypoint using Catch2, our libs and src code.
file(GLOB_RECURSE tests_src CONFIGURE_DEPENDS ${tests_dir}/*.cpp)

include(Catch)

add_executable(test ${tests_src})
target_link_libraries(test PRIVATE Catch2::Catch2WithMain libs src)

catch_discover_tests(test)

# Add the assignment entrypoints using our libs and src code.
foreach(entrypoint IN LISTS assignment_entrypoints)
    add_executable(${entrypoint} ${entry_dir}/${entrypoint}.cpp)
    target_link_libraries(${entrypoint} PRIVATE libs src)
endforeach()


add_custom_target(
    tests
    COMMAND make -j ./test
    COMMAND ./test
)
add_custom_target(
    mains
    COMMAND make
    COMMAND ./main
)
add_custom_target(
    nine
    COMMAND make -j ./test
    COMMAND ./test [9]
)
add_custom_target(
    seven
    COMMAND make -j ./test
    COMMAND ./test [7]
)

add_custom_target(
    graph
    COMMAND make -j ./test
    COMMAND ./test [graph]
)
add_custom_target(
    dfs
    COMMAND make -j ./test
    COMMAND ./test [dfs]
)
add_custom_target(
    ssc
    COMMAND make -j ./test
    COMMAND ./test [ssc]
)
add_custom_target(
    dijkstra
    COMMAND make -j ./test
    COMMAND ./test [dijkstra]
)
add_custom_target(
    gdbssc
    COMMAND make -j ./test
    COMMAND gdb --args ./test [ssc]
)