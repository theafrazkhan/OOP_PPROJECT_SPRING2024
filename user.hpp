
int main ();
using namespace std;
        

class User
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
        
        Check(); // cheaks if the email and password match
    }
    void Check() // cheaks if the email and password match
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

    }
};
