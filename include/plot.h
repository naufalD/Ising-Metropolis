#ifndef PLOT_H
#define PLOT_H

#include <QwtPlot>
#include <QwtPlotCurve>

class Plot : public QwtPlot
{
public:
    Plot(QWidget *parent = NULL);
private:
    void m_plotUp();
    void m_plotDown();

    QPolygonF m_pointsUp;
    QwtPlotCurve *m_curveUp;
    QPolygonF m_pointsDown;
    QwtPlotCurve *m_curveDown;
};

#endif // PLOT_H
