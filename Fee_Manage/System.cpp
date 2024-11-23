//
// Created by ���ٕN on 2024-10-22.
//

#include "System.h"
#include "Header.h"
#include"Admini.h"
#include"Opera.h"
void System::main_window() {
    // ʵ��ϵͳ��������
    int choice;
    do {
        cout << "\t\t\t\t" << "Welcome to the system!" << endl;
        cout << "\t\t\t" << "1. Administrator Sign up" << endl;
        cout << "\t\t\t" << "2. Administrator Log in" << endl;
        cout << "\t\t\t" << "3. Operator Sign up" << endl;
        cout << "\t\t\t" << "4. Operator Log in" << endl;
        cout << "\t\t\t" << "5. Exit" << endl;
        cout << endl;
        cout << "Please enter your choice: (1-5)";
        cin >> choice ;
        system("cls"); // ����
        if(choice < 1 || choice > 5){
            cout << "Invalid choice, please try again." << endl;
        }
    }while(choice < 1 || choice > 5);
    switch (choice) {
        case 1:
            admini_signup_window();
        break;
        case 2:
            admini_login_window();
        break;
        case 3:
            opera_signup_window();
        break;
        case 4:
            opera_login_window();
        break;
        case 5:
            exit(0);
        break;
    }
}

void System::admini_signup_window() {
    // ʵ�ֹ���Աע�ᴰ��
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t" << "Administrator Sign up Window" << endl;
        cout << "\t\t\t" << "Please enter your name(Administrator): ";
        string n;
        cin >> n;
        int p;
        cout << "\t\t\t" << "Please enter your password(Administrator): ";
        cin >> p;
        string admini_file = "admini_info.txt";
        ofstream outfile(admini_file,ios::app); // ׷��ģʽ���ļ�
        if(!outfile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        // ������Ա��Ϣд���ļ�

        outfile << n << " " << p << endl;
        outfile.close();
        cout << "\t\t\t" << "Sign up successfully!" << endl;
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
    cout << "\t\t\t" << "You can log in now!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    main_window();
}

void System::admini_login_window() {
    // ʵ�ֹ���Ա��¼����
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t" << "Administrator Log in Window" << endl;
        string n;
        cout << "\t\t\t" << "Please enter your name(Administrator): ";
        cin >> n;
        string p;
        cout <<  "\t\t\t" << "Please enter your password(Administrator): ";
        cin >> p;
        // ���ļ��ж�ȡ����Ա��Ϣ,�Ա�ȽϹ���Ա���ֺ������Ƿ���ڣ�
        string admini_file = "admini_info.txt";
        ifstream infile(admini_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        string line;
        while(getline(infile, line) ){ // �����infile >> line,�ǵģ�infile >> line �������ո��Ʊ�����з�ʱ��ֹͣ��ȡ��
                                              //������Ϊ >> �������ڶ�ȡʱ���Ὣ������Ϊ�Կո�Ϊ�ָ����Ķ���������ֶΡ�
            istringstream iss(line);
            string name;
            string password;
            iss >> name >> password;
            if(name == n && password == p) {
                cout << "\t\t\t"<<"Welcome, " << n << "!" << endl;
                flag = false;
                break;
            }

        }
        if(flag == true) {
            cout << "\t\t\t"<<"Invalid name or password, please try again." << endl;
            system("pause");
            system("cls");
        }
        // ###########ʵ�ֹ���Ա��½�Ժ�Ĺ��ܴ���

    }
    Admini admini;
    system("pause");
    system("cls");
    admini.do_window();
}

void System::opera_signup_window() {
    // ʵ�ֲ���Աע�ᴰ��
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t" << "Operator Sign up Window" << endl;
        cout << "\t\t\t" << "Please enter your name(Operator): ";
        string n;
        cin >> n;
        int p;
        cout << "\t\t\t" << "Please enter your password(Operator): ";
        cin >> p;
        string opera_file = "opera_info.txt";
        ofstream outfile(opera_file,ios::app);
        if(!outfile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        // ������Ա��Ϣд���ļ�

        outfile << n << " " << p << endl;
        outfile.close();
        cout << "\t\t\t" << "Sign up successfully!" << endl;
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
    cout << "\t\t\t" << "You can log in now!" << endl;
    system("pause"); // �ȴ��û�
    system("cls"); // ����
    main_window();
}

void System::opera_login_window() {
    // ʵ�ֲ���Ա��¼����
    bool flag = true;
    while(flag) {
        cout << "\t\t\t\t" << "Administrator Log in Window" << endl;
        string n;
        cout << "\t\t\t" << "Please enter your name(Operator): ";
        cin >> n;
        string p;
        cout <<  "\t\t\t" << "Please enter your password(Operator): ";
        cin >> p;
        // ���ļ��ж�ȡ����Ա��Ϣ,�Ա�Ƚϲ���Ա���ֺ������Ƿ���ڣ�
        string opera_file = "opera_info.txt";
        ifstream infile(opera_file);
        if(!infile) {
            cerr << "Error: file not found." << endl;
            exit(1);
        }
        string line;
        while(getline(infile, line) ) {
            istringstream iss(line);
            string name;
            string password;
            iss >> name >> password;
            if(name == n && password == p) {
                cout << "\t\t\t"<<"Welcome, " << n << "!" << endl;
                flag = false;
                break;
            }

        }
        if(flag == true) {
            cout << "\t\t\t"<<"Invalid name or password, please try again." << endl;
            system("pause");
            system("cls");
        }

    }
    //###########ʵ�ֲ���Ա��½�Ժ�Ĺ��ܴ���
    Opera opera;
    system("pause");
    system("cls");
    opera.do_window();
}

