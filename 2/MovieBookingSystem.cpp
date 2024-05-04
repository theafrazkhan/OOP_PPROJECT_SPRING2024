#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<bits/stdc++.h> 
using namespace std;

//Template of a Linked List
template <typename N> class LinkedList;
//Template of Linked List Node
template <typename N> 
class Node{
	private:
		N elem;
		Node<N>* next;
	public:
		Node(N elem): elem(elem), next(NULL){}
		friend class LinkedList<N>;
};

//Linked List Class Template
template <typename N>
class LinkedList{
	private:
		Node<N>* head;
		friend class User;
		friend class MovieScreening;
	public:
		LinkedList();                                            //constructor
		~LinkedList();                                           //destructor
		bool empty() const;                                      //check if the linked list is empty
		string get_pswd(string& username);                       //return password given the username (used with guest/admin users when logging in) 
		void addFront(N& elem);                                  //add a node to the front
		void displayFreeMovies();                                //display movies that are not full
		bool isInList(string& search_id);                        //check if a node is in the list given the ID of guest/movie/admin
		void displayMovies();                                    //display all movie screenings
		void displayElem();                                      //display element of a node (used with type string lists)
		void displayGuests(string& searchid);                    //display guests that booked given the movie id
		void displayMovieScreeningDetails(string& searchid);     //display movie screening details
		void cleanup();                                          //
		void updateMS(string& searchid);                         //update a movie screening
		void deleteMS(string& searchid);                         //delete a mocie screening
		string getID(string& uname);                             //get ID of a user given the username
		void book(string& searchid, string& addid);              //add booking/guest to guest/movie list
		void unbook(string& searchid, string& addid);            //cancel booking
		void deleteByID(N& elem);                                //delete a node given its elemnt ID
		bool isBookingValid(string& searchid, string& checkid);  //check if a booking is valid/existent
		bool isInBookingList(string& searchid);                  //check if a given movie in a booking list of the guest
		string concatenateElements();                            //return all elements of the list as a single string (when element is a string)
		string concatenateList();                                //return all elements of the list as a single string (when element is an object of class Guest or MovieScreening)
		bool checkIfFull(string& searchid);                      //check if a movie screening is full
};

template<typename N>
LinkedList<N>::LinkedList ()
{
	this->head = NULL;
}

template<typename N>
LinkedList<N>::~LinkedList () 
{
	while (!empty()){
		Node<N>* to_delete = head;
		head = to_delete->next;
		delete to_delete;
	}
}

template<typename N>  
bool LinkedList<N>::empty() const
{
	if(head == NULL){
		return true;
	}else{
		return false;
	}
}

template<typename N>
string LinkedList<N>::get_pswd(string& uname)
{
	string pswd = "";
	Node<N>* current = head;
	while(current != NULL){
		if (current->elem->username == uname){
			pswd = current->elem->password;
			return pswd;
		}
		current = current->next;
	}
	cout<<"Invalid credentials. Try again."<<endl;
	return pswd;
	}

template<typename N>
string LinkedList<N>::getID(string& uname)
{
	string getid = "lol";
	string compare = uname;
	Node<N>* current = head;
	while(current != NULL){
		if (current->elem->username == compare){
			getid = current->elem->id;
			return getid;
		}
		
		current = current->next;
	}
	return getid;
}

template<typename N>
void LinkedList<N>::addFront(N& elem)
{
	Node<N>* t = new Node<N>(elem);
	t->elem = elem;
	t->next = head;
	head = t;
}

template<typename N>
void LinkedList<N>::deleteByID(N& todelete)
{
	Node<N>* current = head;
	Node<N>* temp;
	while(current->next != NULL){
		if(current->next->elem == todelete){
			temp = current->next;
			current->next = current->next->next;
			delete temp;
			return;
		}else{
			current = current->next;
		}
}}

template<typename N>
bool LinkedList<N>::isInList(string& searchid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			return true;
		} else {
			current=current->next;
		}
	}
	return false;
}

