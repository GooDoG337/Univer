#include "label.h"
#include <QVBoxLayout>
#include <QList>
label::label(QWidget* parent) {
    QString text = R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit.
Aliquam tristique sollicitudin erat et tincidunt.
Donec non ex vestibulum, placerat velit quis, suscipit mauris.
Phasellus ullamcorper tristique turpis, eu commodo purus semper sit amet.
Pellentesque mi quam, lacinia eu elit nec, cursus tincidunt arcu.
Suspendisse aliquet volutpat sem.
Curabitur venenatis est et eros ornare, id placerat mauris semper.
Proin non nulla id arcu aliquet fermentum.
Donec in augue non magna vulputate gravida ac sed urna.
Ut eu ligula iaculis, iaculis nulla quis, rutrum est.
Vestibulum ultrices metus nibh, id ornare orci consequat quis.
Curabitur tincidunt varius lacinia. Donec sed facilisis erat.
Vivamus ut velit at enim auctor vulputate.
Morbi nec tristique quam. )";
    laabel = new QLabel(text,this);
    laabel->setFont(QFont("Purisa", 10));
    auto* vbox = new QVBoxLayout();
    vbox->addWidget(laabel);
    setLayout(vbox);
}
