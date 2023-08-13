#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long double factorial(int a){
    if(a == 0 || a == 1){
        return 1;
    }else{
        return a * factorial(a - 1);
    }
}

long double power(double a, int b){
    double ans = 1;
    for(int i = 0; i < b; i++){
        ans = ans * a;
    }
    return ans;
}

double sin(double a){
    double ans = 0;
    for(int i = 1; i < 13; i++){
        ans = ans + ((power(-1, i + 1))/(factorial(2*i - 1)))*(power(a, (2*i) - 1));
    }
    return ans;
}

double cos(double a){
    double ans = 0;
    for(int i = 0; i < 12; i++){
        ans = ans + ((power(-1, i))/(factorial(2 * i)))*(power(a, 2 * i));
    }
    return ans;
}


int main(){
    start:
    cout << "Please enter the type (serial number) of calculation:\n1. linear algebra(+,-,*,/)\n2. trigonometric\n3. exponential\n4. close calculator\n ";
    start1:
    int choice; cin >> choice;
    if(choice == 1){
        cout << "Please enter the algebraic equation ending with '='(eg. -3+2/3=):\n";
        vector <int> vnum;
        vector <char> vop;
        while(1){
            int a; cin >> a;
            vnum.push_back(a);
            char b; cin >> b;
            if(b == '='){
                break;
            }else{
                vop.push_back(b);
            }
        }
        double ans = vnum[0];
        for(int i = 0; i < (vnum.size() - 1); i++){
            if(vop[i] == '/'){
                ans = ans / vnum[i + 1];
            }else if(vop[i] == '*'){
                ans = ans * vnum[i + 1]; 
            }else if(vop[i] == '+'){
                ans = ans + vnum[i + 1];
            }else if(vop[i] == '-'){
                ans = ans - vnum[i + 1];
            }
        }
        cout << setprecision(20) << ans <<endl;
    }else if(choice == 2){
        cout << "Choose the unit of Angle:\n1. Radian\n2. Degrees\n";
        int unit; cin >> unit;
        cout << "Enter the Angle:\n";
        double angle; cin >> angle;
        if(unit == 2){
            angle = angle * (0.0174532925);
        }
        cout << "Choose the Operation:\n1. sin    4. cosec\n2. cos    5. sec\n3. tan    6. cot\n";
        int trig; cin >> trig;
        if(trig == 1){
            cout << setprecision(20);
            cout << sin(angle) <<endl;
        }else if(trig == 2){
            cout << setprecision(20);
            cout << cos(angle) <<endl;
        }else if(trig == 3){
            cout << setprecision(20);
            cout << sin(angle) / cos(angle) <<endl;;
        }else if(trig == 4){
            cout << setprecision(20);
            cout << 1 / sin(angle) <<endl;
        }else if(trig == 5){
            cout << setprecision(20);
            cout << 1 / cos(angle) <<endl;
        }else if(trig == 6){
            cout << setprecision(20);
            cout << cos(angle) / sin(angle) <<endl;
        }
    }else if(choice == 3){
        cout << "Please enter a and b in the format a^b:\n";
        cout << "Enter a:  "; int a; cin >> a;
        cout << "Enter b:  "; int b; cin >> b;
        cout << power(a, b) <<endl;
    }else if(choice == 4){
        goto end1;
    }else{
        cout << "Please enter a valid input! (1,2,3)\n";
        goto start1;
    }
    cout << "Do you want to try again?: Y/N\n";
    end:
    char c; cin >> c;
    if(c == 'y' || c == 'Y'){
        goto start;
    }else if(c == 'n' || c == 'N'){
        end1:
        cout << "Thank you!";
    }else{
        cout << "Please enter a valid input: Y/N\n";
        goto end;
    }
}