template<typename N>
bool LinkedList<N>::isInBookingList(string& searchid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem == searchid){
			return true;
		} else {
			current=current->next;
		}
	}
	return false;
}

template<typename N>
bool LinkedList<N>::checkIfFull(string& searchid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			return current->elem->isfull();
		} else {
			current=current->next;
		}
	}
	return false;
}

template<typename N>
void LinkedList<N>::displayFreeMovies() {
	Node<N>* current = head;
	while (current != NULL){
		if (!current->elem->isfull()){
			current->elem->display();
		}
		current = current->next;
	}
}

template<typename N>
void LinkedList<N>::displayMovies(){
	Node<N>* current = head;
	while(current!=NULL){
		current->elem->display();
		current = current->next;
	}
}

template<typename N>
void LinkedList<N>::displayElem(){
	Node<N>* pntr = this->head;
	do {
		cout<<pntr->elem<<endl;
		pntr = pntr->next;
	}
	while(pntr!=NULL);
	}

template<typename N>
void LinkedList<N>::displayGuests(string& searchid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			current->elem->guests->displayElem();
			return;
		} else {
			current=current->next;
		}
	}
}

template<typename N>
void LinkedList<N>::displayMovieScreeningDetails(string& searchid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			current->elem->displayDetails();
			return;
		} else {
			current=current->next;
		}
	}
}

template<typename N>
void LinkedList<N>::updateMS(string& searchid){
	string newDate;
	string newTime;
	string newLocation;

	cout<<"Please enter information that you want to update (Enter 0 if you do not want to update)"<<endl
		<<"New Date:     ";
	cin>>newDate;
	cout<<"New Time:     ";
	cin>>newTime;
	cout<<"New Location: ";
	cin>>newLocation;

	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			current->elem->updateMovieScreening(newDate, newTime, newLocation);
			return;
		} else {
			current=current->next;
		}
	}
}

template<typename N>
void LinkedList<N>::deleteMS(string& searchid){
	Node<N>* current = head;
	Node<N>* todelete;
	while(current->next != NULL){
		if(current->next->elem->id == searchid){
			todelete = current->next;
			current->next = current->next->next;
			delete todelete;
			return;
		} else {
			current=current->next;
		}
	}
}

template<typename N>
void LinkedList<N>::book(string& searchid, string& addid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			current->elem->addBooking(addid);
			return;
		} else {
			current=current->next;
		}
	}
}

template<typename N>
void LinkedList<N>::unbook(string& searchid, string& deleteid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			current->elem->removeBooking(deleteid);
			return;
		} else {
			current=current->next;
		}
	}
}

template<typename N>
bool LinkedList<N>::isBookingValid(string& searchid, string& checkid){
	Node<N>* current = head;
	while(current != NULL){
		if(current->elem->id == searchid){
			return(current->elem->isBooked(checkid));
		} else {
			current=current->next;
		}
	} return false;
}

template<typename N>
string LinkedList<N>::concatenateElements(){
	Node<N>* current = head;
	string elements = "";
	if(current != NULL){
		while(current->next != NULL){
			elements += current->elem+";";
			current=current->next;
			}
		elements = elements+current->elem;
	}
	return ("["+elements+"]");
}

template<typename N>
string LinkedList<N>::concatenateList(){
	Node<N>* current = head;
	string list = "";
	while(current->next != NULL){
		list += current->elem->concatenate()+"\n";
		current=current->next;
	}
	list = list+current->elem->concatenate();
	return list;
}

//class of a user
class User {
	public:
		string id;         //user id
		string firstName;  //user first name
		string lastName;   //user last name
		string username;   //user username
		string password;   //user password

	protected:
		User(string& id, string& fname, string& lname);                               //user constructor for creating a new user
		User(string& id, string& fname, string& lname, string& uname, string& pswrd); //user constructor for uploading a user
	};

