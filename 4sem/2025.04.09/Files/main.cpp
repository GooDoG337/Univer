#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>
#include <QFile>
int main(int argc, char *argv[])
{
    /*QTextStream out(stdout);
    QString filename = "text.txt";
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out << QString("шо?") << Qt::endl;
    } else {
        qWarning("Cannot open file.");
    }
    file.close();*/

    /*if(argc != 3) {
        qWarning("Not all arguments are provided.");
        return -1;
    }
    QString source = argv[1];
    if(!QFile(source).exists()) {
        qWarning("File do not exist");
        return -2;
    }
    QString destin(argv[2]);
    QFile::copy(source, destin);*/

    /*QTextStream out(stdout);
    out.setCodec("UTF-8");
    if(argc != 2) {
        qWarning("Not all arguments are provided.");
        return -1;
    }
    QString filename = argv[1];
    QFileInfo fileinfo(filename);
    QString group = fileinfo.group();
    QString owner = fileinfo.owner();
    QDateTime last_read = fileinfo.lastRead();
    QDateTime last_mod = fileinfo.lastModified();
    out << "Group: " << group << Qt::endl;
    out << "Owner: " << owner << Qt::endl;
    out << "Last read: " << last_read.toString() << Qt::endl;
    out << "Last modified: " << last_mod.toString() << Qt::endl;*/

    /*QTextStream out(stdout);
    out.setCodec("UTF-8");
    QDir dir;
    if(dir.mkdir("msubaku")) {
        out << "Folder created." << Qt::endl;
    }
    dir.mkdir("Well");
    if(dir.exists("Well"))
    {
        dir.rename("Well", "Another");
    }
    dir.mkpath("msu/baku/maths");*/

    /*QTextStream out(stdout);
    out.setCodec("UTF-8");
    out << "Current path: " << QDir::currentPath() << Qt::endl;
    out << "Home path: " << QDir::homePath() << Qt::endl;
    out << "Temporary path: " << QDir::tempPath() << Qt::endl;
    out << "Root path: " << QDir::rootPath() << Qt::endl;*/

    /*QTextStream out(stdout);
    out.setCodec("UTF-8");
    if(argc != 2) {
        qWarning("No file provided.");
        return -1;
    }
    QString filename = argv[1];
    QFile::Permissions ps = QFile::permissions(filename);
    QString fper;
    if(ps & QFile::ReadOwner)
    {
        fper.append('r');
    } else {
        fper.append('-');
    }
    if(ps & QFile::WriteOwner)
    {
        fper.append('w');
    } else {
        fper.append('-');
    }
    if(ps & QFile::ExeOwner)
    {
        fper.append('x');
    } else {
        fper.append('-');
    }
    if(ps & QFile::ReadGroup)
    {
        fper.append('r');
    } else {
        fper.append('-');
    }
    if(ps & QFile::WriteGroup)
    {
        fper.append('w');
    } else {
        fper.append('-');
    }
    if(ps & QFile::ExeGroup)
    {
        fper.append('x');
    } else {
        fper.append('-');
    }
    if(ps & QFile::ReadOther)
    {
        fper.append('r');
    } else {
        fper.append('-');
    }
    if(ps & QFile::WriteOther)
    {
        fper.append('w');
    } else {
        fper.append('-');
    }
    if(ps & QFile::ExeOther)
    {
        fper.append('x');
    } else {
        fper.append('-');
    }
    QFileInfo fileinfo(filename);
    QString absPath = fileinfo.absoluteFilePath();
    QString baseName = fileinfo.baseName();
    QString compBasePath = fileinfo.completeBaseName();
    QString fileName = fileinfo.fileName();
    QString suffix = fileinfo.suffix();
    QString compSuffix = fileinfo.completeSuffix();
    out << "absPath = " << absPath << Qt::endl;
    out << "baseName = " << baseName << Qt::endl;
    out << "compBasePath = " << compBasePath << Qt::endl;
    out << "fileName = " << fileName << Qt::endl;
    out << "suffix = " << suffix << Qt::endl;
    out << "compSuffix = " << compSuffix << Qt::endl;
    out << "fper: " << fper << Qt::endl;*/

    QTextStream out(stdout);
    out.setCodec("UTF-8");
    if(argc != 2) {
        qWarning("No dir provided");
        return -1;
    }
    QString directory = argv[1];
    QDir dir(directory);
    if(!dir.exists())
    {
        qWarning("Directory does not exist");
        return -2;
    }
    dir.setFilter(QDir::Files|QDir::AllDirs);
    dir.setSorting(QDir::Size|QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();
    int max_size = 0;
    foreach(QFileInfo finfo, list) {
        QString name = finfo.fileName();
        int size = name.size();
        if(size > max_size)
        {
            max_size = size;
        }
    }
    int len = max_size+2;
    out << QString("Filename").leftJustified(len).append(" bytes.") << Qt::endl;
    for(int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        QString str = fileInfo.fileName().leftJustified(len);
        str.append(QString("%1").arg(fileInfo.size()));
        out << str << Qt::endl;
    }
    return 0;
}
