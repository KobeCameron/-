//
// Created by 王荣昇 on 2024-10-23.
//

#include "Admini.h"
#include "Resident.h"

Admini::Admini() {
    // 初始化 vector<Resident> residents
    string resident_file = "resident_info.txt";
    ifstream infile(resident_file);
    if(!infile) {
        cerr << "Error: file not found." << endl;
        exit(1);
    }
    string line;
    while(getline(infile,line)) {
        istringstream ss(line); // stringstream对象既可以从字符串中读取数据，又可以向字符串中写入数据
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
        residents.push_back(resident); // 将resident类对象加入vector中
    }
}
void Admini::do_window() {
    // 实现管理员登录以后的功能界面
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
        system("cls"); // 清屏
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
    // 实现添加居民信息功能
    /*户主姓名、性别、联系电话、楼号，单元号，房号，面积、
物业单价（高层3元/平方，多层2元/平方，由楼号区分），公摊水电费*/
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
        // 根据楼号区分物业单价(大于6楼为高层，小于等于6楼为低层)
        if(f > 6) {
            p = 3.0;
        }
        else {
            p = 2.0;
        }
        // 将信息写入文件(用resident类)
        Resident resident(n,g,t,f,u,r,a,p,w);

        residents.push_back(resident); // 将resident类对象加入vector中

        string resident_file = "resident_info.txt";
        ofstream outfile(resident_file,ios::app); // 追加模式打开文件
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
            system("cls"); // 清屏
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // 等待用户
    system("cls"); // 清屏
    do_window();
}

