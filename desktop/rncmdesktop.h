/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#ifndef RNCMDESKTOP_H
#define RNCMDESKTOP_H

#include "moduleinterface.h"

#include <QVariantMap>
#include <QMessageBox>

class RNCMPrivate;
class RNCM : public QObject, public ModuleInterface {
    Q_OBJECT
    Q_INTERFACES(ModuleInterface)

    Q_DECLARE_PRIVATE(RNCM)

public:
    Q_INVOKABLE RNCM(QObject* parent = 0);
    ~RNCM();

    virtual void setBridge(Bridge* bridge) override;

    virtual QString moduleName() override;
    virtual QList<ModuleMethod*> methodsToExport() override;
    virtual QVariantMap constantsToExport() override;

    Q_INVOKABLE void show(QString text);

private:
    QScopedPointer<RNCMPrivate> d_ptr;
};

#endif // RNCMDESKTOP_H
