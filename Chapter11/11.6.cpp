/*
* 题目名称：最短路径
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/AilPKHTx
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct BigInteger {
    int digit[10000];
    int length;
    BigInteger();
    BigInteger(int x);
    BigInteger(string str);
    BigInteger(const BigInteger& b);
    BigInteger operator=(int x);
    BigInteger operator=(string str);
    BigInteger operator=(const BigInteger& b);
    bool operator<(const BigInteger& b);
    bool operator<=(const BigInteger& b);
    bool operator==(const BigInteger& b);
    BigInteger operator+(const BigInteger& b);
    BigInteger operator-(const BigInteger& b);
    BigInteger operator*(const BigInteger& b);
    BigInteger operator/(const BigInteger& b);
    BigInteger operator%(const BigInteger& b);
    friend istream& operator>>(istream& in, BigInteger& b);
    friend ostream& operator<<(ostream& out, const BigInteger& b);
};

istream& operator>>(istream& in, BigInteger& b) {
    string str;
    in >> str;
    b = str;
    return in;
}

ostream& operator<<(ostream& out, const BigInteger& b) {
    for (int i = b.length - 1; i >= 0; --i) {
        out << b.digit[i];
    }
    return out;
}

BigInteger::BigInteger() {
    memset(digit, 0, sizeof(digit));
    length = 0;
}

BigInteger::BigInteger(int x) {
    memset(digit, 0, sizeof(digit));
    length = 0;
    if (x == 0) {
        digit[length++] = x;
    }
    while (x != 0) {
        digit[length++] = x % 10;
        x /= 10;
    }
}

BigInteger::BigInteger(string str) {
    memset(digit, 0, sizeof(digit));
    length = str.size();
    for (int i = 0; i < length; ++i) {
        digit[i] = str[length - i - 1] - '0';
    }
}

BigInteger::BigInteger(const BigInteger& b) {
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for (int i = 0; i < length; ++i) {
        digit[i] = b.digit[i];
    }
}

BigInteger BigInteger::operator=(int x) {
    memset(digit, 0, sizeof(digit));
    length = 0;
    if (x == 0) {
        digit[length++] = x;
    }
    while (x != 0) {
        digit[length++] = x % 10;
        x /= 10;
    }
    return *this;
}

BigInteger BigInteger::operator=(string str) {
    memset(digit, 0, sizeof(digit));
    length = str.size();
    for (int i = 0; i < length; ++i) {
        digit[i] = str[length - i - 1] - '0';
    }
    return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b) {
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for (int i = 0; i < length; ++i) {
        digit[i] = b.digit[i];
    }
    return *this;
}

bool BigInteger::operator<(const BigInteger& b) {
    if (length < b.length) {
        return true;
    } else if (b.length < length) {
        return false;
    } else {
        for (int i = length - 1; i >= 0; --i) {
            if (digit[i] == b.digit[i]) {
                continue;
            } else {
                return digit[i] < b.digit[i];
            }
        }
    }
    return false;
}

bool BigInteger::operator<=(const BigInteger& b) {
    if (length < b.length) {
        return true;
    } else if (b.length < length) {
        return false;
    } else {
        for (int i = length - 1; i >= 0; --i) {
            if (digit[i] == b.digit[i]) {
                continue;
            } else {
                return digit[i] < b.digit[i];
            }
        }
    }
    return true;
}

bool BigInteger::operator==(const BigInteger& b) {
    if (length != b.length) {
        return false;
    } else {
        for (int i = length - 1; i >= 0; --i) {
            if (digit[i] != b.digit[i]) {
                return false;
            }
        }
    }
    return true;
}

BigInteger BigInteger::operator+(const BigInteger& b) {
    BigInteger answer;
    int carry = 0;
    for (int i = 0; i < length || i < b.length; ++i) {
        int current = carry + digit[i] + b.digit[i];
        carry = current / 10;
        answer.digit[answer.length++] = current % 10;
    }
    if (carry != 0) {
        answer.digit[answer.length++] = carry;
    }
    return answer;
}

BigInteger BigInteger::operator-(const BigInteger& b) {
    BigInteger answer;
    int carry = 0;
    for (int i = 0; i < length; ++i) {
        int current = digit[i] - b.digit[i] - carry;
        if (current < 0) {
            current += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        answer.digit[answer.length++] = current;
    }
    while (answer.digit[answer.length - 1] == 0 && answer.length > 1)  {
        answer.length--;
    }
    return answer;

}

BigInteger BigInteger::operator*(const BigInteger& b) {
    BigInteger answer;
    answer.length = length + b.length;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < b.length; ++j) {
            answer.digit[i + j] += digit[i] * b.digit[j];
        }
    }
    for (int i = 0; i < answer.length; ++i) {
        answer.digit[i + 1] += answer.digit[i] / 10;
        answer.digit[i] %= 10;
    }
    while (answer.digit[answer.length - 1] == 0 && answer.length > 1)  {
        answer.length--;
    }
    return answer;
}

BigInteger BigInteger::operator/(const BigInteger& b) {
    BigInteger answer;
    answer.length = length;
    BigInteger remainder = 0;
    BigInteger temp = b;
    for (int i = length - 1; i >= 0; --i) {
        if (!(remainder.length == 1 && remainder.digit[0] == 0)) {
            for (int j = remainder.length - 1; j >= 0; --j) {
                remainder.digit[j + 1] = remainder.digit[j];
            }
            remainder.length++;
        }
        remainder.digit[0] = digit[i];
        while (temp <= remainder) {
            remainder = remainder - temp;
            answer.digit[i]++;
        }
    }
    while (answer.digit[answer.length - 1] == 0 && answer.length > 1)  {
        answer.length--;
    }
    return answer;
}

BigInteger BigInteger::operator%(const BigInteger& b) {
    BigInteger remainder = 0;
    BigInteger temp = b;
    for (int i = length - 1; i >= 0; --i) {
        if (!(remainder.length == 1 && remainder.digit[0] == 0)) {
            for (int j = remainder.length - 1; j >= 0; --j) {
                remainder.digit[j + 1] = remainder.digit[j];
            }
            remainder.length++;
        }
        remainder.digit[0] = digit[i];
        while (temp <= remainder) {
            remainder = remainder - temp;
        }
    }
    return remainder;
}

const int MAXN = 100 + 10;
const int MOD = 1e5;

struct Edge {
    int to;                                     //终点
    BigInteger length;                          //长度
    Edge(int t, BigInteger l): to(t), length(l) {}
};

struct Point {
    int number;                                 //点的编号
    BigInteger distance;                        //源点到该点距离
    Point(int n, BigInteger d): number(n), distance(d) {}
    bool operator< (Point p) const {
        return p.distance < distance;           //距离小的优先级高
    }
};

vector<Edge> graph[MAXN];                       //邻接表实现的图
BigInteger minDistance[MAXN];                   //源点到各点最短距离

void Dijkstra(int start) {
    minDistance[start] = 0;
    priority_queue<Point> myPriorityQueue;
    myPriorityQueue.push(Point(start, minDistance[start]));
    while (!myPriorityQueue.empty()) {
        int u = myPriorityQueue.top().number;   //离源点最近的点
        myPriorityQueue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            BigInteger l = graph[u][i].length;
            if (minDistance[u] + l < minDistance[v]) {
                minDistance[v] = minDistance[u] + l;
                myPriorityQueue.push(Point(v, minDistance[v]));
            }
        }
    }
    return ;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));
        BigInteger length = 1;
        for (int i = 0; i < m; ++i) {
            int from, to;
            scanf("%d%d", &from, &to);
            graph[from].push_back(Edge(to, length));
            graph[to].push_back(Edge(from, length));
            length = length * BigInteger(2);
        }
        BigInteger INF = length;
        fill(minDistance, minDistance + n, INF);
        Dijkstra(0);
        for (int i = 1; i < n; ++i) {
            if (minDistance[i] == INF) {
                cout << -1 << endl;
            } else {
                cout << minDistance[i] % MOD << endl;
            }
        }
    }
    return 0;
}