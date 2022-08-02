#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

#include "logmodel.h"

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* model READ logModel CONSTANT)
public:
    explicit MyClass(QObject *parent = nullptr);

public slots:
    void start();
    LogModel* logModel();
    void addLogSample();

signals:
    void done();

private:
    LogModel* m_model;
};

#endif // MYCLASS_H
