#ifndef AGGREGATE_DAO_H
#define AGGREGATE_DAO_H

class QSqlDatabase;
class Aggregate;

class Aggregate_dao
{
public:
    explicit Aggregate_dao(QSqlDatabase& db);

    void init() const;

    void add_aggregate(Aggregate& agg) const;

private:
    QSqlDatabase& m_db;
};

#endif // AGGREGATE_DAO_H
