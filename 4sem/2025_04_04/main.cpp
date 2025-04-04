#include <QCoreApplication>
#include <QDate>
#include <QTextStream>
#include <QDateTime>
#include <QVector>
#include <QList>
#include <algorithm>
#include <QStringList>
#include <QSet>
#include <QMap>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    out.setCodec("UTF-8");
/*    QList<QString> months;
    for(int i = 1; i != 13; i++)
    {
        months.append(QDate::longMonthName(i));
    }
    QDate dt1(2025,4,1);
    QDate dt2(2024,2,11);
    QDate dt3(2023,1,7);
    QDate dt4(2022,3,3);
    QDate dt5(2020,7,8);
    out << QString("Days: ") << dt1.daysInMonth() << QString(" in month ") << months.at(dt1.month()-1) << Qt::endl;
    out << QString("Days: ") << dt2.daysInMonth() << QString(" in month ") << months.at(dt2.month()-1) << Qt::endl;
    out << QString("Days: ") << dt3.daysInMonth() << QString(" in month ") << months.at(dt3.month()-1) << Qt::endl;
    out << QString("Days: ") << dt4.daysInMonth() << QString(" in month ") << months.at(dt4.month()-1) << Qt::endl;
    out << QString("Days: ") << dt5.daysInMonth() << QString(" in month ") << months.at(dt5.month()-1) << Qt::endl;*/

    /*QList<QDate> dates( { QDate(2024,2,29), QDate(2023,2,29), QDate(2025,4,31) });
    for(int i = 0; i != dates.size(); ++i)
    {
        if(dates.at(i).isValid()) {
            out << "Date " << i+1 << " is valid." << Qt::endl;
        } else {
            out << "Date " << i+1 << " is not valid." << Qt::endl;
        }
    }*/

    /*QDateTime cdt = QDateTime::currentDateTime();
    out << cdt.toString("dd-MM-yy hh:mm") << Qt::endl;
    out << cdt.date().toString() << Qt::endl;
    out << cdt.time().toString() << Qt::endl;*/

    /*QDate cd = QDate::currentDate();
    out << "Gregorian calendar: " << cd.toString(Qt::ISODate) << Qt::endl;
    out << "Julian calendar: " << cd.toJulianDay() << Qt::endl;*/

    /*QDate dt(2025,6,1);
    QDate nd = dt.addDays(42);
    QDate dt2(2025,6,30);
    out << "42 days from " << dt.toString() << " is " << nd.toString() << Qt::endl;
    out << "There are " << QDate::currentDate().daysTo(dt) << " days";*/

    /*QDate RM2(-1303, 5, 1);
    QDate mgl(1222,7,28);
    int j_today = QDate::currentDate().toJulianDay();
    int j_rm2 = RM2.toJulianDay();
    int j_mgl = mgl.toJulianDay();
    out << "Days since Ramzes 2 " << j_today-j_rm2 << Qt::endl;
    out << "Days since mongols " << j_today-j_mgls << Qt::endl;*/

    /*QDateTime cdt = QDateTime::currentDateTime();
    out << "UTC: " << cdt.toUTC().toString() << Qt::endl;
    out << "Local: " << cdt.toLocalTime().toString() << Qt::endl;*/

    /*time_t tm = time(0);
    out << tm << Qt::endl;
    QDateTime dt;
    dt.setTime_t(tm);
    out << dt.toString() << Qt::endl;
    QDateTime cd = QDateTime::currentDateTime();
    out << cd.toTime_t() << Qt::endl;*/

    /*QVector<int> vals( {1,2,3,4,5} );
    out << vals.size() << Qt::endl;
    out << vals.first() << Qt::endl;
    out << vals.last() << Qt::endl;
    vals.append(6);
    vals.prepend(0);
    for(int val: vals) {
        out << val << ' ';
    }*/

    /*QList<QString> faculties = { "Прик.мат.", "Эконом.", "Физ.фак.", "Хим.фак.", "Филология", "Психология" };
    for(int i = 0; i != faculties.size(); ++i)
    {
        out << faculties.at(i) << Qt::endl;
    }
    faculties << QString("Жур.фак.") << QString("Ист.фак.");
    std::sort(faculties.begin(), faculties.end());
    for (QString faculty: faculties) {
        out << faculty << Qt::endl;
    }*/

    /*QString faculties = { "Прик.мат., Эконом., Физ.фак., Хим.фак., Филология, Психология" };
    QStringList msu = faculties.split(',');
    QStringListIterator it(msu);
    while(it.hasNext()) {
        out << it.next().trimmed() << Qt::endl;
    }*/

    /*QSet<QString> technical = {"Прик.Мат","Физ.Фак.","Хим.Фак"};
    QSet<QString> liberals = {"Эконом","Фил(Спенсер)","Псих"};
    out << technical.size() << Qt::endl;
    liberals.insert("Жур.Фак");
    out << liberals.size() << Qt::endl;
    technical.unite(liberals);
    out << technical.size() << Qt::endl;
    for(QString faculty: technical)
    {
        out << faculty << Qt::endl;
    }
    QList<QString> l_technical = technical.values();
    std::sort(l_technical.begin(), l_technical.end());
    out << "---------------" << Qt::endl;
    for(QString val: l_technical)
    {
        out << val << Qt::endl;
    }*/

    QMap<QString, int> students = {
        {"PrikMat", 59},
        {"Ekonom", 30},
        {"Fiz", 10},
        {"Xim", 10},
        {"Fil", 40},
        {"Psix", 50}
    };
    students.insert("Jur", 0);
    QList<int> values = students.values();
    out << "Values: " << Qt::endl;
    for(int val: values)
    {
        out << val << Qt::endl;
    }
    QList<QString> keys = students.keys();
    out << "Keys: " << Qt::endl;
    for(QString key: keys)
    {
        out << key << Qt::endl;
    }
    QMapIterator<QString, int> it(students);
    out << "Pairs: " << Qt::endl;
    while(it.hasNext()) {
        it.next();
        out << it.key() << ": " << it.value() << Qt::endl;
    }
    a.exit();
}
