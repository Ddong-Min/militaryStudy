/*
        생각한 알고리즘

        첫번째로 1이 나오게 되면 해당 부분이 암호코드가 됨
        생각할점 1 : 앞에 garbage 값이 꼭 7자리라는 보장이 없음
        생각할점 2 : 모든 수의 마지막 자리수가 1로 끝남 (2진수 기준)
        생각할점 3 : 띄어쓰기 안하면 하나의 수라고 생각함 => string으로 받아야 하나.. gets?
        즉 1이 나오고나서 마지막 1이 나올때 까지 개수에서 부족한 만큼 앞에 0을 채우면 된다.
       
        */


#include<iostream>

using namespace std;

int main(int argc, char** argv)
{

	int test_case;
	int T;
    int row, column;
	int start_row,end_column, start_column=-1;
	char c;
	int code[100][100];
	int realCode[8];
	int numbers[10][7]={{0,0,0,1,1,0,1},{0,0,1,1,0,0,1}, {0,0,1,0,0,1,1}, {0,1,1,1,1,0,1}, {0,1,0,0,0,1,1},{0,1,1,0,0,0,1}, {0,1,0,1,1,1,1}, {0,1,1,1,0,1,1}, {0,1,1,0,1,1,1},{0,0,0,1,0,1,1}};
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> row >> column;
		int start_row,end_column, start_column=-1;
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				cin >> c;
				code[i][j] = c-'0';
				if(code[i][j]==1 && start_column == -1){
					start_column = j;
					start_row = i;
				}
			}
		}
		for(int j=column-1; j>=0; j--){
			if(code[start_row][j] == 1){
				end_column = j;
				break;
			}
		}
		int len = end_column - start_column + 1;
		for(int j=start_column-(56-len);j<=end_column; j++){
		}
		int k;
		for(int i=0; i<8; i++){
			int position = i*7+start_column-(56-len);
			for(int j=0; j<10; j++){
				for(k=0; k<7; k++){
					if(code[start_row][position+k] != numbers[j][k]){
						break;
					}
				}
				if(k==7) realCode[i]=j;
			}
		}
		int sum=0;
		for(int i=0; i<8; i++){
			sum+=realCode[i]*(((i+1)%2)*2+1);
		}
		if(!(sum%10)){
			sum=0;
			for(int i=0; i<8; i++){
				sum+=realCode[i];
			}
			cout << "#" << test_case << " " << sum << endl;
		}
		else{
			cout << "#" << test_case << "0" << sum << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
	
}
