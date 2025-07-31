#include <iostream>
using namespace std;


class Date {
public:
int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int get_day(int month){

}
  Date(int year = 2025, int month = 7, int day = 29) {
    _year = year;
    _month = month;
    _day = day;
  }

  Date operator+(const Date& d){
    
  }

private:
  int _year;
  int _month;
  int _day;
};

int main() { return 0; }