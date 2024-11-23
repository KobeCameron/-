//
// Created by 王荣昇 on 2024-10-23.
//

#ifndef RESIDENT_H
#define RESIDENT_H

#include "Header.h"

class Resident {
public:
    /*户主姓名、性别、联系电话、楼号，单元号，房号，面积、
物业单价（高层3元/平方，多层2元/平方，由楼号区分），公摊水电费，*/
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

    bool y_n_pay = false; // 是否缴纳物业费,默认未缴纳

    double payed_fee = 0.0; // 已缴纳的物业费
};


#endif //RESIDENT_H
