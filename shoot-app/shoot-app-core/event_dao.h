#ifndef EVENT_DAO_H
#define EVENT_DAO_H

#include <vector>
#include <memory>

class QSqlDatabase;
class Event;

class Event_dao
{
public:
    explicit Event_dao(QSqlDatabase& db);
    void init() const;

    void add_event(Event& event) const;
    void update_event(const Event& event) const;
    void remove_event(int id) const;
    std::vector<std::unique_ptr<Event>> events() const;

private:
    QSqlDatabase& m_db;
};

#endif // EVENT_DAO_H
