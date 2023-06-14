#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

class Ion {
public:
    string name;
    int val = 0;
    char charge;

    Ion(string name) {
        this->name = name;
        if (name == "кислотний залишок") {
            this->charge = '-';
        }
        else if (name == "гідроксидна група") {
            this->charge = '-';
        }
        else if (name == "метал") {
            this->charge = '+';
        }
        else if (name == "водень") {
            this->charge = '+';
        }
    }
};

class IonsSet {
public:
    vector<Ion> name;

    IonsSet() {}
    IonsSet operator= (IonsSet& a) {
        return a;
    }
};

void створитиПочатковийНабір(IonsSet& a, IonsSet& b) {
    cout << "Введіть кількість іонів, яку необхідно створити:" << endl;
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int y = rand() % 4;
        a.name[y].val = rand() % 7 + 1;
        b.name.push_back(a.name[y]);
    }
}

void print(IonsSet& x) {
    for (int i = 0; i < x.name.size(); i++) {
        cout << "Іон " << i + 1 << ": " << x.name[i].name << " " << x.name[i].val << " " << x.name[i].charge << endl;
    }
}

void реакція(IonsSet& x, IonsSet& y) {
    for (auto i = x.name.begin(); i != x.name.end(); i++) {
        for (auto j = i; j != x.name.end(); j++) {
            if (i->val == j->val && i->charge != j->charge) {
                y.name.push_back(*i);
                y.name.push_back(*j);
                x.name.erase(i);
                x.name.erase(j - 1);
                i = x.name.begin();
                j = x.name.begin();
            }
        }
    }
}

void молекули(IonsSet& x, vector<string>& a) {
    for (auto i = x.name.begin(); i != x.name.end(); i++) {
        for (auto j = i; j != x.name.end(); j++) {
            if (i->val == j->val && i->charge != j->charge) {
                if (i->name == "кислотний залишок" && j->name == "метал" || i->name == "метал" && j->name == "кислотний залишок") {
                    string w = "сіль";
                    a.push_back(w);
                    i++;
                    break;
                }
                else if (i->name == "водень" && j->name == "гідроксидна група" || i->name == "гідроксидна група" && j->name == "водень") {
                    string w = "вода";
                    a.push_back(w);
                    i++;
                    break;
                }
                else if (i->name == "водень" && j->name == "кислотний залишок" || i->name == "кислотний залишок" && j->name == "водень") {
                    string w = "кислота";
                    a.push_back(w);
                    i++;
                    break;
                }
                else if (i->name == "метал" && j->name == "гідроксидна група" || i->name == "гідроксидна група" && j->name == "метал") {
                    string w = "луг";
                    a.push_back(w);
                    i++;
                    break;
                }
                else {
                    continue;
                }
            }
        }
    }
}

int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    IonsSet видиІонів;
    Ion ion1("кислотний залишок");
    видиІонів.name.push_back(ion1);
    Ion ion2("гідроксидна група");
    видиІонів.name.push_back(ion2);
    Ion ion3("метал");
    видиІонів.name.push_back(ion3);
    Ion ion4("водень");
    видиІонів.name.push_back(ion4);

    IonsSet початковийНабір;
    створитиПочатковийНабір(видиІонів, початковийНабір);

    cout << "Набір іонів у розчині:" << endl;
    print(початковийНабір);

    IonsSet іониЯкіПрореагували;
    реакція(початковийНабір, іониЯкіПрореагували);

    cout << endl << "Іони які вступили в реакцію:" << endl;
    print(іониЯкіПрореагували);

    cout << endl << "Набір іонів у розчині після реакції:" << endl;
    print(початковийНабір);

    vector<string> набірМолекул;
    молекули(іониЯкіПрореагували, набірМолекул);

    cout << endl << "Список утворених молекул (" << набірМолекул.size() << "):" << endl;
    for (int i = 0; i != набірМолекул.size(); i++) {
        cout << набірМолекул[i] << endl;
    }

    double m = 3.14;
    cin.ignore();
    return 0;
}