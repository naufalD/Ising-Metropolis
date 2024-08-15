#include "include/mainwindow.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    double J {-1};
    double temperature {2.5};
    m_sizeX = 200;
    m_sizeY = 200;

    m_isingSpace = new Ising(m_sizeX, m_sizeY, J, temperature);
    m_isingPlot = new PlotIsing(m_sizeX, m_sizeY);
    m_energyPlot = new PlotParam();
    m_magnetizationPlot = new PlotParam();
    m_label1 = new QLabel();

    m_energyPlot->setTitle("Energy");
    m_magnetizationPlot->setTitle("Magnetization");

    QVBoxLayout *layout1 = new QVBoxLayout();
    layout1->addWidget(m_magnetizationPlot);
    layout1->addWidget(m_energyPlot);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_isingPlot, 40);
    layout->addLayout(layout1);

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
        double magTemp {m_isingSpace->getMagnetization()};
        m_energyPlot->plot(static_cast<double>(m_timer.elapsed())*0.001, energyTemp);
        m_magnetizationPlot->plot(static_cast<double>(m_timer.elapsed())*0.001, magTemp);
        m_isingPlot->updatePlot();
        m_isingSpace->updateSpace();
        //m_label1->setText(QString::number(energyTemp));
}