User::User(string& x, string& fname, string& lname){
	id = x;
	firstName = fname;
	lastName = lname;
	transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
	username = fname + id;
	transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
	int random = rand()%(9000)+1000;
	password = lname + to_string(random);
	cout<<"REGISTERED: "<<endl
		<<"User ID    : "<<id<<endl
		<<"First Name : "<<firstName<<endl
		<<"Last Name  : "<<lastName<<endl
		<<"Username   : "<<username<<endl
		<<"Password   : "<<password<<endl;

};
User::User(string& x, string& fname, string& lname, string& uname, string& pswrd){
	id = x;
	firstName = fname;
	lastName = lname;
	username = uname;
	password = pswrd;
};

//admin class that inherits from user
class Admin:public User{
	public:
		Admin(string& x, string& f, string& l, string &u, string& p); //admin class constructor
};


Admin::Admin(string& x, string& f, string& l, string& u, string& p) : User(x, f, l, u, p){};

//guest class that inherits from user
class Guest:public User{
	public:
		Guest(string& x, string& f, string& l, string& u, string& p);  //constructor for uploading a guest
		Guest(string& x, string& f, string& l);                        //constructor for creating a new guest
		LinkedList<string>* bookings = new LinkedList<string>;         //linked list storing booked movie IDs of a single guest
		void addBooking(string& movieID);                              //add booking to guest's list
		void removeBooking(string& movieID);                           //cancel booking
		bool isBooked(string& movieID);                                //check if a movie is in the booking list given its ID
		string concatenate();                                          //return all guest info as a string
	private:
};

Guest::Guest(string& x, string& f, string& l, string& u, string& p) : User(x, f, l, u, p){};
Guest::Guest(string& x, string& f, string& l) : User(x, f, l){};
void Guest::addBooking(string& movieID){
	bookings->addFront(movieID);
}

void Guest::removeBooking(string& movieID){
	bookings->deleteByID(movieID);
}

bool Guest::isBooked(string& movieID){
	return(bookings->isInBookingList(movieID));
}

string Guest::concatenate(){
	string guest = "";
	guest = id + "," + firstName + "," + lastName + "," + username + "," + password + "," + bookings->concatenateElements();
	return guest;

}

//movie screening class 
class MovieScreening{
	public: 
		string id;                                           //movie screening id
		string name;                                         //movie screening name                                   
		int guestsN;                                         //number of guests that booked the screening
		int capacity;                                        //the capacity of the screening
		string date;                                         //screening date
		string time;                                         //screening time
		string hall;                                         //screnning location(hall)
		LinkedList<string>* guests = new LinkedList<string>; //linked list storing IDs of guests that booked the screening

		MovieScreening(string& mid, string& mname, string& mguestsN, string& mcapacity, string& mdate, string& mtime, string& mhall, string& mguests); //constructor for uploading a screening
		MovieScreening(string& mid, string& mname, string& mguestsN, string& mcapacity, string& mdate, string& mtime, string& mhall);                  //constructor for adding a screening
		void updateMovieScreening(string& ndate, string& ntime, string& nloc); //method that updates screnning date/time/location
		void viewListOfGuests();                              //display guests that booked the screening
		bool isfull();                                        //check if the screening is full
		void display();                                       //display the screening movie information
		void displayDetails();                                //display the screening details
		void addBooking(string& guesID);                      //add a guest to the list of guests given the guest ID
		void removeBooking(string& guestID);                  //remove guest from the list of bookings given the guest ID
		string concatenate();                                 //return all movie screening info as a string
};

MovieScreening::MovieScreening(string& mid, string& mname, string& mguestsN, string& mcapacity, string& mdate, string& mtime, string& mhall, string& mguests){
	id = mid;
	name = mname;
	guestsN = stoi(mguestsN);
	capacity = stoi(mcapacity);
	date = mdate;
	time = mtime;
	hall = mhall;
	string g = "";
	for (int i=1; i<mguests.length()-1; i++){
		if (mguests[i] != ';'){
			g += mguests[i];
		} else{
			guests->addFront(g);
			g = "";
		}
	}
	guests->addFront(g);
}

