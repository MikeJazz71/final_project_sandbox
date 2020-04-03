
/*Mike Jasiczek; Into to Computer Programming; Professor Curtis George; Final Project
This is a Tic Tac Toe game, and a solution maker for the eight queen puzzle. The best part of the this project was the 
sheer amount I learned about C++ and the recursion piece.  I watched the geeksforgeeks.com video on the N Queen problem 
many times and worked with their code.Thinking about keeping my finger on the queen while I test the next 
iteration of the function to see if I could place the next queen really helped me understand recursion.  
I watched NVitanovic's tutorial on how to make a Tic Tac Toe game in C++ and got ideas from that. Just the little pieces of 
code and functions that I learned when I needed to do something and didn't know how so I went out and read people's ideas.  For example
when I was putting this all together, my text file instructions displayed for a second and than disappeared.  I knew this because 
I learned how to debug in this class. So I researched on how to get it to pause and someone said to use system("pause") but then 
others said that isn't portable and it cause cause problems in other areas.  So tried other things and those didn't work, so I went
with system("pause") for now until I can learn a better way.  It was little nuggets like that in which I leanred the most.
*/


#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#define N 8
using namespace std;
#define COL_WIDTH 500

void input(); //Thinking about Inputting the Number of Queens to play with
bool nQueenRec(int col); // Recursion Function
void drawBoard();
bool safeQueen(int row, int col); //Checks to see if the queen is safe
bool nQueenSol();// Checks for solutions then draws them
void eightQueen(); 
void board(); //Clears then prints the board
void play(); //Play Tic Tac Toe mechanics
void changePlayer(); //Changes the player between X and O
char winner(); //Checks for a winner after each play
void pause(); //Pauses so that the directions can be read 
void TicTacToe(); //Function to call to play Tic Tac Toe

char matrix[3][3] = { '1', '2' ,'3', '4', '5', '6', '7', '8','9' }; //Creates a global matrix with Chars
char player = 'X';
int Qmatrix[N][N]; // Global Varible Array



int main() {
	int choice = 0;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "WELCOME TO THE GAME PLACE\n\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "Please make a selection:\n";
	cout << "1. Tic Tac Toe\n";
	cout << "2. Eight Queen Solution Finder\n";
	cout << "3. Exit\n";
	cin >> choice;
	//cout << choice << endl;
	switch (choice) {
	case 1:
		TicTacToe();
		break;
	case 2:
		eightQueen();
		break;
	case 3:
		cout << "Now Exiting......\n";
		break;
	default:
		cout << "You choose nothing....You should leave now\n";
	}
	return 0;
}

void eightQueen()
{
	input();

	nQueenSol();

}

bool nQueenRec(int col) { //Recursive function
	if (col >= N) {
		return true; // If col = the imputted number then return true and print the solution
	}

	for (int i = 0; i < N; i++) { //Loop to see if the placement already has a queen that will threaten
		if (safeQueen(i, col)) { //Calls the function to check
			Qmatrix[i][col] = 1; //If Queen is safe place aa 1



			if (nQueenRec(col + 1)) //Recursive function and move to the next col

				return true;
			Qmatrix[i][col] = 0;// If it is threatened then pick up the queen and move to the next row.  If all rows retun false then back up a col.
		}

	}


	return false;
}

void drawBoard()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %d ", Qmatrix[i][j]); //Draws the board with either 1's or 0's

		}
		cout << endl;
	}

}

bool safeQueen(int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++) {
		if (Qmatrix[row][i]) // If there is a threat then return false
			return false;
	}


	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (Qmatrix[i][j]) { //Checks the Left Upper Diagonal. if threat return false
			return false;
		}
	}
	for (i = row, j = col; j >= 0 && i < N; i++, j--) {
		if (Qmatrix[i][j]) //Checks the lower Left Diagonal.  
			return false;
		else
			return true; //Else return that Queen is safe.
	}

}

bool nQueenSol() {
	if (nQueenRec(0) == false) {//I no solution then print no solution
		cout << "Solution doesn't exist" << endl;
		drawBoard();
		return false;
	}
	else {
		cout << "The solution is: \n\n";
		drawBoard(); //Print the solution
	}
}

