#include "myclass.h"
#include "QDebug"
#include <QDateTime>

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{
    m_model = new LogModel(this);
    m_model->addLog(Log("trace", "Q_FUNC_INFO"));
    logModel()->addLog(Log("warning", Q_FUNC_INFO));
}

void MyClass::start()
{
    qInfo() << Q_FUNC_INFO;

    emit done();
}

LogModel *MyClass::logModel()
{
    return m_model;
}

void MyClass::addLogSample()
{
    m_model->addLog(Log("timer",QDateTime::currentDateTime().toString()));
}
