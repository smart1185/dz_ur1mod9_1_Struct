#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)



struct Player
{
	char *Name;
	int *Age;
	int *Games;
	int *Goals;
};

struct Goods
{
	char *Product;
	char *Producer;
	int *Year;
	int *Qnt;
	double *Price;
};

struct ExpDate
{
	int *day;
	int *month;
	int *year;
};

struct MeGoods
{
	char *Product;
	int *Qnt;
	double *Price;
	char *Producer;
	ExpDate *Date;
};

struct Worker
{
	char *Name;
	int *Year;
	char *Position;
	double *Payment;
	char *Education;
};

/*Напечатать фамилии студентов, которые сдали математику на «95», и определить их количество.*/
struct Students
{
	char *Name;
	char *Group;
	int *Year;
	int *FisMark;
	int *MathMark;
	int *InfoMark;
};



void generateName(char * name)
{
	int lName = 4 + rand() % 5;
	for (size_t i = 0; i < lName; i++)
	{
		if (i == 0)
			*(name + i) = (char)(192 + rand() % 32);
		else
			*(name + i) = (char)(224 + rand() % 32);
	}
	*(name + lName) = '\0';
}
void generateAge(int *plAge)
{
	*plAge = 20 + rand() % 20;
}
void generateGames(int *games)
{
	*games = rand() % 50 + 1;
}
void generateGoals(int *goals)
{
	*goals = rand() % 50 + 1;
}


void generateProduct(char *product)
{
	char *pro[] = { "Рубашка", "Штаны", "Куртка", "Ботинки", "Пиджак", "Кофта", "Трусы" };
	strcpy(product, pro[rand() % 7]);
}
void generateProducer(char *producer)
{
	char *prod[] = { "Zara","CAT","Benetton","Under Armour" };
	strcpy(producer, prod[rand() % 4]);
}
void generateYear(int *year, int start, int end)
{
	*year = start + rand() % (start - end);
}
void generateQnt(int *qnt)
{
	*qnt = rand() % 99 + 1;
}
void generatePrice(double *qnt)
{
	*qnt = rand() % 7000 * 1.33;
}

void generateExpDate(ExpDate *date)
{
	date->day = (int*)malloc(sizeof(int));
	date->month = (int*)malloc(sizeof(int));
	date->year = (int*)malloc(sizeof(int));

	*date->day = 1 + rand() % 31;
	*date->month = 1 + rand() % 12;
	*date->year = 2016 + rand() % 3;
}

void generatePosition(char *Pos)
{
	char *pos[] = { "Директор", "Менеджер", "Специалист", "Лаборант", "Программист", "Сисадмин" };
	strcpy(Pos, pos[rand() % 6]);
}
void generateEducation(char *Education)
{
	char *education[] = { "Высшее", "Среднее", "Специальное" };
	strcpy(Education, education[rand() % 3]);
}

void genetrateGroup(char *group)
{
	char *gr[] = { "Заучки","Недоучки","Переучки" };
	strcpy(group, gr[rand() % 3]);

}

