#include "frmtcp.h"
#include "ui_frmtcp.h"

frmTcp::frmTcp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::frmTcp)
{
    ui->setupUi(this);

}

frmTcp::~frmTcp()
{
    delete ui;
}

