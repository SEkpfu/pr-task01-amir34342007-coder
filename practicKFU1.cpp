#include <iostream>
#include <string>



using namespace std;


int main(){
    float t = 16.0; //отработанных часов
    float s = 755.0; //почасовая ставка
    float p = 12.0; // % премии
    cout<< "Часов отработанно: " << t << endl << "Почасовая ставка: " << s << endl << "Процент премии: " << p << endl << "Зарплата рабочего: " << t*s + t*s*p/100.0 <<endl;
    return 0;
}
