//============================================================================
// Name         : Source.cpp
// Author       : Sagynbek Talgatuly st4121
// Version      : 1.0
// Date Created : 23/02/2021
// Date Modified: 24/02/2021
// Copyright    : All rights are reserved
// Description  : Assignment 1. Movie Theater Booking system
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <iomanip>

using namespace std;
 
//defining constants for the sizes of arrays
#define maxSizeOfGuests 10000
#define maxSizeOfAdmins 10000
#define maxSizeOfMovies 10000

//This class will store the ID's of the members of the list
//the id it stores can be either GuestID or MovieID
class Node
{
private:
	string elem;
	Node* next;
	friend class LinkedList;

public:
	//two types of constructors
	Node() : next(NULL) {};
	Node(string elem) : elem(elem), next(NULL) {};
};

//The linked list of nodes
class LinkedList {
private:
	Node* head;
public:
	//constructor
	LinkedList() { head = NULL; };
	//destructor
	~LinkedList() { while (!empty()) removeFront(); };
	//finding an ID e and removing it from the list
	void remove(string e) {
		//if the list is empty don't do anything
		if (!empty()) {
			Node* current = head;
			bool flag = false;
			//if head is the e, then we remove the front only
			if (current->elem == e) { removeFront(); return; }
			//traversing the list
			while (current->next != NULL && flag == false) {
				if (current->next->elem == e) {
					flag = true;
					break;
				}
				current = current->next;
			}
			//if found, we remove it
			if (flag == true) {
				Node* old = current->next;
				current->next = old->next;
				delete old;
			}
		}
	};
	//removing the head element of the list
	void removeFront() {
		if (!empty()) {
			Node* old = head;
			head = old->next;
			delete old;
		}
		else { cout << "A list is empty"; }
	};
	//adding an element to the front
	void addFront(const string& e) {
		Node* v = new Node;
		v->elem = e;
		v->next = head;
		head = v;
	};
	bool empty() const { return head == NULL; }
	const string& front() const { return head->elem; }
	//the list elements are returned as a string,
	//separated with commas
	string display() {
		string out = "";
		if (!empty()) {
			Node* current = head;
			out += current->elem;
			current = current->next;
			while (current != NULL) {
				out += ",";
				out += current->elem;
				current = current->next;
			}
		}
		return out;
	}
};

//class that stores all the movieScreening details
//and that has all the setters and getters, and needed methods
class MovieScreening {
private:
	string ID;
	string MovieName;
	int NumberOfGuests;
	int MaximumCapacity;
	string ScreeningDate;
	string ScreeningTime;
	string HallName;
public:
	//it has a pointer to a linked list called "list of guests"
	LinkedList* ListOfGuests;
	MovieScreening() { ListOfGuests = new LinkedList; NumberOfGuests = 0; MaximumCapacity = 0; };
	MovieScreening(string, string, int, int, string, string, string);
	~MovieScreening() {};
	void clean();
	string getMovieName() const;
	string getID() const;
	int getNG() const;
	int getMC() const;
	string getSD() const;
	string getST() const;
	string getHN() const;
	void setMovieName(string MN);
	void setID(string ID);
	void setNG(int NG);
	void setMC(int MC);
	void setSD(string SD);
	void setST(string ST);
	void setHN(string HN);
	void update(string, string, int, int, string, string, string);
};

MovieScreening::MovieScreening(string ID, string MN, int NG, int MC, string SD, string ST, string HN)
	: ID(ID), MovieName(MN), NumberOfGuests(NG), MaximumCapacity(MC), ScreeningDate(SD), ScreeningTime(ST), HallName(HN)
{
	ListOfGuests = new LinkedList;
}
string MovieScreening::getMovieName() const { return MovieName; }
string MovieScreening::getID() const { return ID; }
int MovieScreening::getNG() const { return NumberOfGuests; }
int MovieScreening::getMC() const { return MaximumCapacity; }
string MovieScreening::getSD() const { return ScreeningDate; }
string MovieScreening::getST() const { return ScreeningTime; }
string MovieScreening::getHN() const { return HallName; }
void MovieScreening::setMovieName(string MN) { MovieName = MN; }
void MovieScreening::setID(string ID) { this->ID = ID; }
void MovieScreening::setNG(int NG) { NumberOfGuests = NG; }
void MovieScreening::setMC(int MC) { MaximumCapacity = MC; }
void MovieScreening::setSD(string SD) { ScreeningDate = SD; }
void MovieScreening::setST(string ST) { ScreeningTime = ST; }
void MovieScreening::setHN(string HN) { HallName = HN; }
//this method updates the details of the movie
void MovieScreening::update(string ID, string MN, int NG, int MC, string SD, string ST, string HN)
{
	this->ID = ID;
	MovieName = MN;
	NumberOfGuests = NG;
	MaximumCapacity = MC;
	ScreeningDate = SD;
	ScreeningTime = ST;
	HallName = HN;
}
//this method clears the details
void MovieScreening::clean() {
	this->ID = "";
	MovieName = "";
	NumberOfGuests = 0;
	MaximumCapacity = 0;
	ScreeningDate = "";
	ScreeningTime = "";
	HallName = "";
	delete ListOfGuests;
}

