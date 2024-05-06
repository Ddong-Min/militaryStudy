#include<stdio.h>
//숫자 하나 7bit/ 8개 숫자

int main(){
    int n;
    int row, column;
    int number, start=-1;
    int arr[56]; //암호 코드는 56개의 2진수로 구성되어 있으므로
    scanf("%d", &n); //몇개의 case가 있는지 입력

    for(int i = 0; i<n; i++){
        scanf("%d %d", &row, &column); //입력되는 array의 크기 정의
        /*
        생각한 알고리즘

        첫번째로 1이 나오게 되면 해당 부분이 암호코드가 됨
        생각할점 1 : 앞에 garbage 값이 꼭 7자리라는 보장이 없음
        */
        for(int j=0; j<row; j++){ 
            for(int k=0; k<column; k++){
                scanf("%d", &number);
                if(number){
                    int s_w = number%7;
                    start = k - s_w;
                    break; 
                }
            }
            if(start != -1) break;
        }
        

    }
}   

