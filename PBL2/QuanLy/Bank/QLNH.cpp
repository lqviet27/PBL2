#include "QLNH.h"

void QLNH::addBank(const Bank& b){
    parBank.Add(b);
}


void QLNH::showBank(){
    parBank.Show();
}