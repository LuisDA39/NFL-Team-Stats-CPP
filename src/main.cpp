#include <iostream>
#include <vector>
#include<ctime>
using namespace std;

vector<vector<int>> matrix;
int rows = 5, columns = 3;

void getAvgFG();
void autofill();
void createMatrix();
void showMatrix();
void manualFill();
float getAverageTD();
float getBestTeam();
float getWorstTeam();
void vectorTest();
void showPoints();
int getLoserTeam();
void search(int dato);
void delay(int secs);


int main() {
    createMatrix();
	char option;
	int searchQuery;

	do  {
        cout << "---------------- Menu --------------" << endl;
        cout << "1. Manual fill" << endl;
        cout << "2. Autofill" << endl;
        cout << "3. Show matrix" << endl;
        cout << "4. Average touchdowns" << endl;
        cout << "5. Team with most points" << endl;
        cout << "6. Team with least points" << endl;
        cout << "7. Average field goals" << endl;
        cout << "8. Team with the most lost games" << endl;
        cout << "'m'. Show points matrix (vector)" << endl;
        cout << "'b' to search for a searchQuery" << endl;
        cout << "'s' to exit" << endl;
        cout << "------------------------------------" << endl;
        cout << "Enter your decision: ";

        cin >> option;
		cout << "\n";

		switch(option){
			case '1':
                manualFill();
			break;

			case '2':
				cout << "Matrix full!" << endl;
				cout << "\n";
                autofill();
				delay(2);
			break;

			case '3':
                showMatrix();
			break;

			case '4':
				cout << "Average touchdowns: " << getAverageTD() << endl;
				cout << "\n";
			break;

			case '5':
				cout << "Team " << getBestTeam() << " has the most points" << endl;
				cout << "\n";
			break;

			case '6':
				cout << "Team " << getWorstTeam() << " has the least points" << endl;
				cout << "\n";
			break;

			case '7':
                getAvgFG();
			break;

			case '8':
				cout << "The team with the most lost games is: " << getLoserTeam() << endl;
				cout << "\n";
			break;

			case '9':
			break;

			case 'm':
                showPoints();
			break;

			case 'b':
				cout << "What do you want to search for?: ";
				cin >> searchQuery;
                search(searchQuery);
				cout << "\n";
			break;

			case 's':
			break;

			default:
			cout << "Invalid, try again" << endl;
			break;
		}

	} while(option != 's');
	cout << "See you later ..." << endl;
}


void createMatrix() {
	matrix.resize(rows);

	for (int i = 0; i < rows; i++) {
		matrix[i].resize(columns);
	}
}

void manualFill() {
	for (int i = 0; i < rows; i++) {
        cout << "Team " << i + 1 << ":\n";
        for (int j = 0; j < columns; j++) {
			if (j == 0) {
				cout << "Touchdowns: ";
				cin >> matrix[i][j];
				cout << "\n";
			}
			if (j == 1) {
				cout << "Field Goals: ";
				cin >> matrix[i][j];
				cout << "\n";
			}
			if (j == 2) {
				cout << "Points against: ";
				cin >> matrix[i][j];
				cout << "\n";
			}
        } cout << "\n";
    }
}

void autofill() {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        matrix[i][0] = rand() % 30 + 1;
        matrix[i][1] = rand() % 15 + 1;
        matrix[i][2] = rand() % 200 + 1;
    }
}

void showMatrix() {
	cout << "           TD    FG    PAT    " << endl;
	for (int i = 0; i < rows; i++) {
		cout << "Team " << i + 1 << "  ";
		for(int j = 0; j < columns; j++) {
			if (j == 0 || j == 1) {
			cout << " " << matrix[i][j] << "\t";
            }
			else {
				cout << "   " << matrix[i][j];
			}
		}
		cout << "\n";
	}
    cout << "\n";
}

void getAvgFG() {
	int vector[rows];
	int suma = 0;

	for (int i = 0; i < rows; i++) {
		suma = 0;
		for(int j = 0; j < columns; j++) {
			suma += matrix[i][j];
			vector[i] = suma;
		}
	}

	for (int i = 0; i < rows; i++)
		cout << "Team " << i + 1 << ": " << vector[i] << " average field goals."<< endl;

	cout << "\n";
}

float getAverageTD() {
	float suma = 0;

	for (int i = 0; i < rows; i++)
			suma += matrix[i][0];

	return float(suma / rows);
}

float getBestTeam() {
    int vector[rows];
	int suma, mayor = 0, pos = 0;

	for (int i = 0; i < rows; i++) {
		suma = 0;
		suma = (matrix[i][0] * 7) + (matrix[i][1] * 3) - matrix[i][2];
		vector[i] = suma;
    }

	for (int i = 0; i < rows; i++) {
		if (vector[i] > mayor) {
            pos = i;
            mayor = vector[i];
		}
    }

	return pos + 1;
}

void vectorTest() {
	int vector[rows];
	int suma, mayor = 0, pos = 0;

	for (int i = 0; i < rows; i++) {
		suma = 0;
		suma = (matrix[i][0] * 3) + matrix[i][2];
		vector[i] = suma;
    }

	for (int i = 0; i < rows; i++) {
		cout << vector[i] << endl;
		if (vector[i] > mayor) {
				pos = i;
				mayor = vector[i];
		}
    }

    cout << "\n";
	cout << mayor << endl;
}

float getWorstTeam() {
    int vector[rows];
	int suma, menor = 100, pos = 0;

	for (int i = 0; i < rows; i++) {
		suma = 0;
		suma = (matrix[i][0] * 7) + (matrix[i][1] * 3) - matrix[i][2];
		vector[i] = suma;
    }

	for (int i = 0; i < rows; i++) {
		if (vector[i] < menor){
				pos = i;
				menor = vector[i];
		}
    }

	return pos + 1;
}

void showPoints() {
	int vector[rows];
	int suma, mayor = 0, pos = 0;

	for (int i = 0; i < rows; i++) {
		suma = 0;
		suma = (matrix[i][0] * 7) + (matrix[i][1] * 3) - matrix[i][2];;
		vector[i] = suma;
    }

	for (int i = 0; i < rows; i++)
		cout << "Team " << i + 1 << ": " << vector[i] << " points" << endl;

	cout << "\n";
}

int getLoserTeam() {
	float perdedor = 0;
	for (int i = 0; i < rows; i++) {
        if (matrix[i][1] > perdedor) {
            perdedor = i;
        }
    }

	return perdedor + 1;
}

void search(int dato) {
	bool bandera = false;
	int pli, pcol;

    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == dato) {
				bandera = true;
				pli = i + 1;
				pcol = j + 1;
			}
        }
    }

	if (bandera)
		cout << "Found " << dato << " in row " << pli << ", column " << pcol << endl;
	else
		cout << "Query not found " << dato << endl;
}

void delay(int secs) {
  for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
