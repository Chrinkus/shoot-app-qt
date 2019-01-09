#include "aggregate_dao.h"
#include "aggregate.h"
#include "databasemanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

Aggregate_dao::Aggregate_dao(QSqlDatabase& db) :
    m_db{db}
{
}

void Aggregate_dao::init() const
{
    if (!m_db.tables().contains("aggregates")) {
        QSqlQuery query{m_db};
        query.exec("CREATE TABLE aggregates ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "aggregate TEXT)");
        DatabaseManager::debug_query(query);
    }
}

void Aggregate_dao::add_aggregate(Aggregate& agg) const
{
    QSqlQuery query{m_db};
    query.prepare("INSERT INTO aggregates (aggregate) VALUES (:aggregate)");
    query.bindValue(":aggregate", agg.aggregate());
    query.exec();
    agg.id(query.lastInsertId().toInt());
    DatabaseManager::debug_query(query);
}
