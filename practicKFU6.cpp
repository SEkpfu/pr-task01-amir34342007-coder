#include <iostream>
#include <string>

using namespace std;

struct Worker{
    int X; // количество отработанных часов
    int Y; //почасовая ставка
    int Z; //% налог
    int W; //% премия
    double allS;
    double NDFL;
    double ZP;
    string famil;
};

void inputWorker(Worker& worker){ //функция для ввода данных
    cout<<"Введите фамилию работника: ";
    cin>>worker.famil;
    cout<<"Введите количество отработанных часов: ";
    cin>>worker.X;
    cout<<"Введите почасовая ставка: ";
    cin>>worker.Y;
    cout<<"Введите % налог: ";
    cin>>worker.Z;
    cout<<"Введите % премия: ";
    cin>>worker.W;
}

void calculateSalary(Worker& worker, double& allS, double& NDFL, double& ZP){ //фунция для подсчета (ЗП, НДФЛ)
    allS = worker.X * worker.Y; 
        allS += allS * worker.W / 100.0; //зарплата с премией 
    NDFL = allS * worker.Z / 100.0; //НДФЛ
    ZP = allS - NDFL; //итоговая сумма
}

void coutWork(Worker& worker){ //фунция для вывода данных
    cout<<"Работник: "<<worker.famil<<endl;
    cout<<"Количество часов: "<<worker.X<<endl;
    cout<<"Почасовая ставка: "<<worker.Y<<endl;
    cout<<"% налог: "<<worker.Z<<endl;
    cout<<"% премия: "<<worker.W<<endl;
}

void coutZP(Worker& worker){ //фунция для вывода (ЗП, НДФЛ) 
    cout<<"Зарплата без НДФЛ-> "<<worker.allS<<endl;
    cout<<"НДФЛ -> "<<worker.NDFL<<endl;
    cout<<"Общая сумма -> "<<worker.ZP<<endl;
}



int main(){
    Worker myWorker1;
    Worker myWorker2;
    cout<<"#РАБОТНИК 1#"<<endl;
    inputWorker(myWorker1);
    cout<<"#РАБОТНИК 2#"<<endl;
    inputWorker(myWorker2);
    cout<<"//////////////////////"<<endl;
    cout<<"#РАБОТНИК 1#"<<endl;
    coutWork(myWorker1);
    calculateSalary(myWorker1, myWorker1.allS, myWorker1.NDFL, myWorker1.ZP);
    coutZP(myWorker1);
    cout<<"#РАБОТНИК 2#"<<endl;
    coutWork(myWorker2);
    calculateSalary(myWorker2, myWorker2.allS, myWorker2.NDFL, myWorker2.ZP);
    coutZP(myWorker2);
    
    if (myWorker1.ZP < 1000){
        cout<<"Маленькая ЗП у :"<<myWorker1.famil<<endl;
    }
    if (myWorker2.ZP < 1000){
        cout<<"Маленькая ЗП у :"<<myWorker2.famil<<endl;
    }
    if (myWorker1.NDFL > 50){
        cout<<"Превышен налог в 50 руб: "<<myWorker1.famil[0]<<"-"<<myWorker1.famil.back()<<endl;
    }
    if (myWorker2.NDFL > 50){
        cout<<"Превышен налог в 50 руб: "<<myWorker2.famil[0]<<"-"<<myWorker2.famil.back()<<endl;
    }
    return 0;
}
