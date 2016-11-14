#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

bool judge(vector<int> rows, int row, int col){
	for(int i = 0; i < row; ++i){
		if(col == rows[i]){
			return false;
		} else if((row + rows[i]) == (i + col)){
			return false;
		} else if((row + col) == (i + rows[i])){
			return false;
		}
	}

	return true;
}

void print(vector<int> rows, int d){
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < d; ++j){
			if(rows[i] == j){
				cout << '*' << ' ';
			} else{
				cout << '.' << ' ';
			}
		}
		cout << endl;
	}


}

void N_queen(vector<int> rows, int d, int row){
	if(row == d){
		++ cnt;
		//cout << "find a answer : " << cnt << endl;
		//print(rows, d);
		return;
	}
	for(int i = 0; i < d; ++i){
		rows[row] = i;
		if(!judge(rows, row, i)){
			rows[row] = -1;
			continue;
		} else {
			N_queen(rows, d, row + 1);
		}
	}
}



int main() {
	int n = 8;

	vector<int> rows(n, -1);
	N_queen(rows, n, 0);
	cout << cnt << endl;

	return 0;
}