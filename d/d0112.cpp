//
// Created by akio on 2021/1/12.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
        vector<vector<int>> groupItem(n + m);
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);

        vector<int> groupDegree(n + m, 0);
        vector<int> itemDegree(n, 0);

        vector<int> id;
        for (int i = 0; i < n + m; ++i) {
            id.emplace_back(i);
        }

        int leftId = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = leftId;
                ++leftId;
            }
            groupItem[group[i]].emplace_back(i);
        }

        for (int i = 0; i < n; ++i) {
            int curGroupId = group[i];
            for (auto &item:beforeItems[i]) {
                int beforeGroupId = group[item];
                if (beforeGroupId == curGroupId) {
                    itemDegree[i] += 1;
                    itemGraph[item].emplace_back(i);
                } else {
                    groupDegree[curGroupId] += 1;
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }

        vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
        if (groupTopSort.size() == 0) {
            return vector<int>{};
        }
        vector<int> res;
        for (auto &curGroupId:groupTopSort) {
            int size = groupItem[curGroupId].size();
            if (size == 0) continue;
            vector<int> itemTopSort = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
            if (itemTopSort.size() == 0) {
                return vector<int>{};
            }
            for (auto &item:itemTopSort) {
                res.emplace_back(item);
            }
        }
        return res;
    }

private:
    vector<int> topSort(vector<int> &deg, vector<vector<int>> &graph, vector<int> &items) {
        queue<int> Q;
        for (auto &item:items) {
            if (deg[item] == 0) {
                Q.push(item);
            }
        }
        vector<int> res;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            res.emplace_back(u);
            for (auto &v:graph[u]) {
                if (--deg[v] == 0) {
                    Q.push(v);
                }
            }
        }
        return res.size() == items.size() ? res : vector<int>{};
    }
};