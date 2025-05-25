#include "../include/Date.h"

void Datetest1()
{
	Date d1(2025, 3, 1);
	Date d2(2025, 3, 2);
	int ret = d1 == d2;
	cout << ret;
}
void Datetest2()
{
	Date d1(2025, 3, 15);
	d1 += 200;
	d1.Print();
	Date d2 = d1 + 200;
	d2.Print();
}
void Datetest3()
{
	Date d1(2025, 3, 15);
	d1 -= 200;
	d1.Print();
	Date d2 = d1 - 200;
	d2.Print();
}
int main()
{
	// Datetest1();
	// Datetest2();
	Datetest3();
	return 0;
}