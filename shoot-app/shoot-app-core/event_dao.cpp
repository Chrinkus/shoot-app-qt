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
        DatabaseManager::debug_query(query);
    }
}

void Event_dao::add_event(Event& event) const
{
    QSqlQuery query{m_db};
    query.prepare("INSERT INTO events (scorer, start) "
                  "VALUES (:scorer, :start)");
    query.bindValue(":scorer", event.scorer());
    query.bindValue(":start", event.start_str());
    query.exec();
    event.id(query.lastInsertId().toInt());
    DatabaseManager::debug_query(query);
}

void Event_dao::update_event(const Event& event) const
{
    QSqlQuery query{m_db};
    query.prepare("UPDATE events SET scorer = (:scorer), start = (:start) "
                  "WHERE id = (:id)");
    query.bindValue(":scorer", event.scorer());
    query.bindValue(":start", event.start_str());
    query.bindValue(":id", event.id());
    query.exec();
    DatabaseManager::debug_query(query);
}

void Event_dao::remove_event(int id) const
{
    QSqlQuery query{m_db};
    query.prepare("DELETE FROM events WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debug_query(query);
}

std::vector<std::unique_ptr<Event>> Event_dao::events() const
{
    std::vector<std::unique_ptr<Event>> vp_events;

    QSqlQuery query{"SELECT * FROM events", m_db};
    query.exec();
    while (query.next()) {
        auto event = std::make_unique<Event>();
        event->id(query.value("id").toInt());
        event->scorer(query.value("scorer").toString());
        event->start_str(query.value("start").toString());
        vp_events.push_back(std::move(event));
    }

    return vp_events;
}
