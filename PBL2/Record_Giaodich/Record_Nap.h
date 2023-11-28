#include"Record.cpp"

class Record_Nap:public Record
{
private:

public:
    Record_Nap();
    Record_Nap(string,string,double);
    void Show();
    void RecordtoFile();
    ~Record_Nap();
};

