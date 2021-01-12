#include <iostream>
using namespace std;
#define MAX_TERMS 21

struct Term { // �ϳ��� ���� ǥ���ϴ� ����ü
    int expn; //���� ����
    float coef; //���� ���
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

class SparsePoly { // ��� ���׽� Ŭ����

private:
    int nTerms; // ����� 0�� �ƴ� ���� ����
    Term term[MAX_TERMS]; // ����� 0�� �ƴ� ���� �迭

public:
    SparsePoly() {}

    void read() {// ��� ���׽��� �Է��ϴ� �Լ�
        cout << "����� 0�� �ƴ� ���� ����: ";
        cin >> nTerms;
        for (int i = 0; i < nTerms; i++)
        {
            struct Term temp;
            cout << i + 1 << " ��° ���� ����� ������ �Է��Ͻÿ�. : ";
            cin >> temp.coef >> temp.expn;
            term[i] = temp;
        }
    }

    void add(SparsePoly a, SparsePoly b) { // �Էµ� �� ��� ���׽��� ���ϴ� �Լ�
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

    void display(const char* str = "SPoly= ") { // ��� ���׽��� ����ϴ� �Լ�
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

int main(void) // ����� �Լ��� �����ϴ� �Լ�
{
    SparsePoly sp1, sp2, sp3;
    sp1.read();
    sp2.read();
    sp3.add(sp1, sp2);
    cout << " ù ��° ��� ���׽� : ";
    sp1.display();
    cout << " �� ��° ��� ���׽� : ";
    sp2.display();
    cout << " ù ��° ���׽İ� �� ��° ���׽��� ���� �� : ";
    sp3.display();

    return 0;
}