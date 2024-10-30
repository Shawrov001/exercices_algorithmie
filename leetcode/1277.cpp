#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        // Parcourir la matrice
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Si c'est un '1' et pas sur la première ligne ou première colonne
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    // Calculer le côté du plus grand carré qui se termine ici
                    matrix[i][j] = std::min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
                }
                // Ajouter ce carré à la somme totale
                count += matrix[i][j];
            }
        }
        return count;
    }
};

int main(){
    Solution solution;

    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> grid2;
    std::vector<std::vector<int>> grid3;
    std::vector<std::vector<int>> grid4;

    grid = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };

    grid2 = {
        {1,0,1},
        {1,1,0},
        {1,1,0},
    };
    
    grid3 = {
        {1}
    };

    grid4 = {
        {1,1,1},
        {1,1,1},
        {1,1,1},
    };

    std::cout << "Total number of squares of grid: " << solution.countSquares(grid) << std::endl;
    std::cout << "Total number of squares of grid2: " << solution.countSquares(grid2) << std::endl;
    std::cout << "Total number of squares of grid3: " << solution.countSquares(grid3) << std::endl;
    std::cout << "Total number of squares of grid4: " << solution.countSquares(grid4) << std::endl;
}
