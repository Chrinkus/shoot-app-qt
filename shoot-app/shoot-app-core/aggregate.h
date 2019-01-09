#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "shoot-app-core_global.h"

#include <QString>

class SHOOTAPPCORESHARED_EXPORT Aggregate
{
public:
    explicit Aggregate(const QString& aggregate);

    int id() const { return m_id; }
    void id(int id) { m_id = id; }

    QString aggregate() const { return m_aggregate; }
    void aggregate(const QString& agg) { m_aggregate = agg; }
private:
    int m_id;
    QString m_aggregate;
};

#endif // AGGREGATE_H
