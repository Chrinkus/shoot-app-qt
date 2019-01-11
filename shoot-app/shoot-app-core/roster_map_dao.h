#ifndef ROSTER_MAP_DAO_H
#define ROSTER_MAP_DAO_H

#include <vector>
#include <memory>

class QSqlDatabase;
class Roster_map;

class Roster_map_dao
{
public:
    explicit Roster_map_dao(QSqlDatabase& db);

    void init() const;

    void add_roster_map(Roster_map& r_map) const;
    void remove_roster_map(int event_id, int shooter_id) const;

    std::vector<int> roster_for_event(int event_id) const;
private:
    QSqlDatabase& m_db;
};

#endif // ROSTER_MAP_DAO_H
