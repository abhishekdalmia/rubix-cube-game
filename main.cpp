//author: abhishekdalmia

#include <iostream>
#include <windows.h>

using namespace std;

//the function gotoxy is used to place the cursour at a desired position and is defined below ->
void gotoxy(short int col, short int row) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {col, row};
	SetConsoleCursorPosition(hStdout, position);

}

//the function printFaceAt is used to print a particular face with its top left corner at (x, y) ->
void printFaceAt(string face, short int x, short int y);

//the function printBoard is the function that prints the layout of the board and asks for move ->
void printBoard();

//the function equateRefVariables copies the contents of face variables into ref face variables.
void equateRefVariables();

//the following six functions  are the face move functions ->
void Front();
void Right();
void Left();
void Top();
void Down();
void Back();
void w();
void a();
void s();
void d();
void q();
void p();

//the function decideAndCallTheMove takes in the move entered by the user and calls the respective function ->
void decideAndCallTheMove(string move);

//the following string variables hold the colors of the faces to be printed ->
string frontFace, rightFace, leftFace, topFace, downFace, backFace;

//the following string variables hold the colors of the faces to be used while a move is performed ->
string refFrontFace, refRightFace, refLeftFace, refTopFace, refDownFace, refBackFace;

int main() {
	system("cls");

	cout << "This is a rubix cube simulator.\n";
	system("pause");
	system("cls");
	cout << "Instruction to enter the colors of the faces . . .\n";
	cout << "Suppose the front face of your rubix cube looks like . . .\n\n\n";
	cout << " w | w | r \n";
	cout << "-----------\n";
	cout << " b | b | y \n";
	cout << "-----------\n";
	cout << " r | r | y \n";
	cout << "\n\nThen you have to enter in the format -> wwrbbyrry\n";
	system("pause");
	system("cls");

	cout << "\n\nHere is the list of legal moves ->\n\n\n";
	cout << "f : rotates the front face by 90 degrees clockwise.\n";
	cout << "r : rotates the right face by 90 degrees clockwise.\n";
	cout << "l : rotates the left face by 90 degrees clockwise.\n";
	cout << "t : rotates the top face by 90 degrees clockwise.\n";
	cout << "d : rotates the down face by 90 degrees clockwise.\n";
	cout << "b : rotates the back face by 90 degrees clockwise.\n";
	cout << "2f : rotates the front face by 180 degrees.\n";
	cout << "2r : rotates the right face by 180 degrees.\n";
	cout << "2l : rotates the left face by 180 degrees.\n";
	cout << "2t : rotates the top face by 180 degrees.\n";
	cout << "2d : rotates the down face by 180 degrees.\n";
	cout << "2b : rotates the back face by 180 degrees.\n";
	cout << "if : rotates the front face by 90 degrees anti-clockwise.\n";
	cout << "ir : rotates the right face by 90 degrees anti-clockwise.\n";
	cout << "il : rotates the left face by 90 degrees anti-clockwise.\n";
	cout << "it : rotates the top face by 90 degrees anti-clockwise.\n";
	cout << "id : rotates the down face by 90 degrees anti-clockwise.\n";
	cout << "ib : rotates the back face by 90 degrees anti-clockwise.\n";
	cout << "\n\n";
	cout << "w : change the view of the cube and make the down face your front face.\n";
	cout << "a : change the view of the cube and make the right face your front face.\n";
	cout << "d : change the view of the cube and make the left face your front face.\n";
	cout << "s : change the view of the cube and make the top face your front face.\n";
	cout << "\n\n";
	cout << "q : rotate the cube 90 degrees anti-clockwise, keeping the frontFace same.\n";
	cout << "     the leftFace comes on the down side\n";
	cout << "     the downFace comes on the right side\n";
	cout << "     the rightFace comes on the top side\n";
	cout << "     the topFace comes on the left side\n";
	cout << "p : rotate the cube 90 degrees clockwise, keeping the frontFace same.\n";
	cout << "     the leftFace comes on the top side\n";
	cout << "     the downFace comes on the left side\n";
	cout << "     the rightFace comes on the down side\n";
	cout << "     the topFace comes on the right side\n\n";
	cout << "` -> to exit\n\n\n";
	system("pause");
	system("cls");

	cout << "\nEnter the colors of the frontFace ->\n\n";
	cin >> frontFace;
	cout << "\nEnter the colors of the rightFace ->\n\n";
	cin >> rightFace;
	cout << "\nEnter the colors of the leftFace ->\n\n";
	cin >> leftFace;
	cout << "\nEnter the colors of the topFace ->\n\n";
	cin >> topFace;
	cout << "\nEnter the colors of the downFace ->\n\n";
	cin >> downFace;
	cout << "\nEnter the colors of the backFace ->\n\n";
	cin >> backFace;

	refFrontFace = frontFace;
	refRightFace = rightFace;
	refLeftFace = leftFace;
	refTopFace = topFace;
	refDownFace = downFace;
	refBackFace = backFace;

	printBoard();

	//the variable move holds the move as entered by the user.
	string move;

	do {
		cin >> move;
		decideAndCallTheMove(move);
		printBoard();

	} while (move != "`");

	gotoxy(5, 41);
	cout << "Since you entered -- ` -- we are aborting.";
	gotoxy(5, 42);
	system("pause");

	system("cls");

	return 0;
}

