#include "lib.hpp"

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
