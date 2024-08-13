#ifndef PLOT_H
#define PLOT_H

#include <QwtPlot>
#include <QwtPlotCurve>

class Plot : public QwtPlot
{
public:
    Plot(QWidget *parent = NULL);
private:
    QPolygonF m_pointsUp;
    QwtPlotCurve *m_scatterUp;
    QPolygonF m_pointsDown;
    QwtPlotCurve *m_scatterDown;
};

#endif // PLOT_H
