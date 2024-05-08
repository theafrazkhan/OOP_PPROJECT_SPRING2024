
class movie
{
public:
    vector<string> v;
    void getdata()
    {
        fstream input;
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
