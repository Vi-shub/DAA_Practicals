#include<stdio.h>
int board[100][100];

int safe(int r,int c,int n){
    for(int i=0;i<r;i++){
        if(board[i][c] == 1)
          return 0;
    }
    for(int i=r,j=c;i>=0 && j>=0;i--,j--){
       if(board[i][j] == 1)
         return 0;
    }
    for(int i=r,j=c;i>=0 && j<n;i--,j++){
       if(board[i][j] == 1)
         return 0;
    }
    return 1;
}

void printsol(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(board[i][j]==1){
             printf("Q ");
           }
           else 
             printf("_ ");
        }
        printf("\n");
    }
    printf("\n");
}
void position(int n,int r){
    if(r>=n){
      printsol(n);
      return;
    }
    for(int i=0;i<n;i++){
        if(safe(r,i,n)){
           board[r][i] = 1;
           position(n,r+1);
           board[r][i] = 0;
        }  
    }
}

int main(){
    int n;
    printf("\nEnter the size of the board: ");
    scanf("%d",&n);
    printf("\nThe possible outputs are: \n");
    position(n,0);
}
