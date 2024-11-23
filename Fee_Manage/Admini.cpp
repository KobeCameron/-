//
// Created by ���ٕN on 2024-10-23.
//

#include "Admini.h"
#include "Resident.h"

Admini::Admini() {
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
void Admini::do_window() {
    // ʵ�ֹ���Ա��¼�Ժ�Ĺ��ܽ���
    int choice;
    do {
        cout << "\t\t\t\t" << "Hello Dear Administrator!" << endl;
        cout << "\t\t\t" << "1. Add new resident information" << endl;
        cout << "\t\t\t" << "2. Modify resident information" << endl;
        cout << "\t\t\t" << "3. Delete resident information" << endl;
        cout << "\t\t\t" << "4. Search resident information" << endl;
        cout << "\t\t\t" << "5. Creat resident management fee" << endl;
        cout << "\t\t\t" << "6. Pay resident management fee" << endl;
        cout << "\t\t\t" << "7. Statistic information" << endl;
        cout << "\t\t\t" << "8. Exit" << endl;
        cout << endl;
        cout << "Please enter your choice: (1-8)";
        cin >> choice ;
        system("cls"); // ����
        if(choice < 1 || choice > 8){
            cout << "Invalid choice, please try again." << endl;
        }
    }while(choice < 1 || choice > 8);
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
            creat_fee_window();
        break;
        case 6:
            pay_fee_window();
        break;
        case 7:
            statistic_window();
        break;
        case 8:
            exit(0);
    }
}

