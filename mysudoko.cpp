#include<iostream>
using namespace std;

 bool canPlace(int no,int x,int y,int mat[][9]){
    for(int i = 0;i<9;i++){
        if(mat[i][y] == no || mat[x][i] == no){
            return false;
        }
    }
    int gx = (x/3)*3, gy = (y/3)*3;
    for(int i = gx; i<gx+3; i++){
        for(int j = gy; j<gy+3; j++){
            if(mat[i][j] == no){
                return false;
            }
        }
    }
    return true;
 }

bool solveSudoku(int mat[][9],int row,int col,bool marked[][9]){
    if(row == 9)
        return true;
    if(col == 9)
        return solveSudoku(mat,row+1,0,marked);
    if(marked[row][col] == false){
        for(int i = 1;i<=9;i++){
            if(canPlace(i,row,col,mat) == true){
                mat[row][col] = i;
                bool ageKaAns = solveSudoku(mat,row,col+1,marked);
                if(ageKaAns == true){
                    return true;
                }
                mat[row][col] = 0;
            }
        }
        return false;
    }else{
        return solveSudoku(mat,row,col+1,marked);
    }

}

int main(){
    bool marked[9][9] = {0};
    int mat[9][9] = {
        {0,0,9,0,0,0,7,0,0},
        {0,0,1,0,0,0,9,5,8},
        {0,0,0,0,8,7,0,0,2},
        {5,8,2,3,0,1,4,0,0},
        {1,0,7,4,0,8,3,0,5},
        {0,0,4,2,0,9,8,7,1},
        {3,0,0,8,4,0,0,0,0},
        {2,1,5,0,0,0,6,0,0},
        {0,0,8,0,0,0,5,0,0}
    };

    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(mat[i][j] != 0){
                marked[i][j] = true;
            }
        }
    }

    bool ans = solveSudoku(mat,0,0,marked);
    if(ans == false){
        cout<<"no solution exists !!!";
    }else{
        for(int i =0;i<9;i++){
            for(int j = 0;j<9;j++){
                cout<<mat[i][j]<< " ";
            }
            cout<<endl;
        }
    }
    return 0;
}
