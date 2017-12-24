#include "DatabaseManager.h"

#include <QDebug>

DatabaseManager&DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"))),
    mPlayerDao(*mDatabase)
{
    qDebug() << path;

    QSettings settings(path, QSettings::IniFormat);

    qDebug() << settings.value("DATABASENAME").toString();
    mDatabase->setDatabaseName(settings.value("DATABASENAME").toString());
    mDatabase->setHostName(settings.value("HOSTNAME").toString());
    mDatabase->setUserName(settings.value("USERNAME").toString());
    mDatabase->setPassword(settings.value("PASSWORD").toString());

    bool databaseConnected = mDatabase->open();

    if(databaseConnected)
    {
        qDebug() << "Database connection: Connected";
    }
    else
    {
        qDebug() << "Database connection: Not Connected";
    }

    mPlayerDao.init();
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
}
