#include <iostream>
#include <cmath>

using namespace std;

const int kTotalFactories = 3;

void ProductionData(int data[], int plantNum);
void TotalUnits(int unit_data[], int produced);
void UnitsProduced(const int kUnits[], int max_units);
void DepartmentData(int& total);
int RoundDown(double data_value);
void PrintAsterisk(int n);

int main() {
    int production[kTotalFactories];

    cout << "This program displays a graph showing\n" 
         << "production for each factory in the company.\n";

    ProductionData(production, kTotalFactories);
    TotalUnits(production, kTotalFactories);
    UnitsProduced(production, kTotalFactories);
    
    return 0;
}

//displays production data of each factory
void ProductionData(int data[], int plantNum) {
    for (int units = 1; units <= plantNum; units++) {

        cout << endl << "Enter production data for plant number: "
             << units << endl;

        DepartmentData(data[units - 1]);
    }
}

//prompt the user for the number of units produced by each department
void DepartmentData(int &total) {
    cout << "Enter number of units produced by each department.\n"
         << "Append a negative number to the end of the list.\n";

    total = 0;
    int units_produced;
    cin >> units_produced;

    while (units_produced >= 0) {
        total = total + units_produced;
        cin >> units_produced;
    } 
    
    cout << "Total = " << total << endl;
}

//calculate total units produced
void TotalUnits(int unit_data[], int produced) {
    for (int u = 0; u < produced; u++) {
        //convert data to integer
        unit_data[u] = RoundDown(unit_data[u]/1000.0);
    }
}

//round data down to nearest whole number then add 0.5
int RoundDown(double data_value) {
    return static_cast<int>(floor(data_value + 0.5));
}

//display units produced by each factory
void UnitsProduced(const int kUnits[], int max_units) {
    cout << "\nUnits produced in thousands of units:\n";

    for (int factorynum = 1; factorynum <= max_units; factorynum++) {
        cout << "Factory #" << factorynum << " ";

        PrintAsterisk(kUnits[factorynum - 1]);
        cout << endl;
    }
}

//print asterisks representing each thousand of units
void PrintAsterisk(int n) {
    for (int count = 1; count <= n; count++) {
        cout << "*";
    }
}
