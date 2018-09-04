#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QVector>
#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    void checkBoxGeneration(int n, QVector<int> list);
public slots:

};

#endif // MAINWIDGET_H
