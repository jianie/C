#include <iostream>
using namespace std;
#define MAX_TERMS 21

struct Term { // 하나의 항을 표현하는 구조체
    int expn; //항의 지수
    float coef; //항의 계수
};

void sortPoly(Term term[], int nTerms) {
    for (int i = 0; i < nTerms; i++)
    {
        for (int j = i; j < nTerms; j++)
        {
            if (term[i].expn < term[j].expn)
            {
                Term temp = term[i];
                term[i] = term[j];
                term[j] = temp;
            }
        }
    }
}

class SparsePoly { // 희소 다항식 클래스

private:
    int nTerms; // 계수가 0이 아닌 항의 개수
    Term term[MAX_TERMS]; // 계수가 0이 아닌 항의 배열

public:
    SparsePoly() {}

    void read() {// 희소 다항식을 입력하는 함수
        cout << "계수가 0이 아닌 항의 개수: ";
        cin >> nTerms;
        for (int i = 0; i < nTerms; i++)
        {
            struct Term temp;
            cout << i + 1 << " 번째 항의 계수와 지수를 입력하시오. : ";
            cin >> temp.coef >> temp.expn;
            term[i] = temp;
        }
    }

    void add(SparsePoly a, SparsePoly b) { // 입력된 두 희소 다항식을 더하는 함수
        int count = 0, bcount = 0;
        int start = 0;
        struct Term add;
        *this = a;
        nTerms += b.nTerms;
        Term* temp = new Term[a.nTerms];
        for (int i = 0; i < a.nTerms; i++)
            temp[i] = a.term[i];
        while (count < nTerms && bcount < b.nTerms) {
            if (temp[count].expn == b.term[bcount].expn)
            {
                add.coef = temp[count].coef + b.term[bcount].coef;
                add.expn = temp[count].expn;
                term[start++] = add;
                count++;
                bcount++;
                nTerms--;
            }
            else if (temp[count].expn > b.term[bcount].expn) {
                term[start++] = temp[count];
                count++;
            }
            else {
                term[start++] = b.term[bcount];
                bcount++;
            }
        }

        for (; count < nTerms; count++) {
            term[start++] = temp[count];
        }

        for (; bcount < b.nTerms; bcount++) {
            term[start++] = b.term[bcount];
        }

        delete[]temp;
    }

    void display(const char* str = "SPoly= ") { // 희소 다항식을 출력하는 함수
        sortPoly(term, nTerms);
        for (int i = 0; i < nTerms; i++) {
            cout << term[i].coef;
            if (term[i].expn)
                cout << "x^" << term[i].expn << "";
            if (i != nTerms - 1)
                cout << " + ";
        }
        cout << endl;
    }
};

int main(void) // 설계된 함수를 구현하는 함수
{
    SparsePoly sp1, sp2, sp3;
    sp1.read();
    sp2.read();
    sp3.add(sp1, sp2);
    cout << " 첫 번째 희소 다항식 : ";
    sp1.display();
    cout << " 두 번째 희소 다항식 : ";
    sp2.display();
    cout << " 첫 번째 다항식과 두 번째 다항식을 더한 값 : ";
    sp3.display();

    return 0;
}