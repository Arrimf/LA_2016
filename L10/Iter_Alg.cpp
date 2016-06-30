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
		PrintCont(poiVect);
		_SP



			//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
			//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
			//[-n, +m].

			//double n = 4;
		//	double m = 7;
	//vector<Point> res = ptList2

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	






	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	



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

