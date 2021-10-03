#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <random>
#include <algorithm>

using namespace std;

template<class A>
void insert_sorted(vector <A>& vct, A val) {
    vct.insert(upper_bound(vct.begin(), vct.end(), val), val);
}

int main()
{
    {
        // #1
        vector <int> a = { 1, 2, 4, 5, 6, 7, 8, 9, 10};
        cout << "Before inserting: " << endl;
        copy(a.begin(), a.end(), ostream_iterator<float>{cout, " "});
        cout << endl;

        insert_sorted(a, 3);
        cout << "After inserting: " << endl;
        copy(a.begin(), a.end(), ostream_iterator<float>{cout, " "});
        cout << endl << endl;
    }

    {
        // #2
        // Генерация первого вектора и печать
        vector <float> a;
        for (int i = 0; i < 100; i++) {
            int tmp = rand() % 100 - 50;
            while (!tmp) {
                tmp = rand() % 100 - 50;
            }
            a.push_back((float)(rand() % 100 - 50) / tmp);
        }
        cout << "Before dropping the fractional part: " << endl;
        copy(a.begin(), a.end(), ostream_iterator<float>{cout, " "});
        cout << endl;

        // Отбрасываение дробной части и печать
        vector <int> b;
        b.resize(a.size());
        copy(a.begin(), a.end(), b.begin());
        cout << "After dropping the fractional part: " << endl;
        copy(b.begin(), b.end(), ostream_iterator<float>{cout, " "});
        cout << endl;

        // Нахождение ошибки и печать
        vector <float> c;
        c.resize(b.size());
        for (int i = 0; i < b.size(); c[i] = a[i] - b[i], i++);
        transform(c.begin(), c.end(), c.begin(), [](float i) { return pow(i, 2); });
        cout << "Error is: " << accumulate(c.begin(), c.end(), 0.0) << endl;
    }

    return 0;
}