MovieScreening::MovieScreening(string& mid, string& mname, string& mguestsN, string& mcapacity, string& mdate, string& mtime, string& mhall){
	id = mid;
	name = mname;
	guestsN = stoi(mguestsN);
	capacity = stoi(mcapacity);
	date = mdate;
	time = mtime;
	hall = mhall;
}


void MovieScreening::display(){
	cout<<endl
		<<"   MOVIE TITLE: "<<name<<endl
		<<"ID:             "<<id<<endl
		<<"Date:           "<<date<<endl
		<<"Time:           "<<time<<endl
		<<"Location:       "<<hall<<endl;
}

void MovieScreening::displayDetails(){
	cout<<endl
		<<"   MOVIE TITLE:   "<<name<<endl
		<<"ID:               "<<id<<endl
		<<"Date:             "<<date<<endl
		<<"Time:             "<<time<<endl
		<<"Location:         "<<hall<<endl
		<<"Number of Guests: "<<guestsN<<endl
		<<"Capacity:         "<<capacity<<endl;
}

bool MovieScreening::isfull(){
	return( guestsN == capacity);
}

void MovieScreening::updateMovieScreening(string& ndate, string& ntime, string& nloc){
	if (ndate!="0"){
		date = ndate;
	}
	if (ntime!="0"){
		time = ntime;
	}
	if (nloc!="0"){
		hall = nloc;
	}
	cout<<"Updated succesfully:"<<endl;
	displayDetails();
}

void MovieScreening::addBooking(string& guestID){
	guests->addFront(guestID);
	guestsN++;

}

void MovieScreening::removeBooking(string& guestID){
	guests->deleteByID(guestID);
	guestsN--;
}

string MovieScreening::concatenate(){
	string screening = "";
	screening = id+","+name+","+to_string(guestsN)+","+to_string(capacity)+","+date+","+time+","+hall+","+guests->concatenateElements();
	return screening;
}

void UploadGuests(LinkedList<Guest*>& guest_list, vector<int>& user_ids)  //upload guests from a file
{
	vector <string> guestline;
	vector <string> guestbookings;

	string file_name;
	file_name = "Guests.txt";
	ifstream guests(file_name);
	if (guests.is_open()){

		string line;
		getline(guests, line);
		while(!guests.eof()){
			getline(guests, line);
			string str = "";
			for(int i=0; i<line.length(); i++){
				if(line[i] != ','){
					str += line[i];
				} else {
					guestline.push_back(str);
					str = "";
				}
			}

			Guest* tempo = new Guest(guestline[0], guestline[1], guestline[2], guestline[3], guestline[4]);
			
			string b = "";
			for (int i=1; i<str.length()-1; i++){
				if (str[i] != ';'){
					b += str[i];
				} else{
					tempo->addBooking(b);
					b = "";
				}
			}
			tempo->addBooking(b);
			guest_list.addFront(tempo);
			guestline.clear();
			guestbookings.clear();
			tempo = NULL;
			delete tempo;
		}
	}
	guests.close();
}

void UploadAdmins(LinkedList<Admin*>& admins_list, vector<int>& user_ids) //upload admins from a gile
{
	vector <string> adminline;
	

	string file_name;
	file_name = "Admins.txt";
	ifstream admins(file_name);
	if (admins.is_open()){

		string line;
		getline(admins, line);
		while(!admins.eof()){
			getline(admins, line);
			string str = "";
			for(int i=0; i<line.length(); i++){
				if(line[i] != ','){
					str += line[i];
				} else {
					adminline.push_back(str);
					str = "";
				}
			}
			adminline.push_back(str);
				
			Admin* tempo = new Admin(adminline[0], adminline[1], adminline[2], adminline[3], adminline[4]);
			user_ids.push_back(stoi(adminline[0]));
			admins_list.addFront(tempo);
			adminline.clear();
			tempo = NULL;
			delete tempo;
		}
	}
	admins.close();
}

