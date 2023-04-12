#pragma once
#include "CardAnimation.h"

CardAnimation::CardAnimation(QObject* target, const QByteArray& propertyName) :
    QPropertyAnimation(target, propertyName)
{}

void CardAnimation::start(QAbstractAnimation::DeletionPolicy policy)
{
    QPropertyAnimation::start(policy);
    started();

}
