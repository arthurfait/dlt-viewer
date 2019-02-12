/**
 * @licence app begin@
 * Copyright (C) 2018 PAISEU
 * Copyright (C) 2018 Luxoft
 *
 * This file is part of GENIVI Project Dlt Viewer.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \file mib3_1.h
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#ifndef MIB3_1_H
#define MIB3_1_H

#include <QObject>
#include <QMap>
#include <QString>
#include "plugininterface.h"
#include "form.h"
#define MIB31_VIEWER_PLUGIN_VERSION "1.0.0"

class Mib3_1 : public QObject, QDLTPluginInterface, QDltPluginViewerInterface
{
    Q_OBJECT
    Q_INTERFACES(QDLTPluginInterface)
    Q_INTERFACES(QDltPluginViewerInterface)
#ifdef QT5
    Q_PLUGIN_METADATA(IID "org.genivi.DLT.Mib3_1")
#endif

public:
    Mib3_1();
    ~Mib3_1();

    /* QDLTPluginInterface interface */
    QString name();
    QString pluginVersion();
    QString pluginInterfaceVersion();
    QString description();
    QString error();
    bool loadConfig(QString filename);
    bool saveConfig(QString filename);
    QStringList infoConfig();

    /* QDltPluginViewerInterface */
    QWidget* initViewer();
    void initFileStart(QDltFile *file);
    void initFileFinish();
    void initMsg(int index, QDltMsg &msg);
    void initMsgDecoded(int index, QDltMsg &msg);
    void updateFileStart();
    void updateMsg(int index, QDltMsg &msg);
    void updateMsgDecoded(int index, QDltMsg &msg);
    void updateFileFinish();
    void selectedIdxMsg(int index, QDltMsg &msg);
    void selectedIdxMsgDecoded(int index, QDltMsg &msg);


    /* internal variables */
    Mib31::Form *form;
    int counterMessages;
    int counterNonVerboseMessages;
    int counterVerboseMessages;

    QMap<QString, uint32_t> m_domains;

    void show(bool value);
    void updateCounters(int index, QDltMsg &msg);

private:
    QDltFile *dltFile;
    QString errorText;
};

#endif // MIB3_1_H
