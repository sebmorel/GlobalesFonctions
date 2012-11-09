#ifndef GLOBALESFONCTIONS_H
#define GLOBALESFONCTIONS_H

#include "GlobalesFonctions_global.h"
#include <QString>
class QString;

typedef unsigned long long UINT64;

QString GLOBALESFONCTIONSSHARED_EXPORT cfgLecture(QString section, QString option, QString cfgfile);
bool GLOBALESFONCTIONSSHARED_EXPORT cfgEcriture(QString section, QString option, QString data, QString cfgfile);
QString GLOBALESFONCTIONSSHARED_EXPORT cfgLecture(QString section, QString option);
bool GLOBALESFONCTIONSSHARED_EXPORT cfgEcriture(QString section, QString option, QString data);

QString GLOBALESFONCTIONSSHARED_EXPORT Capitalize(QString s);
QString GLOBALESFONCTIONSSHARED_EXPORT CharInterdits(QString s);


#endif // GLOBALESFONCTIONS_H
