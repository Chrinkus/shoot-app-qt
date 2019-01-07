#include "event_dao.h"
#include "databasemanager.h"
#include "event.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

Event_dao::Event_dao(QSqlDatabase& db) :
    m_db{db}
{
}

void Event_dao::init() const
{
    if (!m_db.tables().contains("events")) {
        QSqlQuery query{m_db};
        query.exec("CREATE TABLE events ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "scorer TEXT, "
                   "start TEXT)");
    }
}

void Event_dao::add_event(Event& event) const
{
    QSqlQuery query{m_db};
    query.prepare("INSERT INTO events (scorer, start) "
                  "VALUES (:scorer, :start)");
    query.bindValue(":scorer", event.scorer());
    query.bindValue(":start", event.start());
    query.exec();
    event.id(query.lastInsertId().toInt());
}
