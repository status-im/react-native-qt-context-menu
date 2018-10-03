/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include <memory>

#include "bridge.h"
#include "rncmdesktop.h"

#include <QDebug>
#include <QVariantMap>
#include <QMessageBox>

namespace {
struct RegisterQMLMetaType {
    RegisterQMLMetaType() {
        qRegisterMetaType<RNCM*>();
    }
} registerMetaType;
} // namespace

class RNCMPrivate {
public:
    RNCMPrivate() {}
    Bridge* bridge = nullptr;
};

RNCM::RNCM(QObject* parent) : QObject(parent), d_ptr(new RNCMPrivate) {}

RNCM::~RNCM() {}

void RNCM::setBridge(Bridge* bridge) {
    Q_D(RNCM);
    d->bridge = bridge;
}

QString RNCM::moduleName() {
    return "RNCM";
}

QList<ModuleMethod*> RNCM::methodsToExport() {
    return QList<ModuleMethod*>{};
}

QVariantMap RNCM::constantsToExport() {
    return QVariantMap();
}

void RNCM::show(QString text) {
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}