void input() {
	
	cout << endl; //I want to be able to input the number of Queens 4-8
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "Welcome to Eight Queen Solution Finder Program" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	
	char input_line[COL_WIDTH + 1]; //Var for getting the text

	ifstream file_in("eightqueen.txt"); //Get file 
	if (!file_in) {
		cout << "eightqueen.txt could not be opened.\n"; // If ile can't be opened tell user

	}

	//ofstream fout("C:\\Users\\big_j\\source\\repos\\TicTacToe text file MJ\\TicTacToe text file MJ.txt"); 


	while (!file_in.eof()) { // Loop through each line until end of file or line 12
		for (int i = 1;i <= 12 && !file_in.eof(); i++) {
			file_in.getline(input_line, COL_WIDTH); //Read each line of file
			cout << input_line << endl; //Output to screen

		}




	}
	system("pause");
	
}

void board() {
	system("cls"); //Clears the screen 

	for (int i = 0; i < 3; i++) { //Loops through and prints the matrix with spaces each between each spot
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}
}

void play() {
	int num;
	cout << "It's player " << player << " turn.  Choose the number you would like to play in: ";
	cin >> num; //Choose where you want to play

	if (num == 1) { //IF they pick 1 it will check to see if someone already played there.  If not it places an X or an O
		if (matrix[0][0] == '1')
			matrix[0][0] = player;

		else {
			cout << "Spot is filled, Please try again\n"; //Checks to see if spot is filled
			play(); //New Choice
		}
	}
	else if (num == 2) {
		if (matrix[0][1] == '2') {
			matrix[0][1] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
	else if (num == 3) {
		if (matrix[0][2] == '3') {
			matrix[0][2] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
	else if (num == 4) {
		if (matrix[1][0] == '4') {
			matrix[1][0] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
	else if (num == 5) {
		if (matrix[1][1] == '5') {
			matrix[1][1] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
	else if (num == 6) {
		if (matrix[1][2] == '6') {
			matrix[1][2] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
	else if (num == 7) {
		if (matrix[2][0] == '7') {
			matrix[2][0] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
	else if (num == 8) {
		if (matrix[2][1] == '8') {
			matrix[2][1] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
	else if (num == 9) {
		if (matrix[2][2] == '9') {
			matrix[2][2] = player;
		}
		else {
			cout << "Spot is filled, Please try again\n";
			play();
		}
	}
}

void changePlayer() { //Changes the player.  Player X always starts.  After X plays its O's turn
	if (player == 'X') {
		player = 'O';
	}
	else
		player = 'X';
}

char winner() {
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') {
		return 'X'; //If three X's in a row then return X - Top
	}
	else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') {
		return 'X'; //If three X's in a row then return X - Mid
	}
	else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') {
		return 'X'; //If three X's in a row then return X - Bottom
	}
	else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') {
		return 'X'; //If three X's in a row then return X - Diagonal Right
	}
	else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') {
		return 'X'; //If three X's in a row then return X - Diagnal left
	}
	else if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') {
		return 'O';
	}
	else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') {
		return 'O';
	}
	else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') {
		return 'O';
	}
	else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') {
		return 'O';
	}
	else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') {
		return 'O';
	}
	else
		return 'D';
}

void pause() {
	cin.clear();
	cout << endl << "Press any key to continue...";
	cin.ignore();
}

void TicTacToe()
{

	cout << "Welcome to the Tic Tac Toe Game\n\n\n"; //Intro
	char input_line[COL_WIDTH + 1]; //Var for getting the text

	ifstream file_in("TicTacToe.txt"); //Get file 
	if (!file_in) {
		cout << "TicTacToe.txt could not be opened.\n"; // If ile can't be opened tell user

	}

	//ofstream fout("C:\\Users\\big_j\\source\\repos\\TicTacToe text file MJ\\TicTacToe text file MJ.txt"); 


	while (!file_in.eof()) { // Loop through each line until end of file or line 12
		for (int i = 1;i <= 12 && !file_in.eof(); i++) {
			file_in.getline(input_line, COL_WIDTH); //Read each line of file
			cout << input_line << endl; //Output to screen

		}




	}
	system("pause");
	int count = 0;
	board();
	while (true) { //Plays the game with turns
		count++;  //Count has a max of nine then declares a draw
		play();
		board();
		if (winner() == 'X') { //X is the Winner
			cout << "Player One Wins" << endl;
			break;
		}
		else if (winner() == 'O') { //O is the Winner
			cout << "Player 2 Wins" << endl;
			break;
		}
		if (winner() == 'D' && count == 9) { //Draw
			cout << "This game is a draw" << endl;
			break;
		}
		changePlayer(); //Switches players after each turn.
	}






}







