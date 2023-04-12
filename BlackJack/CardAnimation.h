#pragma once
#include <QPropertyAnimation>

class CardAnimation :
    public QPropertyAnimation
{
    Q_OBJECT
public:
    CardAnimation(QObject* target, const QByteArray &propertyName);
    void start(QAbstractAnimation::DeletionPolicy policy = QAbstractAnimation::KeepWhenStopped);

signals:
    void started();
};

