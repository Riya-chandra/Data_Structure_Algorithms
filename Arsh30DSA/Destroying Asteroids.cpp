class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        //mass>=asteroids 
        //mass of the planet=10, 0 th as has mass-3, 1 as has mass=9 , 2 as has mass=19 ...
        // mass=10 humko dekhna h ki 10 se zada mass ka h ya nh ikoi kyuki eventually humme last msb asteriod ko khtm krn ahoga 
        // max of astroid=21 toh humme atleast mass of plate ko 21 pahuchnahoga 
        //sort krege = 3 5 9 19 21 
        //mass=5 ..4 4 9 23 .....
      
        sort(asteroids.begin(), asteroids.end());
        long long planetMass=mass;
        for (int a : asteroids) {
            if (planetMass < a) return false;
            planetMass += a;
        }
        return true;
    }
};