#include <iostream>
using namespace std;

int rotate(int start, char dir, int rotate_amount);

int main()
{
    char direction;
    int amount;
    int password = 0;
    int current = 50;

    while(cin >> direction)
    {
        cin >> amount;
        current = rotate(current, direction, amount);
        // cout << current << endl;
        if(current == 0) password += 1;
    }
    cout << password << endl;
    return 0;
}

int rotate(int start, char dir, int rotate_amount)
{
    int num = start;
    for(int i = rotate_amount; i > 0; i--)
    {
        if(dir == 'L')
        {
            if(num == 0)
            {
                num = 99;
            } else {
                num -= 1;
            }
        } else if(dir == 'R')
        {
            if(num == 99)
            {
                num = 0;
            } else {
                num += 1;
            }
        }
    }
    return num;
}