// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

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

	//������� 1. ���������

	//����������� ���������. ����������� set<Point>. ���������, ���
	//����� ����������� � ������ Point. �������� ������, �������� �������� 
	//�������� ������� ��������� set, �� ����������� �� ��������

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

	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
	
	ostream_iterator<Point>it(std::cout,"\n");

	//copy(poiSet.begin(), poiSet.end(), it);
	//cout << endl;
	//copy(poiVect.begin(), poiVect.end(), it);
	//_SP

	//��������� �������. � ������� ������������ ���������:
	//back_inserter()	 - ������ ���, ��� ���� push_back
	//front_inserter()  - ������ ���, ��� ���� push_front
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������. - inserter()

	copy(poiSet.begin(), poiSet.end(), back_inserter(poiVect));
	//copy(poiVect.begin(), poiVect.end(), it);

	
	//_SP
		///////////////////////////////////////////////////////////////////

			//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

			// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
			//(������, vector, list...)
			//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
			//������������ �������� ���������
			//��������� : ������� ���������� ������� ���������� ��� ������

		//PrintCont(poiVect);
		//_SP
		stop

		//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
		//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
		//��� ������) � �������� ��������� � ������� ����������� ���������



	//RandPoiAssigner( ptList2);
	//PrintCont(ptList2);
	//_SP


		//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
		//��� ��������� �� ������� Point � ��������� ���������.

		deque<Point> PoisNew;

		PoisNew = PoiFinder(ptList2, Point(2, 2));

		//_SP
		

	
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	//���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	
		sort(poiVect.begin(), poiVect.end());
		PrintCont(poiVect);
		_SP


	
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].

	

	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	






	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()


		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
	



		stop
	}
	{// map
		
		//����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������
	







	}

	


	return 0;
}

