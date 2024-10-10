#include "hash_algorithms.h"
#include <QCryptographicHash>

// Función hash MD5 usando QCryptographicHash
QString HashAlgorithms::MD5(const QString &text) {
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Md5);
    return hash.toHex();
}

// Función hash SHA-1 usando QCryptographicHash
QString HashAlgorithms::SHA1(const QString &text) {
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha1);
    return hash.toHex();
}

// Función hash SHA-256 usando QCryptographicHash
QString HashAlgorithms::SHA256(const QString &text) {
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

// Función hash SHA-512 usando QCryptographicHash
QString HashAlgorithms::SHA512(const QString &text) {
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha512);
    return hash.toHex();
}

// Función hash básica que convierte el texto en un número hash
QString HashAlgorithms::BasicHash(const QString &text) {
    quint32 hashValue = 0;
    for (QChar ch : text) {
        hashValue = hashValue * 31 + ch.unicode();
    }
    return QString::number(hashValue, 16);  // Convertir el hash en hexadecimal
}
