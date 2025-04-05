#include <QCoreApplication>
#include <QTextStream>
#include <algorithm>
#include "student.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    QList<Student> students = {
        Student("Ivan", "PrikMat"),
        Student("Diego", "Psix"),
        Student("Quake", "Ekonom"),
        Student("Doom", "Xim"),
        Student("Wolfenstein", "Fis"),
        Student("Forza", "Xim"),
        Student("Half-Life", "Ekonom"),
        Student("Portal", "Xim"),
    };
    std::sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) { return s1.getName() < s2.getName();});
    for(Student student: students)
    {
        out << student.getName() << ": " << student.getFaculty() << Qt::endl;
    }
    a.exit();
}
