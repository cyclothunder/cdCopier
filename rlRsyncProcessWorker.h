#ifndef RLRSYNCPROCESSWORKER_H
#define RLRSYNCPROCESSWORKER_H

#include <QProcess>
//#include <workoptionsdialog.h>

class RLRsyncProcessWorker : public QProcess
{
    Q_OBJECT
public:
    explicit RLRsyncProcessWorker(QObject *parent = 0);

private:


signals:
    void processOutput(QString output);

public slots:
    void process(const QString &parentOrigem, const QString &parentDestino, const QStringList &excludes, const bool &excludesOK, const bool &dryRun);

private slots:
    void onProcessReadyToRead();
    void onFinished(int exitCode,QProcess::ExitStatus status);

};

#endif // RLRSYNCPROCESSWORKER_H
