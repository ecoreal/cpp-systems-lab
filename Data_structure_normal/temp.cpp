#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    unordered_map<int, int> team; // 存储每个成员的团队编号
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        while (n--) {
            int member;
            cin >> member;
            team[member] = i; // 将成员编号映射到团队编号
        }
    }

    vector<queue<int>> queues(t); // 每个团队一个队列
    queue<int> order; // 存储团队的顺序
    unordered_map<int, bool> inQueue(t, false); // 记录每个团队是否在队列中

    string command;
    while (cin >> command && command != "STOP") {
        if (command == "ENQUEUE") {
            int member;
            cin >> member;
            int teamId = team[member];
            if (!inQueue[teamId]) {
                order.push(teamId);
                inQueue[teamId] = true;
            }
            queues[teamId].push(member);
        } else if (command == "DEQUEUE") {
            int teamId = order.front();
            cout << queues[teamId].front() << endl;
            queues[teamId].pop();
            if (queues[teamId].empty()) {
                order.pop();
                inQueue[teamId] = false;
            }
        }
    }

    return 0;
}

