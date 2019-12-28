#ifndef HUFFMAN_H
#define HUFFMAN_H
#define pii pair<int, int>

#include <QObject>
#include <bits/stdc++.h>
using namespace std;
class Huffman : public QObject
{
    Q_OBJECT
public:
    explicit Huffman(QObject *parent = nullptr);

signals:

public slots:
    void init(string inFile);
    int encode(string inFile, string outFile);
    int decode(string inFile, string outFile);
};

#endif // HUFFMAN_H
