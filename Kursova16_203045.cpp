#include <iostream>

using namespace std;

struct num
{
	int cifra;
	num* next;
};

typedef num* point;
point Head;

// Функция за създаване на списък
int Create(point& Head)
{
	int x;
	cout << "Vuvedete goleminata na spisuka: ";
	cin >> x;

	point P;
	point Last = NULL;

	for (int i = 0; i < x; i++)
	{
		P = new num;
		cout << "Cifra = ";
		cin >> P->cifra;
		P->next = NULL;
		if (Head == NULL)
			Head = P;
		else
			Last->next = P;
		Last = P;
	}
	return 0;
}

//Функция за принтиране/извеждане на екрана на списъкът
int Print(point P)
{
	cout << "N = ";
	while (P)
	{
		cout << P->cifra << " -> ";
		P = P->next;
	}
	cout << endl;
	return 0;
}

//Функция за обръщане на списъкът
num* reverseList(num* Head)
{
	num* current = Head;
	num* prev = NULL;
	num* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

//Фунцкия за сумиране на 2 списъка в 1 нов
int Sum(num* Head1, num* Head2, point& Head3)
{
	Head1 = reverseList(Head1);
	Head2 = reverseList(Head2);
	point P, Last;
	Last = NULL;
	int carry = 0;
	
	while (Head1 || Head2)
	{
		int sum = 0;
		if (Head1)
		{
			sum += Head1->cifra;
			Head1 = Head1->next;
		}
		if (Head2)
		{
			sum += Head2->cifra;
			Head2 = Head2->next;
		}
		sum += carry;
		
		if (sum > 9)
		{
			carry = sum / 10;
		}
		else
		{
			carry = 0;
		}
		sum = sum % 10;

		P = new num;
		P->cifra = sum;
		P->next = NULL;

		if (Head3 == NULL)
		{
			Head3 = P;
		}
		else
		{
			Last->next = P;
		}
		Last = P;
	}
	if (carry > 0)
	{
		P = new num;
		P->cifra = carry;
		P->next = NULL;

		if (Head3 == NULL)
		{
			Head3 = P;
		}
		else
		{
			Last->next = P;
		}
		Last = P;
	}
	Head3 = reverseList(Head3);
	return 0;
}

int main()
{
	point Head1, Head2, Head3;
	Head1 = Head2 = Head3 = NULL;

	Create(Head1);
	Create(Head2);

	Print(Head1);
	Print(Head2);

	int sum = Sum(Head1, Head2, Head3);
	cout << endl << "Rezultat ot sumiraneto na N1 & N2: " << endl;
	Print(Head3);
}