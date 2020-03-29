#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;



class Node {
public:
	char c;
	Node* next;
	Node* prev; //Double Linked lists
	Node() { c = ' '; next = prev = NULL; }
};

void gotoxy(int x, int y) {

	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);

}

void main() {

	Node* curr = NULL;
	Node* head = NULL;
	char letter = ' ';

	int x_coord = 0;
	int y_coord = 0;
	int arrow = 1;

	//TEST WHAT KEY CHAR EQUIVALENT IS
	//letter = _getch();
	//cout << int(letter);
	//system("pause");
	//return;

	while (letter != 27) {//Prints key on touch

		letter = _getch();


		if (letter == -32) {
			letter = _getch();

			switch (letter) {
			case 75: //left
				if (curr == NULL || curr->prev == NULL ) {
					//Do nothing
				}
				else if (curr->next == NULL && arrow == 1 ) {
					x_coord--;
					gotoxy(x_coord, y_coord);
					arrow = 0;
				}
				else {
					x_coord--;
					gotoxy(x_coord, y_coord);
					curr = curr->prev;
				}
				break;
			case 77: //right
				if (curr == NULL || curr->next == NULL) {
					//do nothing
				}
				else {
					x_coord++;
					gotoxy(x_coord, y_coord);
					curr = curr->next;
				}
				break;
			case 72: //up
				break;
			case 80: //down
				break;
			}
			
		}
		else if (letter == 27) {
			//do nothing
			//fstream file("TextFile.txt", ios::out);
			Node* x = head;

			//while (x->next != NULL) {
			//	file << x->c;
			//	x = x->next;
			//}
		}
		else if (letter == 8 && curr != NULL) { //Press back
			if (curr != NULL && curr->prev != NULL) {

				curr = curr->prev;
				delete(curr->next);
				curr->next = NULL;
				printf("\b \b");
				x_coord--;
				gotoxy(x_coord, y_coord);

			}
			else if (curr->next != NULL && curr->prev == NULL) {//head delete
				head = head->next;
				curr = curr->next;
				delete(curr->prev);
				curr->prev = NULL;
				printf("\b \b");

				Node* temp = curr;
				while (temp != NULL) {
					cout << temp->c;
					temp = temp->next;
				}

				cout << (" ");
				gotoxy(x_coord, y_coord);

				



			}
		}

		//Press enter
		else if (letter == 13) {
			/*cout << endl;
			x_coord = 0;
			y_coord++;*/
			if (head == NULL) { // if first letter
				Node* x = new Node();
				x->c = letter;
				head = x;
				curr = head;

				cout << x->c;
				y_coord++;
				x_coord = 0;
				gotoxy(0, y_coord);
			}
			else {
				if (curr->next == NULL) {
					Node* x = new Node();
					x->c = letter;
					curr->next = x;
					x->prev = curr;
					curr = curr->next; // move current

					cout << x->c;
					y_coord++;
					x_coord = 0;
					gotoxy(0, y_coord);
				}
				else {//Insert itermediate value(append)
					Node* x = new Node();
					x->c = letter;
					x->next = curr->next;
					curr->next->prev = x;
					curr->next = x;
					x->prev = curr;
					curr = x;

					cout << x->c;
					y_coord++;
					x_coord = 0;
					gotoxy(0, y_coord);

				}
			}
		}

		else { //Regular character

			if (head == NULL) { // if first letter
				//create a node
				//put letter in node
				//make start point to that node
				Node* x = new Node();

				x->c = letter;
				head = x;
				curr = head;

				cout << x->c;
				x_coord++;
				gotoxy(x_coord, y_coord);
			}
			else if (curr->prev != NULL && curr->next != NULL) {//intermediate value
				Node* x = new Node();
				x->c = letter;
				x->next = curr->next;
				curr->next->prev = x;
				curr->next = x;
				x->prev = curr;
				curr = x;


					Node* temp = curr->prev;
					while (temp != NULL) {
						cout << temp->c;
						temp = temp->next;
					}
					arrow = 1;

					x_coord++;
					gotoxy(x_coord, y_coord);
				
			}
			else if (curr->prev == NULL && curr->next != NULL) {//New head char

				Node* x = new Node();
				x->c = letter;
				x->next = curr->next;
				curr->next->prev = x;
				curr->next = x;
				x->prev = curr;
				curr = x;


				Node* temp = curr->prev;
				while (temp != NULL) {
					cout << temp->c;
					temp = temp->next;
				}
				arrow = 1;

				x_coord++;
				gotoxy(x_coord, y_coord);
			}
			else {

				Node* x = new Node();
				x->c = letter;
				curr->next = x;
				x->prev = curr;
				curr = curr->next; // move current
				cout << x->c;
				x_coord++;
				gotoxy(x_coord, y_coord);
			
			}

		}

	}

	//for esc
	Node* p;
	p = head;
	cout << endl;
	while (p != NULL) {
		if (p->c == 13) {
			cout << '\n';
			p = p->next;
		}
		else {
			cout << p->c;
			p = p->next;
		}
	}

}
