#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QHash>
#include <QFile>
#include <QDebug>
#include <QUrl>
//#include <QFileDialog>

class Translator : public QObject
{
    Q_OBJECT

    QHash<QString, QString> thash;

public:
    explicit Translator(QObject *parent = nullptr);

    Q_INVOKABLE QString translate(QString text);
    Q_INVOKABLE QString openFile(QUrl path);
    Q_INVOKABLE void saveFile(QUrl path, QString text);
signals:
    //void openFile();

public slots:
};

#endif // TRANSLATOR_H
