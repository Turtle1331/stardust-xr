#include "launcher.h"

Launcher::Launcher(QObject *parent) :
    QObject(parent),
    m_process(new QProcess(this))
{

}

QString Launcher::launch(const QString &program)
{
    m_process->start(program);
    m_process->waitForFinished(-1);
    QByteArray bytes = m_process->readAllStandardOutput();
    QString output = QString::fromLocal8Bit(bytes);
    output.chop(1);
    return output;
}

void Launcher::launchDetached(const QString &program)
{
    m_process->startDetached(program);
}

Launcher::~Launcher() {

}
