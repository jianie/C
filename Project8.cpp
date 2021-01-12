// Project8.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include<cstdio>
#define MAX_DEGREE 80

class Polynominal {
    int degree;
    int coef[MAX_DEGREE];

public:
    Polynominal() { degree = 0; }


    void read() {
        printf("다항식의 최고 차수를 입력하시오:");
        scanf("%d", &degree);
        printf("각 항의 계수를 입력하시오 ( 총 %d개) : ", degree + 1);
        for (int i = 0; i <= degree; i++)
            scanf("%f", coef + i);

    }

    void display(char* str = "Poly=") {
        printf("\t%s", str);
        for (int i = 0; i < degree; i++)
            printf("%5.1f x^%d + ", coef[i], degree - i);

        printf("%4.1f\n", coef[degree]);
    }

    void add(Polynominal a, Polynominal b) {

        if (a.degree > b.degree) {
            *this = a;
            for (int i = 0; i <= b.degree; i++)
                coef[i + (degree - b.degree)] += b.coef[i];
        }
        else {
            *this = b;
            for(int i=0; i<=a.degree; i++)
                coef[i + (degree - a.degree)] += a.coef[i];

        }
    }
};


int main()
{
    Polynominal a, b, c;
    a.read();
    b.read();
    c.add(a, b);
    a.display("A=");
    b.display("B=");
    c.display("C=");


}

