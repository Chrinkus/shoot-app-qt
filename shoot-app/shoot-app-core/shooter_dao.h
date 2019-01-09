#ifndef SHOOTER_DAO_H
#define SHOOTER_DAO_H

#include <vector>
#include <memory>

class QSqlDatabase;
class Shooter;

class Shooter_dao
{
public:
    explicit Shooter_dao(QSqlDatabase& db);
    void init() const;

    void add_shooter(Shooter& shooter) const;
    void update_shooter(const Shooter& shooter) const;
    void remove_shooter(int id) const;
    std::vector<std::unique_ptr<Shooter>> shooters() const;

private:
    QSqlDatabase& m_db;
};

#endif // SHOOTER_DAO_H
