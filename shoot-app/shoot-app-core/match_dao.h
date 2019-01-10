#ifndef MATCH_DAO_H
#define MATCH_DAO_H

#include <vector>
#include <memory>

class QSqlDatabase;
class Match;

class Match_dao
{
public:
    explicit Match_dao(QSqlDatabase& db);

    void init() const;
    void add_match(Match& match) const;
    void update_match(const Match& match) const;
    void remove_match(int id) const;
    std::vector<std::unique_ptr<Match>> matches_from_event(int event_id) const;

private:
    QSqlDatabase& m_db;
};

#endif // MATCH_DAO_H
