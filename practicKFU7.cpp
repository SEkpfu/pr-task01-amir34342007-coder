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
    cout<<"         ЗАПОЛНЕНИЕ ОТЧЕТА"<<endl;
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

double calculateSalary(Worker& worker, double& allS, double& NDFL, double& ZP){ //фунция для подсчета (ЗП, НДФЛ)
    allS = worker.X * worker.Y; 
        allS += allS * worker.W / 100.0; //зарплата с премией 
    NDFL = allS * worker.Z / 100.0; //НДФЛ
    ZP = allS - NDFL; //итоговая сумма
    return 0;
}

void coutWork(Worker& worker){ //фунция для вывода данных
    cout<<"         ОТЧЕТ НА РАБОТНИКА"<<endl;
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

void functWork(Worker& worker){//функция для вызыва других функций
    coutWork(worker);
    calculateSalary(worker, worker.allS, worker.NDFL, worker.ZP);
    coutZP(worker);
}

int main(){
    Worker myWorker1;
    Worker myWorker2;
    Worker myWorker3;
    Worker myWorker4;
    Worker myWorker5;
    inputWorker(myWorker1);
    inputWorker(myWorker2);
    inputWorker(myWorker3);
    inputWorker(myWorker4);
    inputWorker(myWorker5);
    cout<<"//////////////////////"<<endl;
    functWork(myWorker1);
    functWork(myWorker2);
    functWork(myWorker3);
    functWork(myWorker4);
    functWork(myWorker5);
    
    double allSum;
    allSum = myWorker1.ZP + myWorker2.ZP + myWorker3.ZP + myWorker4.ZP + myWorker5.ZP;
    cout<<"Общая сумма ЗП для всех работников: "<<allSum<<endl;
    double aveVal = allSum/5;
    cout<<"Средняя ЗП: "<<aveVal;
    return 0;
}
