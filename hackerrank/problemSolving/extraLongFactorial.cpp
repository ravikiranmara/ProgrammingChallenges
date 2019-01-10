#include <bits/stdc++.h>

using namespace std;

using namespace std;

class SimpleBigInteger {
    vector<int> number;

    void reset() {
        this->number.clear();
    }
    
  public:
    SimpleBigInteger() {
        this->reset();
    }

    SimpleBigInteger(int number) {
        this->initialize(number);
    }

    void initialize(int number) {
        this->reset();

        while(number > 0) {
            this->number.push_back(number % 10);
            number /= 10;
        }
    }

    void multiply(int operand) {
        int carry = 0;
        int tempMul = 0;
        int tail = 0;

        for (auto num = this->number.begin(); num != this->number.end(); num++) {
            tempMul = (*num) * operand + carry;
            tail = tempMul % 10;   
            carry = tempMul / 10;

            *num = tail;
        }

        while (carry > 0) {
            tail = carry % 10;
            this->number.push_back(tail);
            carry /= 10;
        }

        return;
    }

    void print() {
        for (auto num = this->number.rbegin(); num != this->number.rend(); num++) 
            cout << *num;
    }
};

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    SimpleBigInteger bigNum (1);

    for (int i=1; i<=n; i++)
        bigNum.multiply(i);

    bigNum.print();
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}

// https://www.hackerrank.com/challenges/extra-long-factorials
