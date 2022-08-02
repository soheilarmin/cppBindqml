#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

#include "logmodel.h"

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(LogModel *model READ model WRITE setModel NOTIFY modelChanged)
public:
    explicit MyClass(QObject *parent = nullptr);

public slots:
    void start();

    LogModel* model();
    void setModel(LogModel* model);

signals:
    void done();
    void modelChanged();

private:
    LogModel* m_model;
};

#endif // MYCLASS_H