void decideAndCallTheMove(string move) {

	if (move == "f") {
		Front();
	}

	else if (move == "r") {
		Right();
	}

	else if (move == "l") {
		Left();
	}

	else if (move == "t") {
		Top();
	}

	else if (move == "d") {
		Down();
	}


	else if (move == "b") {
		Back();
	}

	else if (move == "f2") {
		Front();
		Front();
	}

	else if (move == "r2") {
		Right();
		Right();
	}

	else if (move == "l2") {
		Left();
		Left();
	}

	else if (move == "t2") {
		Top();
		Top();
	}

	else if (move == "d2") {
		Down();
		Down();
	}


	else if (move == "b2") {
		Back();
		Back();
	}

	else if (move == "fi") {
		Front();
		Front();
		Front();
	}

	else if (move == "ri") {
		Right();
		Right();
		Right();
	}

	else if (move == "li") {
		Left();
		Left();
		Left();
	}

	else if (move == "ti") {
		Top();
		Top();
		Top();
	}

	else if (move == "di") {
		Down();
		Down();
		Down();
	}

	else if (move == "bi") {
		Back();
		Back();
		Back();
	}

	else if (move == "w") {
		w();
	}

	else if (move == "s") {
		s();
	}

	else if (move == "a") {
		a();
	}

	else if (move == "d") {
		d();
	}

	else if (move == "q") {
		q();
	}

	else if (move == "p") {
		p();
	}

	//the following else case denotes an illegal move. The program simple does nothing.
	else {
		return;
	}

}

