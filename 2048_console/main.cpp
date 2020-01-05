#include<iostream>
#include<time.h>
using namespace std;

static int _arr[4][4] = { { 2, 4, 4, 8 },{ 2, 2, 4, 4 },{ 4, 4, 4 ,4 },{ 4, 4, 8, 2 } };
static int _randromNum[3] = {2, 4, 8};

void
_RightModule_Extra(int _row) {
	int tmp = 0;
	for (int _column = 3; _column >= 0; _column--) {
		if(_arr[_row][_column] != 0 && _column != 3)
			tmp = _column;
		while (_column + 1 <= 3 && _arr[_row][tmp] != 0 && _arr[_row][tmp + 1] == 0) {
			_arr[_row][tmp + 1] = _arr[_row][tmp];
			_arr[_row][tmp] = 0;
			++tmp;
		}
	}
}

void
_DownModule_Extra(int _column) {
	int tmp;
	for (int _row = 3; _row >= 0; _row--) {
		if (_arr[_row][_column] != 0 && _row < 3) {
			tmp = _row;
			while (_arr[tmp][_column] != 0 && _arr[tmp + 1][_column] == 0 && tmp + 1 < 4) {
				_arr[tmp + 1][_column] = _arr[tmp][_column];
				_arr[tmp][_column] = 0;
				++tmp;
			}
		}
	}
}

void
_ShowArr() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			cout << _arr[i][j] << "     ";
			if (j % 4 == 3) cout << endl << endl;
		}
}

void
_LeftModule_Extra(int _row) {
	int tmp = 0;
	for (int j = 0; j < 4; j++) {
		if (j != 0 && _arr[_row][j] != 0) {
			tmp = j;
			while (_arr[_row][j] != 0 && _arr[_row][j - 1] == 0 && j - 1 >= 0) {
				_arr[_row][j - 1] = _arr[_row][j];
				_arr[_row][j] = 0;
				--j;
			}
		}
	}
}
void
_UpModule_Extra(int _column) {
	int tmp;
	for (int i = 0; i < 4; i++) {
		if (_arr[i][_column] != 0 && i > 0) {
			tmp = i;
			while (tmp > 0 && _arr[tmp - 1][_column] == 0) {
				_arr[tmp - 1][_column] = _arr[tmp][_column];
				_arr[tmp][_column] = 0;
				--tmp;
			}
		}
	}	
}

void
_UpModule() {
	for (int _column = 0; _column < 4; _column++) {		//control column
		for (int _row = 0; _row < 4; _row++) {			//control row
			if (_arr[_row][_column] == 0) continue;
			else {
				if (_row + 1 < 4 && _arr[_row][_column] == _arr[_row + 1][_column]) {
					_arr[_row][_column] += _arr[_row + 1][_column];
					_arr[_row + 1][_column] = 0;
					++_row;
				}
			}
		}
		_UpModule_Extra(_column);
	}
	_ShowArr();
}

void
_DownModule() {
	for (int _column = 0; _column < 4; _column++) {
		for (int _row = 0; _row < 4; _row++) {
			if (_arr[_row][_column] == 0) continue;
			else {
				if (_arr[_row + 1][_column] == _arr[_row][_column] && _row + 1 < 4) {
					_arr[_row + 1][_column] += _arr[_row][_column];
					_arr[_row][_column] = 0;
					++_row;
				}
			}
		}
		_DownModule_Extra(_column);
	}
	_ShowArr();
}

void
_RightModule() {
	for (int _row = 0; _row < 4; _row++) { //control row 
		for (int _column = 3; _column >= 0; _column--) { //control column
			if (_arr[_row][_column] == 0)	continue;
			else {
				if (_column - 1 >= 0 && _arr[_row][_column - 1] == _arr[_row][_column]) {
					_arr[_row][_column] += _arr[_row][_column - 1];
					_arr[_row][_column - 1] = 0;
					--_column;
				}
			}
		}
		_RightModule_Extra(_row);
	}
	_ShowArr();
}

void
_LeftModule() {
	for(int _row = 0; _row < 4; _row++) //control row
		for (int _column = 0; _column < 4; _column++) {
			if (_arr[_row][_column] == 0) continue;
			else {
				if (_column + 1 < 4 && _arr[_row][_column + 1] == _arr[_row][_column]) {
					_arr[_row][_column] += _arr[_row][_column + 1];
					_arr[_row][_column + 1] = 0;
					++_column;
				}
			}
			_LeftModule_Extra(_row);
		}
	_ShowArr();
}

int
ForeachJudgeElementsZero(int _Apx[], int _Apy[]){
	 int ntmp = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(_arr[i][j] == 0) {
				_Apx[ntmp] = i;
				_Apy[ntmp] = j;
				++ntmp;
			}	
		}
	}
	return ntmp;
}

void 
VpdeRandom_Number_and_position(int _Apx[], int _Apy[], int ntmp) {

	ntmp = ForeachJudgeElementsZero(_Apx, _Apy);
	if (ntmp == 0) {
		cout << "Game Finished" << endl;
		return;
	}
	
	srand((unsigned)time(0));

	for(int i = 0; i < 3; i++){

		 int nrnd = 0 + rand() % 3;
		 int nPos = 0 + rand() % ntmp;
		 
		 if (_Apx[nPos] != -1 && _Apy[nPos] != -1)
		 {			
			_arr[_Apx[nPos]][_Apy[nPos]] = _randromNum[nrnd]; 
			_Apx[nPos] = -1;
			_Apy[nPos] = -1;
		 }
		// else --i;
	}
	memset(_Apx, 0, sizeof(_Apx));
	memset(_Apx, 0, sizeof(_Apy));
}

int wmain(int argc, char **argv) {
	int _APx[15] = {0};
	int _APy[15] = {0};
	char c = ' ';
	int ntmp = 0;
	_ShowArr();
	while ((c = getchar()) != '\n') {
		if (c == 'w' || c == 'W') {_UpModule();			VpdeRandom_Number_and_position(_APx, _APy, ntmp);}
		if (c == 'd' || c == 'D') {_RightModule(); 		VpdeRandom_Number_and_position(_APx, _APy, ntmp);}
		if (c == 'a' || c == 'A') {_LeftModule();		VpdeRandom_Number_and_position(_APx, _APy, ntmp);}
		if (c == 's' || c == 'S') {_DownModule();		VpdeRandom_Number_and_position(_APx, _APy, ntmp);}		
		c = getchar();
	}
	getchar();
	return 0;
}

