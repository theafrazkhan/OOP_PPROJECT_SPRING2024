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
};
