#include "include/plot.h"

PlotIsing::PlotIsing( QWidget *parent) : QwtPlot(parent)
{
    setTitle( "Ising" );
    setCanvasBackground( Qt::white );
    setMinimumSize(300,300);

    m_curveUp = new QwtPlotCurve();
    m_curveDown = new QwtPlotCurve();

    m_curveUp->setStyle(QwtPlotCurve::Dots);
    m_curveDown->setStyle(QwtPlotCurve::Dots);


}

void PlotIsing::m_plotUp(int x, int y){
    m_pointsUp<<QPointF(x, y);
}

void PlotIsing::m_plotDown(int x, int y){
    m_pointsDown<<QPointF(x, y);
}

void PlotIsing::m_reset(){
    m_curveUp->setSamples(m_pointsUp);
    m_curveDown->setSamples(m_pointsDown);
    m_pointsUp.clear();
    m_pointsDown.clear();
}
