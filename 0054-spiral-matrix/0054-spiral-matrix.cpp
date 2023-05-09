class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        int left=0,right=m-1;
        int top=0,down=n-1;
        int dir=0;   // for left to right
        vector<int >v;
        while (left<=right && top <=down ){
            //print left to right
            if(dir==0){
                for(int i=left; i<=right; i++){
                    v.push_back(mat[top][i]);
                }
                top++;
                dir=1;
            }
            // print top to down
            else if(dir==1){
                for(int i=top; i<=down ; i++){
                    v.push_back(mat[i][right]);
                }
                right--;
                dir=2;
            }
            // print right to left
            else if(dir==2){
                for(int i=right; i>=left ; i--){
                    v.push_back(mat[down][i]);
                }
                down--;
                dir=3;
            }
            // print down to top
            
            else if(dir==3){
                for(int i=down; i>=top; i--){
                    v.push_back(mat[i][left]);
                }
                left++;
                dir=0;
            }
            
            
        }
        return v;
    }
};