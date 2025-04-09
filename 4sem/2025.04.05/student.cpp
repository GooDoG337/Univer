#include "student.h"
Student::Student(QString name, QString faculty): name(name), faculty(faculty) {}
QString Student::getName() const { return name; }
QString Student::getFaculty() const { return faculty; }
