#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <ctime>
#include <string.h>

#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)



using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int  N;
	do
	{
		printf("\t\t----Введите номер задания: ");
		scanf_s("%d", &N);
		cin.get();
		printf("\n");
		switch (N)
		{
		case 1:
			/*1. Определить средний возраст хоккеистов и вывести сведения о хоккеистах, возраст которых меньше 25 лет*/
		{
			Player *pl = (Player*)malloc(sizeof(Player) * 15);
			int sum = 0, med = 0;
			if (pl != NULL)
			{
				for (size_t i = 0; i < 15; i++)
				{
					(pl + i)->Name = (char*)malloc(sizeof(char) * 5);
					(pl + i)->Age = (int*)malloc(sizeof(int));
					(pl + i)->Games = (int*)malloc(sizeof(int));
					(pl + i)->Goals = (int*)malloc(sizeof(int));

					generateName((pl + i)->Name);
					generateAge((pl + i)->Age);
					generateGames((pl + i)->Games);
					generateGoals((pl + i)->Goals);

					sum += *(pl + i)->Age;
				}
				med = sum / 15;

				printf("\tИнформация о хоккеистыах:\n");
				printf("   Фамилия    Возраст    Игр      Шайб\n");
				printf("\----------------------------------------\n");
				for (size_t i = 0; i < 15; i++)
				{
					printf("#%d   %s\t%d\t%d\t%d\n",
						i + 1, (pl + i)->Name,
						*(pl + i)->Age,
						*(pl + i)->Games,
						*(pl + i)->Goals);
				}
				printf("\=======================================\n");
				printf("\t Средний возраст хоккеистов = %d\n", med);
				printf("\=======================================\n");

				printf("\tИнформация о хоккеистыахвозраст которых меньше 25 лет:\n");
				printf("   Фамилия    Возраст    Игр      Шайб\n");
				printf("\----------------------------------------\n");
				for (size_t i = 0; i < 15; i++)
				{
					if (*(pl + i)->Age < 25)
					{
						printf("#%d   %s\t%d\t%d\t%d\n",
							i + 1, (pl + i)->Name,
							*(pl + i)->Age,
							*(pl + i)->Games,
							*(pl + i)->Goals);
					}
				}

			}
			free(pl);
		}
		printf("\n");
		break;

		case 2:
			/*2.Определить общую стоимость всех товаров, выпущенных в текущем году и вывести сведения об этих товарах.*/
		{
			Goods *goo = (Goods*)malloc(sizeof(Goods) * 15);
			double total = 0;
			printf("\tИнформация о товарах\n");
			printf("\--------------------------------------------------------\n");
			if (goo != NULL)
			{
				for (size_t i = 0; i < 15; i++)
				{
					(goo + i)->Product = (char*)malloc(sizeof(char) * 7);
					(goo + i)->Producer = (char*)malloc(sizeof(char) * 4);
					(goo + i)->Year = (int*)malloc(sizeof(int));
					(goo + i)->Qnt = (int*)malloc(sizeof(int));
					(goo + i)->Price = (double*)malloc(sizeof(double));

					generateProduct((goo + i)->Product);
					generateProducer((goo + i)->Producer);
					generateYear((goo + i)->Year, 2016, 2019);
					generateQnt((goo + i)->Qnt);
					generatePrice((goo + i)->Price);

					printf("******************************************\n");
					printf("Наименование: %s\n", (goo + i)->Product);
					printf("Производитель: %s\n", (goo + i)->Producer);
					printf("Год выпуска: %d\n", *(goo + i)->Year);
					printf("Количество: %d\n", *(goo + i)->Qnt);
					printf("Цена: %4.2f\n", *(goo + i)->Price);
				}
				printf("\n=======================================================\n");
				printf("\tИнформация о товарах выпущеных в текущем году\n");
				printf("\========================================================\n");
				for (size_t i = 0; i < 15; i++)
				{
					if (*(goo + i)->Year == 2018)
					{
						printf("******************************************\n");
						printf("Наименование: %s\n", (goo + i)->Product);
						printf("Производитель: %s\n", (goo + i)->Producer);
						printf("Год выпуска: %d\n", *(goo + i)->Year);
						printf("Количество: %d\n", *(goo + i)->Qnt);
						printf("Цена: %4.2f\n", *(goo + i)->Price);
						total += *(goo + i)->Price;
					}
				}
				printf("\--------------------------------------------------------\n");
				printf("Стоимость всех товаров, выпущенных в текущем году = %4.2f\n", total);

			}
			free(goo);
		}
		printf("\n");
		break;

		case 3:
			/*3. Определить среднюю стоимость товаров и товар с минимальной стоимостью*/
		{
			MeGoods *meg = (MeGoods*)malloc(sizeof(MeGoods) * 10);
			double sum = 0;
			int min = 0;

			if (meg != NULL)
			{
				printf("\tИнформация о товарах\n");
				printf("\--------------------------------------------------------\n");
				for (size_t i = 0; i < 10; i++)
				{
					(meg + i)->Product = (char*)malloc(sizeof(char) * 7);
					(meg + i)->Producer = (char*)malloc(sizeof(char) * 4);
					(meg + i)->Price = (double*)malloc(sizeof(double));
					(meg + i)->Qnt = (int*)malloc(sizeof(int));

					(meg + i)->Date = (ExpDate*)malloc(sizeof(ExpDate));

					generateProduct((meg + i)->Product);
					generateProducer((meg + i)->Producer);
					generateQnt((meg + i)->Qnt);
					generatePrice((meg + i)->Price);

					generateExpDate((meg + i)->Date);

					sum += *(meg + i)->Price;

					printf("******************************************\n");
					printf("Наименование: %s\n", (meg + i)->Product);
					printf("Производитель: %s\n", (meg + i)->Producer);
					printf("Количество: %d\n", *(meg + i)->Qnt);
					printf("Цена: %4.2f\n", *(meg + i)->Price);
					printf("Дата выпуска: %d.%d.%d\n",
						*(meg + i)->Date->day,
						*(meg + i)->Date->month,
						*(meg + i)->Date->year);

				}
				printf("\=============================================\n");
				printf("\tСредняя стоимость = %4.2f\n", sum / 10);
				printf("\=============================================\n");

				double temp = *meg->Price;
				for (size_t i = 0; i < 10; i++)
				{
					if (*(meg + i)->Price < temp)
					{
						temp = *(meg + i)->Price;
						min = i;
					}
				}
				printf("\tТовар с минимальной стоимостью\n");
				printf("Наименование: %s\n", (meg + min)->Product);
				printf("Производитель: %s\n", (meg + min)->Producer);
				printf("Количество: %d\n", *(meg + min)->Qnt);
				printf("Цена: %4.2f\n", *(meg + min)->Price);
				printf("Дата выпуска: %d.%d.%d\n",
					*(meg + min)->Date->day,
					*(meg + min)->Date->month,
					*(meg + min)->Date->year);
			}
			free(meg);
		}
		printf("\n");
		break;

		case 4:
			/*4.Определить самого младшего работника и напечатать сведения о нем.*/
		{
			Worker *worker = (Worker*)malloc(sizeof(Worker) * 10);
			int junior = 0;
			if (worker != NULL)
			{
				printf("\tИнформация о работниках\n");
				printf("\--------------------------------------------------------\n");
				for (size_t i = 0; i < 10; i++)
				{
					(worker + i)->Name = (char*)malloc(sizeof(char) * 5);
					(worker + i)->Year = (int*)malloc(sizeof(int));
					(worker + i)->Position = (char*)malloc(sizeof(char) * 6);
					(worker + i)->Payment = (double*)malloc(sizeof(double));
					(worker + i)->Education = (char*)malloc(sizeof(char) * 3);

					generateName((worker + i)->Name);
					generateYear((worker + i)->Year, 1980, 1995);
					generatePosition((worker + i)->Position);
					generatePrice((worker + i)->Payment);
					generateEducation((worker + i)->Education);

					printf("******************************************\n");
					printf("Фамилия: %s\n", (worker + i)->Name);
					printf("Год рождения: %d\n", *(worker + i)->Year);
					printf("Должность: %s\n", (worker + i)->Position);
					printf("Зарплата: %4.2f\n", *(worker + i)->Payment);
					printf("Образование: %s\n", (worker + i)->Education);
				}
				int temp = *worker->Year;
				for (size_t i = 0; i < 10; i++)
				{
					if (*(worker + i)->Year > temp)
					{
						temp = *(worker + i)->Year;
						junior = i;
					}
				}
				printf("\=============================================\n");
				printf("\=============================================\n");
				printf("\tИнформация о самом младшем работнике\n");
				printf("\--------------------------------------------------------\n");
				printf("Фамилия: %s\n", (worker + junior)->Name);
				printf("Год рождения: %d\n", *(worker + junior)->Year);
				printf("Должность: %s\n", (worker + junior)->Position);
				printf("Зарплата: %4.2f\n", *(worker + junior)->Payment);
				printf("Образование: %s\n", (worker + junior)->Education);
			}
			free(worker);
		}
		printf("\n");
		break;

		case 5:
			/*5.Напечатать фамилии студентов, которые сдали математику на «95», и определить их количество.*/
		{
			Students *student = (Students*)malloc(sizeof(Students) * 30);
			int cnt = 0;
			if (student != NULL)
			{
				printf("\tИнформация о студентах, которые сдали математику на «95»\n");
				printf("\--------------------------------------------------------\n");
				for (size_t i = 0; i < 30; i++)
				{
					(student + i)->Name = (char*)malloc(sizeof(char) * 5);
					(student + i)->Group = (char*)malloc(sizeof(char) * 3);
					(student + i)->Year = (int*)malloc(sizeof(int));
					(student + i)->FisMark = (int*)malloc(sizeof(int));
					(student + i)->MathMark = (int*)malloc(sizeof(int));
					(student + i)->InfoMark = (int*)malloc(sizeof(int));

					generateName((student + i)->Name);
					genetrateGroup((student + i)->Group);
					generateYear((student + i)->Year, 2005, 2007);
					generateYear((student + i)->FisMark, 70, 100);
					generateYear((student + i)->MathMark, 70, 100);
					generateYear((student + i)->InfoMark, 70, 100);

					if (*(student + i)->MathMark == 95)
					{
						cnt++;						
						printf("******************************************\n");
						printf("Фамилия: %s\n", (student + i)->Name);
						printf("Группа: %s\n", (student + i)->Group);
						printf("Год рождения: %s\n", *(student + i)->Year);
						printf("Оцнка по физике: %d\n", *(student + i)->FisMark);
						printf("Оценка по математике: %d\n", *(student + i)->MathMark);
						printf("Оценка по информатике: %d\n", *(student + i)->InfoMark);
					}
				}
				printf("Количество студентов, которые сдали математику на «95» = %d\n", cnt);
			}
			free(student);
		}
		printf("\n");
		break;

		default: {printf("Задания с таким номером не существует\n"); }
		}
	} while (N > 0 && N < 5);
	printf("\t\t\t\t\tКОНЕЦ.\n");
	system("pause");
}
