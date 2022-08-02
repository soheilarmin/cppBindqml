#ifndef LOGMODEL_H
#define LOGMODEL_H

#include <QObject>
#include <QAbstractListModel>

class Log
{
public:
    Log(const QString&type, const QString&message);

    QString type() const;
    QString message() const;

private:
    QString m_type;
    QString m_message;
};

class LogModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum LogsRoles {
        TypeRole = Qt::UserRole + 1,
        MessageRole
    };

    explicit LogModel(QObject *parent = nullptr);

    void addLog(const Log &log);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Log> m_logs;
};

#endif // LOGMODEL_H
