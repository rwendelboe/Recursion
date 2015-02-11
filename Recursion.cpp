#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int CountCannonBalls(int levels);

void PrintBinary(int num);

int ComputeSumOfDigits(int num);

bool MazeSearch(int x, int y, char** mazeBoard, int r, int c, vector <string>& reverse);

int main()
{
	vector < string > reverse;
	int mazeBoardSizeRow;
	int mazeBoardSizeCol;
	int startx;
	int starty;
	cout<< "Inside the Count CannonBalls: " << endl;
	cout<< CountCannonBalls(4) << endl;
	cout<< endl;
	cout<< "Inside the Print Binary: " << endl;
	PrintBinary(13);
	cout<< endl;
	cout<< endl;
	cout<< "Inside the Compute Sum of Digits: " << endl; 
	cout<< ComputeSumOfDigits(1812) << endl;
	cout<< endl;
	cout<< endl;
	ifstream file;
	file.open("maze.txt");
	if(!file)
	{
		cout<< "File didn't open" << endl;
	}
	file>>mazeBoardSizeRow;
	file>>mazeBoardSizeCol;
	file>>startx;
	file>>starty;
	
	char** mazeBoard = new char*[mazeBoardSizeRow];
	for (int i = 0; i<mazeBoardSizeRow; i++)
	{
		mazeBoard[i] = new char [mazeBoardSizeCol];
		for (int j = 0; j<mazeBoardSizeCol; j++)
		{
			file>>mazeBoard[i][j];
		}

	}
	mazeBoard[startx][starty] = 's';
	MazeSearch(startx, starty, mazeBoard, mazeBoardSizeRow, mazeBoardSizeCol, reverse);
	
	for(int i= (reverse.size() -1); i>= 0; i--)
		{
			cout<< reverse[i] << endl;

		}
	/*This is first maze i used:
		11 10
		9 4
		XXXXXXXXXX
		XX...tX..X
		XX.XXXX.XX 
		XX.......X
		XXXXXXX.XX
		X....XX.XX
		X.XX.....X
		X...XX.XXX
		XXX..XXXXX
		XXXX....XX
		XXXXXXXXXX
     */
	/*	
		This is my second maze used:
		13 12
		12 2
		XXXXXXXXXXXX
		X.X.X.....XX
		XX.XXtX.X..X 
		XX..XX.X.X.X
		XX.XXXX....X
		X....XX.X.XX
		X.XX.....X.X
		X...XX.X.X.X
		XXX..X.....X
		XXXX....X.XX
		XX...X.....X
		X..XX..XX..X
		XXXXXXXXXXXX
		*/

	//for (int row = 0; row < mazeBoardSizeRow; row++) //////////////TO TEST PRINT
	//{
	//	for (int col = 0; col < mazeBoardSizeCol; col++)
	//	{
	//		cout << mazeBoard[row][col];
	//	}
	//	cout<< endl;
	//}

	system ("pause");
	return 0;
}

int CountCannonBalls(int levels)
{   
	if (levels == 1) return 1;
	int count = levels * levels;
	return count + CountCannonBalls(levels-1);
}

void PrintBinary(int num)
{
	if(num==0) return;
	
	PrintBinary(num/2);
	cout<< num%2;
}

int ComputeSumOfDigits(int num)
{
	if(num == 0) return 0;
	return num%10 + ComputeSumOfDigits(num/10);
}

bool MazeSearch(int x, int y, char** mazeBoard, int mazeBoardSizeRow, int mazeBoardSizeCol, vector <string>& reverse )
{

	if( x > mazeBoardSizeRow) return false;
	if( y > mazeBoardSizeCol) return false;

	

	if(mazeBoard[x][y] == 't') 
	{
			//cout<<"FOUND!!!!" << endl;
		reverse.insert(reverse.begin(), "FOUND!");
		return true;
	}

	if(mazeBoard[x][y] == 'X') return false;
	if(mazeBoard[x][y] == '+') return false;
	if(mazeBoard[x][y] == '.' || mazeBoard[x][y] == 's') mazeBoard[x][y] = '+';

	//cout<< "Path to treasure: " << x << ","<< y << endl;
	string pathName;
	pathName = "Path to treasure: " + to_string(x);
	pathName += "," + to_string(y);
	reverse.push_back(pathName);

	if (MazeSearch(x-1,y, mazeBoard, mazeBoardSizeRow, mazeBoardSizeCol, reverse) == true) return true;
	if (MazeSearch(x,y-1, mazeBoard, mazeBoardSizeRow, mazeBoardSizeCol, reverse) == true) return true;
	if (MazeSearch(x+1,y, mazeBoard, mazeBoardSizeRow, mazeBoardSizeCol, reverse) == true) return true;
	if (MazeSearch(x,y+1, mazeBoard, mazeBoardSizeRow, mazeBoardSizeCol, reverse) == true) return true;
	if(mazeBoard[x][y] == '+') mazeBoard[x][y] = '#';
	
	
	return false;
}