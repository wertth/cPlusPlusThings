#include <iostream>
#include <vector>
#include <algorithm>
#include "set"

using namespace std;

struct Building {
    int left;
    int right;
    int height;

    Building(int l, int r, int h) : left(l), right(r), height(h) {}
};

vector<pair<int, int>> getSkyline(vector<Building>& buildings) {
    vector<pair<int, int>> result;
    vector<pair<int, int>> heights;  // 存储所有关键点的高度信息

    for (const Building& building : buildings) {
        heights.emplace_back(building.left, -building.height);  // 左端点高度为负数表示开始
        heights.emplace_back(building.right, building.height);  // 右端点高度为正数表示结束
    }

    sort(heights.begin(), heights.end());  // 按x坐标排序

    multiset<int> heightSet;  // 用于跟踪当前高度
    heightSet.insert(0);
    int prevMaxHeight = 0;

    for (const pair<int, int>& point : heights) {
        if (point.second < 0) {  // 左端点，高度入集合
            heightSet.insert(-point.second);
        } else {  // 右端点，高度出集合
            heightSet.erase(heightSet.find(point.second));
        }

        int currentMaxHeight = *heightSet.rbegin();

        if (currentMaxHeight != prevMaxHeight) {
            result.emplace_back(point.first, currentMaxHeight);
            prevMaxHeight = currentMaxHeight;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<Building> buildings;

    for (int i = 0; i < n; ++i) {
        int left, right, height;
        cin >> left >> right >> height;
        buildings.emplace_back(left, right, height);
    }

    vector<pair<int, int>> skyline = getSkyline(buildings);

    for (const pair<int, int>& point : skyline) {
        cout << point.first << " " << point.second << endl;
    }

    return 0;
}
