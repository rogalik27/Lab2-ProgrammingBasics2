#include <iostream>
enum Month {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

Month operator++(Month& month){
    if(month == December){
        month = January;
    }else{
        month = (Month)(month+1);
    }
    return month;
}

Month operator++(Month& month, int){
    Month prevDay = month;
    operator++(month);
    return prevDay;
}

const char* getMonth(Month& month){
    switch (month){
        case January:
            return "Січень";
        case February:
            return "Лютий";
        case March:
            return "Березень";
        case April:
            return "Квітень";
        case May:
            return "Травень";
        case June:
            return "Червень";
        case July:
            return "Липень";
        case August:
            return "Серпень";
        case September:
            return "Вересень";
        case October:
            return "Жовтень";
        case November:
            return "Листопад";
        default:
            return "Грудень";
    }
}

int main(){
    for (Month m = June; m!=May; m++){
        std::cout << getMonth(m) << "\n";
    }
    return 0;
}
