#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				board[i][j] += countAdjacent(board, i, j) * 10;
			}
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				int adj = board[i][j] / 10;
				if (adj < 2 || adj > 3) {
					board[i][j] = 0;
				} else if (adj == 3) {
					board[i][j] = 1;
				} else {
					board[i][j] = board[i][j] % 10;
				}
			}
		}
    }

	int countAdjacent(const vector<vector<int>>& board, int x, int y) {
		const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
		const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

		int count = 0;
		for (int i = 0; i < 8; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size()) {
				continue;
			}
			if (board[new_x][new_y] % 10 == 1) {
				count++;
			}
		}

		return count;
	}
};
