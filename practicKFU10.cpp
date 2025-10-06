#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

int main() {
    const int numWorkers = 4;
    int numMonths;
    
    cout << "Введите количество месяцев: ";
    cin >> numMonths;
    
    double hourlyRates[numWorkers];
    int hoursWorked[numWorkers][numMonths];
    double netSalary[numWorkers][numMonths];  // на руки
    double taxAmount[numWorkers][numMonths];  // налог
    double grossSalary[numWorkers][numMonths]; // до налога
    
    const double ndfl = 0.13;
    
    // Ввод данных
    cout << "       Ввод ставки"<<endl;
    for (int i = 0; i < numWorkers; i++) {
        cout << "Ставка работника " << (i + 1) << ": ";
        cin >> hourlyRates[i];
    }
    
    cout << "    Почасовая ставка";
    for (int worker = 0; worker < numWorkers; worker++) {
        cout << "\nРаботник " << (worker + 1) << ":\n";
        for (int month = 0; month < numMonths; month++) {
            cout << "  Месяц " << (month + 1) << ": ";
            cin >> hoursWorked[worker][month];
        }
    }
    
    // Расчеты
    for (int worker = 0; worker < numWorkers; worker++) {
        for (int month = 0; month < numMonths; month++) {
            grossSalary[worker][month] = hourlyRates[worker] * hoursWorked[worker][month];
            taxAmount[worker][month] = grossSalary[worker][month] * ndfl;
            netSalary[worker][month] = grossSalary[worker][month] - taxAmount[worker][month];
        }
    }
    
    // Вывод результатов
    cout << fixed << setprecision(2);
    cout << "      Результатn"<<endl;
    
    //1
    if (numMonths >= 2) {
        cout << "1. Первый работник во втором месяце: $" << netSalary[0][1] << endl;
    }
    
   //2
    double totalTax3 = 0;
    for (int month = 0; month < numMonths; month++) {
        totalTax3 += taxAmount[2][month];
    }
    cout << "2. Налог третьего работника: $" << totalTax3 << endl;
    
    //3
    if (numMonths >= 3) {
        int bestWorker = 0;
        for (int worker = 1; worker < numWorkers; worker++) {
            if (grossSalary[worker][2] > grossSalary[bestWorker][2]) {
                bestWorker = worker;
            }
        }
        cout << "3. Лучший в третьем месяце: работник №" << (bestWorker + 1) << endl;
    }
    
    //4
    double totalSalary = 0;
    for (int worker = 0; worker < numWorkers; worker++) {
        for (int month = 0; month < numMonths; month++) {
            totalSalary += grossSalary[worker][month];
        }
    }
    cout << "4. Общая зарплата бригады: $" << totalSalary << endl;
    
    return 0;
}