#include "review.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
review::review(QWidget* parent):QWidget(parent) {
    auto* grid = new QGridLayout(this);
    grid->setVerticalSpacing(15);
    grid->setHorizontalSpacing(10);
    auto* title = new QLabel("Subject:", this);
    grid->addWidget(title,0,0,1,1);
    title->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    auto* edt1 = new QLineEdit(this);
    grid->addWidget(edt1, 0,1,1,1);
    auto* name = new QLabel("Student:", this);
    grid->addWidget(name,1,0,1,1);
    name->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    auto* edt2 = new QLineEdit(this);
    grid->addWidget(edt2,1,1,1,1);
    auto* review = new QLabel("Mark:", this);
    grid->addWidget(review, 2,0,1,1);
    review->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    auto* te = new QTextEdit(this);
    grid->addWidget(te, 2,1,3,1);
    setLayout(grid);

}
