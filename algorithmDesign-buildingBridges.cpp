#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
//////////////////////////////
int *city_a, *city_b, **bridg,*result;
int size_of_city = 0;
int  maxbridg=0;
///////////////////////////
int find_size()
{
	ifstream f;
	int temp = 0, x;
	f.open("in.txt");
	while (f >> temp)
	{
		x = temp;
		break;
	}
	f.close();
	return x;
}
///////////////////
void setarray()
{
	result=new int[size_of_city + 1];
	city_a = new int[size_of_city + 1];
	city_b = new int[size_of_city + 1];
	city_a[0] = 0;
	city_b[0] = 0;
	bridg = new  int*[size_of_city + 1];
	for (int i = 0; i <= size_of_city; i++)
		bridg[i] = new  int[size_of_city + 1];
	for (int i =0 ; i <= size_of_city; i++)
	{
		bridg[0][i] = 0;
		bridg[i][0] = 0;
	}
}
///////////
void fillarray()
{
	ifstream f;
	bool r = true;
	int temp = 0, i = 1, j = 1, s = 0;
	f.open("in.txt");
	while (f >> temp)
	{
		if (r == true)r = false;
		else
		{
			if (0 <= s && s< size_of_city)
			{
				city_a[i] = temp; i++;
				s++;
				if (s == size_of_city)continue;
			}
			if (size_of_city <= s && s< 2 * size_of_city)
			{
				city_b[j] = temp; j++;
				s++;
			}
		}
	}
	f.close();
}
///////////
void fillbridg()
{
	for (int i = 1; i <= size_of_city; i++)
	{
		for (int j = 1; j <= size_of_city; j++)
		{
			if (city_a[j] == city_b[i])
				bridg[i][j] = 1;
			else
				bridg[i][j] = 0;
		}
	}
}
///////////
int minghotrp(int p)
{
	int k = size_of_city;
	for (int i = 0; i <p; i++)
		if (bridg[k -p+i][k - i] == 1)
			return k -p+ i;
	return 0;
}
//////////////
int minghotrb(int p)
{
	int q=p;
	for (int i = 0; i < p; i++)
		if (bridg[i + 1][q - i] == 1)
			return i + 1;
	return 0;
}
/////////////
void mainjob()
{
	int p = 0;
	int s = 0;
	////////////// paein
	for (int i = 1; i < size_of_city; i++)
	{
		s = 0;
		s = minghotrp(i);
		if (s > 0)
		{
			result[p] = s;
			p++;
			maxbridg++;
		}
	}
	//////////////////////////////////////////// bala
	for (int i = 1; i < size_of_city; i++)
	{
		s = 0;
		s = minghotrb(i);
		if (s > 0)
		{
			result[p] = s;
			p++;
			maxbridg++;
		}
	}
}
/////////////
void addtofile()
{
	ofstream f;
	f.open("out.txt");
	f << maxbridg << endl;
	for (int i = 0; i < maxbridg; i++)
		f << result[i] << "   ";
	f.close();
}
////////////
void print()
{
	cout << "---------------------------------------------------------------" << endl;
	cout <<"max bridg is :"<< maxbridg <<endl;
	for (int i = 0; i < maxbridg; i++)
		cout << result[i] << "   ";
}

///////////////
void printbridg()
{
	for (int i = 0; i <= size_of_city; i++)
		cout <<"A[0][" << i << "]  ";
	cout << endl;
	for (int i = 0; i <= size_of_city; i++)
	{
		for (int j = 0; j <= size_of_city; j++)
		{
			if (j == 0) 
				cout << "A["<< i<<"][0]: ";
			cout << bridg[i][j]<<"       " ;
		}
		cout << endl;
	}
}
////////
int main()
{
	size_of_city = find_size();
	setarray();
	fillarray();
	fillbridg();
	printbridg();
	mainjob();
	print();
	addtofile();
	system("pause");
	return 0;
}

