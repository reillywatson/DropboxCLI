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
#include <QCoreApplication>
#include <QStringList>
#include <QtDebug>
#include <QFile>

#include <QtKOAuth>

#include <QDesktopServices>
#include "twittercli.h"
#include "kqoauthauthreplyserver.h"

static const QString CONSUMER_KEY = "5byxnt7j5bmcq83";
static const QString CONSUMER_SECRET_KEY = "sb831oqdrjklap3";

TwitterCLI::TwitterCLI() {
    oauthRequest = new KQOAuthRequest;
    oauthManager = new KQOAuthManager(this);
    networkAccessManager = new QNetworkAccessManager(this);
}

TwitterCLI::~TwitterCLI() {
    delete oauthRequest;
    delete oauthManager;
    delete networkAccessManager;
}

void TwitterCLI::getAccess(QString email, QString password)  {
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));            
    // dropbox doesn't do proper OAuth authentication (ie take you to an external website and ask you for a password).
    // instead, we need to put the login and password into this token request directly.
    QString url = QString("https://api.dropbox.com/0/token?email=%1&password=%2&oauth_consumer_key=%3").arg(email).arg(password).arg(CONSUMER_KEY);
    networkAccessManager->get(QNetworkRequest(QUrl(url)));
}

void TwitterCLI::replyFinished(QNetworkReply *networkReply) {
	QString reply = networkReply->readAll();
	// todo: proper JSON support
	qDebug() << "REPLY FINISHED!";
	QStringList tokens = reply.split("\"");
	if (tokens.count() != 9) {
		qDebug() << "WHOAAAAAA authorization failed! Reply: " << reply;
		QCoreApplication::exit(-1);
	}
	onAccessTokenReceived(tokens[3],tokens[7]);
}

void TwitterCLI::onAccessTokenReceived(QString token, QString tokenSecret) {
    qDebug() << "Access token received: " << token << tokenSecret;

    oauthSettings.setValue("oauth_token", token);
    oauthSettings.setValue("oauth_token_secret", tokenSecret);

    qDebug() << "Access tokens now stored.";

    QCoreApplication::exit(0);
}

void TwitterCLI::downloadFile(QString path) {
    if( oauthSettings.value("oauth_token").toString().isEmpty() ||
        oauthSettings.value("oauth_token_secret").toString().isEmpty()) {
        qDebug() << "No access tokens. Aborting.";
        QCoreApplication::exit(-1);
    }
    oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl("https://api-content.dropbox.com/0/files/dropbox/" + path));
    oauthRequest->setHttpMethod(KQOAuthRequest::GET);
    oauthRequest->setConsumerKey(CONSUMER_KEY);
    oauthRequest->setConsumerSecretKey(CONSUMER_SECRET_KEY);
    oauthRequest->setToken(oauthSettings.value("oauth_token").toString());
    oauthRequest->setTokenSecret(oauthSettings.value("oauth_token_secret").toString());

    oauthManager->executeRequest(oauthRequest);

    connect(oauthManager, SIGNAL(requestReady(QByteArray)),
            this, SLOT(outputResponse(QByteArray)));
    
}

void TwitterCLI::outputResponse(QByteArray response) {
	QFile file;
	file.open(stdout, QIODevice::WriteOnly);
	file.write(response);
	file.close();
	QCoreApplication::exit(0);
}

void TwitterCLI::listFiles(QString path) {
    if( oauthSettings.value("oauth_token").toString().isEmpty() ||
        oauthSettings.value("oauth_token_secret").toString().isEmpty()) {
        qDebug() << "No access tokens. Aborting.";
        QCoreApplication::exit(-1);
    }

    oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl("https://api.dropbox.com/0/metadata/dropbox/" + path));
    oauthRequest->setConsumerKey(CONSUMER_KEY);
    oauthRequest->setConsumerSecretKey(CONSUMER_SECRET_KEY);
    oauthRequest->setToken(oauthSettings.value("oauth_token").toString());
    oauthRequest->setTokenSecret(oauthSettings.value("oauth_token_secret").toString());

    oauthManager->executeRequest(oauthRequest);

    connect(oauthManager, SIGNAL(requestReady(QByteArray)),
            this, SLOT(outputResponse(QByteArray)));
}

void TwitterCLI::showHelp() {
    QTextStream qout(stdout);
    qout << "Dropbox CLI, version 0.1. Author: Reilly Watson <reillywatson@gmail.com>\n"
         << "\n"
         << "Usage: twittercli -[ald] <path>\n"
         << " -a <email> <password>               Authenticate.\n"
         << " -l '<path>'                  Get metadata info at <path> (returns JSON)\n"
         << " -d '<path>'      Download file at <path>\n"
         << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setOrganizationName("kQOAuth");
    QCoreApplication::setApplicationName("DropboxCLI");

    QStringList args = QCoreApplication::arguments();

    TwitterCLI tAuth;
    if(args.contains("-l")) {
        if(args.last() != "-l") {
            tAuth.listFiles(args.last());
        }
        else {
          tAuth.showHelp();
          return 0;
	    }
     } else if(args.contains("-d")) {
        if(args.last() != "-d") {
            tAuth.downloadFile(args.last());
        }
        else {
          tAuth.showHelp();
          return 0;
	    }
     } else if( args.contains("-a")) {
		 int pos = args.indexOf("-a");
		 if (pos < args.count() - 2) {
			tAuth.getAccess(args[pos+1], args[pos+2]);
		}
		else {
		  tAuth.showHelp();
		  return 0;
	    }
    } else {
        tAuth.showHelp();
        return 0;
    }

    return app.exec();

}
