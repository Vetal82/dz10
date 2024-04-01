//str 27-28 urok 15

//#include <iostream>
//using namespace std;
//int add(int n, int m)
//{
//	return n + m;
//}
//int division(int n, int m)
//{
//	return n / m;
//}
//int mult(int n, int m)
//{
//	return n * m;
//}
//int subt(int n, int m)
//{
//	return n - m;
//}
//int main()
//{
//	int (*par)(int, int); // �������� �� �������
//	int a = 6, b = 2;
//	char c = '+';
//	par = add;
//	while (c != ' ')
//	{
//		cout << "\n Arguments: a = " << a
//			<< ", b = " << b;
//		cout << ". Result for c = \'" << c << "\':";
//		switch (c)
//		{
//		case '+':
//		{
//			par = add;
//			c = '/';
//			break;
//		}
//		case '-':
//		{
//			par = subt;
//			c = ' ';
//			break;
//		}
//		case '*':
//		{
//			par = mult;
//			c = '-';
//			break;
//		}
//		case '/':
//		{
//			par = division;
//			c = '*';
//			break;
//		}
//		}
//		a = (*par)(a, b);// ������ �� �������
//		cout << a << "\n";
//	}
//	return 0;
//}

//str 32-34 urok 15

//#include <iostream>
//using namespace std;
//#include <iostream>
//using namespace std;
///* ���������� ������� ��� ������� ���� (�������
//�������, ����� �������� �� �� ���������):*/
//void act1(char* name)
//{
//	cout << "Create file..." << name;
//}
//void act2(char* name)
//{
//	cout << "Delete file... " << name;
//}
//void act3(char* name)
//{
//	cout << "Read file... " << name;
//}
//void act4(char* name)
//{
//	cout << "Mode file... " << name;
//}
//void act5(char* name)
//{
//	cout << "Close file... " << name;
//}
//int main()
//{
//	// ��������� � ����������� ������ ���������
//	void (*MenuAct[5])(char*) = { act1, act2, act3,
//	act4, act5 };
//	int number; // ����� �������� ������ ����.
//	char FileName[30]; // ����� ��� ���� �����.
//	// ��������� ����
//	cout << "\n 1 - Create";
//	cout << "\n 2 - Delete";
//	cout << "\n 3 - Read";
//	cout << "\n 4 - Mode";
//	cout << "\n 5 - Close";
//	while (1)// ����������� ����
//	{
//		while (1)
//		{
//			/* ���� ������������ �� �����
//			����������� ������.*/
//			cout << "\n\nSelect action: ";
//			cin >> number;
//			if ((number >= 1) && (number <= 5))
//			{
//				break;
//			}
//			else
//			{
//				cout << "\nWrong number!";
//			}
//		}
//		if (number != 5)
//		{
//			cout << "Enter file name: ";
//			cin >> FileName; // ������ ��� �����.
//			34
//				���� � 15
//				// ������ ������� �� ���������� �� ��
//				(*MenuAct[number - 1])(FileName);
//		}
//		else
//		{
//			break;
//		}
//	}
//	return 0;
//}


//2
// .	��������� ������� ���������� ������.��� ��������� �������� ������ �������� ������� ������� �� �������� ����� ��������.


//#include <iostream>
//#include "ArrayTemplate.h"
//using namespace std;
//int main()
//{
//    int arr[] = { 3, 7, 1, 9, 5, 2, 8, 4, 6 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//    // Sorting to up
//    sort<int>(arr, size, [](int a, int b) { return a < b; });
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    // Sorting to down
//    sort<int>(arr, size, [](int a, int b) { return a > b; });
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    // Parni na poczatku, neparni w kinci
//    sort<int>(arr, size, [](int a, int b) {
//        if (a % 2 == 0 && b % 2 != 0) {
//            return true;
//        }
//        else if (a % 2 != 0 && b % 2 == 0) {
//            return false;
//        }
//        else {
//            return a < b;
//        }
//        });
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//3.	�������� �������, ��� ��������� ������ ���������� �������� ������ �� �������.��������� ��������� ������ ��� �������.

#include <iostream>
#include "ArrayTemplate.h"
using namespace std;
bool isPositive(int x) {
    return x > 0;
}

bool isNegative(int x) {
    return x < 0;
}

bool isEven(int x) {
    return x % 2 == 0;
}

bool isOdd(int x) {
    return x % 2 != 0;
}

int main() {
    int arr[] = { -2, -1, 0, 1, 2, 3, 4, 5 };

    // ��������� ������ ���������� ����������� �����
    int lastIndexPositive = findLast_if(arr, sizeof(arr) / sizeof(arr[0]), isPositive);
    if (lastIndexPositive != -1) {
        cout << "Last positive element index: " << lastIndexPositive << std::endl;
    }
    else {
        cout << "No positive elements found." << std::endl;
    }

    // ��������� ������ ���������� ����������� �����
    int lastIndexNegative = findLast_if(arr, sizeof(arr) / sizeof(arr[0]), isNegative);
    if (lastIndexNegative != -1) {
        cout << "Last negative element index: " << lastIndexNegative << std::endl;
    }
    else {
        std::cout << "No negative elements found." << std::endl;
    }

    // ��������� ������ ���������� ������� �����
    int lastIndexEven = findLast_if(arr, sizeof(arr) / sizeof(arr[0]), isEven);
    if (lastIndexEven != -1) {
        cout << "Last even element index: " << lastIndexEven << std::endl;
    }
    else {
        cout << "No even elements found." << std::endl;
    }

    // ��������� ������ ���������� ��������� �����
    int lastIndexOdd = findLast_if(arr, sizeof(arr) / sizeof(arr[0]), isOdd);
    if (lastIndexOdd != -1) {
        cout << "Last odd element index: " << lastIndexOdd << std::endl;
    }
    else {
        cout << "No odd elements found." << std::endl;
    }

    return 0;
}