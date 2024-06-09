// Approach 1 : No queue, just pointers
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end()); // Sort the deck in increasing order
        int n = deck.size();            // Number of cards in the deck
        int revealedIndex = 0;          // Index for the revealed deck
        int flipToggle = 1;             // Flip toggle to determine revealing pattern
        int currentIndex = 0;           // Index to iterate through the revealed deck
        vector<int> revealedDeck(n, 0); // Store the revealed deck
        while (revealedIndex < n)
        {
            // If the current position in the revealed deck is not revealed yet
            if (revealedDeck[currentIndex] == 0)
            {
                // If it's time to reveal a card
                if (flipToggle)
                    revealedDeck[currentIndex] = deck[revealedIndex++];
                // Toggle the revealing pattern
                flipToggle = (flipToggle + 1) % 2;
            }
            // Move to the next position in the revealed deck
            currentIndex = (currentIndex + 1) % n;
        }
        return revealedDeck;
    }
};

// Approach 2 : Queue Simulation
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end()); // Sort the deck in increasing order
        int n = deck.size();            // Number of cards
        vector<int> revealedDeck(n);    // Store the revealed deck
        queue<int> remainingIndices;    // Store indices of cards to be revealed
        // Initialize remainingIndices queue with 0, 1, 2, ..., n-1
        for (int i = 0; i < n; ++i)
            remainingIndices.push(i);
        // Reveal the cards in increasing order
        for (int card : deck)
        {
            int nextIndex = remainingIndices.front(); // Get the index of the next card to be revealed
            remainingIndices.pop();                   // Remove the index from the queue
            revealedDeck[nextIndex] = card;           // Set the card at the index
            if (!remainingIndices.empty())
            {                                            // If there are more cards to reveal
                int newIndex = remainingIndices.front(); // Get the index of the next card
                remainingIndices.pop();                  // Remove the index from the queue
                remainingIndices.push(newIndex);         // Move the index to the back of the queue
            }
        }
        return revealedDeck;
    }
};
