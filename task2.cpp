#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <string> password;
    vector <long long int> money;
    vector <string> name;
    vector <long long int> acc_no;
    fstream bank;
    account_start:

        bank.open("bank_password.txt");
        password.clear();
        string line7;
        if(bank.is_open()){
            while(getline(bank, line7)){
                password.push_back(line7);
            }
        }
        bank.close();

        bank.open("bank_money.txt", ios::in);
        money.clear();
        string line2;
        if(bank.is_open()){
            while(getline(bank, line2)){
                long long int balance_money = stoi(line2);
                money.push_back((balance_money));
            }
        }
        bank.close();

        bank.open("bank_name.txt", ios::in);
        name.clear();
        string line6;
        if(bank.is_open()){
            while(getline(bank, line6)){
                name.push_back(line6);
            }
        }
        bank.close();
        
        bank.open("bank_accno.txt", ios::in);
        acc_no.clear();
        string line8;
        if(bank.is_open()){
            while(getline(bank, line8)){
                long long int acc_roll = stoi(line8);
                acc_no.push_back(acc_roll);
            }
        }
        bank.close();
    start:
    
    cout << "Welcome to IITI Bank! Please choose the service...\n1. Login (If you already have an account)\n2. Sign Up(Create a new Account)\n3. exit\n";
    int choice1; cin >> choice1;
    if(choice1 == 2){
        cout << "Please enter your IITI Roll Number...\n";
        long long int accno; cin >> accno;
        int repeat = 1;
        for(int i = 0; i < acc_no.size(); i++){
            if(accno == acc_no[i]){
                cout << "This Roll Number already exists. Please Login or Try another roll number...\n";
                goto start;
            }
        }
        acc_no.push_back(accno);
        
        cout << "Please enter your Name...(one word)\n";
        string accname; cin >> accname;
        name.push_back(accname);
        
        errpass:
        cout << "Please enter a new Password...\n";
        string acc_pass; cin >> acc_pass;
        cout << "Please re-enter your password...\n";
        string acc_repass; cin >> acc_repass;
        if(acc_pass != acc_repass){
            cout << "The Passwords don't match! Please try again...\n";
            goto errpass;
        }else{
            password.push_back(acc_pass);
        }
        money.push_back(0);
        cout << "You have successfully created an account. Please remember your credentials.\n";
        goto start;
    }else if(choice1 == 1){
        login:
        cout << "Please enter your registered IITI roll number...\n";
        long long int rollno; cin >> rollno;
        int count = 1;
        for(int i = 0; i < acc_no.size(); i++){
            if(rollno == acc_no[i]){
                goto l_pass;
            }else{
                count++;
            }
        }
        if(count == acc_no.size() + 1){
            err1:
            cout << "This number isn't registered!\n1. Try another ID\n2. Sign Up\n";
            int choice2; cin >> choice2;
            if(choice2 == 1){
                goto login;
            }else if(choice2 == 2){
                goto start;
            }else{
                cout << "Please enter a valid input!...\n";
                goto err1;
            }
        }
        l_pass:
        cout << "Please enter your password...\n";
        string pass_input; cin >> pass_input;
        string line1; 
        bank.open("bank_password.txt", ios::in);
        if(bank.is_open()){
            int pass_count = 1;
            while(getline(bank, line1)){
                if(pass_count == count){
                    if(line1 == pass_input){
                        bank.close();
                        goto account;
                    }else{
                        cout << "The entered password is wrong, Please Retry...\n";
                        bank.close();
                        goto l_pass;
                    }
                }else{
                    pass_count++;
                }
            }
        }
        
        account:
        cout << "---Dashboard---\nChoose the service...\n1. Credit/Debit Amount\n2. Send Money\n3. Change Credentials\n4. View Name & Balance\n5. Sign Out\n";
        int choice3; cin >> choice3;
        if(choice3 == 1){
            cout << "Choose option...\n1. Credit\n2. Debit\n";
            int choice4; cin >> choice4;
            if(choice4 == 1){
                long long int add_money;
                cout << "Choose the amount to Add...\nRs. ";
                cin >> add_money;
                money[count - 1] = money[count - 1] + add_money;
                cout << "Amount has been added successfully\n";
                //cout << money[count - 1] <<endl;
                goto account;
            }else if(choice4 == 2){
                long long int subtract_money;
                cout << "Choose the amount to Debit...\nRs. ";
                cin >> subtract_money;
                if(money[count - 1] >= subtract_money){
                    money[count - 1] = money[count - 1] - subtract_money;
                    cout << "Amount has been deducted successfully\n";
                }else{
                    cout << "Insufficient Balance! Please try again...\n";
                    goto account;
                }
                cout << money[count - 1] <<endl;
                goto account;
            }else{
                cout << "Please select a Valid input!...\n";
                goto account;
            }
        }else if(choice3 == 2){
            
            long long int send_money;
            long long int rcv_roll;
            cout << "Please enter the Recipient's IITI Roll number...\n";
            cin >> rcv_roll;
            int count_rcv = 1;
            for(int i = 0; i < acc_no.size(); i++){
                if(rcv_roll == acc_no[i]){
                    goto send;
                }else{
                    count_rcv++;
                }
            }
            if(count_rcv > acc_no.size()){
                cout << "Reciever's Roll number does not exist! Try again...\n";
                goto account;
            }
            send:
            cout << "Please enter the amount to Transfer...\n";
            cin >> send_money;
            if(money[count - 1] >= send_money){
                money[count - 1] = money[count - 1] - send_money;
                money[count_rcv - 1] = money[count_rcv - 1] + send_money;
                cout << "Amount transferred successfully\n";
                goto account;
            }else{
                cout << "Insufficient Balance! Please Try again...\n";
                goto account;
            }
            //cout << money[count - 1] <<endl << money[count_rcv - 1]<<endl; 
        }else if(choice3 == 3){
            cout << "1. Change Password\n2. Change Name\n3. exit\n";
            int choice5; cin >> choice5;
            if(choice5 == 2){
                cout << "Please enter the new Name...(one word)\n";
                string new_name; cin >> new_name;
                name[count - 1] = new_name;
                cout << "Name changed Successfully\n";
                goto account;
            }else if(choice5 == 1){

                string new_pwd;
                string new_pwd_check;
                string old_pwd;
                
                cout << "Please Enter the Current Password...\n";
                cin >> old_pwd;
                if(old_pwd == password[count - 1]){
                    cout << "Please enter the New Password...\n";
                    cin >> new_pwd;
                    cout << "Repeat New Password...\n";
                    cin >> new_pwd_check;
                    if(new_pwd == new_pwd_check){
                        password[count - 1] = new_pwd;
                        goto account;
                    }else{
                        cout << "Passwords don't match! Please Try again\n";
                        goto account;
                    }
                }else{
                    cout << "Wrong Password...\n";
                    goto account;
                }
                //cout << password[count - 1];
            }else if(choice5 == 3){
                goto account;
            }else{
                cout << "Please enter a valid input!...\n";
                goto account;
            }
        }else if(choice3 == 4){
            cout << "Name: " << name[count - 1] <<endl;
            cout << "Balance: Rs. " << money[count - 1] <<endl;
            goto account;
        }else if(choice3 == 5){
            goto start;
        }else{
            cout << "Please enter a valid input!\n";
            goto account;
        }
    }else if(choice1 == 3){
        cout << "Thank you!\n";
        goto end;
    }else{
        cout << "Please enter a valid input!\n";
        goto start;
    }

    end:
    bank.open("bank_money.txt", ios :: out);
    bank.close();
    bank.open("bank_money.txt", ios:: app);
    while(bank.is_open()){
        for(int i = 0; i < money.size(); i++){
            bank << money[i] <<endl;
        }
        bank.close();
    }
    
    bank.open("bank_name.txt", ios :: out);
    bank.close();
    bank.open("bank_name.txt", ios:: app);
    while(bank.is_open()){
        for(int i = 0; i < name.size(); i++){
            bank << name[i] <<endl;
        }
        bank.close();
    }
    
    bank.open("bank_password.txt", ios :: out);
    bank.close();
    bank.open("bank_password.txt", ios:: app);
    while(bank.is_open()){
        for(int i = 0; i < password.size(); i++){
            bank << password[i] <<endl;
        }
        bank.close();
    }

    bank.open("bank_accno.txt", ios :: out);
    bank.close();
    bank.open("bank_accno.txt", ios :: app);
    while(bank.is_open()){
        for(int i = 0; i < acc_no.size(); i++){
            bank << acc_no[i] <<endl;
        }
        bank.close();
    }
}
