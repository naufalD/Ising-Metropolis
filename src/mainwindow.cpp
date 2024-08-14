#include "include/mainwindow.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    double J {1};
    double temperature {2300};
    m_sizeX = 200;
    m_sizeY = 200;

    m_isingSpace = new Ising(m_sizeX, m_sizeY, J, temperature);
    m_isingPlot = new PlotIsing(m_sizeX, m_sizeY);
    m_energyPlot = new PlotEnergy();

    m_label1 = new QLabel();

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_isingPlot);
    layout->addWidget(m_energyPlot);
    layout->addWidget(m_label1);

    startTimer(10);
    m_timer.start();

}

void MainWindow::timerEvent( QTimerEvent* ){
        for (int j {0}; j<m_sizeY; ++j){
            for (int i {0}; i<m_sizeX; ++i){
                if (m_isingSpace->getPoint(i, j)==1) m_isingPlot->plotUp(i, j);
                else m_isingPlot->plotDown(i, j);
            }
        }
        double energyTemp {m_isingSpace->getEnergy()};
        m_energyPlot->plot(m_timer.elapsed(), energyTemp);
        m_isingPlot->updatePlot();
        m_isingSpace->updateSpace();
        m_label1->setText(QString::number(energyTemp));
}

