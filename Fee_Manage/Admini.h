//
// Created by ���ٕN on 2024-10-23.
//

#ifndef ADMINI_H
#define ADMINI_H

#include "Header.h"
#include "Resident.h"

class Admini {
public:
    Admini();
    ~Admini(){}
    virtual void do_window();
    void add_resident_window();
    void delete_resident_window();
    void modify_resident_window();
    void search_resident_window();

    vector<Resident> residents; // δ��ʼ������pushback�����Ԫ��

private:
    void creat_fee_window();

    void pay_fee_window();

    void statistic_window();


};



#endif //ADMINI_H
