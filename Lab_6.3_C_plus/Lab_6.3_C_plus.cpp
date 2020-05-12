#include <sys/types.h>
#include <fcntl.h> 
#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Human
{
	string Surname;				//Ф.И.О
	int Group;				//Группа
	int Math;				//Математика
	int Physics;				//Физика
	int Chemistry;				//Химия
	int Cash;				//Пенсия
};

void task()
{
	cout << "Размер структуры Human: " << sizeof(Human) << " bytes";
	string Surname[] = { "Петров А.Г.","Бобров В.И.","Марков Н.В.","Громов Д.П." };
	const int N = 4;
	Human* human = new Human[N];
	char path[] = "db.bin";
	cout << endl << endl << "Список студеннтов:" << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << (human[i].Surname = Surname[i]) << "\t" << "Группа: " << (human[i].Group = 100 + rand() % 8) << "\t" << "Математика: " << (human[i].Math = 0 + rand() % 100) << "\t" << "Физика: " << (human[i].Physics = 0 + rand() % 100) << "\t" << "Химия: " << (human[i].Chemistry = 0 + rand() % 100) << "\t" << "Стипендия: ";
		if (human[i].Math != 0 && human[i].Physics != 0 && human[i].Chemistry != 0)
		{
			cout << (human[i].Cash = 1000 + rand() % 500) << endl;
		}
		else
		{
			cout << "Отсутсвует" << endl;
		}
	}

	FILE* f_out, * f_in;
	f_out = fopen(path, "wb");
	fwrite(human, sizeof(Human), N, f_out);
	fclose(f_out);

	delete[] human;
	human = nullptr;

	

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Task 3 \n";
	task();
}
