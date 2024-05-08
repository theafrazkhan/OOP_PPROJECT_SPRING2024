
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