#include<stdio.h>
//숫자 하나 7bit/ 8개 숫자

/*
        생각한 알고리즘

        첫번째로 1이 나오게 되면 해당 부분이 암호코드가 됨
        생각할점 1 : 앞에 garbage 값이 꼭 7자리라는 보장이 없음
        생각할점 2 : 모든 수의 마지막 자리수가 1로 끝남 (2진수 기준)
        생각할점 3 : 띄어쓰기 안하면 하나의 수라고 생각함 => string으로 받아야 하나.. gets?
        즉 1이 나오고나서 마지막 1이 나올때 까지 개수에서 부족한 만큼 앞에 0을 채우면 된다.
       
        */


int main(){
    int n;
    int row, column;
    int start_row, start_column=-1;
    char number;
    scanf("%d", &n); //몇개의 case가 있는지 입력

    for(int i = 0; i<n; i++){
        scanf("%d %d", &row, &column); //입력되는 array의 크기 정의
        char code[100][100];

        for(int j=0; j<row; j++){ 
            for(int k=0; k<column; k++){
                scanf("%c", &number);
                code[j][k]=number;
                if((number-'0') && start_column==-1){
                    start_column = k;
                    start_row = j;
                }
            }
        }

        printf("row %d, colume %d", start_row, start_column);
    }
}   

/* regacy
        int end_column;
        for(int k=column-1; k>=0; k--){
            if(code[start_row][k]){
                end_column = k;
                break;
            }
        }
        int len = end_column - start_column + 1;
        
        int password[7];
        int j=0;
        for(int k=start_column - (56-len); k<=end_column; k++){
            printf("%d", code[start_row][k]);
        }

*/
