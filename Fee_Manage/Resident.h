//
// Created by ���ٕN on 2024-10-23.
//

#ifndef RESIDENT_H
#define RESIDENT_H

#include "Header.h"

class Resident {
public:
    /*�����������Ա���ϵ�绰��¥�ţ���Ԫ�ţ����ţ������
��ҵ���ۣ��߲�3Ԫ/ƽ�������2Ԫ/ƽ������¥�����֣�����̯ˮ��ѣ�*/
    Resident(string name, string sex, string phone, int floor, string unit, string room,
        double area, double price, double water_electric_fee)
            :_name(name),_sex(sex),_phone(phone),_floor(floor),_unit(unit),_room(room),
            _area(area),_price(price),_water_electric_fee(water_electric_fee)
    {}

    ~Resident(){}

    string _name;
    string _sex;
    string _phone;
    int _floor;
    string _unit;
    string _room;
    double _area;
    double _price;
    double _water_electric_fee;

    bool y_n_pay = false; // �Ƿ������ҵ��,Ĭ��δ����

    double payed_fee = 0.0; // �ѽ��ɵ���ҵ��
};


#endif //RESIDENT_H
