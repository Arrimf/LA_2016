// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <tchar.h>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>


#include <ctime>
#include "myString.h"
#include "Shape.h"
#include "Rect.h"
#include "Point.h"
#include "Templs.h"

using namespace std;	

#define	  stop __asm nop
#define  _SP system("pause");

int _tmain(int argc, _TCHAR* argv[])
{
	std::srand(time(0));
	setlocale(LC_ALL, "Russian");
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	deque<Point>ptList2;
	ptList2.push_back(Point(2, 2));
	ptList2.push_back(Point(3, 2));
	ptList2.push_back(Point(5, 1));
	ptList2.push_front(Point(4, 5));
	ptList2.push_front(Point(3, 7));
	ptList2.push_front(Point(1, 2));
	ptList2.push_back(Point(2, 2));


	set<Point> poiSet(ptList2.begin(), ptList2.end());
	vector<Point> poiVect(poiSet.rbegin(), poiSet.rend());
	//Print(poiVect);
	//_SP

	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.
	
	ostream_iterator<Point>it(std::cout,"\n");

	//copy(poiSet.begin(), poiSet.end(), it);
	//cout << endl;
	//copy(poiVect.begin(), poiVect.end(), it);
	//_SP

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()	 - только там, где есть push_back
	//front_inserter()  - только там, где есть push_front
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером. - inserter()

	copy(poiSet.begin(), poiSet.end(), back_inserter(poiVect));
	//copy(poiVect.begin(), poiVect.end(), it);

	
	//_SP
		///////////////////////////////////////////////////////////////////

			//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

			// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
			//(массив, vector, list...)
			//С помощью алгоритма for_each в любой последовательности с элементами любого типа
			//распечатайте значения элементов
			//Подсказка : неплохо вызываемую функцию определить как шаблон

		//PrintCont(poiVect);
		//_SP
		stop

		//С помощью алгоритма for_each в любой последовательности с элементами типа Point
		//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
		//как шаблон) и выведите результат с помощью предыдущего предиката



	//RandPoiAssigner( ptList2);
	//PrintCont(ptList2);
	//_SP


		//С помощью алгоритма find() найдите в любой последовательности элементов Point
		//все итераторы на элемент Point с указанным значением.

		deque<Point> PoisNew;

		PoisNew = PoiFinder(ptList2, Point(2, 2));

		//_SP
		

	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	//Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	
		sort(poiVect.begin(), poiVect.end());
		//PrintCont(poiVect);
		//_SP



			//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
			//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
			//[-n, +m].

			double n = 4;
			double m = 7;

			//unary_function < Point&, bool > pred = [](Point& poi)->bool {return poi.GetX() > poi.GetY();};

			auto itb = ptList2.begin();
			auto ite = ptList2.end();
			vector<Point> res;
			
			while ( (itb = find_if(itb, ite, [n, m](Point& poi) 
				{return (((poi.GetX()) >= n && (poi.GetX() <= m)) || ((poi.GetY() >= n) && (poi.GetY() <= m)));}))
					!= ite) {
				res.push_back(*itb);
				++itb;
				};
			
			//PrintCont(res);
			//_SP

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	
			vector<Shape*> ShapesList;

			for (int i = 0; i < 20;i++) {
				int tmp = rand() % 2;
				if (tmp) {
					ShapesList.push_back(new Rect(RandPoi(), RandPoi()));
				}
				else {
					ShapesList.push_back(new Circle(RandPoi(), RandPoi()));

				}
			}
				//Print(ShapesList, &Shape::OffsetZero);
				//_SP

				sort(ShapesList.begin(), ShapesList.end(), [](Shape* obj1, Shape* obj2) {
								return obj1->OffsetZero() < obj2->OffsetZero();
				});

				//Print(ShapesList);
				//Print(ShapesList, &Shape::OffsetZero);
				//_SP

	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

		string str = "qWerTYy";
		string str2;
		str2.resize(str.size());
		transform(str.begin(), str.end(), str2.begin(), [](const char t)->char {return tolower(t);});
		Print(str2);
		_SP
			//Заполните list объектами string. С помощью алгоритма transform сформируте
			//значения "пустого" set, конвертируя строки в нижний регистр
			list<string> StrS;
		StrS.push_back(str);
		StrS.push_back("aAFasdgagADFHAFgaWERa");
		StrS.push_back("ASQWecxvzxGdRGDCNYU");
		StrS.push_back("QWEDFdfAWqwe");

		set<string>SetStr;
		auto itB = StrS.begin();
		auto itE = StrS.end();
		auto itDest = SetStr;
		while (itB != itE){
			//transform(*itB.begin());
		}

		stop
	}
	{// map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	







	}

	


	return 0;
}

