#include "huffman.h"
#include <bits/stdc++.h>
#include <QDebug>
using namespace std;

Huffman::Huffman(QObject *parent) : QObject(parent)
{

}
struct node {
    char id;
    int val;
    bool operator < (const node &b) const {
        return val > b.val;
    }
    node(int id = 0, int val = 0): id(id), val(val) {}
};
vector<node> weight;
vector<char> charset;
struct huftree {
    char ch;
    int l, r;
    int fa;
};
vector<huftree> Htree;
int n;
map<string, char> mp1;
map<char, string> mp2;
int cnt = 1;

void build() {
    priority_queue<node> q;
    for (int i = 1; i <= n; i++) {
        q.push(weight[i]);
    }
    for (int i = 1; i <= n; i++) {
        Htree[i].ch = charset[i];
        Htree[i].l = Htree[i].r = Htree[i].fa = -1;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        Htree[i].l = Htree[i].r = Htree[i].fa = -1;
        Htree[i].ch = '*';
    }

    while (!q.empty()) {
        node a = q.top(); q.pop();
        bool flag = false;
        node b;
        if (!q.empty()) {
            flag = true;
            b = q.top(); q.pop();
        }
        if (flag) {
            Htree[a.id].fa = Htree[b.id].fa = n + cnt;
            Htree[n + cnt].l = a.id;
            Htree[n + cnt].r = b.id;
            q.push(node(n + cnt, a.val + b.val));
        }
        else {
            break;
        }
        cnt++;
    }

    for (int i = 1; i <= n; i++) {
        string ss = "";
        int tmp = i;
        while (Htree[tmp].fa != -1) {
            int fa = Htree[tmp].fa;
            if (tmp == Htree[fa].l) ss = ss + "0";
            else ss = ss + "1";
            tmp = fa;
        }
        reverse(ss.begin(), ss.end());
        mp1[ss] = charset[i];
        mp2[charset[i]] = ss;
    }
}

char buf[1050][1050];
int dfs(int now) {
    return now == -1 ? 0 : max(dfs(Htree[now].l), dfs(Htree[now].r)) + 1;
}
void buildBuf(int now, int rx, int ry, int rc) {
    if (now == -1) return;
    int l = rx - rc;
    int r = rx + rc;
    if (Htree[now].ch != '*')
        return;
    else {
        buf[ry][rx] = Htree[now].ch;
        if(Htree[now].l != -1) {
            buf[ry + 1][rx - 1] = '/';
            if (Htree[Htree[now].l].ch != '*')
                buf[ry + 2][rx - 2] = Htree[Htree[now].l].ch;
        }
        if(Htree[now].r != -1) {
            buf[ry + 1][rx + 1] = '\\';
            if (Htree[Htree[now].r].ch != '*')
                buf[ry + 2][rx + 2] = Htree[Htree[now].r].ch;
        }
        buildBuf(Htree[now].l, l-1, ry+2, (rc>>1));
        buildBuf(Htree[now].r, r+2, ry+2, (rc>>1));
    }
}
int line;
void printTree() {

    memset(buf, ' ', sizeof(buf));
    int dep = dfs(n + cnt - 1);
    buildBuf(n + cnt - 1, 60, 0, 3 * dep);
    line = 0;
    for (int i=0; i<1050; i++) {
        int j = 1050-1;
        while (buf[i][j] == ' ' && j >= 0)
            j--;
        buf[i][j+1] = '\0';
        if (j <= -1) break;
        line++;
    }

}

void Huffman::init(string inFile) {
    ifstream in(inFile);
    
    in >> n;
    Htree.resize(n << 1 | 1);
    charset.resize(n << 1 | 1, 0);
    weight.resize(n << 1 | 1);

    for (int i = 1; i <= n; i++) {
        in >> charset[i] >> weight[i].val;
        weight[i].id = i;
    }
    
    build();
    printTree();
    in.close();
}


int Huffman::encode(string inFile, string outFile) {
    ifstream in(inFile);
    ofstream out(outFile, ios::app);
    string text;
    while (in >> text) {
        if (text.compare("##") == 0) {
            out << endl;
            out << "##" << endl;
            continue;
        }
        int len = text.length();

        for (int i = 0; i < len; i++) {
            if (!mp2.count(text[i])) {
                cout << text[i] << endl;
                in.close();
                out.close();
                return -1;
            }
            out << mp2[text[i]].c_str();
        }
        out << " ";
    }

    in.close();
    out.close();
    return 1;
}
int Huffman::decode(string inFile, string outFile) {
    ifstream in(inFile);
    ofstream out(outFile, ios::app);
    string text;
    text.clear();
    bool flag = false;
    while (in >> text) {
        if (text.compare("##") == 0) {
            out << endl;
            out << "##" << endl;
            continue;
        }
        int len = text.length();
        string ss = "";
        for (int i = 0; i < len; i++) {
            ss = ss + text[i];
            flag = false;
            if (mp1.count(ss) != 0) {
                out << mp1[ss];
                ss = "";
                flag = true;
            }
        }
        out << " ";
    }
    in.close();
    out.close();
    if (!flag) return -1;
    return 1;
}
