//행렬 테두리 회전하기

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int matrix[102][102];


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int cnt = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            matrix[i][j] = cnt;
            cnt++;
        }
    }


    for (int i = 0; i < queries.size(); i++) {
        int r1, c1, r2, c2;

        r1 = queries[i][0];
        c1 = queries[i][1];
        r2 = queries[i][2];
        c2 = queries[i][3];

        int minNum = 500000;
        int start = matrix[r1][c1];
        if (minNum >= matrix[r1][c1]) minNum = matrix[r1][c1];

        for (int j = r1 + 1; j <= r2; j++) {
            if (minNum >= matrix[j][c1]) minNum = matrix[j][c1];
            matrix[j - 1][c1] = matrix[j][c1];
        }

        for (int j = c1 + 1; j <= c2; j++) {
            if (minNum >= matrix[r2][j]) minNum = matrix[r2][j];
            matrix[r2][j - 1] = matrix[r2][j];
        }

        for (int j = r2 - 1; j >= r1; j--) {
            if (minNum >= matrix[j][c2]) minNum = matrix[j][c2];
            matrix[j + 1][c2] = matrix[j][c2];
        }

        for (int j = c2 - 1; j >= c1; j--) {
            if (minNum >= matrix[r1][j]) minNum = matrix[r1][j];
            matrix[r1][j + 1] = matrix[r1][j];
        }

        matrix[r1][c1 + 1] = start;

        answer.push_back(minNum);
    }

    return answer;
}