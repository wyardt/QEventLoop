#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runBtn_clicked();

    void on_feedBtn_clicked();

private:
    Ui::MainWindow *ui;
    bool flag = false;
signals:
    void feedBtnPressed(void);
};

#endif // MAINWINDOW_H
