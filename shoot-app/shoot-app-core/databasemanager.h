#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "event_dao.h"
#include "shooter_dao.h"
#include "match_dao.h"
#include "roster_map_dao.h"

class QSqlDatabase;
class QSqlQuery;

const QString database_filename = "shoot.db";

class DatabaseManager
{
public:
    static void debug_query(const QSqlQuery& query);

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = database_filename);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase* m_db;

public:
    const Event_dao m_event_dao;
    const Shooter_dao m_shooter_dao;
    const Match_dao m_match_dao;
    const Roster_map_dao m_roster_map_dao;
};

#endif // DATABASEMANAGER_H
