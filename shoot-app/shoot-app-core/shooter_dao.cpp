#include "shooter_dao.h"
#include "shooter.h"
#include "databasemanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

Shooter_dao::Shooter_dao(QSqlDatabase& db) :
    m_db{db}
{
}

void Shooter_dao::init() const
{
    if (!m_db.tables().contains("shooters")) {
        QSqlQuery query{m_db};
        query.exec("CREATE TABLE shooters ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "first_name TEXT, "
                   "last_name TEXT)");
        DatabaseManager::debug_query(query);
    }
}

void Shooter_dao::add_shooter(Shooter& shooter) const
{
    QSqlQuery query{m_db};
    query.prepare("INSERT INTO shooters (first_name, last_name) "
                  "VALUES (:first_name, :last_name)");
    query.bindValue(":first_name", shooter.first());
    query.bindValue(":last_name", shooter.last());
    query.exec();
    shooter.id(query.lastInsertId().toInt());
    DatabaseManager::debug_query(query);
}

void Shooter_dao::update_shooter(const Shooter& shooter) const
{
    QSqlQuery query{m_db};
    query.prepare("UPDATE shooters SET first_name = (:first_name) "
                  "last_name = (:last_name) WHERE id = (:id)");
    query.bindValue(":first_name", shooter.first());
    query.bindValue(":last_name", shooter.last());
    query.bindValue(":id", shooter.id());
    query.exec();
    DatabaseManager::debug_query(query);
}

void Shooter_dao::remove_shooter(int id) const
{
    QSqlQuery query{m_db};
    query.prepare("DELETE FROM shooters WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debug_query(query);
}

std::vector<std::unique_ptr<Shooter>> Shooter_dao::shooters() const
{
    std::vector<std::unique_ptr<Shooter>> vp_shooters;
    QSqlQuery query{"SELECT * FROM shooters", m_db};
    query.exec();
    while (query.next()) {
        auto shooter = std::make_unique<Shooter>();
        shooter->id(query.value("id").toInt());
        shooter->first(query.value("first_name").toString());
        shooter->last(query.value("last_name").toString());
        vp_shooters.push_back(std::move(shooter));
    }

    return vp_shooters;
}
