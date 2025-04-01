#include <QCoreApplication>
//#include <iostream>

#include <QTextStream>
int main(int argc, char *argv[])
{/*
//    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    QString a = "тест";
    a.append(" великого могучего.");
    a.prepend("Это ");
    out << a << Qt::endl;
    out << "The string has: " << a.count() << " symbols." << Qt::endl;
    out << a.toUpper() << endl;
    out << a.toLower() << endl;
    //std::cout << "Hello World? QT Version: " << qVersion() << '\n';
    //return a.exec();
    return 0;
*/
/*    QTextStream out(stdout);
    QString str1 = "Идеи кончились.";
    out << str1 << Qt::endl;

    QString str2("Допустим, что тут другой текст.");
    out << str2 << Qt::endl;

    std::string stdr1 = "Тут ещё какой-то текст?";
    QString str3 = stdr1.c_str();
    out << str3 << Qt::endl;

    std::string stdr2 = "WE DO NOT USE RUSSIAN HERE!!!";
    QString str4 = QString::fromLatin1(stdr2.data(), stdr2.size());
    out << str4 << Qt::endl;

    char s3[] = "Я слишком стар для новых текстов.";
    QString str5(s3);
    out << str5 << Qt::endl;
*/
/*    QTextStream out(stdout);
    QString s1 = "New ideas";
    QString s2 = "New ideas\n";
    QString s3 = "New ideas ";
    QString s4 = "Новые идеи";
    out << s1.length() << ' ' << s1.count() << ' ' << s1.size() << Qt::endl;
    out << s2.length() << ' ' << s2.count() << ' ' << s2.size() << Qt::endl;
    out << s3.length() << ' ' << s3.count() << ' ' << s3.size() << Qt::endl;
    out << s4.length() << ' ' << s4.count() << ' ' << s4.size() << Qt::endl;
*/
QTextStream out(stdout);
QString s1 = "OK, %1 white roses are not so zaeshenniy meme";
int n = 12;
out << s1.arg(n) << Qt::endl;
QString s2 = "There will be %1 nixpkgs";
double num = 777;
out << s2.arg(num) << Qt::endl;
QString s3 = "Well, nums are: %1 and %2";
QString str("NOT NUM");
QString str2("WHERE NUM?");
out << s3.arg(str).arg(str2) << Qt::endl;
    return 0;
}
