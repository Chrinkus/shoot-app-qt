#include "roster_map_dao.h"
#include "roster_map.h"
#include "databasemanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

Roster_map_dao::Roster_map_dao(QSqlDatabase& db) :
    m_db{db}
{
}

void Roster_map_dao::init() const
{
    if (!m_db.tables().contains("roster_map")) {
        QSqlQuery query{m_db};
        query.exec("CREATE TABLE roster_map ("
                   "event_id INTEGER, shooter_id INTEGER)");
        DatabaseManager::debug_query(query);
    }
}

void Roster_map_dao::add_roster_map(Roster_map& r_map) const
{
    QSqlQuery query{m_db};
    query.prepare("INSERT INTO roster_map (event_id, shooter_id) "
                  "VALUES (:event_id, :shooter_id)");
    query.bindValue(":event_id", r_map.event_id());
    query.bindValue(":shooter_id", r_map.shooter_id());
    query.exec();
    DatabaseManager::debug_query(query);
}

void Roster_map_dao::remove_roster_map(int event_id, int shooter_id) const
{
    QSqlQuery query{m_db};
    query.prepare("DELETE FROM roster_map WHERE event_id = (:event_id) "
                  "AND shooter_id = (:shooter_id)");
    query.bindValue(":event_id", event_id);
    query.bindValue(":shooter_id", shooter_id);
    query.exec();
    DatabaseManager::debug_query(query);
}

std::vector<int> Roster_map_dao::roster_for_event(int event_id) const
{
    std::vector<int> v_shooter_ids;

    QSqlQuery query{m_db};
    query.prepare("SELECT * FROM roster_map WHERE event_id = (:event_id)");
    query.bindValue(":event_id", event_id);
    query.exec();
    DatabaseManager::debug_query(query);

    while (query.next()) {
        v_shooter_ids.push_back(query.value("shooter_id").toInt());
    }

    return v_shooter_ids;
}