void UploadMovies(LinkedList<MovieScreening*>& movies_list)               //upload Movie screenings from a file
{
	vector <string> movieline;
	string file_name;
	file_name = "MovieScreenings.txt";
	ifstream movies(file_name);
	if (movies.is_open()){

		string line;
		getline(movies, line);
		while(!movies.eof()){
			getline(movies, line);
			string str = "";
			for(int i=0; i<line.length(); i++){
				if(line[i] != ','){
					str += line[i];
				} else {
					movieline.push_back(str);
					str = "";
				}
			}
			MovieScreening* tempo  = new MovieScreening(movieline[0], movieline[1], movieline[2], movieline[3], movieline[4], movieline[5], movieline[6], str);
			movies_list.addFront(tempo);
			movieline.clear();
			tempo = NULL;
			delete tempo;
		}
	}
	movies.close();
}

bool login(string& user, LinkedList<Admin*>& admins_list)                 //admin log in
{
	string username;
	string password;

	cout<<"Enter username and password to login"<<endl;
	do{
		cout<<"Username: ";
		cin>>username;
		cout<<"Password: ";
		cin>>password;}
	while(admins_list.get_pswd(username) != password);
	return true;
}

bool login(string& user, LinkedList<Guest*>& guest_list, string& uname)   //user log in
{
	string username;
	string password;

	cout<<"Enter username and password to login"<<endl;
	do{
		cout<<"Username: ";
		cin>>username;
		cout<<"Password: ";
		cin>>password;}
	while(guest_list.get_pswd(username) != password);
	uname = username;
	return true;
}

void registerguest(LinkedList<Guest*>& guest_list, vector<int>& user_ids, string& uname) //register a new guest
{
	string fname;
	string lname;
	string id;
	bool unique_id = true;
	cout<<"REGISTER GUEST"<<endl
		<<"First Name: ";
	cin>>fname;
	cout<<"Last Name: ";
	cin>>lname;
	int randid;
	do{
		srand(time(NULL));	
		randid = rand()%(9000)+1000;
		for(int i=0; i<user_ids.size(); i++){
			if (randid == user_ids[i]){
				unique_id = false;
			}
		}
	}
	while(!unique_id);
	user_ids.push_back(randid);
	id = to_string(randid);
	Guest* guest = new Guest(id, fname, lname);
	uname = guest->username;
	guest_list.addFront(guest);
	guest = NULL;
	delete guest;
}

void displayAdminMenu()     //display admin's menu screen
{
	cout<<endl
		<<"List of Operations:"<<endl
		<<" - 1 : View Available Screenings"<<endl
		<<" - 2 : View Screenings Available for Booking"<<endl
		<<" - 3 : View List of Guests"<<endl
		<<" - 4 : View Movie Screening Details"<<endl
		<<" - 5 : Update Movie Screening"<<endl
		<<" - 6 : Add Movie Screening"<<endl
		<<" - 7 : Delete Movie Screening"<<endl
		<<" - 0 : Exit the Program"<<endl
		<<">>";
}

string adminAction()        //get admin's choice from the menu
{
	string choice;
	cin>>choice;
	while( !(choice=="0" || choice=="1" || choice=="2" || choice=="3" || choice=="4" || choice=="5" || choice =="6" || choice =="7")){
		cout<<"Invalid input. Please choose one of the abailable options below.";
		displayAdminMenu();
		cin>>choice;
	}
	return choice;
}

void displayGuestMenu()     //diaplay guest's menu screen
{
	cout<<endl
		<<"List of Operations:"<<endl
		<<" - 1 : View Available Screenings"<<endl
		<<" - 2 : View Screenings Available for Booking"<<endl
		<<" - 3 : Book a Seat"<<endl
		<<" - 4 : Cancel Booking"<<endl
		<<" - 0 : Exit the Program"<<endl
		<<">>";
}

string guestAction()        //get guest's choice from the menu
{
	string choice;
	cin>>choice;
	while( !(choice=="0" || choice=="1" || choice=="2" || choice=="3" || choice=="4")){
		cout<<"Invalid input. Please choose one of the abailable options below.";
		displayGuestMenu();
		cin>>choice;
	}
	return choice;
}

