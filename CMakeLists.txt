cmake_minimum_required(VERSION 2.6)

project(KompasCore)

option(BUILD_TESTS "Build unit tests (requires Qt4)." OFF)

if(BUILD_TESTS)
    find_package(Qt4)

    if(NOT QT4_FOUND)
        message(WARNING "Qt4 is required for building unit tests. No tests will be build.")
        set(BUILD_TESTS OFF)
    else()
        enable_testing()
    endif()

endif()

set(CMAKE_MODULE_PATH "${KompasCore_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})
find_package(Corrade REQUIRED)

# Default directories
set_parent_scope(KOMPAS_CORE_INCLUDE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/src")
set_parent_scope(KOMPAS_PLUGINS_INCLUDE_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/src/Plugins")
set_parent_scope(KOMPAS_CORE_LIBRARY         KompasCore)
include(FindKompasCore)

# On 64bit Linux with GCC flag -fPIC is needed for building some static libraries
if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_COMPILER_IS_GNUCC AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(USE_FPIC ON)
else()
    set(USE_FPIC OFF)
endif()

# Library version
set(KOMPAS_CORE_LIBRARY_VERSION 0.1.2)
set(KOMPAS_CORE_LIBRARY_SOVERSION 0)

add_subdirectory(modules)
add_subdirectory(src)

if(NOT WIN32)
    install(DIRECTORY src/ DESTINATION ${KOMPAS_CORE_INCLUDE_INSTALL_DIR}
                 FILES_MATCHING PATTERN "*.h"
                 PATTERN "*/Test" EXCLUDE
                 PATTERN "*/doc" EXCLUDE
                 PATTERN src/Plugins EXCLUDE)
    install(DIRECTORY src/Plugins/ DESTINATION ${KOMPAS_PLUGINS_INCLUDE_INSTALL_DIR}
                FILES_MATCHING PATTERN "*.h"
                PATTERN "*/Test" EXCLUDE)
endif()
