#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iosfwd>
using namespace std;
int main();

class movie
{
public:
    vector<string> v;
    void getdata()
    {
        fstream input;// FILE *input
        input.open("movielist.txt", ios::in);
        string line;
        while (input)
        {
            getline(input, line);
            v.push_back(line);
        }
    }
    void show()
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
    }
};

class theater : public movie
{
public:
    int v8[100], v1[100], v5[100];
    theater()
    {
        for (int i; i < 100; i++)
        {
            v8[i] = 0;
            v5[i] = 0;
            v1[i] = 0;
        }
    }
};


//usertime class
class userTime {
    public:
    virtual bool Check(int s, theater t, int i) = 0;
};


int arr[100];

class TIME : public theater, userTime
{
public:
    int noob = 0;
    int seats;

    bool Check(int, theater, int);
    void timet()
    {
        theater();
        cout << "show time:\n1. 8:00am\n2. 1:00pm\n3. 5:00pm" << endl;
        cout << "Choose your show time : ";
        int x;
        cin >> x;
        theater t1, t2, t3;
        cout << "\nEnter the number of seats you want: ";
        cin >> seats;
        if (x == 1)
        {
            if (Check(seats, t1, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 1; i <= 100; i++)
                {
                    if (t1.v8[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t1.v8[x] = 1;
                }
            }
            else if (Check(seats, t2, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 1; i <= 100; i++)
                {
                    if (t2.v8[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t2.v8[x] = 1;
                }
            }
            else if (Check(seats, t3, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 1; i <= 100; i++)
                {
                    if (t3.v8[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t3.v8[x] = 1;
                }
            }
            else
            {
                noob = 1;
                cout << "in 8:00am  no seats are available" << endl;
            }
        }
        else if (x == 2)
        {
            if (Check(seats, t1, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 1; i <= 100; i++)
                {
                    if (t1.v1[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t1.v1[x] = 1;
                }
            }
            else if (Check(seats, t2, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 1; i <= 100; i++)
                {
                    if (t2.v1[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t2.v1[x] = 1;
                }
            }
            else if (Check(seats, t3, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 1; i <= 100; i++)
                {
                    if (t3.v1[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t3.v1[x] = 1;
                }
            }
            else
            {
                noob = 1;
                cout << "in 1:00pm  no seats are available" << endl;
            }
        }
        else if (x == 3)
        {
            if (Check(seats, t1, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 0; i <= 100; i++)
                {
                    if (t1.v5[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t1.v5[x] = 1;
                }
            }
            else if (Check(seats, t2, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 0; i <= 100; i++)
                {
                    if (t2.v5[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t2.v5[x] = 1;
                }
            }
            else if (Check(seats, t3, x))
            {
                cout << "Available seats are: " << endl;
                for (int i = 0; i <= 100; i++)
                {
                    if (t3.v5[i] == 0)
                        cout << i << "A ";
                    else
                        cout << i << "X ";
                    if (i % 10 == 0 and i != 0)
                        cout << endl;
                }
                for (int i = 0; i < seats; i++)
                {
                    int x = rand() % 99 + 1;
                    arr[i] = x;
                    t3.v5[x] = 1;
                }
            }
            else
            {
                noob = 1;
                cout << "in 5:00pm  no seats are available" << endl;
            }
        }
    }
};

class User : public userTime
{
public:
    string pass;
    string name;
    string address;
    string email;
    bool chk = false;

    void sign_up()
    {
    signUp:
        ofstream outfile;
        outfile.open("user.txt", ios::out | ios::app);
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\nEnter your email: ";
        cin >> email;

        if (!validate_email(email))
        {
            int choise;
            cout << "Invalid Email, press 0 for main menu and 1 to enter email: ";
            cin >> choise;

            switch (choise)
            {
            options:
            case 0:
                // goto main

                main();
            case 1:
                goto signUp;
            default:
                cout << "Invalid choise! press 0 for main menu and 1 to enter email: ";
                cin >> choise;
                goto options;
            }
        }

        cout << "\nEnter your password: ";
        cin >> pass;


        if (!validate_password(pass))
        {
            int choise;
            cout << "Invalid password, press 0 for main menu and 1 to enter correct credintials: ";
            cin >> choise;

            switch (choise)
            {
            uper:
            case 0:
                // goto main
                main();
            case 1:
                goto signUp;
            default:
                cout << "Invalid choise! press 0 for main menu and 1 to enter email: ";
                cin >> choise;
                goto uper;
            }
        }


        cout << "\nEnter your address: ";

        cin >> address;
        cout << endl;

        outfile << "Name: " << name << "\n";
        outfile << "Email: " << email << "\n";
        outfile << "Password: " << pass << "\n";

        outfile << "Address: " << address << "\n\n\n";
    }
    bool validate_email(const string email)
    {

        bool valid = false;
        bool at = false, dot = false, com = false;

        // iterators
        int i, j, k, l = 0;

        string domain = "";

        if (email[0] == '@')
        {
            return false;
        }

        int length = email.length();

        for (i = 0; i < length; i++)
        {
            if (email[i] == '@')
            {
                at = true;
                break;
            }
        }

        for (j = i + 1; j < length; j++)
        {
            if (email[j] == '.')
            {
                dot = true;
                break;
            }
        }

        string temp;
        for (k = j + 1; k < length; k++)
        {
            temp = email[k];
            domain = domain + temp;
        }

        if (domain == "net" or domain == "com" or domain == "edu.pk" or domain == "co" or domain == "io")
            com = true;

        valid = (at and dot and com);
        return valid;
    }

    bool validate_password(const string password)
    {
        bool cap = false, small = false, number = false, symbol = false, len = false;

        int length = password.length();
        if (length > 8)
        {
            len = true;
        }
        else
            return false;

        for (int i = 0; i < length; i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                small = true;
            }
            else if (password[i] >= 'A' && password[i] <= 'Z')
            {
                cap = true;
            }
            // 0 == 48 , 9 == 57 ASCII
            else if ((int)password[i] > 47 && (int)password[i] < 58)
            {
                number = true;
            }
            else
            {
                symbol = true;
            }
        }

        return (cap && small && number && symbol && len);
    }

    void sign_in()
    {
    signIn:
        cout << "Please enter your email: ";
        cin >> email;
        cout << "\nPlease enter your password:\n";
        cin >> pass;

        theater t;
        int x, y;
        
        Check(x, t, y); // cheaks if the email and password match
    }
    bool Check(int, theater, int) // cheaks if the email and password match
    {
        fstream fin;
        fin.open("user.txt", ios::in);
        string line;
        string chek1 = "email: " + email; // Operator overloading for strings
        string chek2 = "Password: " + pass;
        bool c1 = false, c2 = false;
        while (fin) // goes till EOF
        {
            getline(fin, line);

            if (c1 == false and line == chek1)
            {
                c1 = true;
                
            }
            if (c2 == false and chek2 == line)
            {
                c2 = true;
            }
            if (c1 and c2)
            {
                chk = true;
                break;
            }
        }
    return false;
    }
};

class ticket : public TIME, public User
{
public:
    int no;
    void buy(int no)
    {
        cout << "For movie no " << no << " the available ";
        timet();
        if (noob == 0)
        {
            cout << "\n\nPrice of ticket :" << seats * 300 << "tk" << endl;
            cout << "\nYour seats are: \n";
            for (int i = 0; i < seats; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n\nConfirm purchase?\nY/N" << endl;
            char q;
            cin >> q;
            if (q == 'Y')
            {
                cout << "Your ticket is purchased" << endl;
            }
        }
    }
       void available()
    {
        cout << "Available movies are\n\n";
        getdata();
        show();
        cout << "\nWhich movie do you want to watch?\nEnter the serial number: ";
        cin >> no;
        cout << "\n\n1 For buy ticket\n2 For booking " << endl;
        int x;
        cin >> x;
        if (x == 1)
            buy(no);
        else
            booking(no);
    }
    void booking(int no)
    {
        cout << "For movie no " << no << " the available ";
        timet();
        if (noob == 0)
        {
            cout << "\nYour seats are: \n";
            for (int i = 0; i < seats; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n\nConfirm booking?\nY/N" << endl;
            char q;
            cin >> q;
            if (q == 'Y')
            {
                cout << "Your ticket is booked" << endl;
            }
        }
    }

    
};


// card validator for payments
    bool validate_card(long long card)
    {
        long long counter;
        counter = card;
        int rem_doub;
        int rem_sin;
        int sum_doub = 0;
        int sum_sin = 0;
        int sum_total;

        // to find the sum of doubled digits of the card
        while (counter > 0)
        {
            counter /= 10;
            rem_doub = counter % 10;
            counter /= 10;
            rem_doub = rem_doub * 2;

            if (rem_doub >= 10)
            {
                int r = rem_doub % 10;
                rem_doub /= 10;
                rem_doub = rem_doub + r;
            }

            sum_doub += rem_doub;
        }

        counter = card;

        // to sum up the non doubled digits of the card
        while (counter > 0)
        {
            rem_sin = counter % 10;
            sum_sin += rem_sin;
            counter /= 100;
        }

        sum_total = sum_sin + sum_doub;

        return (sum_total % 10 == 0);
    }

    /*********************************fUNCTION TO CHECK CARD TYPE STARTS HERE*********************************************************/

    string card_type(long long card)
    {
        string type;
        // AMEX use 15 digit card number starting from 34 or 37

        if ((card >= 340000000000000 && card < 350000000000000) || (card >= 370000000000000 && card < 380000000000000))
        {
            type = "AMEX";
        }

        // Master card uses 16 digit numbers starting with 51 52 53 54 55

        if ((card >= 5100000000000000 && card < 5600000000000000))
        {
            type = "Master";
        }

        // Visa uses  13 and 16 digits and starts with 4

        if ((card >= 4000000000000 && card < 5000000000000) || (card >= 4000000000000000 && card < 5000000000000000))
        {
            type = "Visa";
        }

        // discover starts with 6 and have 16 digits

        if (card >= 6000000000000000 && card < 7000000000000000)
        {
            type = "Discover";
        }

        // union pay start with 62 and have 16 - 19 digits

        if ((card >= 6200000000000000 && card < 6300000000000000) || (card >= 62000000000000000 && card < 6300000000000000) || (card >= 620000000000000000 && card < 63000000000000000) || (card >= 6200000000000000000 && card < 6300000000000000000))
        {
            type = "unionPay";
        }

        return type;
    }

    /********************************FUNCTION TO CHECK CARD TYPE ENDS HERE**********************************************************/

 

    // This function will proceed checkout for any sort of purchase, its return will not likely be used
    // But can be taken as reference if the transaction was successfull and can be used to make further decisions
    bool checkOut(long long card, float price)
    {
        bool valid = false;
        string cardType;

        if (validate_card(card))
        {
            valid = true;
            cardType = card_type(card);

            cout << "your payment of " << price << " rupees from " << cardType << " card was successfull " << endl;
        }
        else
        {
            cout << "Transaction failed, Not a valid card Number";
        }

        return valid;
    }

    float addOns()
    {
     float total_food = 0; // Initialize total_food

        system("cls"); // to clear screen
        char c;
        int choice;
        int quant;
        cout << "WELCOME TO FOOD CORNER\n";
        cout << "\t\tMenu \n ";
        cout << "\nPopcorns --2$\nDrinks --2$\nBurger --5$\nPizza --8$\n\n";
        do
        {
            cout << "Press 1 for Popcorns\n";
            cout << "Press 2 for Drinks\n";
            cout << "Press 3 for Burgers\n";
            cout << "Press 4 for Pizza\n";
            cout << "Press 5 to go back\n";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Please enter how many Popcorn Buckets you want :\n";
                cin >> quant;
                total_food = total_food + (2 * quant); // multiplying with quantity and adding to total sum
            }
            else if (choice == 2)
            {
                cout << "Please enter how many drinks you want : \n";
                cin >> quant;
                total_food = total_food + quant * 2; // multiplying with quantity and adding to total sum
            }
            else if (choice == 3)
            {
                cout << "Please enter how many Burgers you want :\n";
                cin >> quant;
                total_food = total_food + quant * 5; // multiplying with quantity and adding to total sum
            }
            else if (choice == 4)
            {
                cout << "Please enter the number of Pizza You want : \n";
                cin >> quant;
                total_food = total_food + quant * 8; // multiplying with quantity and adding to total sum
            }
            else if (choice != 5) // when user inputs invalid command
            {
                cout << "Invalid command\n";
            }
        } while (choice != 5);
        // yaha ek lvl back jaha jana ha woh waha function aye ga
        return total_food;
    }


    bool TIME::Check(int cnt, theater t, int x)
{
    if (x == 1)
    {
        int i;
        for (i = 0; i < 100; i++)
        {
            if (t.v8[i] == 0 and cnt)
            {
                cnt--;
            }
            if (cnt == 0)
                break;
        }
        if (i == 100)
            return 0;
        return true;
    }
    if (x == 2)
    {
        int i;
        for (i = 0; i < 100; i++)
        {
            if (t.v1[i] == 0 and cnt)
            {
                cnt--;
            }
            if (cnt == 0)
                break;
        }
        if (i == 100)
            return 0;
        return true;
    }
    if (x == 3)
    {
        int i;
        for (i = 0; i < 100; i++)
        {
            if (t.v5[i] == 0 and cnt)
            {
                cnt--;
            }
            if (cnt == 0)
                break;
        }
        if (i == 100)
            return 0;
        return true;
    }
    return false;
}

int main()
{
mainMenu:
    ticket TKT;
    cout << "\t\t\t\t\t __________________________________________" << endl;
    cout << "\t\t\t\t\t|                                          |" << endl;
    cout << "\t\t\t\t\t|       Welcome to Irray Cineplex          |" << endl;
    cout << "\t\t\t\t\t|__________________________________________|" << endl
         << endl
         << endl;
    cout << "\t\t\t\t\t\tDo you have an account?" << endl;
    cout << "\t\t\t\t\t\tY/N" << endl;
    char x;
    cin >> x;
    if (x == 'Y' || x == 'y')
    {
        TKT.sign_in();
    }
    else if (x == 'N' || x == 'n')
    {
        TKT.sign_up();
    }
    else
    {
        cout << "Invalid option \n";
        goto mainMenu;
    }
    movie mo;
    while (1)
    {
        option:
        cout << "\t\t\t\t\t __________________________________________" << endl;
        cout << "\t\t\t\t\t|                                          |" << endl;
        cout << "\t\t\t\t\t|       Welcome to Irray Cineplex          |" << endl;
        cout << "\t\t\t\t\t|__________________________________________|" << endl
             << endl
             << endl;
        cout << "\t\t\t\t\t\tPlease choose your option:" << endl;
        cout << "\t\t\t\t\t\t1.Check all movies" << endl;
        cout << "\t\t\t\t\t\t2.Purchase tickets" << endl;
        cout << "\t\t\t\t\t\t3.Purchase refreshment" << endl;

        cout << "\t\t\t\t\t\t4.Exit" << endl;
        int m;
        cin >> m;
        if (m == 1)
        {
            mo.getdata();
            mo.show();
            cout << "\nDo you want to go back to the homepage?" << endl;
            cout << "Y/N" << endl;
            cin >> x;
            if (x == 'Y')
            {
                continue;
            }
            else
            {
                cout << "Thanks for visiting";
                break;
            }
        }
        else if (m == 2)
        {
            TKT.available();
            cout << "\nDo you want to go back to the homepage?" << endl;
            cout << "Y/N" << endl;
            cin >> x;
            if (x == 'Y')
            {
                continue;
            }
            else
            {
                cout << "Thanks for visiting";
                break;
            }
        }

        else if (m == 3)
        {
            float price;
            price = addOns();

            long long card;

            cout<< "Price for your selections is: " << price <<endl;
            cout<< "Enter your card number to proceed payment: ";
            cin >> card;

            bool status = checkOut (card, price);

            if (status)
            {
                cout << "Thankyou for using our services\n";
            } 
        }

        else if (m == 4)
        {
            cout << "Thanks for visiting";
            return 0;
        }

        else 
        {
            cout << "Invalid choise! \n";
            cout << "Press 1 to go to menu, 0 to exit \n";
            int choise ;
            cin >> choise; 

            if (choise == 0 )
            {
                return 0;
            }
            else if (choise == 1 )
            goto option;
        }
    }
}