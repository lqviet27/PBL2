#include"Record.cpp"

class Record_Rut:public Record
{
private:
    const static string Type;
public:
    Record_Rut();
    Record_Rut(string,string,long long);
    void Show();
    void RecordtoFile();
    ~Record_Rut();
};

