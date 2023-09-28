#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

// 定义线段树节点
struct TreeNode {
    int left;
    int right;
    int height;
    TreeNode* left_child;
    TreeNode* right_child;

    TreeNode(int l, int r) : left(l), right(r), height(0), left_child(nullptr), right_child(nullptr) {}
};

// 更新线段树节点的高度
void updateHeight(TreeNode* node) {
    if (node) {
        int left_height = node->left_child ? node->left_child->height : 0;
        int right_height = node->right_child ? node->right_child->height : 0;
        node->height = max(left_height, right_height) + (node->right - node->left);
    }
}

// 插入一个新节点到线段树
void insert(TreeNode*& root, int left, int right, int height) {
    if (!root) {
        root = new TreeNode(left, right);
        root->height = height;
        return;
    }

    if (left >= root->right) {
        insert(root->right_child, left, right, height);
    } else if (right <= root->left) {
        insert(root->left_child, left, right, height);
    } else {
        int new_left = min(left, root->left);
        int new_right = max(right, root->right);
        insert(root->left_child, new_left, left, height);
        insert(root->right_child, right, new_right, height);
    }

    updateHeight(root);
}

// 查询线段树中的最大高度
int query(TreeNode* root, int left, int right) {
    if (!root || left >= root->right || right <= root->left) {
        return 0;
    }

    if (left <= root->left && right >= root->right) {
        return root->height;
    }

    return max(query(root->left_child, left, right), query(root->right_child, left, right));
}

vector<int> fallingSquares(vector<vector<int> >& positions) {
    vector<int> result;
    TreeNode* root = nullptr;
    int max_height = 0;

    for (const vector<int>& position : positions) {
        int left = position[0];
        int side_length = position[1];
        int right = left + side_length;

        int current_height = query(root, left, right) + side_length;
        insert(root, left, right, current_height);
        max_height = max(max_height, current_height);
        result.push_back(max_height);
    }

    return result;
}

int main() {
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        int n;
        if (!(iss >> n)) {
            break; // 无法读取整数，可能是到达文件末尾
        }

        vector<vector<int> > positions;

        for (int i = 0; i < n; ++i) {
            int left, side_length;
            cin >> left >> side_length;
            vector<int> a;
            a.push_back(left);
            a.push_back(side_length);
            positions.push_back(a);
        }

        vector<int> heights = fallingSquares(positions);

        for (int i = 0; i < heights.size(); ++i) {
            cout << heights[i];
            if (i < heights.size() - 1) {
                cout << " ";
            }
        }
        cout << endl; // 打印换行符以确保输出的格式正确
    }

    return 0;
}
