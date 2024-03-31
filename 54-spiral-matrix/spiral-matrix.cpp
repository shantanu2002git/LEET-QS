class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int lef=0,rig=m-1, top=0,bot=n-1;

        int direc=1;
        vector<int>res;
        while(lef<=rig && top<=bot){
            if(direc==1){
                for(int i=lef; i<=rig; i++){
                    res.push_back(mat[top][i]);
                }
                top++;
                direc=2;
            }
            else if(direc==2){
                for(int i=top; i<=bot; i++){
                    res.push_back(mat[i][rig]);
                }
                rig--;
                direc=3;
            }
            else if(direc==3){
                for(int i=rig; i>=lef; i--){
                    res.push_back(mat[bot][i]);
                }
                bot--;
                direc=4;
            }
            else if(direc=4){
                for(int i=bot; i>=top; i--){
                    res.push_back(mat[i][lef]);
                }
                lef++;
                direc=1;
            }
        }
        return res;
    }
};