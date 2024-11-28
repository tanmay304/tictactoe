#include<iostream>
#include<vector>
using namespace std;
void printBoard(const vector<vector<char> >&board){
cout<<"\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		cout<<board[i][j];
		if(j<2)cout<<"|";
	}
	cout<<"\n";
	if(i<2)cout<<"---------\n";
}
}
bool checkWin(const vector<vector<char> >&board,char player){
	for(int i=0;i<3;i++){
		if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
		return true;
		if(board[0][1]==player&&board[1][i]==player&&board[2][i]==player)
		return true;
	}
	if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player)
	return true;
	if(board[0][2]==player&&board[1][1]==player&&board[2][0]==player)
	return true;
	return false;
	
}
bool checkDraw(const vector<vector<char> >&board){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j] == 'X'){
				return false;
			}
		}
	}
	return true;
}
bool isValidMove(const vector<vector<char> >&board,int move){
	return(move>=1&&move<=9&&board[(move-1)/3][(move-1)%3]=='X');
}
void getMove(int &move, char player, const vector<vector<char> >&board){
	do{
		cout<<"Player"<<player<<"enter you move(1-9):";
		cin>>move;
		if(!isValidMove(board,move)){
			cout<<"Invalid move!! Try again.\n";
		}
	}while(!isValidMove(board,move));
}
void playGame(){
	vector<vector<char> >board(3,vector<char>(3,'X'));
	char currentPlayer='X';
	while(true){
		printBoard(board);
		getMove(move,currentPlayer,board);
		board[(move-1)/3][(move-1)%3]=currentPlayer;
		
		if(checkWin(board,currentPlayer)){
			printBoard(board);
			cout<<"Player"<<currentPlayer<<"wins!!\n";
			break;
		}
		if(checkDraw(board)){
			printBoard(board);
			cout<<"it's a draw!!\n";
			break;
		}
		currentPlayer=(currentPlayer=='X')?'O':'X';
		
	}
	char playAgain;
	cout<<"Do you want to play again?(y/n):";
	cin>>playAgain;
	if(playAgain=='y'||playAgain=='Y'){
		playGame();
	}
}
int main(){
	playGame();
	return 0;
}

