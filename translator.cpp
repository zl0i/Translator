#include "translator.h"

Translator::Translator(QObject *parent) : QObject(parent)
{
    thash["a"] = ".-";
    thash["b"] = "-...";
    thash["c"] = "-.-.";
    thash["d"] = "-..";
    thash["e"] = ".";
    thash["f"] = "..-.";
    thash["g"] = "--.";
    thash["h"] = "....";
    thash["i"] = "..";
    thash["j"] = ".---";
    thash["k"] = "-.--";
    thash["l"] = ".-..";
    thash["m"] = "--";
    thash["n"] = "-.";
    thash["o"] = "---";
    thash["p"] = ".--.";
    thash["q"] = "--.-";
    thash["r"] = ".-.";
    thash["s"] = "...";
    thash["t"] = "-";
    thash["u"] = "..-";
    thash["v"] = "...-";
    thash["w"] = ".--";
    thash["x"] = "-..-";
    thash["y"] = "-.--";
    thash["z"] = "--..";
    thash[" "] = " ";
    thash[","] = ".-.-.-";
    thash["."] = "......";
    thash["!"] = "--..--";
    thash["?"] = "..--..";
}

QString Translator::translate(QString text) {
    QString translated;
    QRegExp exp("[A-z]");
    if(exp.indexIn(text) >= 0) { //латинские буквы
        text = text.toLower();
        for(int i = 0; i < text.length(); i++) {
            QString str = thash.value(text.at(i));
            translated.append(str + " ");
        }
    }
    else { //азбука Морзе
        QStringList words = text.split(" ");
        for(int i = 0; i < words.length(); i++) {
            QString str = thash.key(words.at(i));
            if(str == "") str = " ";
            translated.append(str);
        }
    }
    return translated;
}

QString Translator::openFile(QUrl path) {
    QFile file(path.path().remove(0, 1));
    if(file.open(QIODevice::ReadOnly)) {
        QString str = file.readAll();
        file.close();
        return str;
    }
    return "";
}

void Translator::saveFile(QUrl path, QString text) {
    QFile file(path.path().remove(0, 1));
    if(file.open(QIODevice::WriteOnly)) {
        file.write(text.toLocal8Bit());
        file.close();
    }
}
