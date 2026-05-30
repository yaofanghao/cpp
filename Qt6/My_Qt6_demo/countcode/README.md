<!--
 * @Author: yao fanghao
 * @Date: 2023-05-31 22:15:20
 * @LastEditTime: 2023-05-31 22:28:18
 * @LastEditors: yao fanghao
-->
# countcode-demo

* 2023.5.31
* 实现代码统计的qt小项目
* Qt Creator 10.0.1
* Qt 6.5.1
* MSVC 2019, x86_64
* MinGW 11.20.64

* 启动入口
  * main.cpp

* 实现软件功能
  * frmcountcode.cpp
  * frmcountcode.h
  * frmcountcode.ui

# frmcountcode.h

* frmCountCode 类
* private接口

    ```cpp
        QStringList listFile;
        void initForm();
        bool checkFile(const QString &fileName);
        void countCode(const QString &filePath);
        void countCode(const QStringList &files);
        void countCode(const QString &fileName, int &lineCode, int &lineBlank, int &lineNotes);
    ```

* private slots 信号槽接口
  
    ```cpp
    #include "qfiledialog.h"
    #include "qfileinfo.h"
    #include "qdebug.h"
    ```

    ```cpp
        void on_btnOpenFile_clicked();
        void on_btnOpenPath_clicked();
        void on_btnClear_clicked();
    ```
