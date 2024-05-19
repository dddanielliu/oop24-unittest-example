cmake_minimum_required(VERSION 3.14)
project(unittest VERSION 1.0 LANGUAGES CXX)

# 設定 C++ 標準
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 設定編譯選項，包含測試覆蓋率選項
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")

# 建立 add 函示庫
add_library(add STATIC add.cpp)

# 加入 include 資料夾給 add.h
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 建立可執行檔 main
add_executable(main main.cpp)

# 將可執行檔和函示庫做連結
target_link_libraries(main PUBLIC add)

# 使用 FetchContent 模組
include(FetchContent)
# 下載和引入 Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# 建立一個測試用的可執行檔 test_add
add_executable(test_add unittest.cpp)
# 連結必要函示庫給 test_add
target_link_libraries(test_add PRIVATE add gtest gtest_main)

# 開啟 CMake 測試
enable_testing()

# 把 test_add 加進命名 my_project_test 的測試
add_test(
    NAME my_project_test
    COMMAND test_add
)