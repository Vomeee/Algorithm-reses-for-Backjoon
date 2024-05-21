#include <iostream>


using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int directions[6]{};
    int lengths[6]{};

    int n;
    cin >> n;

    for (int i = 0; i < 6; i++)
    {
        int direction, length;
        cin >> direction >> length;

        directions[i] = direction;
        lengths[i] = length;
    } //arr complete.

    int s1, s2;
    int l1, l2;

    for (int i = 0; i < 6; i++)
    {
        if (directions[(i + 2) % 6] == directions[i] && directions[(i + 5) % 6] == directions[(i + 1) % 6]) //음수 방지
        {
            s1 = lengths[i];
            s2 = lengths[(i + 1) % 6];
            l1 = lengths[(i + 3) % 6];
            l2 = lengths[(i + 4) % 6];
            break;
        }
    }

    cout << n * (l1 * l2 - s1 * s2);

    



}
