
int arr[100];

class TIME : public theater
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