//class that stores user info
//user is either admin or a guest
class User {
private:
	string FirstName;
	string LastName;
	string Username;
	string Password;
public:
	User() {};
	~User() {};
	User(string, string, string, string);
	string getPassword() const;
	string getFirstName() const;
	string getUserName() const;
	string getLastName() const;
	void setPassword(string);
	void setFirstName(string);
	void setUserName(string);
	void setLastName(string);
};

User::User(string FN, string LN, string UN, string P) : FirstName(FN), LastName(LN), Username(UN), Password(P) {}
string User::getPassword() const { return Password; }
string User::getFirstName() const { return FirstName; }
string User::getLastName() const { return LastName; }
string User::getUserName() const { return Username; }
void User::setPassword(string P) { Password = P; }
void User::setFirstName(string FN) { FirstName = FN; };
void User::setUserName(string UN) { Username = UN; };
void User::setLastName(string LN) { LastName = LN; };

//class Admin inherits from User
class Admin : public User {
private:
	string AdminID;
public:
	Admin() {};
	~Admin() {};
	Admin(string, string, string, string, string);
	string getID() const;
	void setID(string ID);
	void update(string, string, string, string, string);
};

Admin::Admin(string ID, string FN, string LN, string UN, string P) : AdminID(ID), User(FN, LN, UN, P) {}
string Admin::getID() const { return AdminID; }
void Admin::setID(string ID) { AdminID = ID; }
void Admin::update(string ID, string FN, string LN, string UN, string P)
{
	AdminID = ID;
	setFirstName(FN);
	setLastName(LN);
	setUserName(UN);
	setPassword(P);
}
//class Guest inherits from User
class Guest : public User {
private:
	string GuestID;
public:
	LinkedList* ListOfBookings;
	Guest() { ListOfBookings = new LinkedList; };
	~Guest() { while (!ListOfBookings->empty()) ListOfBookings->removeFront(); delete ListOfBookings; };
	Guest(string, string, string, string, string);
	string getID() const;
	void setID(string ID);
	void update(string, string, string, string, string);
};

Guest::Guest(string ID, string FN, string LN, string UN, string P) : GuestID(ID), User(FN, LN, UN, P) { ListOfBookings = new LinkedList; }
string Guest::getID() const { return GuestID; }
void Guest::setID(string ID) { GuestID = ID; }
void Guest::update(string ID, string FN, string LN, string UN, string P)
{
	GuestID = ID;
	setFirstName(FN);
	setLastName(LN);
	setUserName(UN);
	setPassword(P);
}

//class of exceptions
class MyExceptions {
private:
	string errorMessage; 
public:
	MyExceptions(const string& error) : errorMessage(error) {}
	string getError() { return errorMessage; }
};

