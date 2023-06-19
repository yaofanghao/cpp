// PV操作（Semaphore）是一种多线程同步机制，可以用于实现并发编程。在图像处理和串口通信的应用中，我们可以使用PV操作来协调图像处理线程和串口通信线程之间的资源共享。
// 具体实现流程如下：
// 1. 定义两个计数信号量：一个用于控制图像处理线程的执行（初始值为0），另一个用于控制串口通信线程的执行（初始值为1）。
// 2. 编写图像处理线程函数，该线程从共享缓冲区中获取图像数据，进行处理后将结果存储到共享缓冲区，并对串口通信信号量进行V操作，表示图像处理线程已完成处理任务，唤醒串口通信线程。
// 3. 编写串口通信线程函数，该线程从共享缓冲区中获取图像处理线程处理好的结果，进行串口通信发送，并对图像处理信号量进行V操作，表示串口通信线程已完成通信任务，唤醒图像处理线程。
// 4. 主函数中创建两个线程：一个用于执行图像处理线程函数，另一个用于执行串口通信线程函数。
// 5. 在主函数中使用PV操作控制图像处理线程和串口通信线程的执行：初始化串口通信信号量的初始值为1，即串口通信线程可以开始执行；初始化图像处理信号量的初始值为0，即图像处理线程需要等待串口通信线程执行完再开始执行。
// 6. 在图像处理线程中使用P操作降低图像处理信号量计数值，表示请求资源；在串口通信线程中使用P操作降低串口通信信号量计数值，表示请求资源。在两个线程完成任务后，分别对另一个信号量进行V操作，增加其计数值，以唤醒等待线程开始执行。
// 通过上述步骤，我们可以实现图像处理和串口通信的并发编程，并确保两个线程之间共享的资源不会出现冲突和竞争的情况。

// 我们使用了两个信号量：image_sem和serial_sem。其中，image_sem的初始值为0，表示图像处理线程需要等待串口通信线程执行完才能开始执行；serial_sem的初始值为1，表示串口通信线程可以开始执行。
// 在图像处理线程中，我们使用sem_wait()函数进行P操作降低image_sem信号量的计数值，然后从共享缓冲区中获取数据进行处理，并对serial_sem信号量进行V操作增加其计数值，以唤醒串口通信线程。
// 在串口通信线程中，我们使用sem_wait()函数进行P操作降低serial_sem信号量的计数值，然后从共享缓冲区中获取处理好的数据并进行发送，并对image_sem信号量进行V操作增加其计数值，以唤醒图像处理线程。
// 通过这种方式，我们可以实现图像处理和串口通信的并发编程，并确保两个线程之间共享的资源不会出现冲突和竞争的情况。

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <semaphore.h>

using namespace std;

// 定义信号量
sem_t image_sem;
sem_t serial_sem;

// 共享缓冲区
queue<int> buffer;

void process_image() {
    while (true) {
        // P操作等待可用资源
        sem_wait(&image_sem);

        // 从共享缓冲区中获取数据并进行处理
        int data = buffer.front();
        buffer.pop();
        cout << "Processing image data: " << data << endl;

        // 处理完成后唤醒串口通信线程
        sem_post(&serial_sem);
    }
}

void send_serial_data() {
    while (true) {
        // P操作等待可用资源
        sem_wait(&serial_sem);

        // 从共享缓冲区中获取处理好的数据并进行发送
        int data = buffer.front();
        buffer.pop();
        cout << "Sending serial data: " << data << endl;

        // 发送完成后唤醒图像处理线程
        sem_post(&image_sem);
    }
}

int main() {
    // 初始化信号量
    sem_init(&image_sem, 0, 0);
    sem_init(&serial_sem, 0, 1);

    // 创建两个线程
    thread image_thread(process_image);
    thread serial_thread(send_serial_data);

    // 主线程往共享缓冲区中添加数据
    for (int i = 0; i < 10; i++) {
        buffer.push(i);

        // 唤醒图像处理线程
        sem_post(&image_sem);
    }

    // 等待两个线程执行完成
    image_thread.join();
    serial_thread.join();

    // 销毁信号量
    sem_destroy(&image_sem);
    sem_destroy(&serial_sem);

    return 0;
}
