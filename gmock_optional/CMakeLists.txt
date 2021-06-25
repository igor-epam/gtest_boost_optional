# CMakeList.txt : CMake project for gmock_optional, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
        message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
    endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES gtest/1.11.0
    boost/1.76.0
    GENERATORS cmake)

conan_cmake_autodetect(CONAN_SETTINGS)

conan_cmake_install(PATH_OR_REFERENCE .
    SETTINGS ${CONAN_SETTINGS}
    BUILD missing)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
#find_package(GTest REQUIRED)


add_executable(gmock_optional gmock_optional.cpp gmock_optional.h)
target_link_libraries(gmock_optional ${CONAN_LIBS})
target_include_directories(gmock_optional PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(AllTestsInFoo gmock_optional)
