#include <QCoreApplication>
#include <QTextStream>
#include <QTime>
#include <QDate>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    out.setCodec("UTF-8");
    /*QDate dt1(2025,4,11);
    QDate dt2(2025,4,1);
    if(dt1 < dt2)
    {
        out << dt1.toString() << " comes before " << dt2.toString() << Qt::endl;
    } else {
        out << dt2.toString() << " comes before " << dt1.toString() << Qt::endl;
    }*/

    /*QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    out << cd.toString() << Qt::endl << ct.toString() << Qt::endl;*/

    /*QList<int> years({2020,2021,2022,2023,2024});
    foreach(int year, years)
    {
        if(QDate::isLeapYear(year)){
            out << year << " is високосный year.";
        } else {
            out << year << " is not високосный year.";
        }
        out << Qt::endl;
    }*/

    /*QDate cd = QDate::currentDate();
    out << cd.toString(Qt::TextDate) << Qt::endl;
    out << cd.toString(Qt::ISODate) << Qt::endl;
    out << cd.toString(Qt::SystemLocaleShortDate) << Qt::endl;
    out << cd.toString(Qt::SystemLocaleLongDate) << Qt::endl;
    out << cd.toString(Qt::DefaultLocaleShortDate) << Qt::endl;
    out << cd.toString(Qt::DefaultLocaleLongDate) << Qt::endl;
    out << cd.toString(Qt::SystemLocaleDate) << Qt::endl;
    out << cd.toString(Qt::LocaleDate) << Qt::endl;
    out << cd.toString("d.dd.ddd.dddd M.MM.MMM_MMMM yy-yyyy") << Qt::endl;*/
/* d-dddd, M-MMMM, yy,yyyy*/

    /*QDate cd = QDate::currentDate();
    out << cd.toString("yyyy-MM.dd") << Qt::endl;
    out << cd.toString("yy/M/dd") << Qt::endl;
    out << cd.toString("d.M.yyyy") << Qt::endl;
    out << cd.toString("d-MMMM-yyyy") << Qt::endl;*/

    /*QTime ct = QTime::currentTime();
    out << ct.toString(Qt::TextDate) << Qt::endl;
    out << ct.toString(Qt::ISODate) << Qt::endl;
    out << ct.toString(Qt::SystemLocaleShortDate) << Qt::endl;
    out << ct.toString(Qt::SystemLocaleLongDate) << Qt::endl;
    out << ct.toString(Qt::DefaultLocaleShortDate) << Qt::endl;
    out << ct.toString(Qt::DefaultLocaleLongDate) << Qt::endl;
    out << ct.toString(Qt::SystemLocaleDate) << Qt::endl;
    out << ct.toString(Qt::LocaleDate) << Qt::endl;*/

   /* out << ct.toString("hh:mm:ss.zzz") << Qt::endl;
    out << QLocale("Russian").toString(ct, "h:m:s a") << Qt::endl;
    out << QLocale("Russian").toString(ct, "H:m:s A") << Qt::endl;
    out << QLocale("Russian").toString(ct, "h:m AP") << Qt::endl;*/

    //h,hh,H,HH, m,mm, s,ss,z, zzz |AP,A|, |ap, a|, t

    QDate cd = QDate::currentDate();
    int nd = cd.dayOfWeek();
    QLocale loc;
    out << QDate::shortDayName(nd) << Qt::endl;
    out << QDate::longDayName(nd) << Qt::endl;
    a.exit();

}
