/*
  Copyright (c) 2011 - Tőkés Attila

  This file is part of SmtpClient for Qt.

  SmtpClient for Qt is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  SmtpClient for Qt is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY.

  See the LICENCE file for more details.
*/

#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QWidget>
#include <QSettings>

#include "../../src/SmtpMime"

namespace Ui {
    class SendEmail;
}

using namespace SimpleMail;

class SendEmail : public QWidget
{
    Q_OBJECT

public:
    explicit SendEmail(QWidget *parent = nullptr);
    ~SendEmail();

private Q_SLOTS:
    void on_addAttachment_clicked();

    void on_sendEmail_clicked();
    void sendMailAsync(const MimeMessage &msg);
    void sendMailSync(const MimeMessage &msg);

private:
    QSettings m_settings;
    Ui::SendEmail *ui;

    void errorMessage(const QString & message);
};

#endif // SENDEMAIL_H
