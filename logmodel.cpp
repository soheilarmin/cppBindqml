#include "logmodel.h"

Log::Log(const QString &type, const QString &message) : m_type(type), m_message(message) { }

QString Log::type() const
{
    return m_type;
}

QString Log::message() const
{
    return m_message;
}

LogModel::LogModel(QObject *parent) : QAbstractListModel{ parent } { }

void LogModel::addLog(const Log &log)
{
    qInfo() << Q_FUNC_INFO;
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_logs << log;
    endInsertRows();
}

int LogModel::rowCount(const QModelIndex &parent) const
{
    qInfo() << Q_FUNC_INFO;
    Q_UNUSED(parent);
    return m_logs.count();
}

QVariant LogModel::data(const QModelIndex &index, int role) const
{
    qInfo() << Q_FUNC_INFO;
    if (index.row() < 0 || index.row() >= m_logs.count()) {
        return QVariant();
    }

    const Log &log = m_logs[index.row()];
    if (role == TypeRole)
        return log.type();
    else if (role == MessageRole)
        return log.message();
    return QVariant();
}

QHash<int, QByteArray> LogModel::roleNames() const
{
    static QHash<int, QByteArray> roles = { { TypeRole, "type" }, { MessageRole, "message" } };
    return roles;
}
