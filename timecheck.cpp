#include "timecheck.h"


TimeCheck::TimeCheck()
{

}

void TimeCheck::AddToProgress(bool value, int id_Habit)
{
    if(value)
    {
        QSqlQuery query;
        QSqlRecord rec;
        QString str_t;
        int P;
        str_t = "SELECT progression "
                "FROM User_Habits"
                    " WHERE id_habit = ";
        str_t.append(QString::number(id_Habit));
        str_t.append(";");
        query.exec(str_t);
        query.next();
        P = query.value(0).toInt();
        P++;
        str_t               =   "UPDATE User_Habits SET progression = ";
        str_t.append(QString::number(P));
        str_t.append(" WHERE ");
        str_t.append("id_habit = ");
        str_t.append(QString::number(id_Habit));
        query.exec(str_t);
    }
}


void TimeCheck::DateChecker(int id_Habit, bool value)
{
    QDateTime dcurrDateTime, checkTime;
    QDateTime currDateTime;
    currDateTime = dcurrDateTime.currentDateTime();
    QSqlQuery query;
    QSqlRecord rec;
    QString str_t;

    str_t = "SELECT check_time "
            "FROM User_Habits"
                " WHERE id_habit = ";
    str_t.append(QString::number(id_Habit));
    str_t.append(";");
    query.exec(str_t);
    query.next();
    checkTime = query.value(0).toDateTime();
    if(currDateTime.toSecsSinceEpoch() - checkTime.toSecsSinceEpoch() > 86400)
    {
        AddToProgress(value, id_Habit);
    }

}
