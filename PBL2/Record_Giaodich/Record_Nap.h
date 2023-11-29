#include"Record.cpp"

class Record_Nap:public Record
{
private:
    const static string Type;
public:
    Record_Nap();
    Record_Nap(string,string,long long);
    void Show();
    void RecordtoFile();
    ~Record_Nap();
};

