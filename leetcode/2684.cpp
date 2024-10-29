#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Fonction pour vérifier si on est dans les limites de la matrice
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    // Fonction de récursion avec mémoïsation
    int dfs(int row, int col, const vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[row][col] != -1) {
            return dp[row][col]; // Si on a déjà calculé cette cellule, on renvoie la valeur mémorisée
        }

        int n = grid.size();
        int m = grid[0].size();
        int maxMoves = 0;

        // Déplacement possible vers les trois directions (diagonales à droite)
        vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};

        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if (isValid(newRow, newCol, n, m) && grid[newRow][newCol] > grid[row][col]) {
                maxMoves = max(maxMoves, 1 + dfs(newRow, newCol, grid, dp)); // Récursion sur la cellule voisine
            }
        }

        dp[row][col] = maxMoves; // On mémorise le résultat
        return dp[row][col];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Tableau pour mémoriser les résultats intermédiaires
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxMoves = 0;

        // On commence par chaque cellule de la première colonne
        for (int i = 0; i < n; i++) {
            maxMoves = max(maxMoves, dfs(i, 0, grid, dp));
        }

        return maxMoves;
    }
};

int main() {

    Solution solution;

    vector<vector<int>> grid1 = {
        {2, 4, 3, 5},
        {5, 4, 9, 3},
        {3, 4, 2, 11},
        {10, 9, 13, 15}
    };

    vector<vector<int>> grid2 = {
        {3, 2, 4},
        {2, 1, 9},
        {1, 1, 7}
    };

    cout << "Maximum moves in grid1: " << solution.maxMoves(grid1) << endl;
    cout << "Maximum moves in grid2: " << solution.maxMoves(grid2) << endl;

    return 0;
}
