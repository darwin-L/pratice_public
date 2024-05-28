#include<vector>
using namespace std;

class Solution {
public:
    void dfs (vector<vector<int>>& image, int sr, int sc, int origin_color, int input_color) {
        int x_boundary = image.size();
        int y_boundary = image[0].size();
        if(
            sr<0 ||
            sc<0 ||
            sr>=x_boundary ||
            sc>= y_boundary ||
            image[sr][sc] != origin_color // this condition is for skip the cell that has been changed
        ) {
            return;
        }
        image[sr][sc] = input_color;
        dfs(image,sr,sc+1,origin_color,input_color);
        dfs(image,sr,sc-1,origin_color,input_color);
        dfs(image,sr+1,sc,origin_color,input_color);
        dfs(image,sr-1,sc,origin_color,input_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // break if color are the same, this condition work because array is filled with same color
        int origin_color = image[sr][sc];
        if(origin_color == color) return image;
        dfs(image,sr,sc,origin_color,color);
        return image;
    }
};