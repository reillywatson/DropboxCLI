#ifndef DROPBOXCLI_H
#define DROPBOXCLI_H

#include <QObject>
#include <QMultiMap>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class KQOAuthManager;
class KQOAuthRequest;
class DropboxCLI : public QObject {
Q_OBJECT
public:
	DropboxCLI();
	~DropboxCLI();

	void getAccess(QString email, QString password);
	void listFiles(QString path);
	void downloadFile(QString path);
	void showHelp();
	void showAuth();

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


#endif // DROPBOXCLI_H
