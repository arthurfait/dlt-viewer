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
 * \file Mib3_1.cpp
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#include <QtGui>

#include "mib3_1.h"

Mib3_1::Mib3_1()
{
    form = NULL;
    dltFile = NULL;
    counterMessages = 0;
    counterNonVerboseMessages = 0;
    counterVerboseMessages = 0;
}

Mib3_1::~Mib3_1()
{

}

QString Mib3_1::name()
{
    return QString("Dummy Viewer Plugin");
}

QString Mib3_1::pluginVersion(){
    return MIB31_VIEWER_PLUGIN_VERSION;
}

QString Mib3_1::pluginInterfaceVersion(){
    return PLUGIN_INTERFACE_VERSION;
}

QString Mib3_1::description()
{
    return QString();
}

QString Mib3_1::error()
{
    return QString();
}

bool Mib3_1::loadConfig(QString /* filename */)
{
    return true;
}

bool Mib3_1::saveConfig(QString /* filename */)
{
    return true;
}

QStringList Mib3_1::infoConfig()
{
    return QStringList();
}

QWidget* Mib3_1::initViewer()
{
    form = new Mib31::Form();
    return form;
}


void Mib3_1::updateCounters(int , QDltMsg &msg)
{
    if (!dltFile)
        return;

    if (m_domains.count(msg.getApid())) {
        m_domains[msg.getApid()]++;
    } else {
        m_domains[msg.getApid()] = 0;
    }
}


void Mib3_1::selectedIdxMsg(int index, QDltMsg &/*msg*/) {
    if(!dltFile)
        return;
    //qDebug() << "undecoded: " << msg.toStringPayload();
//    form->setSelectedMessage(index);
}

void Mib3_1::selectedIdxMsgDecoded(int , QDltMsg &/*msg*/){

    //qDebug() << "decoded: " << msg.toStringPayload();

}

void Mib3_1::initFileStart(QDltFile *file){

    dltFile = file;

//    form->setMessages(dltFile->size());

    counterMessages = dltFile->size();

    counterNonVerboseMessages = 0;
    counterVerboseMessages = 0;
}

void Mib3_1::initMsg(int index, QDltMsg &msg)
{
    updateCounters(index, msg);
}



void Mib3_1::initMsgDecoded(int , QDltMsg & msg){
    if (msg.getApid() == "") {

        QString payload(msg.getPayload().toStdString().c_str());
        if (payload.startsWith("SYSTEM INFO HEARTBEAT - LINUX: CPU load")) {
            payload.
        }

    }
}

void Mib3_1::initFileFinish(){
//    form->setMessages(dltFile->size());
//    form->setVerboseMessages(counterVerboseMessages);
//    form->setNonVerboseMessages(counterNonVerboseMessages);
}

void Mib3_1::updateFileStart()
{

}

void Mib3_1::updateMsg(int index, QDltMsg &msg)
{
    if(!dltFile)
        return;
    updateCounters(index,msg);
    counterMessages = dltFile->size();
}

void Mib3_1::updateMsgDecoded(int , QDltMsg &){
//empty. Implemented because derived plugin interface functions are virtual.
}

void Mib3_1::updateFileFinish(){
    form->setDomains(m_domains);
}

#ifndef QT5
Q_EXPORT_PLUGIN2(Mib3_1, Mib3_1);
#endif