//any face move is executed in the following manner ->
//look at that face and then turn clockwise.
//the following six function definitions are of the moves(front, right, left, top, down, back) ->
void Front() {

	//front corner piece changes ->
	frontFace[0] = refFrontFace[6];
	frontFace[2] = refFrontFace[0];
	frontFace[6] = refFrontFace[8];
	frontFace[8] = refFrontFace[2];

	//front side piece changes ->
	frontFace[1] = refFrontFace[3];	
	frontFace[3] = refFrontFace[7];
	frontFace[5] = refFrontFace[1];	
	frontFace[7] = refFrontFace[5];

	//top piece changes ->
	topFace[6] = refLeftFace[8];
	topFace[7] = refLeftFace[5];
	topFace[8] = refLeftFace[2];

	//right piece changes ->
	rightFace[0] = refTopFace[6];
	rightFace[3] = refTopFace[7];
	rightFace[6] = refTopFace[8];

	//down piece changes ->
	downFace[0] = refRightFace[6];
	downFace[1] = refRightFace[3];
	downFace[2] = refRightFace[0];

	//left piece changes ->
	leftFace[2] = refDownFace[0];
	leftFace[5] = refDownFace[1];
	leftFace[8] = refDownFace[2];

	equateRefVariables();
	
}
void Right() {

	//right corner piece changes ->
	rightFace[0] = refRightFace[6];
	rightFace[2] = refRightFace[0];
	rightFace[6] = refRightFace[8];
	rightFace[8] = refRightFace[2];

	//right side piece changes ->
	rightFace[1] = refRightFace[3];	
	rightFace[3] = refRightFace[7];
	rightFace[5] = refRightFace[1];	
	rightFace[7] = refRightFace[5];

	//top piece changes ->
	topFace[8] = refFrontFace[8];
	topFace[5] = refFrontFace[5];
	topFace[2] = refFrontFace[2];

	//back piece changes ->
	backFace[0] = refTopFace[8];
	backFace[3] = refTopFace[5];
	backFace[6] = refTopFace[2];

	//down piece changes ->
	downFace[2] = refBackFace[6];
	downFace[5] = refBackFace[3];
	downFace[8] = refBackFace[0];

	//front piece changes ->
	frontFace[2] = refDownFace[2];
	frontFace[5] = refDownFace[5];
	frontFace[8] = refDownFace[8];

	equateRefVariables();	

}
void Left() {
	
	//left corner piece changes ->
	leftFace[0] = refLeftFace[6];
	leftFace[2] = refLeftFace[0];
	leftFace[6] = refLeftFace[8];
	leftFace[8] = refLeftFace[2];

	//left side piece changes ->
	leftFace[1] = refLeftFace[3];
	leftFace[3] = refLeftFace[7];
	leftFace[5] = refLeftFace[1];
	leftFace[7] = refLeftFace[5];

	//top piece changes ->
	topFace[0] = refBackFace[8];
	topFace[3] = refBackFace[5];
	topFace[6] = refBackFace[2];

	//front piece changes ->
	frontFace[0] = refTopFace[0];
	frontFace[3] = refTopFace[3];
	frontFace[6] = refTopFace[6];

	//down piece changes ->
	downFace[0] = refFrontFace[0];
	downFace[3] = refFrontFace[3];
	downFace[6] = refFrontFace[6];

	//back piece changes ->
	backFace[2] = refDownFace[6];
	backFace[5] = refDownFace[3];
	backFace[8] = refDownFace[0];

	equateRefVariables();	

}
void Top() {
	//top corner piece changes ->
	topFace[0] = refTopFace[6];
	topFace[2] = refTopFace[0];
	topFace[6] = refTopFace[8];
	topFace[8] = refTopFace[2];

	//top side piece changes ->
	topFace[1] = refTopFace[3];
	topFace[3] = refTopFace[7];
	topFace[5] = refTopFace[1];
	topFace[7] = refTopFace[5];

	//front piece changes ->
	frontFace[0] = refRightFace[0];
	frontFace[1] = refRightFace[1];
	frontFace[2] = refRightFace[2];

	//left piece changes ->
	leftFace[0] = refFrontFace[0];
	leftFace[1] = refFrontFace[1];
	leftFace[2] = refFrontFace[2];

	//back piece changes ->
	backFace[0] = refLeftFace[0];
	backFace[1] = refLeftFace[1];
	backFace[2] = refLeftFace[2];

	//right piece changes ->
	rightFace[0] = refBackFace[0];
	rightFace[1] = refBackFace[1];
	rightFace[2] = refBackFace[2];

	equateRefVariables();	

}
void Down() {
	//down corner piece changes ->
	downFace[0] = refDownFace[6];
	downFace[2] = refDownFace[0];
	downFace[6] = refDownFace[8];
	downFace[8] = refDownFace[2];

	//down side piece changes ->
	downFace[1] = refDownFace[3];
	downFace[3] = refDownFace[7];
	downFace[5] = refDownFace[1];
	downFace[7] = refDownFace[5];

	//front piece changes ->
	frontFace[6] = refLeftFace[6];
	frontFace[7] = refLeftFace[7];
	frontFace[8] = refLeftFace[8];

	//left piece changes ->
	leftFace[6] = refBackFace[6];
	leftFace[7] = refBackFace[7];
	leftFace[8] = refBackFace[8];

	//back piece changes ->
	backFace[6] = refRightFace[6];
	backFace[7] = refRightFace[7];
	backFace[8] = refRightFace[8];

	//right piece changes ->
	rightFace[6] = refFrontFace[6];
	rightFace[7] = refFrontFace[7];
	rightFace[8] = refFrontFace[8];

	equateRefVariables();	

}
void Back() {
	//back corner piece changes ->
	backFace[0] = refBackFace[6];
	backFace[2] = refBackFace[0];
	backFace[6] = refBackFace[8];
	backFace[8] =refBackFace[2];

	//back side piece changes ->
	backFace[1] = refBackFace[3];
	backFace[3] = refBackFace[7];
	backFace[5] = refBackFace[1];
	backFace[7] = refBackFace[5];

	//top piece changes ->
	frontFace[0] = refRightFace[2];
	frontFace[1] = refRightFace[5];
	frontFace[2] = refRightFace[8];

	//right piece changes ->
	rightFace[2] = refDownFace[8];
	rightFace[5] = refDownFace[7];
	rightFace[8] = refDownFace[6];
	
	//down piece changes ->
	downFace[6] = refLeftFace[0];
	downFace[7] = refLeftFace[3];
	downFace[8] = refLeftFace[6];

	//left piece changes ->
	leftFace[0] = refTopFace[2];
	leftFace[3] = refTopFace[1];
	leftFace[6] = refTopFace[0];

	equateRefVariables();	

}

