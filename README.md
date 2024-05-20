# Google Test 範例專案

## 使用方法

### 0. 請於事前安裝 cmake

Linux:

```sh
$ apt update
$ apt install g++ cmake
```

若環境有需要，請自行加上 `sudo`

Windows:

可以透過 Windows Subsystem of Linux 來操作 Linux。

### 1. clone 這個專案

```shell
$ git clone https://github.com/oopnccucs/oop24-unittest-example
```

### 2. 建立並移動到 build 資料夾

```shell
$ mkdir build && cd build
```

### 3. 使用 cmake 建立 makefile，並編譯檔案

```shell
$ cmake .. && make
```

在這之後的指令都在 /build 資料夾下執行。

### 4. 執行 ctest 並確認結果

```sh
$ ctest --output-on-failure
```

在這次測試中應當會出現以下結果：

```
Test project /oop24-unittest-example/build
    Start 1: my_project_test
1/1 Test #1: my_project_test ..................***Failed    0.10 sec
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from Calculator
[ RUN      ] Calculator.Add
[       OK ] Calculator.Add (0 ms)
[ RUN      ] Calculator.Add2
/oop24-unittest-example/unittest.cpp:12: Failure
Expected equality of these values:
  C.Add(1, 3)
    Which is: 4
  5
[  FAILED  ] Calculator.Add2 (0 ms)
[----------] 2 tests from Calculator (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] Calculator.Add2

 1 FAILED TEST


0% tests passed, 1 tests failed out of 1

Total Test time (real) =   0.17 sec

The following tests FAILED:
          1 - my_project_test (Failed)
Errors while running CTest
```

可以發現在 unittest.cpp:12 行中對以下結果提報了錯誤：

```cpp
TEST(Calculator, Add2) {
    Calculator C;
    EXPECT_EQ(C.Add(1, 3), 5);
}
```

### 5. 修改程式碼後，再度 make 與 ctest 察看結果

```sh
make && ctest --output-on-failure
```
除非改動到專案構造，否則不需要重新cmake

### 6. 執行 gcov ，查看程式碼覆蓋率

```sh
$ gcov ./CMakeFiles/add.dir/add.cpp.gcda 
$ cat ./add.cpp.gcov
```
gcov格式如下:
gcov ./CMakeFiles/<檔案名稱>.dir/<檔案路徑>/<檔案名稱(包含副檔名)>.gcda

可以看到如下涵蓋率報表：

```
    -:    0:Source:/oop24-unittest-example/add.cpp
    -:    0:Graph:./CMakeFiles/add.dir/add.cpp.gcno
    -:    0:Data:./CMakeFiles/add.dir/add.cpp.gcda
    -:    0:Runs:3
    -:    1:
    -:    2:#include "add.h"
    -:    3:
    6:    4:int Calculator::Add(int a, int b) {
    6:    5:    return a + b;
    -:    6:}
    -:    7:
#####:    8:int Calculator::Sub(int a, int b) {
#####:    9:    return a - b;
    -:   10:}
```

### 7. 為了視覺化程式碼覆蓋率，我們可以安裝 lcov 

Linux:

```sh
$ apt-get install lcov
```

若環境有需要，請自行加上 `sudo`

Windows:

可以透過 Windows Subsystem of Linux 來操作 Linux。

### 8. 執行 lcov ，產生統計資料

```sh
$ lcov -c -d CMakeFiles -o cov.info
```

### 9. 使用內建在 lcov 的 genhtml 產生視覺化資料 (html)

```sh
$ genhtml cov.info -o report
```

### 10. 查看 /build/report/index.html ，以瀏覽器開啟這個html檔案

### 11. 確認程式碼覆蓋率。
    
在這個測試中，點入 `/oop24-unittest-example` 後，可以看到 `app.cpp` 的覆蓋率為50%，查看測試程式後可以發現在減法的部分沒有在測試中。

![image](https://i.imgur.com/8fWeBEG.png)