/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#include "reportpublisher.h"

#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

ReportPublisher::ReportPublisher(QObject *parent) : QObject(parent) {}

void ReportPublisher::submit() {
  qDebug() << "ReportPublisher::submit()";
  QDesktopServices::openUrl(QUrl("https://goo.gl/forms/0705ZN0EMW3xLDpI2"));
}
