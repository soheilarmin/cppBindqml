#include "myclass.h"
#include "QDebug"

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{
    m_model->addLog(Log("trace", "Q_FUNC_INFO"));

    model()->addLog(Log("warning", Q_FUNC_INFO));
}

void MyClass::start()
{
    qInfo() << Q_FUNC_INFO;

    emit done();
}

LogModel *MyClass::model()
{
    return m_model;
}

void MyClass::setModel(LogModel *model)
{
    m_model = model;

    emit modelChanged();
}
