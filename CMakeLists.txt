cmake_minimum_required(VERSION 2.8)
project(RobocupUlaval)

set(CMAKE_BUILD_TYPE Release)

set(COMPILE_TESTS FALSE)
set(COMPILE_PYTHONTESTS FALSE)
set(COMPILE_CLI TRUE)
set(COMPILE_GUI FALSE)

ADD_CUSTOM_COMMAND(
    OUTPUT BUILD PROTOC
	COMMAND ${CMAKE_ROOT}/compile.sh
	WORKING_DIRECTORY ${CMAKE_ROOT}
)

#Find Threads
find_package(Threads REQUIRED)
list(APPEND libs  ${CMAKE_THREAD_LIBS_INIT})

#Find boost
set(Boost_USE_STATIC_LIBS ON) # ON
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ALL_DYN_LINK ON) # ON

if (MINGW)
	set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "")
endif ()

set(Boost_ADDITIONAL_VERSIONS "1.55" "1.53" "1.46")
#set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/ext/boost)
#set(Boost_INCLUDE_DIR ${BOOST_ROOT}/include)
#set(Boost_LIBRARY_DIRS ${BOOST_ROOT}/lib)



#set(Boost_LIBRARIES ${BOOST_ROOT}/lib/libboost_filesystem.a ${BOOST_ROOT}/lib/libboost_system.a ${BOOST_ROOT}/lib/libboost_program_options.a ${BOOST_ROOT}/lib/libboost_thread.a)



find_package(Boost COMPONENTS filesystem system program_options thread log log_setup REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
list(APPEND libs ${Boost_LIBRARIES})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Qt
set(QT_USE_QTNETWORK true)
set(QT_USE_QTAPPLICATION true)
set(QT_USE_QTCORE true)
set(QT_USE_QTOPENGL true)
find_package(Qt4 REQUIRED )

include(${QT_USE_FILE})
list(APPEND libs ${QT_LIBRARIES})


set(CMAKE_AUTOMOC_MOC_OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED -DBOOST_LEXICAL_CAST_INCLUDED -DBOOST_VF2_SUB_GRAPH_ISO_HPP)
set(CMAKE_AUTOMOC ON)

# Protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
list(APPEND libs ${PROTOBUF_LIBRARIES})

# Include files
file(GLOB_RECURSE files_SRC
    "./src/*.cpp"
    "./include/*.h"
    "./include/*.hpp"
    "./src/*.cc"
    "./include/*.pb*"
)


set(CMAKE_AUTOMOC ON)

# Protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
list(APPEND libs ${PROTOBUF_LIBRARIES})


set (PROJECT_INCLUDE_DIR include)
include_directories(${PROJECT_INCLUDE_DIR})

if(COMPILE_TESTS)
    #Code coverage
    set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -fPIC")
    set(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

    #GoogleTest
    set(GTEST_DIR ext/gmock/gtest)
    set(GMOCK_DIR ext/gmock)

    include(${GTEST_DIR}/cmake/internal_utils.cmake)
    config_compiler_and_linker()  # Defined in internal_utils.cmake.

    include_directories(
        ${GTEST_DIR}/include
        ${GTEST_DIR}
        ${GMOCK_DIR}/include
        ${GMOCK_DIR}
    )
    link_directories(
        ${gtest_BINARY_DIR}/src
    )

    cxx_library(gtest "${cxx_strict}" ${GTEST_DIR}/src/gtest-all.cc)
    cxx_library(gtest_main "${cxx_strict}" ${GTEST_DIR}/src/gtest_main.cc)
    cxx_library(gmock "${cxx_strict}" ${GMOCK_DIR}/src/gmock-all.cc)

    set(TEST_INCLUDE_DIR test)
    include_directories(${TEST_INCLUDE_DIR})

    file(GLOB_RECURSE tests_SRC
        "test/*.cc"
        "test/*.h"
    )

    add_executable(robocupulaval_tests ${tests_SRC} ${files_SRC})
    target_link_libraries(robocupulaval_tests gtest_main gtest gmock ${libs})

endif(COMPILE_TESTS)

if(COMPILE_PYTHONTESTS)
    file(GLOB_RECURSE python_SRC
        "./python/*"
    )
    Find_Package(SDL REQUIRED)
    Find_Package(SDL_image REQUIRED)
    find_package(PythonLibs REQUIRED)

    if(NOT SDL_FOUND)
       message(FATAL_ERROR "SDL not found!" )
    endif( NOT SDL_FOUND )

    add_executable(pythonTest ${python_SRC})
    include_directories(${PYTHON_INCLUDE_DIRS})
    target_link_libraries(pythonTest ${PYTHON_LIBRARIES} ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} SDLmain)

endif(COMPILE_PYTHONTESTS)

if(COMPILE_GUI)

    add_executable(robocupulaval_qt ${files_SRC} main_qt.cpp)
    target_link_libraries(robocupulaval_qt ${libs})

endif(COMPILE_GUI)

if(COMPILE_CLI)

    add_executable(robocupulaval_cli ${files_SRC} main_cli.cpp ${SAMPLE_MOC_SRCS})
    target_link_libraries(robocupulaval_cli ${libs})

endif(COMPILE_CLI)



