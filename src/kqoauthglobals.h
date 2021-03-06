/**
 * KQOAuth - An OAuth authentication library for Qt.
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
#ifndef KQOAUTHGLOBALS_H
#define KQOAUTHGLOBALS_H

//////////// Static constant definitions ///////////
const QString KQOAuthRequestPrivate::OAUTH_KEY_CONSUMER("oauth_consumer");
const QString KQOAuthRequestPrivate::OAUTH_KEY_CONSUMER_KEY("oauth_consumer_key");
const QString KQOAuthRequestPrivate::OAUTH_KEY_TOKEN("oauth_token");
const QString KQOAuthRequestPrivate::OAUTH_KEY_TOKEN_SECRET("oauth_token_secret");
const QString KQOAuthRequestPrivate::OAUTH_KEY_SIGNATURE_METHOD("oauth_signature_method");
const QString KQOAuthRequestPrivate::OAUTH_KEY_TIMESTAMP("oauth_timestamp");
const QString KQOAuthRequestPrivate::OAUTH_KEY_NONCE("oauth_nonce");
const QString KQOAuthRequestPrivate::OAUTH_KEY_SIGNATURE("oauth_signature");
const QString KQOAuthRequestPrivate::OAUTH_KEY_CALLBACK("oauth_callback");
const QString KQOAuthRequestPrivate::OAUTH_KEY_VERIFIER("oauth_verifier");
const QString KQOAuthRequestPrivate::OAUTH_KEY_VERSION("oauth_version");

#endif // KQOAUTHGLOBALS_H
