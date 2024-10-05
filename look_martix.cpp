#include <iostream>
#include <vector>

using namespace std;

// 在矩阵的行中查找目标值所在的行
int look_r(const vector<vector<int>>& matrix, int target, int r_s, int r_l, int c) {
    // 目标值位于行与行之间或小于第一行的第一个元素或者大于最后一行的最后一个元素，则返回-1
    if (r_s > r_l) {
        return -1;
    }
    int index = r_s + (r_l - r_s) / 2; // 计算中间行索引
    // 检查目标值是否在当前行的范围内
    if (target >= matrix[index][0] && target <= matrix[index][c - 1]) {
        return index;
    } else if (target < matrix[index][0]) {
        return look_r(matrix, target, r_s, index - 1, c); // 在上半部分继续查找
    } else {
        return look_r(matrix, target, index + 1, r_l, c); // 在下半部分继续查找
    }
}

// 在指定的行中查找目标值所在的列
bool look_c(const vector<vector<int>>& matrix, int target, int c_s, int c_l, int r) {
    // 目标值位于列与列之间或小于第一列的第一个元素或者大于最后一列的最后一个元素
    if (c_s > c_l) {
        return false;
    }
    int index = c_s + (c_l - c_s) / 2; // 计算中间列索引
    if (target == matrix[r][index]) {
        return true; // 找到目标值
    } else if (target < matrix[r][index]) {
        return look_c(matrix, target, c_s, index - 1, r); // 在左半部分继续查找
    } else {
        return look_c(matrix, target, index + 1, c_l, r); // 在右半部分继续查找
    }
}

// 在矩阵中查找目标值
bool look_in_matrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false; // 如果矩阵为空，返回False
    }
    int r = matrix.size(); // 矩阵的行数
    int c = matrix[0].size(); // 矩阵的列数
    int row = look_r(matrix, target, 0, r - 1, c); // 查找目标值所在的行
    if (row == -1) {
        return false; // 如果未找到行，返回False
    }
    return look_c(matrix, target, 0, c - 1, row); // 在找到的行中查找目标值
}

// 测试
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 31;
    cout << (look_in_matrix(matrix, target) ? "True" : "False") << endl; 
    return 0;
}