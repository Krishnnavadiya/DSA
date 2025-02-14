#include <bits/stdc++.h>
using namespace std;

// 1352. Product of the Last K Numbers

class ProductOfNumbers
{
    vector<int> vc = {1};
    int lastZeroIndex;
    int n;

public:
    ProductOfNumbers()
    {
        n = 1;
        lastZeroIndex = -1;
    }

    void add(int num)
    {
        if (num == 0)
            lastZeroIndex = n;
        if (vc.back() == 0)
            vc.push_back(num);
        else
            vc.push_back(vc.back() * num);
        n++;
    }

    int getProduct(int k)
    {
        if (lastZeroIndex >= n - k)
            return 0;
        if (vc[n - k - 1] == 0)
        {
            return vc[n - 1];
        }
        return vc[n - 1] / vc[n - k - 1];
    }
};

int main()
{
    ProductOfNumbers obj;
    obj.add(3);
    obj.add(0);
    obj.add(2);
    obj.add(5);
    obj.add(4);

    cout << obj.getProduct(2) << endl;
    cout << obj.getProduct(3) << endl;
    cout << obj.getProduct(1) << endl;
}


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */