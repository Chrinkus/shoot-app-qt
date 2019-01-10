#include "match_dao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "databasemanager.h"
#include "match.h"

Match_dao::Match_dao(QSqlDatabase& db) :
    m_db{db}
{
}

void Match_dao::init() const
{
    if (!m_db.tables().contains("matches")) {
        QSqlQuery query{m_db};
        query.exec("CREATE TABLE matches ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "score REAL, "
                   "shooter_id INTEGER, "
                   "event_id INTEGER, "
                   "aggregate_id INTEGER, "
                   "match_number INTEGER)");
        DatabaseManager::debug_query(query);
    }
}

void Match_dao::add_match(Match& match) const
{
    QSqlQuery query{m_db};
    query.prepare("INSERT INTO matches (score, shooter_id, event_id, "
                  "aggregate_id, match_number) "
                  "VALUES (:score, :shooter_id, :event_id, :aggregate_id, "
                  ":match_number)");
    query.bindValue(":score", match.score());
    query.bindValue(":shooter_id", match.shooter_id());
    query.bindValue(":event_id", match.event_id());
    query.bindValue(":aggregate_id", match.aggregate_id());
    query.bindValue(":match_number", match.match_number());
    query.exec();
    match.id(query.lastInsertId().toInt());
    DatabaseManager::debug_query(query);
}

void Match_dao::update_match(const Match& match) const
{
    QSqlQuery query{m_db};
    query.prepare("UPDATE matches SET score = (:score), "
                  "shooter_id = (:shooter_id), event_id = (:event_id), "
                  "aggregate_id = (:aggregate_id), "
                  "match_number = (:match_number) "
                  "WHERE id = (:id)");
    query.bindValue(":score", match.score());
    query.bindValue(":shooter_id", match.shooter_id());
    query.bindValue(":event_id", match.event_id());
    query.bindValue(":aggregate_id", match.aggregate_id());
    query.bindValue(":match_number", match.match_number());
    query.bindValue(":id", match.id());
    query.exec();
    DatabaseManager::debug_query(query);
}

void Match_dao::remove_match(int id) const
{
    QSqlQuery query{m_db};
    query.prepare("DELETE FROM matches WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debug_query(query);
}

std::vector<std::unique_ptr<Match>> Match_dao::matches_from_event(int event_id)
        const
{
    std::vector<std::unique_ptr<Match>> vp_matches;

    QSqlQuery query{m_db};
    query.prepare("SELECT * FROM matches WHERE event_id = (:event_id)");
    query.bindValue(":event_id", event_id);
    query.exec();
    DatabaseManager::debug_query(query);

    while (query.next()) {
        auto pmatch = std::make_unique<Match>();
        pmatch->id(query.value("id").toInt());
        pmatch->score(query.value("score").toDouble());
        pmatch->shooter_id(query.value("shooter_id").toInt());
        pmatch->event_id(query.value("event_id").toInt());
        pmatch->aggregate_id(query.value("aggregate_id").toInt());
        pmatch->match_number(query.value("match_number").toInt());
        vp_matches.push_back(std::move(pmatch));
    }

    return vp_matches;
}
