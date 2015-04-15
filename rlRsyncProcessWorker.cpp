#include "rlRsyncProcessWorker.h"
#include <QDateTime>

RLRsyncProcessWorker::RLRsyncProcessWorker(QObject *parent):
    QProcess(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(onProcessReadyToRead()));
    connect(this,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(onFinished(int,QProcess::ExitStatus)));

}

void RLRsyncProcessWorker::process(const QString &parentOrigem, const QString &parentDestino,
                                    const QStringList &excludes,
                                    const bool &excludesOK,
                                    const bool &dryRun)
{
    QStringList args, l_excludes;
    l_excludes = excludes;
    QString origem = parentOrigem;
    QString destino = parentDestino;
    args << "-ruv";
    if (dryRun) args << "-n";
    if (excludesOK) {
        for (int i = 0;i < l_excludes.count();i++) args << "--exclude=" + l_excludes.at(i) ;
    }
    args << "--progress" << origem << destino;
    this->start("rsync",args);
    this->waitForStarted();
}

void RLRsyncProcessWorker::onProcessReadyToRead()
{

    if (!this->isOpen()) this->open(QIODevice::ReadOnly);
    QString output = QString::fromLatin1(this->readAll());
    emit processOutput(output);
}

void RLRsyncProcessWorker::onFinished(int exitCode, QProcess::ExitStatus status)
{
    if (this->state() == 2 || status == QProcess::CrashExit) {
        this->close();
        this->terminate();
        this->waitForFinished(-1);
        emit finished(exitCode);
    } else emit finished(exitCode);
}
