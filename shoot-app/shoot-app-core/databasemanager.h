#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

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
};

#endif // DATABASEMANAGER_H
