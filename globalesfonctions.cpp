#include "globalesfonctions.h"

#include "cconfigparser.h"

#include <QString>


QString cfgLecture(QString section, QString option){return cfgLecture(section, option, "SuperVision.cfg");}
QString cfgLecture(QString section, QString option, QString cfgfile)
{
    QString strRetour;
    CConfigParser cfg;
    bool bOK = cfg.open(cfgfile, QIODevice::ReadOnly);
    if (cfgfile.isNull()) cfgfile = "SuperVision.cfg";

    // Sauvegarder le poste sélectionné dans le fichier init.
    if (!bOK) return QString::null;
    cfg.read();
    if (!cfg.has_section(section) || (!cfg.has_option(section, option))) strRetour = QString::null;
    else strRetour = cfg.get(section, option);
    cfg.close();
    return strRetour;
}
bool cfgEcriture(QString section, QString option, QString data){return cfgEcriture(section, option, data, "SuperVision.cfg");}
bool cfgEcriture(QString section, QString option, QString data, QString cfgfile)
{
    CConfigParser cfg;
    bool bOK(true);

    if (cfgfile.isNull()) cfgfile = "SuperVision.cfg";
    if (true) {//(cfgLecture(section, option) != data){
        bOK = cfg.open(cfgfile, QIODevice::ReadOnly, true);

        // Sauvegarder le poste sélectionné dans le fichier init.
        if (bOK){
            cfg.read();
            cfg.close();
            cfg.open(cfgfile, QIODevice::WriteOnly, false, false);
            if (!cfg.has_section(section)) cfg.add_section(section);
            if (!cfg.has_option(section, option)) cfg.add_option(section, option);
            cfg.set(section, option, data);
            cfg.write();
            cfg.close();
        }
    }
    return bOK;
}

QString Capitalize(QString s)
{
    QString strRet = s.at(0).toUpper()+s.mid(1,-1);
    return strRet;
}

QString CharInterdits(QString s)
{
    s.replace(QRegExp("[éèëê]"), "e");
    s.replace(QRegExp("[àäâ]"), "a");
    s.replace(QRegExp("[ùüû]"), "u");
    s.replace(QRegExp("[ïî]"), "i");
    s.replace(QRegExp("[öô]"), "o");
    s.replace(QRegExp("[ç]"), "c");
    s.replace(QRegExp("["), "_");
    s.replace(QRegExp("]"), "_");
    s.replace(QRegExp("[' (&-)=+*-.,;!:?]"), "_");
    return s;
}

