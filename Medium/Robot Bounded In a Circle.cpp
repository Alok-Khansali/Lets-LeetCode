class Solution { //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Robot Bounded In Circle.
public:
    bool isRobotBounded(string instructions) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int a[4] ={0,0,0,0}, r = 0;                                  //Array to store four directions in format N W S E
                                                                     //r can be thought of as a direction indicator
        for(char i : instructions)                                   //Traverse the characters in the instructions
        {
            if(i == 'G')                                             //If character is G, go straight in the direction where the robot is looking at
                a[r]++;
            else if(i == 'L')                                        //Move 90 degrees to left
                r = (3 + r)%4;
            else                                                     //Move 90 degrees to right
                r = (r + 1)%4;
        }
        return (a[0] == a[2] && a[1] == a[3] || r != 0);             // If (North movement = South Movement
                                                                     // And West Movement = East Movement), 
                                                                     // Or r != 0,Return Yes
        /*
        r = 0, means no turning on the overall movement
        In this case the up-down and right-left movements should be equal
        */
    }
};
