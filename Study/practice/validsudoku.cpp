#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool isValidSudoku(vector<vector<char>>& board) {
//         // use this variable to check e
//         vector<int> count(9);
//         for(int i = 0; i < 9; ++i)
//         {
//             // Check Rule 1 : Each row must contain the digits 1-9 without repetition
//             fill(count.begin(), count.end(), 0);
//             for(int j = 0; j < 9; ++j)
//             {
//                 if(board[i][j] != '.')
//                 {
//                     int idx = board[i][j] - '0' - 1; // char to int and get idx
//                     if(count[idx] == 0) count[idx] += 1;
//                     else return false;
//                 }
//             }
//             // Check Rule 2 : Each column must contain the digits 1-9 without repetition
//             fill(count.begin(), count.end(), 0);
//             for(int j = 0; j < 9; ++j)
//             {
//                 if(board[j][i] != '.')
//                 {
//                     int idx = board[j][i] - '0' - 1; // char to int and get idx
//                     if(count[idx] == 0) count[idx] += 1;
//                     else return false;
//                 }
//             }
//         }
//         // Check Rule 3 : Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//         for(int r = 0; r < 3; ++r)
//         {
//             for(int c = 0; c < 3; ++c)
//             {
//                 fill(count.begin(), count.end(), 0);
//                 for (int i = r * 3; i < r * 3 + 3; ++i)
//                     for (int j = c * 3; j < c * 3 + 3; ++j)
//                     {
//                         if(board[i][j] != '.')
//                         {
//                             int idx = board[i][j] - '0' - 1; // char to int and get idx
//                             if(count[idx] == 0) count[idx] += 1;
//                             else return false;
//                         }
//                     }
                        
//             }   
//         }
//         return true;
//     }
int validsudokumain()
{
    return 0;
}