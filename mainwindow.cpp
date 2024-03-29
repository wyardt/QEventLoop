#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runBtn_clicked()
{
    QTimer *timerRun = new QTimer();
    QEventLoop loop;
    connect(timerRun, SIGNAL(timeout()), &loop, SLOT(quit()));
    connect(this, SIGNAL(feedBtnPressed()), &loop, SLOT(quit()));
    timerRun->stop();
    timerRun->start(ui->nTimeout->value() * 1000);
    ui->plainTextEdit->appendPlainText("timer starts");
    loop.exec(/* QEventLoop::ExcludeUserInputEvents */);
    if (flag != false)
    {
        flag = false;
        ui->plainTextEdit->appendPlainText("fed, timer stops");
    }
    else
    {
        ui->plainTextEdit->appendPlainText("timer expires");
    }
}

void MainWindow::on_feedBtn_clicked()
{
    flag = true;
    emit feedBtnPressed();
}


void MainWindow::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}
