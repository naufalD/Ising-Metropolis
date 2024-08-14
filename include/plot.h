#ifndef PLOT_H
#define PLOT_H

#include <QwtPlot>
#include <QwtPlotCurve>

class PlotIsing : public QwtPlot
{
public:
    PlotIsing(int sizeX, int sizeY, QWidget *parent = nullptr);
    void plotUp(int x, int y);
    void plotDown(int x, int y);
    void updatePlot();
private:
    QPolygonF m_pointsUp;
    QwtPlotCurve *m_curveUp;
    QPolygonF m_pointsDown;
    QwtPlotCurve *m_curveDown;
};

class PlotEnergy : public QwtPlot
{
public:
    PlotEnergy(QWidget *parent = nullptr);
    void plot(int x, double y);

private:
    QPolygonF m_points;
    QwtPlotCurve *m_curve;
};

#endif // PLOT_H
