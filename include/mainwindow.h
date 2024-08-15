#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QElapsedTimer>
#include <QMainWindow>
#include <QLabel>

#include "include/ising.h"
#include "include/plot.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    virtual void timerEvent( QTimerEvent* ) QWT_OVERRIDE;

private:
    Ising *m_isingSpace;
    PlotIsing *m_isingPlot;
    PlotParam *m_energyPlot;
    PlotParam *m_magnetizationPlot;
    QLabel *m_label1;
    QElapsedTimer m_timer;


    int m_sizeX;
    int m_sizeY;

};
#endif // MAINWINDOW_H