void Admini::search_resident_window() {
    // 实现搜索居民信息功能
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t\t" << "Search a Resident Information Window" << endl;
        string n;
        cout << "\t\t\t" << "Please enter resident's name you want to search: ";
        cin >> n;

        // #########################从vector<Resident>中搜索
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


        // 需要从已有的居民信息文件中搜索
        /*string resident_file = "resident_info.txt";
        ifstream infile(resident_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        bool flag_find = false;
        string line;
        while(getline(infile,line)) {
            istringstream ss(line); // stringstream对象既可以从字符串中读取数据，又可以向字符串中写入数据
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
            system("cls"); // 清屏
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // 等待用户
    system("cls"); // 清屏
    do_window();
}

void Admini::modify_resident_window() {
    // 实现修改居民信息功能
    // 思路：利用vector<vector<string> > 来存储我遍历文本文件获得的居民信息，
    // 用户会输入想要修改的居民的姓名，以及想要你修改的信息对应的编号，
    // 以及修改的新内容，然后在vector<vector<string> > 中先修改对应的信息 可以用迭代器遍历
    // 然后再将修改后的信息写入文本文件，最后提示修改成功。
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

        // 需要从已有的居民信息文件中搜索
        /*string resident_file = "resident_info.txt";
        ifstream infile(resident_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }

        string line;
        while(getline(infile,line)) {
            istringstream ss(line); // stringstream对象既可以从字符串中读取数据，又可以向字符串中写入数据
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

            resident_info.push_back(resident); // 将居民信息加入vector中

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
        // 修改信息
        bool flag_find = false;
        // #################遍历vector<Resident> 找到对应的居民信息，并修改信息

        for(auto i = residents.begin(); i != residents.end(); ++i) {
            if(i->_name == n) {
                switch(choice) {
                    case 1:
                        i->_name = new_content; // 修改姓名
                        break;
                    case 2:
                        i->_sex = new_content; // 修改性别
                        break;
                    case 3:
                        i->_phone = new_content; // 修改电话号码
                        break;
                    case 4:
                        i->_floor = stoi(new_content); // 修改楼号
                        break;
                    case 5:
                        i->_unit = new_content; // 修改单元号
                        break;
                    case 6:
                        i->_room = new_content; // 修改房号
                        break;
                    case 7:
                        i->_area = stod(new_content); // 修改面积
                        break;
                    case 8:
                        i->_price = stod(new_content); // 修改物业单价

                        break;
                    case 9:
                        i->_water_electric_fee = stod(new_content); // 修改公摊水电费
                        break;
                    default:
                        cout << "\t\t\t" << "Invalid choice, please try again." << endl;
                        break;
                }
                flag_find = true;
                // 将修改后的信息写入文本文件
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
            system("cls"); // 清屏
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // 等待用户
    system("cls"); // 清屏
    do_window();
}

void Admini::delete_resident_window() {
    //     // 实现删除居民信息功能
    //     // 思路：利用vector<vector<string> > 来存储我遍历文本文件获得的居民信息，
    //     // 用户会输入想要删除的居民的姓名，然后在vector<vector<string> > 中用迭代器找到对应的信息，
    //     // 用泛型算法find_if寻找其在vector<vector<string> > 中的位置，
    //     // 其中的if条件是判断是否与输入的姓名相同，
    //     // 然后用erase删除，
    //     // 最后再将删除后的信息写入文本文件，最后提示删除成功。
    bool flag = true;
    // vector<vector<string> > resident_info;
    while(flag) {
        cout << "\t\t\t\t\t" << "Delete a Resident Information Window" << endl;
        cout << endl;

        // 需要从已有的居民信息文件中搜索
        /*string resident_file = "resident_info.txt";
        ifstream infile(resident_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }

        string line;
        while(getline(infile,line)) {
            istringstream ss(line); // stringstream对象既可以从字符串中读取数据，又可以向字符串中写入数据
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

            resident_info.push_back(resident); // 将居民信息加入vector中
            // 因为并没有初始化vector<vector<string> >，所以需要用push_back来添加元素，不用迭代器

        }
        infile.close();
        */

        string n;
        cout << "\t\t\t" << "Please enter resident's name you want to delete: ";
        cin >> n;
        // 删除信息

        auto it = find_if(residents.begin(), residents.end(),
         [&n](const Resident& resident) {
             // 这里的 resident 是当前迭代到的子数组

             return resident._name == n; // 检查第一个元素（姓名）
         });
        if(it != residents.end()) {
            residents.erase(it); // 删除整个用户！

            // 写入文件 将vector<Resident> 写入文本文件
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
            system("cls"); // 清屏
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // 等待用户
    system("cls"); // 清屏
    do_window();
}


void Admini::creat_fee_window() {
    // 实现应缴物业费自动生成，每月1日起生成缴费额，如遇到拖欠则实施累加，
    // 并按每天1 % 的标准收取滞纳金

    // 思路：
    // 1 先判断是不是当前这个月的一号，如果是，并且物业费没有交过，则只是生成应缴物业费
    // 2 如果不是一号，且物业费没有交过，那么需要计算当前的日期与的当前月份1号的天数差值，
    // 首先先生成基础的应缴物业费，然后再计算滞纳金，最后再加上物业费，
    // 3 如果物业费已经交过，则直接提示已经交过，同时也生成已交费用数目。

    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t\t" << "Create Managment Fee Window" << endl;
        cout << endl;
        string n;
        cout << "\t\t\t" << "Please enter resident's name(Administrator): ";
        cin >> n;
        // 找到对应的居民信息
        auto it = find_if(residents.begin(), residents.end(),
         [&n](const Resident& resident) {
             // 这里的 resident 是当前迭代到的子数组

             return resident._name == n; // 检查第一个元素（姓名）
         });
        if(it != residents.end()) {
            // 找到了居民信息
            // 先获取当前日期并判断是否为1号：
            time_t now = time(0);
            // 本地时间
            tm *ltm = localtime(&now);
            // 获取当前年月日
            int year = 1900 + ltm->tm_year;
            int month = 1 + ltm->tm_mon;
            int day = ltm->tm_mday;

            // 先生成基础的应缴物业费
            double base_fee = it->_price * it->_area + it->_water_electric_fee; // 基础物业费

            // 判断是否为1号
            if (day == 1) {
                std::cout << "\t\t\t" << "Today is " << year << "Y" << month << "M" << " first day." << std::endl;
                // 判断物业费是否已经交过
                if(it->y_n_pay == false){
                    // 没有交过，生成应缴物业费
                    cout << "\t\t\t" << "You Should Pay " << base_fee << " as Management Fee."<< endl;
                }
                else {
                    // 已经交过，提示已交费用数目
                    cout << "\t\t\t" << "You Have Paid " << base_fee << " as Management Fee."<< endl;
                }


            }
            // 不是1号，则计算滞纳金
            int days_gap = day - 1; // 计算当前日期与1号的天数差值
            double late_fee = base_fee * days_gap * 0.01; // 计算滞纳金
            double total_fee = base_fee + late_fee; // 计算总费用
            // 判断物业费是否已经交过
            if(it->y_n_pay == false){
                // 没有交过，生成应缴物业费
                cout << "\t\t\t" << "Today is " << year << "Y" << month << "M" << day << "D" << std::endl;
                cout << "\t\t\t" << "You Should Pay " << total_fee << " as Management Fee."<< endl;
            }
            else {
                // 已经交过，提示已交费用数目
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
            system("cls"); // 清屏
        }

    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // 等待用户
    system("cls"); // 清屏
    do_window();
}

void Admini::pay_fee_window() {
    // 该窗口主要是实现物业费缴纳功能，匹配用户姓名
    // 提供选项，1. 一次缴纳一年物业费 2. 提前半年缴纳 这两项是有奖励的。
    // 3. 一次只缴纳一个月物业费。
    // 奖励，对于一次缴纳一年物业费的住户享受9折优惠，对于提前半年缴纳的住户享受97折优惠。
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
        // 找到对应的居民信息
        auto it = find_if(residents.begin(), residents.end(),
         [&n](const Resident& resident) {
             // 这里的 resident 是当前迭代到的子数组
             return resident._name == n; // 检查第一个元素（姓名）
         });

        if(it != residents.end()) {
            // 找到了居民信息
            // 先获取当前日期并判断是否为1号：
            time_t now = time(0);
            // 本地时间
            tm *ltm = localtime(&now);
            // 获取当前年月日
            int year = 1900 + ltm->tm_year;
            int month = 1 + ltm->tm_mon;
            int day = ltm->tm_mday;

            // 先生成基础的应缴物业费
            double base_fee = it->_price * it->_area + it->_water_electric_fee; // 基础物业费

            cout << "\t\t\t" << "Please enter your choice: ";
            int choice;
            cin >> choice;

            // 看选择
            switch(choice) {
                case 3:
                    // 一次只缴纳一个月物业费
                {
                    // 判断是否为1号
                    if (day == 1) {
                        std::cout << "\t\t\t" << "Today is " << year << "Y" << month << "M" << " first day." << std::endl;
                        // 判断物业费是否已经交过
                        if(it->y_n_pay == false){
                            // 没有交过，生成应缴物业费
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
                            // 已经交过，提示已交费用数目
                            cout << "\t\t\t" << "You Have Paid " << base_fee << " as Management Fee."<< endl;
                        }

                    }
                    // 不是1号，则计算滞纳金
                    int days_gap = day - 1; // 计算当前日期与1号的天数差值
                    double late_fee = base_fee * days_gap * 0.01; // 计算滞纳金
                    double total_fee = base_fee + late_fee; // 计算总费用
                    // 判断物业费是否已经交过
                    if(it->y_n_pay == false){
                        // 没有交过，生成应缴物业费
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
                        // 已经交过，提示已交费用数目
                        cout << "\t\t\t" << "You Have Paid " << total_fee << " as Management Fee."<< endl;
                    }
                }
                break;
                case 2:
                    // 提前半年缴纳
                {
                    double half_year_fee = base_fee * 0.97 * 6.0; // 半年物业费
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
                    // 一次缴纳一年物业费
                {
                    double year_fee = base_fee * 0.9 * 12.0; // 一年物业费
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
            system("cls"); // 清屏
        }
    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // 等待用户
    system("cls"); // 清屏
    do_window();
}

void Admini::statistic_window() {
    /*
    *统计功能，能够按楼号分类统计所有未缴清物业费的住户，并公示提醒
    *能够按月统计物业营收费总额，实际收费总额.
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
                // 按楼号分类统计所有未缴清物业费的住户
                cout << "\t\t\t" << "Statistics by floor(not pay residents)" << endl;
                cout << "\t\t\t" << "Please enter floor number: ";
                int floor_num;
                cin >> floor_num;
                // 找到对应的居民信息
                cout << "\t\t\t" << "Living in Floor " << floor_num << " Resident's name: (not pay residents)" <<  endl;
                for(auto it = residents.begin(); it != residents.end(); it++) {
                    it = find_if(residents.begin(), residents.end(),
                [&floor_num](const Resident& resident) {
                    // 这里的 resident 是当前迭代到的子数组
                    return resident._floor == floor_num; // 检查第一个元素（姓名）
                });
                    if(it != residents.end()) {
                        if(it->y_n_pay == false) {
                            // 未缴清物业费
                            // 输出用户的姓名和电话号码

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
                // 按月统计物业营收费总额
                cout << "\t\t\t" << "Statistics by month(all income)" << endl;
                // 获取当前月份

                time_t now = time(0);
                // 本地时间
                tm *ltm = localtime(&now);
                // 获取当前月份
                int month = 1 + ltm->tm_mon;

                // 遍历residents,计算收费总额
                double income = 0.0;
                for(auto it = residents.begin(); it != residents.end(); it++) {
                    if(it->y_n_pay == true) {
                        // 已缴清物业费
                        // 计算收费总额
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
            system("cls"); // 清屏
        }
    }
    cout << "\t\t\t" << "You can continue to manage!" << endl;
    system("pause"); // 等待用户
    system("cls"); // 清屏
    do_window();
}