void w() {
	topFace = refFrontFace;
	frontFace = refDownFace;
	//the following for loop is to assign the respective values to the down and the back face
	for (int i = 0; i < 9; i++) {
		downFace[i] = refBackFace[8 - i];
		backFace[i] = refTopFace[8 - i];
	}
	//following for loop is to assign the respective values to the corner and side pieces
	int corner[] = {0, 2, 8, 6};
	int side[] = {1, 5, 7, 3};
	for (int i = 0; i < 4; i++) {
		leftFace[corner[i]] = refLeftFace[corner[(i + 1) % 4]];
		leftFace[side[i]] = refLeftFace[side[(i + 1) % 4]];
		rightFace[corner[i]] = refRightFace[(i - 1) == -1 ? (3) : (i - 1)];
		rightFace[side[i]] = refRightFace[(i - 1) == -1 ? (3) : (i - 1)];
	}

	equateRefVariables();

}

void s() {
	downFace = refFrontFace;
	frontFace = refTopFace;
	//the following for loop is to assign the respective values to the top and the back face
	for (int i = 0; i < 9; i++) {
		topFace[i] = refBackFace[8 - i];
		backFace[i] = refDownFace[8 - i];
	}
	//following for loop is to assign the respective values to the corner and side pieces
	int corner[] = {0, 2, 8, 6};
	int side[] = {1, 5, 7, 3};
	for (int i = 0; i < 4; i++) {
		rightFace[corner[i]] = refRightFace[corner[(i + 1) % 4]];
		rightFace[side[i]] = refRightFace[side[(i + 1) % 4]];
		leftFace[corner[i]] = refLeftFace[(i - 1) == -1 ? (3) : (i - 1)];
		leftFace[side[i]] = refLeftFace[(i - 1) == -1 ? (3) : (i - 1)];
	}

	equateRefVariables();

}

void a() {
	frontFace = refRightFace;
	rightFace = refBackFace;
	backFace = refLeftFace;
	leftFace = refFrontFace;
	//following for loop is to assign the respective values to the corner and side pieces
	int corner[] = {0, 2, 8, 6};
	int side[] = {1, 5, 7, 3};
	for (int i = 0; i < 4; i++) {
		downFace[corner[i]] = refDownFace[corner[(i + 1) % 4]];
		downFace[side[i]] = refDownFace[side[(i + 1) % 4]];
		topFace[corner[i]] = refTopFace[(i - 1) == -1 ? (3) : (i - 1)];
		topFace[side[i]] = refTopFace[(i - 1) == -1 ? (3) : (i - 1)];
	}

	equateRefVariables();

}

void d() {
	frontFace = refLeftFace;
	rightFace = refFrontFace;
	backFace = refRightFace;
	leftFace = refBackFace;
	//following for loop is to assign the respective values to the corner and side pieces
	int corner[] = {0, 2, 8, 6};
	int side[] = {1, 5, 7, 3};
	for (int i = 0; i < 4; i++) {
		topFace[corner[i]] = refTopFace[corner[(i + 1) % 4]];
		topFace[side[i]] = refTopFace[side[(i + 1) % 4]];
		downFace[corner[i]] = refDownFace[(i - 1) == -1 ? (3) : (i - 1)];
		downFace[side[i]] = refDownFace[(i - 1) == -1 ? (3) : (i - 1)];
	}	

	equateRefVariables();

}

void q() {	
	//following for loop is to assign the respective values to the corner and side pieces
	int corner[] = {0, 2, 8, 6};
	int side[] = {1, 5, 7, 3};
	for (int i = 0; i < 4; i++) {
		frontFace[corner[i]] = refFrontFace[corner[(i + 1) % 4]];
		frontFace[side[i]] = refFrontFace[side[(i + 1) % 4]];
		backFace[corner[i]] = refBackFace[(i - 1) == -1 ? (3) : (i - 1)];
		backFace[side[i]] = refBackFace[(i - 1) == -1 ? (3) : (i - 1)];

		topFace[corner[i]] = refRightFace[corner[(i + 1) % 4]];
		topFace[side[i]] = refRightFace[side[(i + 1) % 4]];
		rightFace[corner[i]] = refDownFace[corner[(i + 1) % 4]];
		rightFace[side[i]] = refDownFace[side[(i + 1) % 4]];
		downFace[corner[i]] = refLeftFace[corner[(i + 1) % 4]];
		downFace[side[i]] = refLeftFace[side[(i + 1) % 4]];
		leftFace[corner[i]] = refTopFace[corner[(i + 1) % 4]];
		leftFace[side[i]] = refTopFace[side[(i + 1) % 4]];
	}
	//changing the unchanged but to be changed center pieces ->
	topFace[4] = refRightFace[4];
	rightFace[4] = refDownFace[4];
	downFace[4] = refLeftFace[4];
	leftFace[4] = refTopFace[4];
	equateRefVariables();
	
}

