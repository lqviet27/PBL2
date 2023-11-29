#include"Record.cpp"

class Record_Chuyen:public Record
{
private:
    const static string Type;
public:
    Record_Chuyen();
    Record_Chuyen(string,string,string,long long);
    void Show();
    void RecordtoFile();
    ~Record_Chuyen();
};

