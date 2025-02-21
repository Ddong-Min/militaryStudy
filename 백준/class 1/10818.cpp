#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int max=0, min=0;
    for(int i=0; i<n; i++){
        if(arr[max] < arr[i]) max = i;
        if(arr[min] > arr[i]) min = i;
    }
    printf("%d %d\n", arr[min], arr[max]);
    
}

/* 나중에 참고하기
#include <iostream>

#define SZ 1 << 17

inline int read_int(char* buf, int* idx) {
	int ret = 0;
	char tmp = buf[*idx] & 31;
	bool sign = 0;

	if (!tmp) {
		fread(buf, 1, SZ - 1, stdin);
		*idx = 0;
		tmp = buf[*idx] & 31;
	}

	if (tmp == 0b1101) {
		sign = 1;
		tmp = buf[++(*idx)] & 31;
	}

	while (true) {
		if (tmp & 16) {
			ret = (ret << 1) + (ret << 3);
			ret += (tmp & 15);
		}
		else if (*idx >= SZ - 1) {
			buf[fread(buf, 1, SZ - 1, stdin)] = 0;
			*idx = 0;
			if (buf[*idx] == ' ') {
				(*idx)++;
				return sign ? -ret : ret;
			}
			tmp = buf[(*idx)] & 31;
			continue;
		}
		else {
			break;
		}

		tmp = buf[++(*idx)] & 31;
	}

	(*idx)++;
	
	if (sign) {
		return ret * (-1);
	}
	else {
		return ret;
	}
}

int main() {
	char buf[SZ] = { 0, };
	int n = 0, idx = 0, max_num = -1000001, min_num = 1000001;

	buf[fread(buf, 1, SZ - 1, stdin)] = 0;

	n = read_int(buf, &idx);
	for (int i = 0; i < n; i++) {
		int tmp = read_int(buf, &idx);
		if (max_num < tmp) {
			max_num = tmp;
		}
		if (min_num > tmp) {
			min_num = tmp;
		}
	}

	printf("%d %d\n", min_num, max_num);

	return 0;
}
*/