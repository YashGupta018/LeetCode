class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            int asteroid = asteroids[i];

            while (j > 0 && asteroids[j - 1] > 0 && asteroid < 0 && asteroids[j - 1] < abs(asteroid)) {
                j--;
            }

            if (j == 0 || asteroid > 0 || asteroids[j - 1] < 0) {
                asteroids[j++] = asteroid;
            } else if (asteroids[j - 1] == abs(asteroid)) {
                j--;
            }
        }

        vector<int> result(asteroids.begin(), asteroids.begin() + j);

        return result;
    }
};