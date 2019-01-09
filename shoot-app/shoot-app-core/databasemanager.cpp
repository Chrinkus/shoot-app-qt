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
    event_dao{*m_db},
    shooter_dao{*m_db}
{
    m_db->setDatabaseName(path);
    m_db->open();

    event_dao.init();
    shooter_dao.init();
}

DatabaseManager::~DatabaseManager()
{
    m_db->close();
    delete m_db;
}
