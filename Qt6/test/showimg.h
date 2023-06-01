#ifndef SHOWIMG_H
#define SHOWIMG_H

#include <QWidget>
#include <QMessageBox>
#include <QLabel>  // 用于放置图片QPixmap
#include <QTimer>
#include <QString>

namespace Ui {
class ShowImg;
}

class ShowImg : public QWidget
{
    Q_OBJECT

public:
    explicit ShowImg(QWidget *parent = nullptr);
    ~ShowImg();

private:
    Ui::ShowImg *ui;
    QLabel lblimg;
    QPixmap *pm;
    QTimer *timer1;
    int num;  // 图片数量

private slots:
    // 显示图片
    void displayImg();

    // 退出
    void exitShowImg();
};

#endif // SHOWIMG_H
