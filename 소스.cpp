#include <iostream>

using namespace std;



#define MAX_DEGREE 80 //다항식의 처리 가능한 최대차수+1



class Polynomial

{

    int degree; //다항식의 최고 차수

    float coef[MAX_DEGREE]; //각 항에 대한 계수

public:

    Polynomial() //생성자:최대 차수를 0으로 초기화

    {

        degree = 0;

    }

    //다항식의 내용을 입력받는 멤버함수

    void read()

    {

        cout << "다항식의 최고 차수를 입력: ";

        cin >> degree;

        cout << "각 항의 개수를 입력하시오 (총 " << degree + 1 << "개): ";

        for (int i = 0; i <= degree; i++)

            cin >> coef[i];

    }

    //다항식의 내용을 화면에 출력하는 함수

    void display(char* str = " Poly = ") //디폴트 매개변수 사용

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

    //다항식 a와 b를 더하는 함수. a와 b를 더해 자신의 다항식 설정

    void add(Polynomial a, Polynomial b)

    {

        if (a.degree > b.degree) //a항>b항

        {

            *this = a; //a 다항식을 자기 객체에 복사

            for (int i = 0; i <= b.degree; i++)

                coef[i + (degree - b.degree)] += b.coef[i];

        }

        else //a항<=b항

        {

            *this = b; //b다항식을 자신에 복사

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