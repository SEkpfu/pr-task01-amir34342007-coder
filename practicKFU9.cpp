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

void minZP(vector<double> workersZP){//1
    int minInx;
    double minZp = 99999999999;
    for (int i = 0; i < workersZP.size(); i++){
        if (minZp > workersZP[i]){
            minZp = workersZP[i];
            minInx = i+1;
        }
    }
    cout<<"Минимальное ЗП полчил работник №"<<minInx<<" -> "<<minZp<<endl;
}

void maxZP(vector<double> workersZP){//2
    int maxInx;
    double maxZp = 0;
    for (int i = 0; i < workersZP.size(); i++){
        if (maxZp < workersZP[i]){
            maxZp = workersZP[i];
            maxInx = i+1;
        }
    }
    cout<<"Максимальное ЗП получил работник №"<< maxInx<< " -> "<<maxZp<<endl;
}

void ZP_50K(vector<double> workersZP){
    int count = 0;
    vector <int> workInx;
    for (int i = 0; i < workersZP.size(); i++){
        if (workersZP[i] > 50000){
            count += 1;
            workInx.push_back(i + 1);
        }
    }
    cout<<"Количество работников у кого ЗП больше 50к -> "<<count<<endl;//3
    cout<<"Номера работников -> ";
    for (int i = 0; i < workInx.size(); i++){
        cout<<workInx[i]<<" ";
    }
}

void SumNDFL(vector<double> NDFL){//4
    double sumNDFL;
    for (int i = 0; i < NDFL.size(); i++){
        sumNDFL += NDFL[i];
    }
    cout<<endl<<"Общая налоговая сумма -> "<<sumNDFL<<endl;
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
    cout<<"##################"<<endl;
    minZP(workersZP);
    maxZP(workersZP);
    ZP_50K(workersZP);
    SumNDFL(workersNDFL);
}