void movieGuests(LinkedList<MovieScreening*>& movies_list)                //display guests of a movie screening
{
	string input_id;
	cout<<"Enter movie screening ID to see guests"<<endl
		<<">>";
	cin>>input_id;
	while(!movies_list.isInList(input_id)){
		cout<<"Invalid ID. Please try again!"<<endl
			<<">>";
		cin>>input_id;
	}
	movies_list.displayGuests(input_id);
}

void viewMovieScreeningDetails(LinkedList<MovieScreening*>& movies_list)  //display movie screening details
{
	string input_id;
	cout<<"Enter movie screening ID to see details"<<endl
		<<">>";
	cin>>input_id;
	while(!movies_list.isInList(input_id)){
		cout<<"Invalid ID. Please try again!"<<endl
			<<">>";
		cin>>input_id;
	}
	movies_list.displayMovieScreeningDetails(input_id);
}

void updateMovieScreening(LinkedList<MovieScreening*>& movies_list)       //update movie screening date/time/location
{
	string input_id;
	cout<<"Enter movie screening ID to update"<<endl
		<<">>";
	cin>>input_id;
	while(not(movies_list.isInList(input_id))){
		cout<<"Invalid ID. Please try again!"<<endl
			<<">>";
		cin>>input_id;
	}
	movies_list.updateMS(input_id);
	cout<<"Movie scnreening has been updated successfully!"<<endl;
}

void addMovieScreening(LinkedList<MovieScreening*>& movies_list)          //add a new movie screening
{
	string nid;
	string nname;
	string nguestsN;
	string ncapacity;
	string ndate;
	string ntime;
	string nloc;
	cout<<"Enter the following details to add a new Movie Screening"<<endl;
	cout<<"ID:               >>";
	cin>>nid;
	while(movies_list.isInList(nid)){
		cout<<"Movie with given ID alreday exists. Please try again :)"<<endl
			<<"ID:               >>";
		cin>>nid;
	}
	cout<<"Name:             >>";
	cin>>nname;
	cout<<"Date:             >>";
	cin>>ndate;
	cout<<"Time:             >>";
	cin>>ntime;
	cout<<"Location:         >>";
	cin>>nloc;
	cout<<"Number of Guests: >>";
	cin>>nguestsN;
	cout<<"Capacity:         >>";
	cin>>ncapacity;

	MovieScreening* temp = new MovieScreening(nid, nname, nguestsN, ncapacity, ndate, ntime, nloc);
	movies_list.addFront(temp);
	temp = NULL;
	delete temp;
	movies_list.displayMovieScreeningDetails(nid);
	cout<<endl<<"MovieScreening added to the system!"<<endl;
}

void deleteMovieScreening(LinkedList<MovieScreening*>& movies_list)       //delete a movie screening
{
	string input_id;
	cout<<"Enter movie screening ID to delete"<<endl
		<<">>";
	cin>>input_id;
	while(not(movies_list.isInList(input_id))){
		cout<<"Invalid ID. Please try again!"<<endl
			<<">>";
		cin>>input_id;
	}
	movies_list.deleteMS(input_id);
	cout<<"Movie succesfully deleted."<<endl;
}

void bookASeat(LinkedList<Guest*>& guest_list, LinkedList<MovieScreening*>& movies_list, string username)     //book a seat in a movie screening
{
	string userID = guest_list.getID(username);
	string movieID;
	cout<<"Endter a movie ID to book it"<<endl
		<<">>";
	cin>>movieID;
	while(!movies_list.isInList(movieID) || movies_list.checkIfFull(movieID)){
		cout<<"Invalid movie ID. Please try again."<<endl
			<<">>";
		cin>>movieID;
	}
	guest_list.book(userID, movieID);
	movies_list.book(movieID, userID);

	cout<<"A seat is successfully booked!"<<endl;
}

