// 第一反應: 能找到頭之後從該元素的上下左右開始繼續找
// 但頭不唯一, 如何優化找頭沒有概念

#include<bits/stdc++.h>
using namespace std;
// 看過解答對於找頭優化都沒有什麼新想法, 跟flood-flow很像,除了多上找過的要checked之外
class Solution {
public:
    //pass board by reference
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
		//check if all the alphabets in the word is checked
        if(n == word.size()) return true; 
        
		//check if i and j are out of bound or if the characters aren't equal
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
		//mark as visited 
        board[i][j] = '0';
        
		//branch out in all 4 directions
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        
		//change the character back for other searches
        board[i][j] = word[n];
		
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
				//check if the characters are equal then call DFS
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        
        return false;
    }
};