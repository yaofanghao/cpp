#ifndef FRMTCP_H
#define FRMTCP_H

#include <QWidget>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class frmTcp; }
QT_END_NAMESPACE

class frmTcp : public QWidget
{
    Q_OBJECT

public:
    frmTcp(QWidget *parent = nullptr);
    ~frmTcp();

private:
    Ui::frmTcp *ui;
    Server server;
};
#endif // FRMTCP_H
