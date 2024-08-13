#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "include/ising.h"
#include "include/plot.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ising ising;
};
#endif // MAINWINDOW_H
