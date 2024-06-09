class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int length = hand.size();
        // The task is only possible if the length of the array is a multiple of groupSize
        // Else the division into groups is not possible
        if (length % groupSize != 0)
            return false;
        // A container that can store multiple similiar values
        // But takes very less time for adding or removing an element
        multiset<int> Multiset;
        for (int i : hand)
            Multiset.insert(i);
        while (!Multiset.empty())
        {
            // Since the Multiset keeps the elements in sorted order
            // The first element will be the starting point of any group
            int start_pt = *Multiset.begin();
            // Remove this value after using it, and increase the starting point
            Multiset.erase(Multiset.find(start_pt++));
            // Now since we have already got one member of the group
            // We now need to check for groupSize - 1, members
            for (int i = 1; i < groupSize; i++)
                // If the next consecutive value is not available
                // return false
                if (Multiset.find(start_pt) == Multiset.end())
                    return false;
                // else erase the current member, and go to the next member
                else
                    Multiset.erase(Multiset.find(start_pt++));
        }
        return true;
    }
};
// Approach 2 : Using map
class Solution
{
public:
    bool isNStraightHand(std::vector<int> &hand, int groupSize)
    {
        int length = hand.size();
        // The task is only possible if the length of the array is a multiple of groupSize
        // Else the division into groups is not possible
        if (length % groupSize != 0)
            return false;
        // A map to store the frequency of each card, similar to TreeMap in Java
        map<int, int> cardCount;
        // Increase the frequency of each card
        for (int card : hand)
            cardCount[card]++;
        while (!cardCount.empty())
        {
            // Since map keeps the elements in sorted order
            // The first element will be the starting point of any group
            int startCard = cardCount.begin()->first;
            // Remove cards from the map to form a valid group
            for (int i = 0; i < groupSize; i++)
            {
                int currentCard = startCard + i;
                if (cardCount.find(currentCard) == cardCount.end())
                    return false;
                // Decrease the frequency of the current card
                cardCount[currentCard]--;
                if (cardCount[currentCard] == 0)
                    cardCount.erase(currentCard);
            }
        }
        // If all groups are formed successfully, return true
        return true;
    }
};