//
// Created by ���ٕN on 2024-11-23.
//

#ifndef OPERA_H
#define OPERA_H

#include "Admini.h"


class Opera:public Admini {
public:
    Opera() {
        // ��ʼ�� vector<Resident> residents
        string resident_file = "resident_info.txt";
        ifstream infile(resident_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        string line;
        while(getline(infile,line)) {
            istringstream ss(line); // stringstream����ȿ��Դ��ַ����ж�ȡ���ݣ��ֿ������ַ�����д������
            string _n;
            string _g;
            string _t;
            string _f;
            string _u;
            string _r;
            string _a;
            string _p;
            string _w;
            ss >> _n >> _g >> _t >> _f >> _u >> _r >> _a >> _p >> _w;
            Resident resident(_n,_g,_t,stoi(_f),_u,_r,stod(_a),stod(_p),stod(_w));
            residents.push_back(resident); // ��resident��������vector��
        }
    }
    ~Opera(){}

    void do_window() {
        // ʵ�ֲ���Ա��¼�Ժ�Ĺ��ܽ���
        int choice;
        do {
            cout << "\t\t\t\t" << "Hello Dear Operator!" << endl;
            cout << "\t\t\t" << "1. Add new resident information" << endl;
            cout << "\t\t\t" << "2. Modify resident information" << endl;
            cout << "\t\t\t" << "3. Delete resident information" << endl;
            cout << "\t\t\t" << "4. Search resident information" << endl;
            cout << "\t\t\t" << "5. Exit" << endl;
            cout << endl;
            cout << "Please enter your choice: (1-5)";
            cin >> choice ;
            system("cls"); // ����
            if(choice < 1 || choice > 5){
                cout << "Invalid choice, please try again." << endl;
            }
        }while(choice < 1 || choice > 5);
        switch(choice) {
            case 1:
                add_resident_window();
            break;
            case 2:
                modify_resident_window();
            break;
            case 3:
                delete_resident_window();
            break;
            case 4:
                search_resident_window();
            break;
            case 5:
                exit(0);
        }
    }

};



#endif //OPERA_H