void p() {
	//following for loop is to assign the respective values to the corner and side pieces
	int corner[] = {0, 2, 8, 6};
	int side[] = {1, 5, 7, 3};
	for (int i = 0; i < 4; i++) {
		frontFace[corner[i]] = refFrontFace[(i - 1) == -1 ? (3) : (i - 1)];
		frontFace[side[i]] = refFrontFace[(i - 1) == -1 ? (3) : (i - 1)];
		backFace[corner[i]] = refBackFace[corner[(i + 1) % 4]];
		backFace[side[i]] = refBackFace[side[(i + 1) % 4]];		

		topFace[corner[i]] = refLeftFace[corner[(i - 1) == -1 ? (3) : (i - 1)]];
		topFace[side[i]] = refLeftFace[side[(i - 1) == -1 ? (3) : (i - 1)]];
		rightFace[corner[i]] = refTopFace[corner[(i - 1) == -1 ? (3) : (i - 1)]];
		rightFace[side[i]] = refTopFace[side[(i - 1) == -1 ? (3) : (i - 1)]];
		downFace[corner[i]] = refRightFace[corner[(i - 1) == -1 ? (3) : (i - 1)]];
		downFace[side[i]] = refRightFace[side[(i - 1) == -1 ? (3) : (i - 1)]];
		leftFace[corner[i]] = refDownFace[corner[(i - 1) == -1 ? (3) : (i - 1)]];
		leftFace[side[i]] = refDownFace[side[(i - 1) == -1 ? (3) : (i - 1)]];
	}
	//changing the unchanged but to be changed center pieces ->
	topFace[4] = refLeftFace[4];
	rightFace[4] = refTopFace[4];
	downFace[4] = refRightFace[4];
	leftFace[4] = refDownFace[4];
	equateRefVariables();
	
}

void equateRefVariables() {
	refFrontFace = frontFace;
	refRightFace = rightFace;
	refLeftFace = leftFace;
	refTopFace = topFace;
	refDownFace = downFace;
	refBackFace = backFace;

}

void printBoard() {
	system("cls");

	//each face would occupy 5x5 character space on the screen;

	gotoxy(32, 3);
	cout << "Your_Rubix_Cub";

	gotoxy(33, 21);
	cout << "frontFace";
	printFaceAt(frontFace, 35, 15);
	gotoxy(44, 21);
	cout << "rightFace";
	printFaceAt(rightFace, 46, 15);
	gotoxy(22, 21);
	cout << "leftFace";
	printFaceAt(leftFace, 24, 15);
	gotoxy(33, 13);
	cout << "topFace";
	printFaceAt(topFace, 35, 7);
	gotoxy(33, 29);
	cout << "downFace";
	printFaceAt(downFace, 35, 23);
	gotoxy(33, 37);
	cout << "backFace";
	printFaceAt(backFace, 35, 31);

	gotoxy(10, 40);
	cout << "Enter your move : ";

}

void printFaceAt(string face, short int x, short int y) {
	//printing the color of the face variable ->
	gotoxy(x, y);
	cout << face[0];
	gotoxy(x + 2, y);
	cout << face[1];
	gotoxy(x + 4, y);
	cout << face[2];
	gotoxy(x, y + 2);
	cout << face[3];
	gotoxy(x + 2, y + 2);
	cout << face[4];
	gotoxy(x + 4, y + 2);
	cout << face[5];
	gotoxy(x, y + 4);
	cout << face[6];
	gotoxy(x + 2, y + 4);
	cout << face[7];
	gotoxy(x + 4, y + 4);
	cout << face[8];	

	//printing the horizontal lines ->
	gotoxy(x, y + 1);
	cout << "-----";
	gotoxy(x, y + 3);
	cout << "-----";

	//printing the vertical lines ->
	gotoxy(x + 1, y);
	cout << "|";
	gotoxy(x + 3, y);
	cout << "|";
	gotoxy(x + 1, y + 2);
	cout << "|";
	gotoxy(x + 3, y + 2);
	cout << "|";
	gotoxy(x + 1, y + 4);
	cout << "|";
	gotoxy(x + 3, y + 4);
	cout << "|";

}
