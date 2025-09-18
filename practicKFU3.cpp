#include <iostream>
#include <string>

using namespace std;

struct Worker{
    int X; // количество отработанных часов
    int Y; //почасовая ставка
    int Z; //% налог
    int W; //% премия
};

void inputWorker(Worker& worker){ //фунция для ввода данных
    cout<<"Введите количество отработанных часов: ";
    cin>>worker.X;
    cout<<"Введите почасовая ставка: ";
    cin>>worker.Y;
    cout<<"Введите % налог: ";
    cin>>worker.Z;
    cout<<"Введите % премия: ";
    cin>>worker.W;
}



int main(){
    Worker myWorker;
    inputWorker(myWorker);
    cout<<"Количество часов: "<<myWorker.X<<endl;
    cout<<"Почасовая ставка: "<<myWorker.Y<<endl;
    cout<<"% налог: "<<myWorker.Z<<endl;
    cout<<"% премия: "<<myWorker.W<<endl;

    
    return 0;
}