void Admini::add_resident_window() {
    // ʵ����Ӿ�����Ϣ����
    /*�����������Ա���ϵ�绰��¥�ţ���Ԫ�ţ����ţ������
��ҵ���ۣ��߲�3Ԫ/ƽ�������2Ԫ/ƽ������¥�����֣�����̯ˮ���*/
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t" << "Add New Resident Window" << endl;
        string n;
        cout << "\t\t\t" << "Please enter resident's name: ";
        cin >> n;
        string g;
        cout << "\t\t\t" << "Please enter resident's gender: ";
        cin >> g;
        string t;
        cout << "\t\t\t" << "Please enter resident's telephone number: ";
        cin >> t;
        int f;
        cout << "\t\t\t" << "Please enter resident's floor number: ";
        cin >> f;
        string u;
        cout << "\t\t\t" << "Please enter resident's unit number: ";
        cin >> u;
        string r;
        cout << "\t\t\t" << "Please enter resident's room number: ";
        cin >> r;
        double a;
        cout << "\t\t\t" << "Please enter resident's area: ";
        cin >> a;
        double w;
        cout << "\t\t\t" << "Please enter resident's water and electricity fee: ";
        cin >> w;
        double p;
        // ����¥��������ҵ����(����6¥Ϊ�߲㣬С�ڵ���6¥Ϊ�Ͳ�)
        if(f > 6) {
            p = 3.0;
        }
        else {
            p = 2.0;
        }
        // ����Ϣд���ļ�(��resident��)
        Resident resident(n,g,t,f,u,r,a,p,w);

        residents.push_back(resident); // ��resident��������vector��

        string resident_file = "resident_info.txt";
        ofstream outfile(resident_file,ios::app); // ׷��ģʽ���ļ�
        if(!outfile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        outfile << resident._name << " " << resident._sex << " " << resident._phone << " " << resident._floor << " " << resident._unit << " " << resident._room << " " << resident._area << " " << resident._price << " " << resident._water_electric_fee << endl;
        outfile.close();
        cout << "\t\t\t" << "Add new resident information successfully!" << endl;
        string choose;
        cout << "\t\t\t" << "contunue? (y/n)";
        cin >> choose;
        if(choose == "n") {
            flag = false;
        }
        else {
            system("cls"); // ����
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    do_window();
}

void Admini::search_resident_window() {
    // ʵ������������Ϣ����
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t\t" << "Search a Resident Information Window" << endl;
        string n;
        cout << "\t\t\t" << "Please enter resident's name you want to search: ";
        cin >> n;

        // #########################��vector<Resident>������
        bool flag_find = false;
        for(auto i = residents.begin(); i != residents.end(); ++i) {
            if(i->_name == n) {
                cout << "\t\t\t" << "Find the Resident's information!:" << endl;
                cout << "\t\t\t" << "Name: " << i->_name << endl;
                cout << "\t\t\t" << "Gender: " << i->_sex << endl;
                cout << "\t\t\t" << "Telephone number: " << i->_phone << endl;
                cout << "\t\t\t" << "Floor number: " << i->_floor << endl;
                cout << "\t\t\t" << "Unit number: " << i->_unit << endl;
                cout << "\t\t\t" << "Room number: " << i->_room << endl;
                cout << "\t\t\t" << "Area: " << i->_area << endl;
                cout << "\t\t\t" << "Price: " << i->_price << endl;
                cout << "\t\t\t" << "Water and electricity fee: " << i->_water_electric_fee << endl;
                flag_find = true;
                break;
            }
        }
        if(!flag_find) {
            cout << "\t\t\t" << "Sorry, the resident's information is not found!" << endl;
        }


        // ��Ҫ�����еľ�����Ϣ�ļ�������
        /*string resident_file = "resident_info.txt";
        ifstream infile(resident_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        bool flag_find = false;
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
            if(_n == n) {
                cout << "\t\t\t" << "Find the Resident's information!:" << endl;
                cout << "\t\t\t" << "Name: " << _n << endl;
                cout << "\t\t\t" << "Gender: " << _g << endl;
                cout << "\t\t\t" << "Telephone number: " << _t << endl;
                cout << "\t\t\t" << "Floor number: " << _f << endl;
                cout << "\t\t\t" << "Unit number: " << _u << endl;
                cout << "\t\t\t" << "Room number: " << _r << endl;
                cout << "\t\t\t" << "Area: " << _a << endl;
                cout << "\t\t\t" << "Price: " << _p << endl;
                cout << "\t\t\t" << "Water and electricity fee: " << _w << endl;
                flag_find = true;
                break;
            }
        }
        if(!flag_find) {
            cout << "\t\t\t" << "Sorry, the resident's information is not found!" << endl;
        }
        infile.close();
        */

        string choose;
        cout << "\t\t\t" << "contunue? (y/n)";
        cin >> choose;
        if(choose == "n") {
            flag = false;
        }
        else {
            system("cls"); // ����
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    do_window();
}

void Admini::modify_resident_window() {
    // ʵ���޸ľ�����Ϣ����
    // ˼·������vector<vector<string> > ���洢�ұ����ı��ļ���õľ�����Ϣ��
    // �û���������Ҫ�޸ĵľ�����������Լ���Ҫ���޸ĵ���Ϣ��Ӧ�ı�ţ�
    // �Լ��޸ĵ������ݣ�Ȼ����vector<vector<string> > �����޸Ķ�Ӧ����Ϣ �����õ���������
    // Ȼ���ٽ��޸ĺ����Ϣд���ı��ļ��������ʾ�޸ĳɹ���
    bool flag = true;
    // vector<vector<string> > resident_info;
    while(flag) {
        cout << "\t\t\t\t\t" << "Modify a Resident Information Window" << endl;
        cout << "\t\t\t" << "1. Name" << endl;
        cout << "\t\t\t" << "2. Gender" << endl;
        cout << "\t\t\t" << "3. Telephone number" << endl;
        cout << "\t\t\t" << "4. Floor number" << endl;
        cout << "\t\t\t" << "5. Unit number" << endl;
        cout << "\t\t\t" << "6. Room number" << endl;
        cout << "\t\t\t" << "7. Area" << endl;
        cout << "\t\t\t" << "8. Price" << endl;
        cout << "\t\t\t" << "9. Water and electricity fee" << endl;
        cout << "\t\t\t" << "10. Exit" << endl;
        cout << endl;

        // ��Ҫ�����еľ�����Ϣ�ļ�������
        /*string resident_file = "resident_info.txt";
        ifstream infile(resident_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }

        string line;
        while(getline(infile,line)) {
            istringstream ss(line); // stringstream����ȿ��Դ��ַ����ж�ȡ���ݣ��ֿ������ַ�����д������
            vector<string> resident;
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

            resident.push_back(_n);
            resident.push_back(_g);
            resident.push_back(_t);
            resident.push_back(_f);
            resident.push_back(_u);
            resident.push_back(_r);
            resident.push_back(_a);
            resident.push_back(_p);
            resident.push_back(_w);

            resident_info.push_back(resident); // ��������Ϣ����vector��

        }
        infile.close();
        */
        string n;
        cout << "\t\t\t" << "Please enter resident's name you want to modify: ";
        cin >> n;
        int choice;
        cout << "\t\t\t" << "Please enter the number of the information you want to modify: ";
        cin >> choice;
        cout << "\t\t\t" << "Please enter the new content: ";
        string new_content;
        cin >> new_content;
        // �޸���Ϣ
        bool flag_find = false;
        // #################����vector<Resident> �ҵ���Ӧ�ľ�����Ϣ�����޸���Ϣ

        for(auto i = residents.begin(); i != residents.end(); ++i) {
            if(i->_name == n) {
                switch(choice) {
                    case 1:
                        i->_name = new_content; // �޸�����
                        break;
                    case 2:
                        i->_sex = new_content; // �޸��Ա�
                        break;
                    case 3:
                        i->_phone = new_content; // �޸ĵ绰����
                        break;
                    case 4:
                        i->_floor = stoi(new_content); // �޸�¥��
                        break;
                    case 5:
                        i->_unit = new_content; // �޸ĵ�Ԫ��
                        break;
                    case 6:
                        i->_room = new_content; // �޸ķ���
                        break;
                    case 7:
                        i->_area = stod(new_content); // �޸����
                        break;
                    case 8:
                        i->_price = stod(new_content); // �޸���ҵ����

                        break;
                    case 9:
                        i->_water_electric_fee = stod(new_content); // �޸Ĺ�̯ˮ���
                        break;
                    default:
                        cout << "\t\t\t" << "Invalid choice, please try again." << endl;
                        break;
                }
                flag_find = true;
                // ���޸ĺ����Ϣд���ı��ļ�
                string resident_file = "resident_info.txt";
                ofstream outfile(resident_file);
                if(!outfile) {
                    cerr << "Error: file not found." << endl;
                    exit(1);
                }
                for(auto j = residents.begin(); j != residents.end(); ++j) {
                    outfile << j->_name << " " << j->_sex << " " << j->_phone << " " << j->_floor << " " << j->_unit << " " << j->_room << " " << j->_area << " " << j->_price << " " << j->_water_electric_fee << endl;
                }
                outfile.close();
                cout << "\t\t\t" << "Modify the resident's information successfully!" << endl;
                break;
            }
        }
        if(!flag_find) {
            cout << "\t\t\t" << "Sorry, the resident's information is not found!" << endl;
        }

        string choose;
        cout << "\t\t\t" << "contunue? (y/n)";
        cin >> choose;
        if(choose == "n") {
            flag = false;
        }
        else {
            system("cls"); // ����
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    do_window();
}

void Admini::delete_resident_window() {
    //     // ʵ��ɾ��������Ϣ����
    //     // ˼·������vector<vector<string> > ���洢�ұ����ı��ļ���õľ�����Ϣ��
    //     // �û���������Ҫɾ���ľ����������Ȼ����vector<vector<string> > ���õ������ҵ���Ӧ����Ϣ��
    //     // �÷����㷨find_ifѰ������vector<vector<string> > �е�λ�ã�
    //     // ���е�if�������ж��Ƿ��������������ͬ��
    //     // Ȼ����eraseɾ����
    //     // ����ٽ�ɾ�������Ϣд���ı��ļ��������ʾɾ���ɹ���
    bool flag = true;
    // vector<vector<string> > resident_info;
    while(flag) {
        cout << "\t\t\t\t\t" << "Delete a Resident Information Window" << endl;
        cout << endl;

        // ��Ҫ�����еľ�����Ϣ�ļ�������
        /*string resident_file = "resident_info.txt";
        ifstream infile(resident_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }

        string line;
        while(getline(infile,line)) {
            istringstream ss(line); // stringstream����ȿ��Դ��ַ����ж�ȡ���ݣ��ֿ������ַ�����д������
            vector<string> resident;
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

            resident.push_back(_n);
            resident.push_back(_g);
            resident.push_back(_t);
            resident.push_back(_f);
            resident.push_back(_u);
            resident.push_back(_r);
            resident.push_back(_a);
            resident.push_back(_p);
            resident.push_back(_w);

            resident_info.push_back(resident); // ��������Ϣ����vector��
            // ��Ϊ��û�г�ʼ��vector<vector<string> >��������Ҫ��push_back�����Ԫ�أ����õ�����

        }
        infile.close();
        */

        string n;
        cout << "\t\t\t" << "Please enter resident's name you want to delete: ";
        cin >> n;
        // ɾ����Ϣ

        auto it = find_if(residents.begin(), residents.end(),
         [&n](const Resident& resident) {
             // ����� resident �ǵ�ǰ��������������

             return resident._name == n; // ����һ��Ԫ�أ�������
         });
        if(it != residents.end()) {
            residents.erase(it); // ɾ�������û���

            // д���ļ� ��vector<Resident> д���ı��ļ�
            string resident_file = "resident_info.txt";
            ofstream outfile(resident_file);
            if(!outfile) {
                cerr << "Error: file not found." << endl;
                exit(1);
            }
            for(auto j = residents.begin(); j != residents.end(); ++j) {
                outfile << j->_name << " " << j->_sex << " " << j->_phone << " " << j->_floor << " " << j->_unit << " " << j->_room << " " << j->_area << " " << j->_price << " " << j->_water_electric_fee << endl;
            }
            outfile.close();
            cout << "\t\t\t" << "Delete the resident's information successfully!" << endl;
        }
        else {
            cout << "\t\t\t" << "Sorry, the resident's information is not found!" << endl;
        }

        string choose;
        cout << "\t\t\t" << "contunue? (y/n)";
        cin >> choose;
        if(choose == "n") {
            flag = false;
        }
        else {
            system("cls"); // ����
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    do_window();
}


void Admini::creat_fee_window() {
    // ʵ��Ӧ����ҵ���Զ����ɣ�ÿ��1�������ɽɷѶ��������Ƿ��ʵʩ�ۼӣ�
    // ����ÿ��1 % �ı�׼��ȡ���ɽ�

    // ˼·��
    // 1 ���ж��ǲ��ǵ�ǰ����µ�һ�ţ�����ǣ�������ҵ��û�н�������ֻ������Ӧ����ҵ��
    // 2 �������һ�ţ�����ҵ��û�н�������ô��Ҫ���㵱ǰ��������ĵ�ǰ�·�1�ŵ�������ֵ��
    // ���������ɻ�����Ӧ����ҵ�ѣ�Ȼ���ټ������ɽ�����ټ�����ҵ�ѣ�
    // 3 �����ҵ���Ѿ���������ֱ����ʾ�Ѿ�������ͬʱҲ�����ѽ�������Ŀ��

    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t\t" << "Create Managment Fee Window" << endl;
        cout << endl;
        string n;
        cout << "\t\t\t" << "Please enter resident's name(Administrator): ";
        cin >> n;
        // �ҵ���Ӧ�ľ�����Ϣ
        auto it = find_if(residents.begin(), residents.end(),
         [&n](const Resident& resident) {
             // ����� resident �ǵ�ǰ��������������

             return resident._name == n; // ����һ��Ԫ�أ�������
         });
        if(it != residents.end()) {
            // �ҵ��˾�����Ϣ
            // �Ȼ�ȡ��ǰ���ڲ��ж��Ƿ�Ϊ1�ţ�
            time_t now = time(0);
            // ����ʱ��
            tm *ltm = localtime(&now);
            // ��ȡ��ǰ������
            int year = 1900 + ltm->tm_year;
            int month = 1 + ltm->tm_mon;
            int day = ltm->tm_mday;

            // �����ɻ�����Ӧ����ҵ��
            double base_fee = it->_price * it->_area + it->_water_electric_fee; // ������ҵ��

            // �ж��Ƿ�Ϊ1��
            if (day == 1) {
                std::cout << "\t\t\t" << "Today is " << year << "Y" << month << "M" << " first day." << std::endl;
                // �ж���ҵ���Ƿ��Ѿ�����
                if(it->y_n_pay == false){
                    // û�н���������Ӧ����ҵ��
                    cout << "\t\t\t" << "You Should Pay " << base_fee << " as Management Fee."<< endl;
                }
                else {
                    // �Ѿ���������ʾ�ѽ�������Ŀ
                    cout << "\t\t\t" << "You Have Paid " << base_fee << " as Management Fee."<< endl;
                }


            }
            // ����1�ţ���������ɽ�
            int days_gap = day - 1; // ���㵱ǰ������1�ŵ�������ֵ
            double late_fee = base_fee * days_gap * 0.01; // �������ɽ�
            double total_fee = base_fee + late_fee; // �����ܷ���
            // �ж���ҵ���Ƿ��Ѿ�����
            if(it->y_n_pay == false){
                // û�н���������Ӧ����ҵ��
                cout << "\t\t\t" << "Today is " << year << "Y" << month << "M" << day << "D" << std::endl;
                cout << "\t\t\t" << "You Should Pay " << total_fee << " as Management Fee."<< endl;
            }
            else {
                // �Ѿ���������ʾ�ѽ�������Ŀ
                cout << "\t\t\t" << "You Have Paid " << total_fee << " as Management Fee."<< endl;
            }

        }
        else {
            cout << "\t\t\t" << "Sorry, the resident's information is not found!" << endl;
        }
        string choose;
        cout << "\t\t\t" << "contunue? (y/n)";
        cin >> choose;
        if(choose == "n") {
            flag = false;
        }
        else {
            system("cls"); // ����
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    do_window();
}

void Admini::pay_fee_window() {
    // �ô�����Ҫ��ʵ����ҵ�ѽ��ɹ��ܣ�ƥ���û�����
    // �ṩѡ�1. һ�ν���һ����ҵ�� 2. ��ǰ������� ���������н����ġ�
    // 3. һ��ֻ����һ������ҵ�ѡ�
    // ����������һ�ν���һ����ҵ�ѵ�ס������9���Żݣ�������ǰ������ɵ�ס������97���Żݡ�
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t\t" << "Pay Management Fee Window" << endl;
        cout << endl;
        cout << "\t\t\t" << "1. Once Pay for a Year Management Fee(0.9 discount)" << endl;
        cout << "\t\t\t" << "2. Advance Pay for Half a Year Management Fee(0.97 discount)" << endl;
        cout << "\t\t\t" << "3. Once Pay for a Month Management Fee" << endl;

        string n;
        cout << "\t\t\t" << "Please enter resident's name(Administrator): " << endl;
        cin >> n;
        // �ҵ���Ӧ�ľ�����Ϣ
        auto it = find_if(residents.begin(), residents.end(),
         [&n](const Resident& resident) {
             // ����� resident �ǵ�ǰ��������������
             return resident._name == n; // ����һ��Ԫ�أ�������
         });

        if(it != residents.end()) {
            // �ҵ��˾�����Ϣ
            // �Ȼ�ȡ��ǰ���ڲ��ж��Ƿ�Ϊ1�ţ�
            time_t now = time(0);
            // ����ʱ��
            tm *ltm = localtime(&now);
            // ��ȡ��ǰ������
            int year = 1900 + ltm->tm_year;
            int month = 1 + ltm->tm_mon;
            int day = ltm->tm_mday;

            // �����ɻ�����Ӧ����ҵ��
            double base_fee = it->_price * it->_area + it->_water_electric_fee; // ������ҵ��

            cout << "\t\t\t" << "Please enter your choice: ";
            int choice;
            cin >> choice;

            // ��ѡ��
            switch(choice) {
                case 3:
                    // һ��ֻ����һ������ҵ��
                {
                    // �ж��Ƿ�Ϊ1��
                    if (day == 1) {
                        std::cout << "\t\t\t" << "Today is " << year << "Y" << month << "M" << " first day." << std::endl;
                        // �ж���ҵ���Ƿ��Ѿ�����
                        if(it->y_n_pay == false){
                            // û�н���������Ӧ����ҵ��
                            cout << "\t\t\t" << "You Should Pay " << base_fee << " as Management Fee."<< endl;
                            double pay_fee;
                            cout << "\t\t\t" << "Please enter your pay fee: ";
                            cin >> pay_fee;
                            if(pay_fee == base_fee){
                                it->y_n_pay = true;
                                cout << "\t\t\t" << "Congratulations, you have paid " << pay_fee << " as Management Fee."<< endl;
                                it->payed_fee = pay_fee;
                            }
                            else {
                                cout << "\t\t\t" << "You Pay Fee is wrong!" << endl;
                            }
                        }

                        else {
                            // �Ѿ���������ʾ�ѽ�������Ŀ
                            cout << "\t\t\t" << "You Have Paid " << base_fee << " as Management Fee."<< endl;
                        }

                    }
                    // ����1�ţ���������ɽ�
                    int days_gap = day - 1; // ���㵱ǰ������1�ŵ�������ֵ
                    double late_fee = base_fee * days_gap * 0.01; // �������ɽ�
                    double total_fee = base_fee + late_fee; // �����ܷ���
                    // �ж���ҵ���Ƿ��Ѿ�����
                    if(it->y_n_pay == false){
                        // û�н���������Ӧ����ҵ��
                        cout << "\t\t\t" << "Today is " << year << "Y" << month << "M" << day << "D" << std::endl;
                        cout << "\t\t\t" << "You Should Pay " << total_fee << " as Management Fee."<< endl;
                        double pay_fee;
                        cout << "\t\t\t" << "Please enter your pay fee: ";
                        cin >> pay_fee;
                        if(pay_fee >= total_fee){
                            it->y_n_pay = true;
                            cout << "\t\t\t" << "Congratulations, you have paid " << pay_fee << " as Management Fee."<< endl;
                            it->payed_fee = pay_fee;
                        }
                        else {
                            cout << "\t\t\t" << "You Pay Fee is wrong!" << endl;
                        }

                    }
                    else {
                        // �Ѿ���������ʾ�ѽ�������Ŀ
                        cout << "\t\t\t" << "You Have Paid " << total_fee << " as Management Fee."<< endl;
                    }
                }
                break;
                case 2:
                    // ��ǰ�������
                {
                    double half_year_fee = base_fee * 0.97 * 6.0; // ������ҵ��
                    cout << "\t\t\t" << "You Should Pay " << half_year_fee << " as Management Fee."<< endl;
                    double pay_fee;
                    cout << "\t\t\t" << "Please enter your pay fee: ";
                    cin >> pay_fee;
                    if(pay_fee == half_year_fee) {
                        cout << "\t\t\t" << "Congratulations, you have paid " << pay_fee << " as Management Fee."<< endl;
                        it->payed_fee = pay_fee;
                        it->y_n_pay = true;
                    }


                }
                break;
                case 1:
                    // һ�ν���һ����ҵ��
                {
                    double year_fee = base_fee * 0.9 * 12.0; // һ����ҵ��
                    cout << "\t\t\t" << "You Should Pay " << year_fee << " as Management Fee."<< endl;
                    double pay_fee;
                    cout << "\t\t\t" << "Please enter your pay fee: ";
                    cin >> pay_fee;
                    if(pay_fee == year_fee) {
                        cout << "\t\t\t" << "Congratulations, you have paid " << pay_fee << " as Management Fee."<< endl;
                        it->payed_fee = pay_fee;
                        it->y_n_pay = true;
                    }
                }
                break;
                default:
                    cout << "\t\t\t" << "You have entered a wrong choice!" << endl;
            }

        }
        else {
            cout << "\t\t\t" << "Sorry, the resident's information is not found!" << endl;
        }
        string choose;
        cout << "\t\t\t" << "contunue? (y/n)";
        cin >> choose;
        if(choose == "n") {
            flag = false;
        }
        else {
            system("cls"); // ����
        }
    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    do_window();
}

void Admini::statistic_window() {
    /*
    *ͳ�ƹ��ܣ��ܹ���¥�ŷ���ͳ������δ������ҵ�ѵ�ס��������ʾ����
    *�ܹ�����ͳ����ҵӪ�շ��ܶʵ���շ��ܶ�.
     */
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t\t" << "Statistic Management Fee Window" << endl;
        cout << endl;
        cout << "\t\t\t" << "1. Statistics by floor(not pay residents)" << endl;
        cout << "\t\t\t" << "2. Statistics by month(all income)" << endl;

        int choose;
        cout << "\t\t\t" << "Please enter your choice: ";
        cin >> choose;

        switch(choose) {
            case 1: {
                // ��¥�ŷ���ͳ������δ������ҵ�ѵ�ס��
                cout << "\t\t\t" << "Statistics by floor(not pay residents)" << endl;
                cout << "\t\t\t" << "Please enter floor number: ";
                int floor_num;
                cin >> floor_num;
                // �ҵ���Ӧ�ľ�����Ϣ
                cout << "\t\t\t" << "Living in Floor " << floor_num << " Resident's name: (not pay residents)" <<  endl;
                for(auto it = residents.begin(); it != residents.end(); it++) {
                    it = find_if(residents.begin(), residents.end(),
                [&floor_num](const Resident& resident) {
                    // ����� resident �ǵ�ǰ��������������
                    return resident._floor == floor_num; // ����һ��Ԫ�أ�������
                });
                    if(it != residents.end()) {
                        if(it->y_n_pay == false) {
                            // δ������ҵ��
                            // ����û��������͵绰����

                            cout << "\t\t\t" << "Resident's name: " << it->_name << endl;
                            cout << "\t\t\t" << "Resident's phone number: " << it->_phone << endl;
                            cout << endl;
                        }
                    }
                    else {
                        cout << "\t\t\t" << "There is no resident in Floor " << floor_num << "." << endl;
                    }

                }
            }
            break;
            case 2: {
                // ����ͳ����ҵӪ�շ��ܶ�
                cout << "\t\t\t" << "Statistics by month(all income)" << endl;
                // ��ȡ��ǰ�·�

                time_t now = time(0);
                // ����ʱ��
                tm *ltm = localtime(&now);
                // ��ȡ��ǰ�·�
                int month = 1 + ltm->tm_mon;

                // ����residents,�����շ��ܶ�
                double income = 0.0;
                for(auto it = residents.begin(); it != residents.end(); it++) {
                    if(it->y_n_pay == true) {
                        // �ѽ�����ҵ��
                        // �����շ��ܶ�
                        income += it->payed_fee;
                    }

                }
                cout << "\t\t\t" << "This month " << month << " income is " << income << endl;

            }
            break;
            default:
                cout << "\t\t\t" << "You have entered a wrong choice!" << endl;

        }
        string choice;
        cout << "\t\t\t" << "contunue? (y/n)";
        cin >> choice;
        if(choice == "n") {
            flag = false;
        }
        else {
            system("cls"); // ����
        }
    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    do_window();
}





