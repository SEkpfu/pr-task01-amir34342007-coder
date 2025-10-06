#include <iostream>
#include <string>



float cnt1(int a, int b, int c) { //фунция для подсчета заработной платы
    return a * b * c/ 100.0 + a*b;
}

float cnt2(float c, float d) { //фунция для полсчета подоходного налога
    return c * d/100.0;
}



using namespace std;



int main(){
    int t = 16; //отработанных часов
    int s = 750; //почасовая ставка
    float p = 12; // % налог
    float c = 20; //% премии
    float x = cnt1(t, s, c);
    float y = cnt2(x, p);
    cout<<"Зарплата: "<<x<<endl;
    cout<<"Налог: "<<y<<endl;
    cout<<"Сумма после вычета налога: "<<x-y<<endl;
    return 0;
}
