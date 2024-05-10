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
