cmake_minimum_required(VERSION 3.3)
project(FastAnim)

include_directories(deps/glm deps/FastGFX/include include)

set(SRC_ROOT ./)
aux_source_directory(${SRC_ROOT}src SRC_LIST)
set(SOURCE_FILES ${SRC_LIST})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g4")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -s DEMANGLE_SUPPORT=1 -s ASSERTIONS=2")
set(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} --bind -s TOTAL_MEMORY=128000000  -g4")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -stdlib=libc++ -O3 -Os")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s DEMANGLE_SUPPORT=1")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s TOTAL_MEMORY=128000000 -Wno-error=unused-command-line-argument")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s DISABLE_EXCEPTION_CATCHING=0 -s ASSERTIONS=1")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++ -Wall -Werror -s NO_EXIT_RUNTIME=1")

link_directories(deps/FastGFX)
link_libraries(FastGFX)

set(CMAKE_C_COMPILER "emcc")
set(CMAKE_CXX_COMPILER "em++")
#add_library(FastAnim STATIC ${SOURCE_FILES})

find_package(Boost 1.40.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${Boost_CFLAGS_OTHER})
#target_include_directories(${EXECUTABLE_NAME} PUBLIC ${Boost_INCLUDE_DIRS})


set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples )
add_executable(logo.asm.js ${SOURCE_FILES} examples/logo.cpp)
add_executable(pong.asm.js ${SOURCE_FILES} examples/pong.cpp)