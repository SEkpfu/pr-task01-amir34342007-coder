#include <iostream>
#include <string>
#include <vector>

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
    int cntWork;
    vector<double> workersZP;
    vector<double> workersNDFL;
    cout<<"Введите количество работников: ";
    cin>>cntWork;

    for (int i = 0; i < cntWork;i++){
        Worker worker;
        inputWorker(worker);
        cout<<"##################"<<endl;
        functWork(worker);
        workersZP.push_back(worker.ZP);
        workersNDFL.push_back(worker.NDFL);
    }
    double minZP = 99999999999999999;
    int minInx;
    double maxZP = 0;
    int maxInx;
    vector <int> numWorkers;
    int count = 0;
    for (int i = 0; i < workersZP.size();i++){
        if (minZP > workersZP[i]){
            minZP = workersZP[i];
            minInx = i+1;
        }
        if (maxZP < workersZP[i]){
            maxZP = workersZP[i];
            maxInx = i+1;
        }
        if (workersZP[i] > 50000){
            count += 1;
            numWorkers.push_back(i+1);
        }
    }
    double sumNDFL;
    for (int i = 0; i < workersNDFL.size(); i++){
        sumNDFL += workersNDFL[i];
    }
    cout<<"Минимальное ЗП полчил работник №"<<minInx<<" -> "<<minZP<<endl;//1
    cout<<"Максимальное ЗП получил работник №"<< maxInx<< " -> "<<maxZP<<endl;//2
    cout<<"Количество работников у кого ЗП больше 50к -> "<<count<<endl;//3
    cout<<"Номера работников -> ";
    for (int i = 0; i < numWorkers.size(); i++){
        cout<<numWorkers[i]<<" ";
    }
    cout<<endl<<"Общая налоговая сумма -> "<<sumNDFL<<endl;//4
}
