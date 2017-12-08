//Program simulates a memory matching game that uses a deck of cards that have
//identical pairs.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std; 

const int ROW = 4;
const int COLUMN = 4;

void prepareDeck(char faceDownCards[][COLUMN], char faceUpCards[][COLUMN]);
//Initializes all element values of array faceDownCards and faceUpCards.

void displayCards(char faceDownCards[][COLUMN]);
//Precondition: All elements of the array faceDownCards has been 
//initialized. 
//Postcondition: Prints out the layout of cards that are either face up
//or face down.

void wait (int seconds); //Stalls the execution

bool gameFinished(char faceDownCards[][COLUMN]);
//Precondition: The array faceDown cards has been filled.
//Returns true if all elements of the array faceDownCards have
//an number character.

bool cardsMatch(char faceUpCards[][COLUMN], int c1, int c2, int c3, int c4);
//Precondition: All elements of the array faceUpCards has been initialized.
//c1, c2, c3, and c4 have been intialized.
//Postcondition: Returns true if two particular elements of array
//faceUpCards are equal and false if not.

void clearScreen(); //Clears console screen;

void shuffle(char faceUpCards[][COLUMN]);
//Precondition: All elements of array faceUpCards have been initialized.
//Postcondition: Randomly selects two elements of array faceUpCards, and swaps them.

void playerInput(int& c1, int& c2, int& c3, int& c4);
//Precondition: coordinate1 and coordinate 2 are >= 1 && <= 4.
//Postcondition: The values of coordinate1 and coordinate2 have been intialized.

void updateGame(char faceDownCards[][COLUMN], char faceUpCards[][COLUMN], int c1, int c2, int c3, int c4);
//Precondition: Both arrays faceDownCards and faceUpCards have been intialized. coordinate1 and coordinate2
//have both been initialized.
//Postcondition: Various elements of faceDownCards have been re-initialized.

void keepCardsFaceUp(char faceDownCards[][COLUMN], char faceUpCards[][COLUMN], int c1, int c2, int c3, int c4);
//Precondition: Both arrays faceDownCards and faceUpCards have been initialized. The
//variables c1, c2, c3, and c4 have been initialized.
//Postcondition: Initializes two particular elements of faceDownCards to a number
//character value.

void keepCardsFaceDown(char faceDownCards[][COLUMN], int c1, int c2, int c3, int c4);
//Precondition: Both arrays faceDownCards and faceUpCards have been initialized. The
//variables c1, c2, c3, and c4 have been initialized.
//Postcondition: Initializes two particular elements of faceDownCards to '*' character
//value.

int main()
{
    char faceDownCards[ROW][COLUMN], faceUpCards[ROW][COLUMN];
    int c1, c2, c3, c4;

    prepareDeck(faceDownCards, faceUpCards);
    displayCards(faceDownCards);

    do
    {
        playerInput(c1,c2,c3,c4);
        updateGame(faceDownCards, faceUpCards, c1, c2, c3, c4);
    }while(!(gameFinished(faceDownCards)));

    system("pause");
    return 0;
}

void prepareDeck(char faceDownCards[][COLUMN], char faceUpCards[][COLUMN])
{
    int count = 1;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
            faceDownCards[i][j] = '*';
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            faceUpCards[i][j] = count + 48;
            ++count;

            if (count == 9)
                count = 1;
        }
    }

    shuffle(faceUpCards);
}

void shuffle(char faceUpCards[][COLUMN])
{
    srand(time(NULL));

    for (int i = 1; i <= 48; i++)
    {
        int r1 = rand() % 4;
        int c1 = rand() % 4;
        int r2 = rand() % 4;
        int c2 = rand() % 4;

        char temp;

        temp = faceUpCards[r1][c1];
        faceUpCards[r1][c1] = faceUpCards[r2][c2];
        faceUpCards[r2][c2] = temp;
    }
}

void displayCards(char faceDownCards[][COLUMN])
{
    for (int i = 0; i < ROW; i++)
    {
        cout<<setw(39);

        for (int j = 0; j < COLUMN; j++)
            cout<<faceDownCards[i][j]<<setw(5);

        cout<<endl;
    }

    cout<<endl;
}

void playerInput(int& c1, int& c2, int& c3, int& c4)
{
    char a1, a2, a3, a4;
    cout<<"Select two cards (enter in coordinates): ";
    cin>>a1>>a2>>a3>>a4;
    c1 = a1 - 48, c2 = a2 - 48, c3 = a3 - 48, c4 = a4 - 48;
    cout<<endl;
}

void wait (int seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

void clearScreen()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void updateGame(char faceDownCards[][COLUMN], char faceUpCards[][COLUMN], int c1, int c2, int c3, int c4)
{
    if (cardsMatch(faceUpCards, c1, c2, c3, c4))
    {
        keepCardsFaceUp(faceDownCards, faceUpCards, c1, c2, c3, c4);
        displayCards(faceDownCards);
    }
    else
    {
        keepCardsFaceUp(faceDownCards, faceUpCards, c1, c2, c3, c4);
        displayCards(faceDownCards);
        wait(1);
        clearScreen();
        keepCardsFaceDown(faceDownCards, c1, c2, c3, c4);
        displayCards(faceDownCards);
    }
}

bool gameFinished(char faceDownCards[][COLUMN])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (faceDownCards[i][j] == '*')
                return false;
        }
    }

    return true;
}

bool cardsMatch(char faceUpCards[][COLUMN], int c1, int c2, int c3, int c4)
{
    return (faceUpCards[c1-1][c2-1] == faceUpCards[c3-1][c4-1]);
}

void keepCardsFaceUp(char faceDownCards[][COLUMN], char faceUpCards[][COLUMN], int c1, int c2, int c3, int c4)
{
    faceDownCards[c1-1][c2-1] = faceUpCards[c1-1][c2-1];
    faceDownCards[c3-1][c4-1] = faceUpCards[c3-1][c4-1];

}

void keepCardsFaceDown(char faceDownCards[][COLUMN], int c1, int c2, int c3, int c4)
{
    faceDownCards[c1-1][c2-1] = '*';
    faceDownCards[c3-1][c4-1] = '*';
}
