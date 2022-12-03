% 读取csv文件夹
x1=daizi{:,1};
y1=daizi{:,2};

x2=deng{:,1};
y2=deng{:,2};

x3=qiqiu{:,1};
y3=qiqiu{:,2};

x4=fire3{:,1};
y4=fire3{:,2};

plot(y1);
hold on;
plot(y2);
hold on;
plot(y3);
hold on;
plot(y4)
xlabel('帧数')
ylabel('图像熵值')
legend('塑料袋','灯','气球','火焰','Location','SouthEast')

