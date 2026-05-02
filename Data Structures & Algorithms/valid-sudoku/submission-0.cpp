class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>row(9),col(9),box(9);
        for(int i = 0;i<9;++i){
            for(int j = 0;j<9;++j){
                char val = board[i][j];
                if(val == '.') continue;
                if(row[i].count(val)) return false;
                row[i].insert(val);
                if(col[j].count(val)) return false;
                col[j].insert(val);
                int boxIdx = (i/3) *3 + j/3;
                if(box[boxIdx].count(val)) return false;
                box[boxIdx].insert(val);

            }
        }
        return true;
    }
};
