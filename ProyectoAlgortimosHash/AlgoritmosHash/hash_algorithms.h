#ifndef HASH_ALGORITHMS_H
#define HASH_ALGORITHMS_H

#include <QString>

class HashAlgorithms {
public:
    static QString MD5(const QString &text);
    static QString SHA1(const QString &text);
    static QString SHA256(const QString &text);
    static QString SHA512(const QString &text);
    static QString BasicHash(const QString &text);
};

#endif // HASH_ALGORITHMS_H
