#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> life_losses;
vector<int> joy_gets;
vector<int> combination_arr;
int max_joys[21] = { 0 }; 

void getMaxAtCurrentPeople(int depth, int next, int max_num, int selection_num) {
    if (depth == selection_num) {
        int life_sum = 0;
        int joy_sum = 0;

        for (int i : combination_arr) {
            life_sum += life_losses[i];
            joy_sum += joy_gets[i];
        }

        if (life_sum < 100) {
            max_joys[selection_num] = max(max_joys[selection_num], joy_sum);
        }

        return;
    }

    for (int i = next; i <= max_num; i++) {
        combination_arr[depth] = i;
        getMaxAtCurrentPeople(depth + 1, i + 1, max_num, selection_num);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int number_of_people;
    cin >> number_of_people;

    life_losses.resize(number_of_people);
    joy_gets.resize(number_of_people);

    for (int i = 0; i < number_of_people; i++) {
        cin >> life_losses[i];
    }

    for (int i = 0; i < number_of_people; i++) {
        cin >> joy_gets[i];
    }

    for (int i = 0; i <= number_of_people; i++) {
        combination_arr.resize(i);
        getMaxAtCurrentPeople(0, 0, number_of_people - 1, i);
    }

    cout << *max_element(max_joys, max_joys + number_of_people + 1);

    return 0;
}
