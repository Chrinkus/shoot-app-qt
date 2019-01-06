#include "databasemanager.h"

#include <QSqlDatabase>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
    m_db{new QSqlDatabase{QSqlDatabase::addDatabase("QSQLITE")}}
{
    m_db->setDatabaseName(path);
    m_db->open();
}

DatabaseManager::~DatabaseManager()
{
    m_db->close();
    delete m_db;
}
