#include "algorithms.h"
#include <vector>
#include <queue>
#include <unordered_map>

// Función para crear la tabla de fallos (fallo o bordes)
void buildKMPTable(const QString &pattern, std::vector<int> &lps) {
    int m = pattern.length();
    lps[0] = 0;  // lps[0] siempre es 0
    int len = 0; // longitud del borde más largo
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

QString Algorithms::KMP(const QString &text, const QString &pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || n == 0) {
        return "Patrón o texto vacío.";
    }

    // Construir la tabla de fallos
    std::vector<int> lps(m);
    buildKMPTable(pattern, lps);

    int i = 0; // Índice para text
    int j = 0; // Índice para pattern
    QString result;

    // Recorrer el texto para encontrar coincidencias
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            result += QString("Texto encontrado entre las posiciones %1 y %2\n")
            .arg(i - j + 1)
                .arg(i);
            j = lps[j - 1];  // Reiniciar j usando la tabla de fallos
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (result.isEmpty()) {
        return "Patrón no encontrado.";
    }

    return result;
}
#include "algorithms.h"
#include <cmath>

const int d = 256;
const int q = 101;  // Un número primo para reducir colisiones de hash

QString Algorithms::RabinKarp(const QString &text, const QString &pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || n == 0) {
        return "Patrón o texto vacío.";
    }

    int h = 1;  // Valor de 'd' elevado a m-1
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    int p = 0;  // Valor de hash para el patrón
    int t = 0;  // Valor de hash para el texto

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i].unicode()) % q;
        t = (d * t + text[i].unicode()) % q;
    }

    QString result;

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                result += QString("Texto encontrado entre las posiciones %1 y %2\n")
                .arg(i + 1)
                    .arg(i + m);
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i].unicode() * h) + text[i + m].unicode()) % q;
            if (t < 0) t = (t + q);
        }
    }

    return result.isEmpty() ? "Patrón no encontrado." : result;
}
QString Algorithms::BruteForce(const QString &text, const QString &pattern) {
    int m = pattern.length();
    int n = text.length();
    QString result;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) {
            result += QString("Texto encontrado entre las posiciones %1 y %2\n")
            .arg(i + 1)
                .arg(i + m);
        }
    }
    return result.isEmpty() ? "Patrón no encontrado." : result;
}
#include "algorithms.h"
#include <vector>

void buildBadCharTable(const QString &pattern, std::vector<int> &badCharTable) {
    int m = pattern.length();
    for (int i = 0; i < 256; i++) badCharTable[i] = -1;
    for (int i = 0; i < m; i++) badCharTable[pattern[i].unicode()] = i;
}

QString Algorithms::BoyerMoore(const QString &text, const QString &pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || n == 0) {
        return "Patrón o texto vacío.";
    }

    std::vector<int> badCharTable(256);
    buildBadCharTable(pattern, badCharTable);

    int shift = 0;
    QString result;

    while (shift <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) j--;

        if (j < 0) {
            result += QString("Texto encontrado entre las posiciones %1 y %2\n")
            .arg(shift + 1)
                .arg(shift + m);
            shift += (shift + m < n) ? m - badCharTable[text[shift + m].unicode()] : 1;
        } else {
            shift += std::max(1, j - badCharTable[text[shift + j].unicode()]);
        }
    }

    return result.isEmpty() ? "Patrón no encontrado." : result;
}
#include "algorithms.h"
#include <queue>
#include <unordered_map>

struct TrieNode {
    std::unordered_map<QChar, TrieNode*> children;
    TrieNode* failLink = nullptr; // Enlace de fallo para Aho-Corasick
    bool isEndOfWord = false;
    int index = -1; // Índice donde el patrón comienza
};

class AhoCorasickTrie {
public:
    TrieNode* root;

    AhoCorasickTrie() {
        root = new TrieNode();
    }

    // Insertar un patrón en el trie
    void insertPattern(const QString &pattern) {
        TrieNode* current = root;
        for (int i = 0; i < pattern.length(); i++) {
            QChar ch = pattern[i];
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Construir enlaces de fallo (esto es simplificado para un solo patrón)
    void buildFailureLinks() {
        std::queue<TrieNode*> q;
        root->failLink = root;

        for (auto &child : root->children) {
            child.second->failLink = root;
            q.push(child.second);
        }

        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

            for (auto &child : current->children) {
                TrieNode* fail = current->failLink;

                while (fail != root && fail->children.find(child.first) == fail->children.end()) {
                    fail = fail->failLink;
                }

                if (fail->children.find(child.first) != fail->children.end()) {
                    child.second->failLink = fail->children[child.first];
                } else {
                    child.second->failLink = root;
                }

                q.push(child.second);
            }
        }
    }

    // Buscar el patrón en el texto
    QString searchPattern(const QString &text, const QString &pattern) {
        TrieNode* current = root;
        QString result;
        int patternLength = pattern.length();

        for (int i = 0; i < text.length(); i++) {
            QChar ch = text[i];

            while (current != root && current->children.find(ch) == current->children.end()) {
                current = current->failLink;
            }

            if (current->children.find(ch) != current->children.end()) {
                current = current->children[ch];
            }

            // Si estamos en un nodo que es fin de palabra (encontramos el patrón completo)
            if (current->isEndOfWord) {
                // Ajuste del índice de inicio y fin del patrón encontrado
                int start = i - patternLength + 1;
                int end = i + 1;
                result += QString("Texto encontrado entre las posiciones %1 y %2\n")
                              .arg(start + 1)  // Ajustar índice a 1 basado
                              .arg(end);
            }
        }

        return result.isEmpty() ? "Patrón no encontrado." : result;
    }
};

QString Algorithms::AhoCorasick(const QString &text, const QString &pattern) {
    if (pattern.isEmpty() || text.isEmpty()) {
        return "Patrón o texto vacío.";
    }

    AhoCorasickTrie trie;
    trie.insertPattern(pattern);
    trie.buildFailureLinks();

    return trie.searchPattern(text, pattern);
}
