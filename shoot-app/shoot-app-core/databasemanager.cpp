#include "databasemanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void DatabaseManager::debug_query(const QSqlQuery& query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK: " << query.lastQuery();
    } else {
        qWarning() << "Query Error: " << query.lastError().text();
        qWarning() << "Query Text: " << query.lastQuery();
    }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
    m_db{new QSqlDatabase{QSqlDatabase::addDatabase("QSQLITE")}},
    m_event_dao{*m_db},
    m_shooter_dao{*m_db},
    m_match_dao{*m_db},
    m_roster_map_dao{*m_db}
{
    m_db->setDatabaseName(path);
    m_db->open();

    m_event_dao.init();
    m_shooter_dao.init();
    m_match_dao.init();
    m_roster_map_dao.init();
}

DatabaseManager::~DatabaseManager()
{
    m_db->close();
    delete m_db;
}
