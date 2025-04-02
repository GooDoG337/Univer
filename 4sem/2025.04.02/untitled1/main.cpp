#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDate>
#include <QTime>
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
/*  QTextStream out(stdout);
    QString str = "Very long radio?";
    out << str.left(5) << Qt::endl;
    out << str.right(9) << Qt::endl;
    out << str.mid(4,6) << Qt::endl;
    QString str2("Maybe another radio");
    QStringRef sub(&str2, 0, 7);
    out << sub.toString() << Qt::endl;*/

 /* QTextStream out(stdout);
    QString str = "Another long one";
    foreach(QChar qc, str) {
        out << qc << ' ';
    }
    out << Qt::endl;
    for(QChar* it = str.begin(); it != str.end(); ++it)
    {
        out << *it << ' ';
    }
    out << Qt::endl;
    for(int i = 0; i != str.size(); ++i)
    {
        out << str.at(i) << ' ';
    }
    out << Qt::endl;*/

    /*const int STR_EQUAL = 0;
    QTextStream out(stdout);
    QString a = "Make";
    QString b = "MAKE";
    QString c = "MAKE ";
    if(QString::compare(a,b) == STR_EQUAL)
    {
        out << "a,b are the same." << Qt::endl;
    } else {
        out << "a,b are NOT the same." << Qt::endl;
    }
    out << "Something about regrets." << Qt::endl;
    if(QString::compare(a,b, Qt::CaseInsensitive) == STR_EQUAL)
    {
        out << "Case insentive a,b are the same." << Qt::endl;
    } else {
        out << "Case insentive a,b are NOT the same." << Qt::endl;
    }
    if(QString::compare(b,c) == STR_EQUAL)
    {
        out << "b,c are the same." << Qt::endl;
    } else {
        out << "b,c are NOT the same." << Qt::endl;
    }
    c.chop(1);
    out << "After last character " << Qt::endl;
    if(QString::compare(b,c) == STR_EQUAL)
    {
        out << "b,c are the same." << Qt::endl;
    } else {
        out << "b,c are NOT the same." << Qt::endl;
    }*/

    /*QTextStream out(stdout);
    int digits = 0;
    int letters = 0;
    int spaces = 0;
    int puncts = 0;
    QString str("John Wick 5 will be released.");
    foreach(QChar s, str)
    {
        if(s.isDigit())
        {
            digits++;
        } else if(s.isLetter())
        {
            letters++;
        } else if(s.isSpace())
        {
            spaces++;
        } else if(s.isPunct())
        {
            puncts++;
        }
    }
    out << QString("There are %1 characters.").arg(str.size()) << Qt::endl;
    out << QString("There are %1 digits, %2 letters, %3 spaces and %4 punctuation signs.").arg(digits).arg(letters).arg(spaces).arg(puncts) << Qt::endl;*/

    /*QTextStream out(stdout);
    QString s1 = "12";
    QString s2 = "15";
    QString s3, s4;
    out << s1.toInt() + s2.toInt() << Qt::endl;
    int n1 = 30, n2 = 40;
    out << s3.setNum(n1) + s4.setNum(n2) << Qt::endl;*/

    /*QTextStream out(stdout);
    QString name = "Name: ";
    QString occup = "Occupation: ";
    QString address = "Address: ";
    int width = occup.size();
    out << name.rightJustified(width,'_') << "Ivan" << Qt::endl;
    out << occup.rightJustified(width, 'W') << "****post" << Qt::endl;
    out << address.rightJustified(width, 'F') << "Internet" << Qt::endl;
    out << name.leftJustified(width,'_') << "Ivan" << Qt::endl;
    out << occup.leftJustified(width, 'W') << "****post" << Qt::endl;
    out << address.leftJustified(width, 'F') << "Internet" << Qt::endl;*/

    /*QTextStream out(stdout);
    QFile file("example.cpp");
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning("Can't open the file.\n");
        return -1;
    }
    QTextStream in(&file);
    QString allCode = in.readAll();
    out << allCode.toHtmlEscaped() << Qt::endl;
    file.close();*/

    QTextStream out(stdout);
    out.setCodec("UTF-8");
    QDate dt1(2025,4,2);
    out << "Date: " << dt1.toString() << Qt::endl;
    QDate dt2(2025,7,8);
    QTime tm1(17,30,25,123);
    out << "Time is " << tm1.toString("hh:mm:ss.zzz") << Qt::endl;
    QTime tm2;
    tm2.setHMS(13,52,47,777);
    out << "Time is " << tm2.toString("hh:mm:ss.zzz") << Qt::endl;
    app.exit();
}
