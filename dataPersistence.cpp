#include <Qfile>
#include <QDataStream>
#include <QString>
#include <QMap>

class DataPersistence{

public:
    static QMap<QString,QString> loadNotes(){
        QMap<QString,QString> notes;

        QFile file("notes.dat");
        if(file.open(QIODevice::ReadOnly)){

            QDataStream in(&file);
            in>>notes;
            file.close();
        }
        return notes;
    }

    static void saveNotes(const QMap<QString,QString> &notes){

        QFile file("notes.dat");
        if(file.open(QIODevice::WriteOnly)){

            QDataStream out(&file);
            out<<notes;
            file.close();
        }
    }
};