#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "event_dao.h"

class QSqlDatabase;

const QString database_filename = "shoot.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = database_filename);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase* m_db;

public:
    const Event_dao event_dao;
};

#endif // DATABASEMANAGER_H
