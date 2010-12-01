/**
 * TwitterCLI - This file is a part of the kQOAuth library.
 *
 * Author: Johan Paul (johan.paul@d-pointer.com)
 *         http://www.d-pointer.com
 *
 *  KQOAuth is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  KQOAuth is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with KQOAuth.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TWITTERAUTH_H
#define TWITTERAUTH_H

#include <QObject>
#include <QMultiMap>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class KQOAuthManager;
class KQOAuthRequest;
class TwitterCLI : public QObject {
    Q_OBJECT
public:
    TwitterCLI();
    ~TwitterCLI();

    void getAccess(QString email, QString password);
    void listFiles(QString path);
    void downloadFile(QString path);
    void showHelp();

private slots:
    void onAccessTokenReceived(QString token, QString tokenSecret);
    void replyFinished(QNetworkReply *reply);
    void outputResponse(QByteArray response);

private:
    KQOAuthManager *oauthManager;
    KQOAuthRequest *oauthRequest;
    QSettings oauthSettings;
    QNetworkAccessManager *networkAccessManager;
};


#endif // TWITTERAUTH_H