//a function that returns true if an input is an integer
bool isNumber(string s)
{
	int S = s.length();
	for (int i = 0; i < S; i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

//a function that loads the data to the system
//this function is called three times for each txt file
void load(string path, Admin* ptr1, Guest* ptr2, MovieScreening* ptr3) {
	ifstream fin(path);
	if (fin.is_open()){
		//ignoring first line
		fin.ignore(1000, '\n');

		if (ptr1 != NULL)
			while (!fin.eof()) {
				//reading the line and updating the object
				string ID, FN, LN, UN, P;
				getline(fin, ID, ',');
				getline(fin, FN, ',');
				getline(fin, LN, ',');
				getline(fin, UN, ',');
				getline(fin, P, '\n');
				ptr1[stoi(ID)].update(ID, FN, LN, UN, P);
			}
		if (ptr2 != NULL)
			while (!fin.eof()) {
				//reading the line and updating the object
				string ID, FN, LN, UN, P;
				getline(fin, ID, ',');
				getline(fin, FN, ',');
				getline(fin, LN, ',');
				getline(fin, UN, ',');
				getline(fin, P, ',');
				ptr2[stoi(ID)].update(ID, FN, LN, UN, P);
				string MovieIDs;
				//reading inside the bracket and adding an element to the list of bookings
				getline(fin, MovieIDs, '\n');
				string MovieID;
				if (MovieIDs.length() != 2) {
					MovieIDs = MovieIDs.substr(1);
					stringstream ss(MovieIDs);
					int counter = 1;
					for (int i = 0; i < MovieIDs.length(); i++) {
						if (MovieIDs[i] == ',') counter++;
					}
					for (int i = 0; i < counter - 1; i++) {
						getline(ss, MovieID, ',');
						ptr2[stoi(ID)].ListOfBookings->addFront(MovieID);
					}
					getline(ss, MovieID, ']');
					ptr2[stoi(ID)].ListOfBookings->addFront(MovieID);
				}
			}
		if (ptr3 != NULL)
			while (!fin.eof()) {
				//reading the line and updating the object
				string ID, MN, NG, MC, SD, ST, HN;
				getline(fin, ID, ',');
				getline(fin, MN, ',');
				getline(fin, NG, ',');
				getline(fin, MC, ',');
				getline(fin, SD, ',');
				getline(fin, ST, ',');
				getline(fin, HN, ',');
				ptr3[stoi(ID)].update(ID, MN, stoi(NG), stoi(MC), SD, ST, HN);
				//reading inside the bracket and adding an element to the list of bookings
				string GuestIDs;
				getline(fin, GuestIDs, '\n');
				string GuestID;
				if (GuestIDs.length() != 2) {
					GuestIDs = GuestIDs.substr(1);
					stringstream ss(GuestIDs);
					int counter = 1;
					for (int i = 0; i < GuestIDs.length(); i++) {
						if (GuestIDs[i] == ',') counter++;
					}
					for (int i = 0; i < counter - 1; i++) {
						getline(ss, GuestID, ',');
						ptr3[stoi(ID)].ListOfGuests->addFront(GuestID);
					}
					getline(ss, GuestID, ']');
					ptr3[stoi(ID)].ListOfGuests->addFront(GuestID);
				}
			}
	}
	else
	{
		throw MyExceptions("Invalid path to the database");
	}
	fin.close();
}

//this function is to save the data from the system to the txt files
//the format of the txt files remain the same
void save(string path1, string path2, string path3, Admin* ptr1, Guest* ptr2, MovieScreening* ptr3) {
	if (ptr1 != NULL) {
		ofstream fout(path1);
		if (fout.is_open())
		{
			fout << "admin_id, first_name, last_name, username, password";
			for (int i = 0; i < 10000; i++) {
				if (ptr1[i].getID() != "")
				{
					fout << endl;
					fout << ptr1[i].getID() << ',';
					fout << ptr1[i].getFirstName() << ',';
					fout << ptr1[i].getLastName() << ',';
					fout << ptr1[i].getUserName() << ',';
					fout << ptr1[i].getPassword();
				}
			}
		}
		else
		{
			throw MyExceptions("Invalid path to the database");
		}
		fout.close();
	}
	if (ptr2 != NULL) {
		ofstream fout(path2);
		if (fout.is_open()) {
			fout << "guest_id,first_name,last_name,username,password,list_of_bookings";
			for (int i = 0; i < 10000; i++) {
				if (ptr2[i].getID() != "") {
					fout << endl;
					fout << ptr2[i].getID() << ",";
					fout << ptr2[i].getFirstName() << ",";
					fout << ptr2[i].getLastName() << ",";
					fout << ptr2[i].getUserName() << ",";
					fout << ptr2[i].getPassword() << ",";
					fout << "[";
					fout << ptr2[i].ListOfBookings->display();
					fout << "]";
				}
			}
		}
		else
		{
			throw MyExceptions("Invalid path to the database");
		}
		fout.close();
	}
	if (ptr3 != NULL) {
		ofstream fout(path3);
		if (fout.is_open()) {
			fout << "movie_screening_id,movie_name,number_of_guests,maximum_capacity,screening_date,screening_time,hall_name,list_of_guests";
			for (int i = 0; i < 10000; i++) {
				if (ptr3[i].getID() != "") {
					fout << endl;
					fout << ptr3[i].getID() << ",";
					fout << ptr3[i].getMovieName() << ",";
					fout << ptr3[i].getNG() << ",";
					fout << ptr3[i].getMC() << ",";
					fout << ptr3[i].getSD() << ",";
					fout << ptr3[i].getST() << ",";
					fout << ptr3[i].getHN() << ",";
					fout << "[";
					fout << ptr3[i].ListOfGuests->display();
					fout << "]";
				}
			}
		}
		else
		{
			throw MyExceptions("Invalid path to the database");
		}
		fout.close();
	}
}

//this function is to randomly choose an ID for a new guest
string IDRandomizer(Guest* ptr2) {
	srand(time(NULL));
	int a;
	//we randomly take a number in the range and check if it exists
	while (true) {
		a = rand() % 10000;
		if (ptr2[a].getID() == "") { break; }
	}
	string b = "0000" + to_string(a);
	return b.substr(b.size()-4);
}

//this function is to register a new guest
bool registerGuest(Guest* ptr2) { 
	int counter = 0;
	//we go through the array and find how many guests are there in the system
	for (int i = 0; i < 10000; i++) { if (ptr2[i].getID() != "") counter++; }
	//if the system is not full we do the next
	if (counter != 10000) {
		//we take all the details and save it in the array under the same ID
		string ID, FN, LN, UN, P;
		cout << "Please, provide the details of a guest for the registration" << endl;
		cout << "Note: enter names without white spaces" << endl;
		cout << "First Name: ";
		cin >> FN;
		cout << "Last Name: ";
		cin >> LN;
		ID = IDRandomizer(ptr2);
		UN = "";
		for (int i = 0; i < FN.length(); i++) { UN += char(tolower(FN[i])); }
		UN += ID;
		srand(time(NULL) * 2);
		int a = rand() % 10000;
		string b = "0000" + to_string(a);
		P = "";
		for (int i = 0; i < LN.length(); i++) { P += char(tolower(LN[i])); }
		P += b.substr(b.size() - 4);;
		ptr2[stoi(ID)].update(ID, FN, LN, UN, P);
		cout << "Registration complete!" << endl;
		cout << "Your credentials are as follows: " << endl;
		cout << "ID: " << ID << endl;
		cout << "Fisrt Name: " << FN << endl;
		cout << "Last Name: " << LN << endl;
		cout << "Username: " << UN << endl;
		cout << "Password: " << P << endl << endl;
		return true;
	} 
	else { 
		return false;
		throw MyExceptions("The system is full, no more registarions"); }
}

//this function is to log in the system
bool login(int& currentUserType, string &currentUserID, Admin* ptr1, Guest* ptr2) {
	string input1, input2;
	bool flag = false;
	do {
		cout << "Username: ";
		cin >> input1;
		cout << "PassWord: ";
		cin >> input2;
		system("clear");
		if (ptr1 != NULL) {
			for (int i = 0; i < 10000; i++) {
				//check if the credentials are valid
				if (ptr1[i].getUserName() == input1 && ptr1[i].getPassword() == input2)
				{
					flag = true; 
					currentUserType = 1;
					currentUserID = ptr1[i].getID();
					cout << "Welcome to the system, " << ptr1[stoi(currentUserID)].getUserName() << endl;
					break;
				}
			}
		}
		if (ptr2 != NULL) {
			for (int i = 0; i < 10000; i++) {
				if (ptr2[i].getUserName() == input1 && ptr2[i].getPassword() == input2)
				{
					flag = true; 
					currentUserType = 2;
					currentUserID = ptr2[i].getID();
					cout << "Welcome to the system, " << ptr2[stoi(currentUserID)].getUserName() << endl;
					break;
				}
			}
		}
		//if the log in didn't take place correctly the flag is false
		//we need to ask for it again or go back
		if (flag == false)
		{ 
			cout << "Username or password you entered is wrong" << endl;
			cout << "Enter 1 to retry" << endl;
			cout << "Enter 2 to go back" << endl;
			string input3;
			cin >> input3;
			system("clear");
			if (input3 == "2") return false;
		}
	} while (flag == false);
	return true;
}

//this function summarizes all the actions in the beginning
//and gives true if everything went fine
bool start(int &currentUserType, string& currentUserID, Admin* ptr1, Guest* ptr2){
	string input;
	cout << "Welcome to the movies booking system" << endl;
	bool flag = false;;
	do {
		cout << "Enter 1 --> if you are an admin" << endl;
		cout << "Enter 2 --> if you are a guest" << endl;
		cout << "Enter 3 --> to exit the system" << endl;
		cin >> input;
		system("clear");
		if (input == "1") {
			flag = login(currentUserType, currentUserID, ptr1, NULL);
		}
		if (input == "2") {
			cout << "Enter 1, to register" << endl;
			cout << "Enter 2, to log in" << endl;
			cin >> input;
			system("clear");
			if (input == "1") {
				registerGuest(ptr2);
			}
			if (input == "2") {
				flag = login(currentUserType, currentUserID, NULL, ptr2);
			}
		}
		if (input == "3") {
			save("", "Guests.txt", "", NULL, ptr2, NULL);
			exit(0);
		}
	} while (flag != true);
	return true;
}

//this function shows the list of actions depending on the currentusertype
void ShowCommands(int currentUserType)
{
	if (currentUserType == 1) {
		cout << "List of available Commands:" << endl
			<< "0 -> help                        \t: Display the list of available commands" << endl
			<< "1 -> addMovieScreening           \t: Add a new movie to the database" << endl
			<< "2 -> deleteMovieScreening        \t: Remove a movie from the database" << endl
			<< "3 -> updateMovieScreening        \t: Update the details of a movie" << endl
			<< "4 -> registerGuest               \t: Register a new guest" << endl
			<< "5 -> viewMovieScreeningDetails   \t: Display the details of a movie" << endl
			<< "6 -> viewListOfGuests            \t: Display the list of guest for a movie" << endl
			<< "7 -> viewListOfBookings          \t: Display the list of bookings of a guest" << endl
			<< "8 -> viewAvailableMovieScreenings\t: Display the list of available movies" << endl
			<< "9 -> viewMovieScreeningsWithSeats\t: Display the list of movies with available seats" << endl
			<< "! -> exit                        \t: Exit the Program" << endl;
	}
	if (currentUserType == 2) {
		cout << "List of available Commands:" << endl
			<< "0 -> help                        \t: Display the list of available commands" << endl
			<< "1 -> viewAvailableMovieScreenings\t: Display the list of available movies" << endl
			<< "2 -> viewMovieScreeningsWithSeats\t: Display the list of movies with available seats" << endl
			<< "3 -> bookASeat                   \t: To book a seat for one of the movies" << endl
			<< "4 -> cancelBooking               \t: To cancel the booking for one of the movies" << endl
			<< "5 -> viewYourListOfBookings      \t: Display the list of bookings of you" << endl
			<< "! -> quitProgram                 \t: Exit the Program" << endl;
	}
}

void addMovieScreening(MovieScreening* ptr3, Guest* ptr2) {
	cout << endl;
	//ID, maximum number are validated
	string ID, MN, NG, MC, SD, ST, HN;
	cout << "Please, provide the details of the movie you want to add" << endl << endl;
	cout << "Movie screening ID : ";
	cin >> ID;
	if (!isNumber(ID) || stoi(ID) > maxSizeOfMovies) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	if (ptr3[stoi(ID)].getID() != "") { throw MyExceptions("ID you entered already exists"); }
	cout << "Movie Name : ";
	getline(cin, MN);
	getline(cin, MN);
	//number of guests is set to 0, because the movie is new
	cout << "Number of Guests : 0" << endl;
	NG = "0";
	if (!isNumber(NG) || stoi(NG) < 0) { throw MyExceptions("Number of guests must be a non-negative integer"); }
	cout << "Maximum Capacity : ";
	cin >> MC;
	if (!isNumber(MC) || stoi(MC) <= 0) { throw MyExceptions("Maximum capacity must be a positive integer"); }
	if (stoi(MC) < stoi(NG)) { throw MyExceptions("Maximum capacity must be greater that number of guests"); }
	cout << "Screening Date in the format dd-mm-yy: ";
	cin >> SD;
	if (SD.length() != 8) { throw MyExceptions("Screening Date must be in a format dd-mm-yy"); }
	cout << "Screening Time in the format hh:mm: ";
	cin >> ST;
	if (ST.length() != 5) { throw MyExceptions("Screening Time must be in a format hh:mm"); }
	cout << "Hall Name : ";
	cin >> HN;
	ptr3[stoi(ID)].update(ID, MN, stoi(NG), stoi(MC), SD, ST, HN);
	cout << "The movie was added succesfully!" << endl;
}

void deleteMovieScreening(MovieScreening* ptr3, Guest* ptr2) {
	cout << endl;
	string ID;
	cout << "Please, provide the ID of the movie to be removed" << endl;
	cout << "ID: ";
	cin >> ID;
	if (!isNumber(ID) || stoi(ID) > maxSizeOfMovies) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	//checking if the movie with such ID exists
	if (ptr3[stoi(ID)].getID() != "") {
		string GuestID;
		string GuestIDs = ptr3[stoi(ID)].ListOfGuests->display();
		GuestIDs += "]";
		stringstream ss(GuestIDs);
		//if the list of guests is not empty then we need to clear all the list
		//as well as  the lists of each guest that booked for this movie
		if (GuestIDs.length() != 1) {
			int counter = 1;
			for (int i = 0; i < GuestIDs.length(); i++) {
				if (GuestIDs[i] == ',') counter++;
			}
			for (int i = 0; i < counter - 1; i++) {
				getline(ss, GuestID, ',');
				ptr2[stoi(GuestID)].ListOfBookings->remove(ID);
			}
			getline(ss, GuestID, ']');
			ptr2[stoi(GuestID)].ListOfBookings->remove(ID);
		}
		//claening the movieObject
		ptr3[stoi(ID)].clean();
		cout << "The movie was deleted succesfully!" << endl;
	}
	else { throw MyExceptions("The movie was not found"); }
}

void updateMovieScreening(MovieScreening* ptr3) {
	cout << endl;
	string ID, SD, ST, HN;
	cout << "Please, provide the ID of the movie to be updated" << endl;
	cout << "ID: ";
	cin >> ID;
	if (!isNumber(ID) || stoi(ID) > maxSizeOfMovies) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	if (ptr3[stoi(ID)].getID() != "") {
		cout << "The movie was found" << endl;
		cout << "Movie name: " << ptr3[stoi(ID)].getMovieName() << endl;
		cout << "Please, provide the details of the movie to be updated" << endl;
		cout << "Screening Date in the format dd-mm-yy: ";
		cin >> SD;
		if (SD.length()!=8) { throw MyExceptions("Screening Date must be in a format dd-mm-yy"); }
		cout << "Screening Time in the format hh:mm: ";
		cin >> ST;
		if (ST.length() != 5) { throw MyExceptions("Screening Time must be in a format hh:mm"); }
		cout << "Hall Name: ";
		cin >> HN;
		ptr3[stoi(ID)].setSD(SD);
		ptr3[stoi(ID)].setST(ST);
		ptr3[stoi(ID)].setHN(HN);
		cout << "The movie was updated succesfully!" << endl;
	}
	else throw MyExceptions{ "The movie with this ID doesn't exist" };
}

void viewMovieScreeningDetails(MovieScreening* ptr3) {
	cout << endl;
	string ID;
	cout << "Please, provide the ID of the movie to show its details" << endl;
	cout << "ID: ";
	cin >> ID;
	if (!isNumber(ID) || stoi(ID) > maxSizeOfMovies) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	if (ptr3[stoi(ID)].getID() != "") {
		cout << "The movie was found" << endl;
		cout << "Movie ID: " << ptr3[stoi(ID)].getID() << endl;
		cout << "Movie name: " << ptr3[stoi(ID)].getMovieName() << endl;
		cout << "Number of guests: " << ptr3[stoi(ID)].getNG() << endl;
		cout << "Maximum capacity: " << ptr3[stoi(ID)].getMC() << endl;
		cout << "Screening date: " << ptr3[stoi(ID)].getSD() << endl;
		cout << "Screening time: " << ptr3[stoi(ID)].getST() << endl;
		cout << "Hall name: " << ptr3[stoi(ID)].getHN() << endl;
		cout << endl;
	}
	else throw MyExceptions{ "The movie with this ID doesn't exist" };
}

void viewListOfGuests(MovieScreening* ptr3, Guest* ptr2) {
	cout << endl;
	string ID;
	cout << "Please, provide the ID of the movie" << endl;
	cout << "ID: ";
	cin >> ID;
	if (!isNumber(ID) || stoi(ID) > maxSizeOfMovies) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	if (ptr3[stoi(ID)].getID() != "") {
		string GuestID;
		string GuestIDs = ptr3[stoi(ID)].ListOfGuests->display();
		if (GuestIDs == "") { cout << "The list of guests for this movie is empty" << endl; return; }
		cout << "The list of guests for this movie is shown below: " << endl;
		GuestIDs += "]";
		stringstream ss(GuestIDs);
		int counter = 1;
		for (int i = 0; i < GuestIDs.length(); i++) {
			if (GuestIDs[i] == ',') counter++;
		}
		cout << "Number of guests in the list is: " << counter << endl << endl;
		for (int i = 0; i < counter - 1; i++) {
			getline(ss, GuestID, ',');
			cout << " --->>  " << endl
				<< "GuestID:     " << ptr2[stoi(GuestID)].getID() << '\n'
				<< "First name:  " << ptr2[stoi(GuestID)].getFirstName() << '\n'
				<< "Last name:   " << ptr2[stoi(GuestID)].getLastName() << '\n';
		}
		getline(ss, GuestID, ']');
		cout << " --->> " << endl
			<< "GuestID:     " << ptr2[stoi(GuestID)].getID() << '\n'
			<< "First name:  " << ptr2[stoi(GuestID)].getFirstName() << '\n'
			<< "Last name:   " << ptr2[stoi(GuestID)].getLastName() << '\n' << '\n';
	}
	else throw MyExceptions("Incorrect ID, the movie wasn't found");
}

void viewListOfBookings(string currentUserID, Guest* ptr2, MovieScreening* ptr3) {
	cout << endl;
	string ID;
	if (currentUserID == "") {
		cout << "Please, provide the ID of the guest" << endl;
		cout << "ID: ";
		cin >> ID;
		if (!isNumber(ID) || stoi(ID) > maxSizeOfGuests) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	}
	else ID = currentUserID;
	if (ptr2[stoi(ID)].getID() != "") {
		string MovieID;
		string MovieIDs = ptr2[stoi(ID)].ListOfBookings->display();
		if (MovieIDs == "") { cout << "The list of bookingns for this guest is empty" << endl; return; }
		cout << "The list of bookings for this guest is shown below: " << endl;
		MovieIDs += "]";
		stringstream ss(MovieIDs);
		int counter = 1;
		for (int i = 0; i < MovieIDs.length(); i++) {
			if (MovieIDs[i] == ',') counter++;
		}
		cout << "Number of bookings in the list is: " << counter << endl << endl;
		for (int i = 0; i < counter - 1; i++) {
			getline(ss, MovieID, ',');
			cout << " --->>  " << endl
				<< "MovieID:     " << ptr3[stoi(MovieID)].getID() << '\n'
				<< "First name:  " << ptr3[stoi(MovieID)].getMovieName() << '\n';
		}
		getline(ss, MovieID, ']');
		cout << " --->> " << endl
			<< "MovieID:     " << ptr3[stoi(MovieID)].getID() << '\n'
			<< "Movie name:  " << ptr3[stoi(MovieID)].getMovieName() << '\n' << '\n';
	}
	else throw MyExceptions("Incorrect ID, the movie wasn't found");
}

void bookASeat(Guest* ptr2, MovieScreening* ptr3, string currentUserID) {
	string ID;
	cout << "Please, provide the ID of the movie you want to book" << endl;
	cout << "ID: ";
	cin >> ID;
	if (!isNumber(ID) || stoi(ID) > maxSizeOfMovies) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	if (ptr3[stoi(ID)].getID() != "") {
		//checking if there are still seats available
		if (ptr3[stoi(ID)].getNG() < ptr3[stoi(ID)].getMC()) {
			cout << "The movie was found" << endl;
			cout << "Movie name: " << ptr3[stoi(ID)].getMovieName() << endl;
			cout << "Date      : " << ptr3[stoi(ID)].getSD() << endl;
			cout << "Time      : " << ptr3[stoi(ID)].getST() << endl;
			cout << "Hall name : " << ptr3[stoi(ID)].getHN() << endl;
			//adding the guest to the list of geuests and vice versa
			ptr2[stoi(currentUserID)].ListOfBookings->addFront(ID);
			ptr3[stoi(ID)].ListOfGuests->addFront(currentUserID);
			ptr3[stoi(ID)].setNG(ptr3[stoi(ID)].getNG() + 1);
			cout << "You have booked a seat succesfully" << endl << endl;
		}
		else cout << "Sorry, the movie has no available seats currently" << endl << endl;
	}
	else throw MyExceptions{ "The movie with this ID doesn't exist" };
	
}

void cancelBooking(Guest* ptr2, MovieScreening* ptr3, string currentUserID) {
	string ID;
	cout << "Please, provide the ID of the movie you want to cancel" << endl;
	cout << "ID: ";
	cin >> ID;
	if (!isNumber(ID) || stoi(ID) > maxSizeOfMovies) { throw MyExceptions("ID must be an integer in the range 0 to 9999"); }
	if (ptr3[stoi(ID)].getID() != "") {
		//if there is no booking then corresponding exception will be thrown
		bool notbooked = true;
		string MovieID;
		string MovieIDs = ptr2[stoi(currentUserID)].ListOfBookings->display();
		MovieIDs += "]";
		stringstream ss(MovieIDs);
		int counter = 1;
		for (int i = 0; i < MovieIDs.length(); i++) {
			if (MovieIDs[i] == ',') counter++;
		}
		for (int i = 0; i < counter - 1; i++) {
			getline(ss, MovieID, ',');
			if (MovieID == ID) { notbooked = false; break; }
		}
		getline(ss, MovieID, ']');
		if (MovieID == ID) { notbooked = false; }
		if (!notbooked) {
			cout << "The movie was found" << endl;
			cout << "Movie name: " << ptr3[stoi(ID)].getMovieName() << endl;
			cout << "Date      : " << ptr3[stoi(ID)].getSD() << endl;
			cout << "Time      : " << ptr3[stoi(ID)].getST() << endl;
			cout << "Hall name : " << ptr3[stoi(ID)].getHN() << endl;
			ptr2[stoi(currentUserID)].ListOfBookings->remove(ID);
			ptr3[stoi(ID)].ListOfGuests->remove(currentUserID);
			ptr3[stoi(ID)].setNG(ptr3[stoi(ID)].getNG() - 1);
			cout << "You have cancelled your booking succesfully" << endl << endl;
		}
		else throw MyExceptions{ "You don't have a booking for this movie" };
	}
	else throw MyExceptions{ "The movie with this ID doesn't exist" };
}

void viewAvailableMovieScreenings(MovieScreening* ptr3) {
	cout << endl;
	int counter = 0;
	for (int i = 0; i < 10000; i++) {
		if (ptr3[i].getID() != "") counter++;
	}
	cout << "Number of movie screenings is: " << counter << endl;
	cout.setf(ios::left);
	const int width = 12;
	cout 
		<< setw(width - 7) << "ID"
		<< setw(width + 6) << "Movie name"
		<< setw(width + 1) << "# of guests"
		<< setw(width - 2) << "Maxumim#"
		<< setw(width) << "Date"
		<< setw(width - 4) << "Time"
		<< setw(width) << "Hall name" << endl;

	//for each movie that exists, we display its details
	//to check if the movies exists we check if its ID is not empty string
	for (int i = 0; i < 10000; i++) {
		if (ptr3[i].getID() != "") {
			cout
				<< setw(width - 7) << ptr3[i].getID()
				<< setw(width + 6) << ptr3[i].getMovieName()
				<< setw(width + 1) << ptr3[i].getNG()
				<< setw(width - 2) << ptr3[i].getMC()
				<< setw(width) << ptr3[i].getSD()
				<< setw(width - 4) << ptr3[i].getST()
				<< setw(width) << ptr3[i].getHN()
				<< endl;
		}
	}
	cout << endl;
}

//the same as the function above
//but the number of guests is checked
void viewMovieScreeningsWithSeats(MovieScreening* ptr3) {
	cout << endl;
	int counter = 0;
	for (int i = 0; i < 10000; i++) {
		if (ptr3[i].getID() != "" && (ptr3[i].getNG() < ptr3[i].getMC())) counter++;
	}
	cout << "Number of movie screenings with seats is: " << counter << endl;
	cout.setf(ios::left);
	const int width = 12;
	cout
		<< setw(width - 7) << "ID"
		<< setw(width + 6) << "Movie name"
		<< setw(width + 1) << "# of guests"
		<< setw(width - 2) << "Maxumim#"
		<< setw(width)	   << "Date"
		<< setw(width - 4) << "Time"
		<< setw(width)     << "Hall name" << endl;

	for (int i = 0; i < 10000; i++) {
		if (ptr3[i].getID() != "" && (ptr3[i].getNG() < ptr3[i].getMC()))
		{
			cout
				<< setw(width - 7) << ptr3[i].getID()
				<< setw(width + 6) << ptr3[i].getMovieName()
				<< setw(width + 1) << ptr3[i].getNG()
				<< setw(width - 2) << ptr3[i].getMC()
				<< setw(width)	   << ptr3[i].getSD()
				<< setw(width - 4) << ptr3[i].getST()
				<< setw(width)     << ptr3[i].getHN()
				<< endl;
		}
	}
	cout << endl;
}

int main()
{
	//the database of all the guests, admins, and movies is three dynamic arrays
	//the pros of this solution is that i'th element of the arrays stores exactly
	//one entity with the same ID number. For example, element 564 of the array Guests is
	//an object of class Guest with GuestID attribute equal to 0546. Accessing the object
	//in this way is also a pro. What we need is just to write Guests[546] for example.
	//On the contrary, according to the requirements of the assigment
	//the list of bookings and the list of guests for each guest or a movie
	//is implemented as a linked list
	Guest* Guests = new Guest[maxSizeOfGuests];
	Admin* Admins = new Admin[maxSizeOfAdmins];
	MovieScreening* Movies = new MovieScreening[maxSizeOfMovies];

	//these two variables store the info about the user who have succesfully logged in
	int currentUserType;
	string currentUserID;
	//loading the database to the system
	try {
		load("Admins.txt", Admins, NULL, NULL);
		load("Guests.txt", NULL, Guests, NULL);
		load("MovieScreenings.txt", NULL, NULL, Movies);
	}
	catch (MyExceptions& e)
	{
		cout << "Exception: " << e.getError() << endl << endl;
	}

	bool flag = false;

	//calling the start function, that includes both registration
	//and login functions
	flag = start(currentUserType, currentUserID, Admins, Guests);

	//if everything is fine we can proceed
	if (flag) {

		string user_input;
		string comm;
		getline(cin, user_input);
		ShowCommands(currentUserType);
		do
		{
			cout << ">";
			//reading the user input
			getline(cin, user_input);
			//if user input is an empty string then we just skip this iteration
			if (user_input == "") { cout << '\b'; continue; }

			//we find the command in the input
			//and assign it to the comm
			comm = user_input.substr(0, user_input.find(" "));

			try {
				//depending on the currentusertype we call the command functions
				if (currentUserType == 1) {
					if (comm == "help" || comm == "0")	ShowCommands(currentUserType);
					else if (comm == "addMovieScreening" || comm == "1")	addMovieScreening(Movies, Guests);
					else if (comm == "deleteMovieScreening" || comm == "2")	deleteMovieScreening(Movies, Guests);
					else if (comm == "updateMovieScreening" || comm == "3")	updateMovieScreening(Movies);
					else if (comm == "registerGuest" || comm == "4")	registerGuest(Guests);
					else if (comm == "viewMovieScreeningDetails" || comm == "5")	viewMovieScreeningDetails(Movies);
					else if (comm == "viewListOfGuests" || comm == "6")	viewListOfGuests(Movies, Guests);
					else if (comm == "viewListOfBookings" || comm == "7")	viewListOfBookings("", Guests, Movies);
					else if (comm == "viewAvailableMovieScreenings" || comm == "8")	viewAvailableMovieScreenings(Movies);
					else if (comm == "viewMovieScreeningsWithSeats" || comm == "9")	viewMovieScreeningsWithSeats(Movies);
					else if (comm == "quitProgram" || comm == "exit" || comm == "!")	break;
					else if (comm == "clear") { system("clear"); ShowCommands(currentUserType); }
					else 																cout << "Invalid Command !!!" << endl;
				}
				if (currentUserType == 2) {
					if (comm == "help" || comm == "0")	ShowCommands(currentUserType);
					else if (comm == "viewAvailableMovieScreenings" || comm == "1")	viewAvailableMovieScreenings(Movies);
					else if (comm == "viewMovieScreeningsWithSeats" || comm == "2")	viewMovieScreeningsWithSeats(Movies);
					else if (comm == "bookASeat" || comm == "3")	bookASeat(Guests, Movies, currentUserID);
					else if (comm == "cancelBooking" || comm == "4")	cancelBooking(Guests, Movies, currentUserID);
					else if (comm == "viewYourListOfBookings" || comm == "5")	viewListOfBookings(currentUserID, Guests, Movies);
					else if (comm == "quitProgram" || comm == "exit" || comm == "!")	break;
					else if (comm == "clear") { system("clear"); ShowCommands(currentUserType); }
					else 																cout << "Invalid Command !!!" << endl;
				}
			}
			//all the exceptions that are thrown are caught here 
			catch (MyExceptions& e)
			{
				cout << "Exception: " << e.getError() << endl << endl;
			}
		} while (comm != "quitProgram");
	}

	//saving the system data to the txt files
	save("Admins.txt", "Guests.txt", "MovieScreenings.txt", Admins, Guests, Movies);

	return EXIT_SUCCESS;

}