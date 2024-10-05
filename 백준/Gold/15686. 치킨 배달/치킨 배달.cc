#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

vector<vector<int>> grid(51, vector<int>(51, 0));
vector<pair<int, int>> house_pairs;
vector<pair<int, int>> chicken_pairs;
vector<int> current_selections;
vector<int> sums;

void combination_arithmetic(int depth, int next, int count_obj) //count_obj is the objective count of chicken stores.
{
    if (depth == count_obj)
    {
        vector<int> currentDistances(house_pairs.size(), INT_MAX);

        // Calculate distances for the current selection of chicken stores
        for (int i = 0; i < house_pairs.size(); i++)
        {
            for (int j = 0; j < count_obj; j++) // Iterate over selected chicken stores
            {
                int distance = abs(house_pairs[i].first - chicken_pairs[current_selections[j]].first)
                    + abs(house_pairs[i].second - chicken_pairs[current_selections[j]].second);
                currentDistances[i] = min(currentDistances[i], distance); // Find the minimum distance for each house
            }
        }

        // Sum the distances for the current combination
        int totalDistance = accumulate(currentDistances.begin(), currentDistances.end(), 0);
        sums.push_back(totalDistance);

        return;
    }

    for (int i = next; i < chicken_pairs.size(); i++)
    {
        current_selections[depth] = i;
        combination_arithmetic(depth + 1, i + 1, count_obj);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // Inputs
    int n, m;
    cin >> n >> m; // n == square's side length. m = count of chickens

    // Inputs.grid
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int value; // Current input.
            cin >> value;
            if (value == 1) // New value has the position of a house
            {
                house_pairs.push_back(make_pair(i, j));
                grid[i][j] = 1;
            }
            else if (value == 2) // New value has the position of a chicken store.
            {
                chicken_pairs.push_back(make_pair(i, j));
                grid[i][j] = 2;
            }
        }
    }

    // Initialize vectors
    sums.reserve(house_pairs.size());
    current_selections.resize(m);

    // Find the combination
    combination_arithmetic(0, 0, m);

    // Find the minimum value of sums
    int min_value = *min_element(sums.begin(), sums.end());

    cout << min_value;

    return 0;
}
