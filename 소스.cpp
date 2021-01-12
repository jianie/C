#include <iostream>

using namespace std;



#define MAX_DEGREE 80 //���׽��� ó�� ������ �ִ�����+1



class Polynomial

{

    int degree; //���׽��� �ְ� ����

    float coef[MAX_DEGREE]; //�� �׿� ���� ���

public:

    Polynomial() //������:�ִ� ������ 0���� �ʱ�ȭ

    {

        degree = 0;

    }

    //���׽��� ������ �Է¹޴� ����Լ�

    void read()

    {

        cout << "���׽��� �ְ� ������ �Է�: ";

        cin >> degree;

        cout << "�� ���� ������ �Է��Ͻÿ� (�� " << degree + 1 << "��): ";

        for (int i = 0; i <= degree; i++)

            cin >> coef[i];

    }

    //���׽��� ������ ȭ�鿡 ����ϴ� �Լ�

    void display(char* str = " Poly = ") //����Ʈ �Ű����� ���

    {

        cout << "\t" << str;

        for (int i = 0; i < degree; i++)

        {

            if (coef[i])

                cout << coef[i] << "x^(" << degree - i << ")";

            if (coef[i + 1])

                cout << " + ";

        }

        if (coef[degree])

            cout << coef[degree];

        cout << endl;

    }

    //���׽� a�� b�� ���ϴ� �Լ�. a�� b�� ���� �ڽ��� ���׽� ����

    void add(Polynomial a, Polynomial b)

    {

        if (a.degree > b.degree) //a��>b��

        {

            *this = a; //a ���׽��� �ڱ� ��ü�� ����

            for (int i = 0; i <= b.degree; i++)

                coef[i + (degree - b.degree)] += b.coef[i];

        }

        else //a��<=b��

        {

            *this = b; //b���׽��� �ڽſ� ����

            for (int i = 0; i <= a.degree; i++)

                coef[i + (degree - a.degree)] += a.coef[i];

        }

        trim();

    }


    void main()
    {
        Polynominal a, b, c;
        a.read();
        b.read();
        c.add(a, b);
        a.display("A= ");
        b.display("B= ");
        c.display("C= ");
    }