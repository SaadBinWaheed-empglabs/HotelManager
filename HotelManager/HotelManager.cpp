#include <iostream>
#include <fstream>
#include <string>
using namespace std;


string room[5] = { "R0","R1","R2","R3","R4" };

bool store[5] = { false, false, false, false, false };


void booking() {
	
	for (int z=0; z < 5; z++) {
		
		if (store[z]==false) {
			cout << "Your Room number is..." << room[z] << endl;
			store[z] = true;
			break;
			
			
		}
		
	}

}

void checkingout() {
	int roomnum;
	

	cout << "Enter your room number" << endl;

	cin >> roomnum;
	store[roomnum] = false;


}


void availability() {
	int sum = 0;

	for(int i = 0; i < 5; i++) {
		if (store[i] == false) {
			sum = sum + 1;
			
		}

	}
	cout << sum << " ...rooms are available" << endl;
}
	



int main() {
	string username,password; 
	int temp1=0,temp2=0;
	
	bool mybool = false;
	cout << "Enter username and password" << endl;
	cin >> username;
	cin >> password;
	string myText1;
	string myText2;
	ifstream MyReadFile1("username.txt");
	while (getline(MyReadFile1, myText1)) {
		if (myText1 == username) {
			temp1 = 1;
		}
	}
    ifstream MyReadFile2("password.txt");
    while (getline(MyReadFile2, myText2)) {
			if (myText2 == password) {
				temp2 = 1;
			}
			if (temp1 == temp2) {
				mybool = true;
			}else {
				mybool = false;
			cout << "Wrong username or password" << endl;

		}
	}
	MyReadFile1.close();
	MyReadFile2.close();

	
	int num;

	while (mybool==true) {

		cout << "Press 1 to book a room" << endl;
		cout << "Press 2 to checkout from a room" << endl;
		cout << "Press 3 to check rooms availability" << endl;
		cout << "Press 4 to exit" << endl;
		cin >> num;

		switch (num) {

		case 1:
			booking();
			break;

		case 2:
			checkingout();
			break;


		case 3:
			availability();
			break;

		case 4:
			cout << "Program ended" << endl;
			mybool = false;
		}
		
		cout << "______________" << endl;
		
	}


	return 0;
}