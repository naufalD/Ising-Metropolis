#include "include/plot.h"

#include <QwtPlotGrid>

PlotIsing::PlotIsing(int sizeX, int sizeY, QWidget *parent) : QwtPlot(parent)
{
    setTitle( "Ising" );
    setCanvasBackground( Qt::black );
    setMinimumSize(300,300);
    setAxisScale( QwtAxis::YLeft, -1, sizeY );
    setAxisScale( QwtAxis::XBottom, -1, sizeX );

    m_curveUp = new QwtPlotCurve();
    m_curveUp->setPen(Qt::red, 2);
    m_curveUp->setStyle(QwtPlotCurve::Dots);
    m_curveUp->attach(this);

    m_curveDown = new QwtPlotCurve();
    m_curveDown->setPen(Qt::blue, 2);
    m_curveDown->setStyle(QwtPlotCurve::Dots);
    m_curveDown->attach(this);


}

void PlotIsing::plotUp(int x, int y){
    m_pointsUp<<QPointF(x, y);

}

void PlotIsing::plotDown(int x, int y){
    m_pointsDown<<QPointF(x, y);

}

void PlotIsing::updatePlot(){
    m_curveUp->setSamples(m_pointsUp);
    m_curveDown->setSamples(m_pointsDown);
    replot();
    m_pointsUp.clear();
    m_pointsDown.clear();
}


PlotEnergy::PlotEnergy(QWidget *parent) : QwtPlot(parent)
{
    setTitle( "Energy" );
    setCanvasBackground( Qt::white );
    setMinimumSize(300,300);
    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->attach( this );

    m_curve = new QwtPlotCurve();
    m_curve->setPen(Qt::red, 1);
    //m_curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
    m_curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    m_curve->attach(this);
}
void PlotEnergy::plot(int x, double y){
    m_points<<QPointF(x, y);
    m_curve->setSamples(m_points);
    replot();
}
