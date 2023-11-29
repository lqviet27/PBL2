#include"Record.cpp"

class Record_Rut:public Record
{
private:

public:
    Record_Rut();
    Record_Rut(string,string,double);
    void Show();
    void RecordtoFile();
    ~Record_Rut();
};

