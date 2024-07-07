#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> curAsteroids = asteroids;
        while (true) {

            for (auto x : curAsteroids) {
                cout << x << ' ';
            }
            cout << endl;

            bool collision = false;
            vector<int> newAsteroids;
            newAsteroids.push_back(curAsteroids[0]);

            for (int i = 1; i < curAsteroids.size(); i++) {
                if (newAsteroids.size() == 0) {
                    newAsteroids.push_back(curAsteroids[i]);
                }
                else if (newAsteroids.back() > 0 and curAsteroids[i] < 0) {
                    collision = true;
                    if (abs(newAsteroids.back()) < abs(curAsteroids[i])) {
                        newAsteroids.pop_back();
                        newAsteroids.push_back(curAsteroids[i]);
                    }
                    else if (abs(newAsteroids.back()) == abs(curAsteroids[i])) {
                        newAsteroids.pop_back();
                    }
                }
                else {
                    newAsteroids.push_back(curAsteroids[i]);
                }
            }

            if (!collision) {
                break;
            }

            curAsteroids = newAsteroids;

        }

        return curAsteroids;

    }
};