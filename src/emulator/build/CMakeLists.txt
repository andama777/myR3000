# emulator/build/CMakeLists.txt
# emulator/top.cpp
# emulator/r3k.cpp
# emulator/r3k.hpp
# cmake .
# make

# 以下にCMakeLists.txtを記述

cmake_minimum_required(VERSION 3.0)
project(r3kemu)

set(CMAKE_CXX_STANDARD 11)

# デバッグビルド用の設定
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -O0 -DDEBUG")

# リリースビルド用の設定
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# ビルドのタイプはデバッグ
set(CMAKE_BUILD_TYPE Debug)

# ビルド対象のソースコード
set(SRC_FILES
    ../top.cpp
    ../r3k.cpp
    ../r3k.hpp
    # ../register.cpp
    # ../register.hpp
)

set(LIB_PATH ../lib/)

add_library(mylib STATIC 
    # ../lib/register.cpp ../lib/register.hpp ../lib/instruction.cpp ../lib/instruction.hpp
    ${LIB_PATH}/register.cpp ${LIB_PATH}/register.hpp ${LIB_PATH}/instruction.cpp ${LIB_PATH}/instruction.hpp
)

target_include_directories(mylib PUBLIC ${LIB_PATH})

# 実行ファイルの出力先
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 実行ファイルの名前
add_executable(r3kemu ${SRC_FILES})
target_link_libraries(r3kemu mylib)