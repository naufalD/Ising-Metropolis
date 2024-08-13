#ifndef PLOT_H
#define PLOT_H

#include <QwtPlot>
#include <QwtPlotCurve>

class PlotIsing : public QwtPlot
{
public:
    PlotIsing(int sizeX, int sizeY, QWidget *parent = NULL);
    void plotUp(int x, int y);
    void plotDown(int x, int y);
    void updatePlot();
private:
    QPolygonF m_pointsUp;
    QwtPlotCurve *m_curveUp;
    QPolygonF m_pointsDown;
    QwtPlotCurve *m_curveDown;
};

#endif // PLOT_H
