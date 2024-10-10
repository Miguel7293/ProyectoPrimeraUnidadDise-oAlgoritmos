#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QString>

class Algorithms {
public:
    static QString BoyerMoore(const QString &text, const QString &pattern);
    static QString KMP(const QString &text, const QString &pattern);
    static QString RabinKarp(const QString &text, const QString &pattern);
    static QString BruteForce(const QString &text, const QString &pattern);
    static QString AhoCorasick(const QString &text, const QString &pattern);
};

#endif // ALGORITHMS_H