void deleteBooking(LinkedList<Guest*>& guest_list, LinkedList<MovieScreening*>& movies_list, string username) //cancel a booking
{
	string userID;
	userID = guest_list.getID(username);
	string movieID;
	cout<<"Enter a movie ID to cancel booking"<<endl
		<<">>";
	cin>>movieID;
	while(!guest_list.isBookingValid(userID, movieID)){ //check if we ever add the booking to the list of bookings
		cout<<"You cannot cancel a booking you dont have. Please try again."<<endl
			<<">>";
		cin>>movieID;
	}

	guest_list.unbook(userID, movieID);
	movies_list.unbook(movieID, userID);

	cout<<"Booking was cancelled successfully :("<<endl;
\
}

void quitProgram(LinkedList<Guest*>& guest_list, LinkedList<MovieScreening*>& movies_list)  //exit the program after saving to files
{	
	string guestFile = "guest_id,first_name,last_name,username,password,list_of_bookings\n";
	guestFile += guest_list.concatenateList();
	ofstream guestfile;
	guestfile.open("Guests.txt");
	guestfile<<guestFile;
	guestfile.close();

	string movieFile = "movie_screening_id,movie_name,number_of_guests,maximum_capacity,screening_date,screening_time,hall_name,list_of_guests\n";
	movieFile += movies_list.concatenateList();
	ofstream moviefile;
	moviefile.open("MovieScreenings.txt");
	moviefile<<movieFile;
	moviefile.close();
}

int main(){
	LinkedList<Admin*> admins_list;           //list of admins
	LinkedList<Guest*> guest_list;            //list of guests
	LinkedList<MovieScreening*> movies_list;  //list of movie screenings
	vector <int> user_ids;                    //vector containing all user ids in int form
	UploadAdmins(admins_list, user_ids);
	UploadGuests(guest_list, user_ids);
	UploadMovies(movies_list);
	
	string user;             
	string logreg;
	string action_choice;
	bool exit = false;
	string userName;

	//welcome screen
	cout<<"Welcome to MTMS!"<<endl
			<<"Please identify yourself"<<endl
			<<" - Enter 1 for Admin"<<endl
			<<" - Enter 2 for Guest"<<endl
			<<">>";
		cin>>user;

	//user input error checking
	while (not(user == "1" || user == "2")){
		cout<<"Please choose one of the available options!"<<endl<<">>";
		cin>>user;
	}

	//logging in or registering the user
	if (user == "1" && login(user, admins_list)){
		displayAdminMenu();
		action_choice = adminAction();
	} else {

		cout<<" - Enter 1 if you want to log in"<<endl
			<<" - Enter 2 if you want to register"<<endl
			<<">>";
		cin>>logreg;
		while (not(logreg == "1" || logreg == "2")){
			cout<<"Please choose one of the available options!"<<endl<<">>";
			cin>>logreg;
		}

		if (logreg == "1" && login(user, guest_list, userName)){
			displayGuestMenu();
			action_choice = guestAction();
		}else{
			registerguest(guest_list, user_ids, userName);
			displayGuestMenu();
			action_choice = guestAction();

		}
	}

	//menu screen interactions
	while(!exit){
		if (action_choice=="1"){
			movies_list.displayMovies();
		} else if (action_choice=="2"){
			movies_list.displayFreeMovies();
		} else if (action_choice=="3" && user=="1"){
			movieGuests(movies_list); 
		} else if (action_choice=="4" && user=="1"){
			viewMovieScreeningDetails(movies_list);
		} else if (action_choice=="5"){
			updateMovieScreening(movies_list);
		} else if (action_choice=="0"){
			exit = true;
			break;
		} else if (action_choice=="6"){
			addMovieScreening(movies_list); 
		} else if (action_choice=="7"){
			deleteMovieScreening(movies_list);
		} else if (action_choice=="3" && user=="2"){
			bookASeat(guest_list, movies_list, userName);
		} else if (action_choice=="4" && user=="2"){
			deleteBooking(guest_list, movies_list, userName);
		}

		if(user=="1"){
			displayAdminMenu();
			action_choice = adminAction();
		} else{
			displayGuestMenu();
			action_choice = guestAction();
		}
	}

	quitProgram(guest_list, movies_list);

	return 0;
}