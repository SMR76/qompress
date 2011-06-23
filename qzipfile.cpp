/**
 * Copyright (c) 2011 Oleksandr Tymoshenko <gonzo@bluezbox.com>
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.

 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "qzipfile.h"
namespace qompress 
{

QZipFile::QZipFile(const QString &name, QObject *parent) :
    QIODevice(parent), m_fileName(name), m_unzFile(0)
{
}

QZipFile::~QZipFile()
{
}

bool QZipFile::open()
{
    if (m_unzFile) {
        setError("File is already open"); 
        return false;
    }

    m_unzFile = unzOpen64(m_fileName.toAscii());
    if (m_unzFile)
        return true;
    else {
        // XXX: more human-readable
        setError("unzOpen64 failed");
        return false;
    }
}

void QZipFile::close()
{
    unzClose(m_unzFile);
}

qint64 QZipFile::readData(char*, qint64)
{
    return -1;
}

qint64 QZipFile::writeData(const char*, qint64)
{
    return -1;
}

} // namespace
