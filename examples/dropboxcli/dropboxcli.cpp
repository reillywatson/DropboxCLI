#include <QCoreApplication>
#include <QStringList>
#include <QtDebug>
#include <QFile>

#include <QtKOAuth>

#include <QDesktopServices>
#include "dropboxcli.h"
#include "kqoauthauthreplyserver.h"

static const QString CONSUMER_KEY = "5byxnt7j5bmcq83";
static const QString CONSUMER_SECRET_KEY = "sb831oqdrjklap3";

DropboxCLI::DropboxCLI() {
    oauthRequest = new KQOAuthRequest;
    oauthManager = new KQOAuthManager(this);
    networkAccessManager = new QNetworkAccessManager(this);
}

DropboxCLI::~DropboxCLI() {
    delete oauthRequest;
    delete oauthManager;
    delete networkAccessManager;
}

static QString _email;

void DropboxCLI::getAccess(QString email, QString password)  {
	_email = email;
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));            
    // dropbox doesn't do proper OAuth authentication (ie take you to an external website and ask you for a password).
    // instead, we need to put the login and password into this token request directly.
    QString url = QString("https://api.dropbox.com/0/token?email=%1&password=%2&oauth_consumer_key=%3").arg(email).arg(password).arg(CONSUMER_KEY);
    networkAccessManager->get(QNetworkRequest(QUrl(url)));
}

void DropboxCLI::replyFinished(QNetworkReply *networkReply) {
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

void DropboxCLI::onAccessTokenReceived(QString token, QString tokenSecret) {
    qDebug() << "Access token received: " << token << tokenSecret;

    oauthSettings.setValue("oauth_token", token);
    oauthSettings.setValue("oauth_token_secret", tokenSecret);
    oauthSettings.setValue("email", _email);

    qDebug() << "Access tokens now stored.";

    QCoreApplication::exit(0);
}

void DropboxCLI::downloadFile(QString path) {
    if( oauthSettings.value("oauth_token").toString().isEmpty() ||
        oauthSettings.value("oauth_token_secret").toString().isEmpty()) {
        qDebug() << "No access tokens. Aborting.";
        exit(-1);
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

void DropboxCLI::outputResponse(QByteArray response) {
	QFile file;
	file.open(stdout, QIODevice::WriteOnly);
	file.write(response);
	file.close();
	QCoreApplication::exit(0);
}

void DropboxCLI::listFiles(QString path) {
    if( oauthSettings.value("oauth_token").toString().isEmpty() ||
        oauthSettings.value("oauth_token_secret").toString().isEmpty()) {
        qDebug() << "No access tokens. Aborting.";
        exit(-1);
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

void DropboxCLI::showAuth() {
	QTextStream qout(stdout);
	QString email = oauthSettings.value("email").toString();
	qout << email;
}

void DropboxCLI::showHelp() {
    QTextStream qout(stdout);
    qout << "Usage: DropboxCLI -[ald] <path>\n"
         << " -a <email> <password>               Authenticate.\n"
         << " -l <path>                  Get metadata info at <path> (returns JSON object)\n"
         << " -d <path>      Download file at <path>\n"
         << " -c             List the email address that's been authenticated against\n"
         << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setOrganizationName("kQOAuth");
    QCoreApplication::setApplicationName("DropboxCLI");

    QStringList args = QCoreApplication::arguments();

    DropboxCLI tAuth;
    if(args.contains("-l")) {
        if(args.last() != "-l") {
            tAuth.listFiles(args.last());
        }
        else {
          tAuth.listFiles("");
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
	} else if (args.contains("-c")) {
		tAuth.showAuth();
		return 0;
    } else {
        tAuth.showHelp();
        return 0;
    }

    return app.exec();

}
