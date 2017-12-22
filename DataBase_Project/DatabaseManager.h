#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>
#include <QString>
#include <QSettings>
#include <QSqlDatabase>
#include <QDir>

class QSqlQuerry;
class QSqlDatabase;

const QString DATABASE_CONFIG_FILE_PATH = QDir::currentPath() + "release/confing.conf";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_CONFIG_FILE_PATH);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;
};

#endif // DATABASEMANAGER_H
