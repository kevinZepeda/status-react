/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#ifndef REPORTPUBLISHER
#define REPORTPUBLISHER

#include <QObject>

class ReportPublisher : public QObject {
    Q_OBJECT

public:
    ReportPublisher(QObject* parent = 0);

    Q_INVOKABLE void submit();
};


#endif // REPORTPUBLISHER
