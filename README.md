# Memory Matching Game
A program that simulates a memory matching game that uses a deck of cards that have identical pairs.

### Synopsis
A deck of 16 cards contains identical pairs. The cards are shuffled and placed face down on the table.

The player then selects two cards that are face down, turns them faceup, and if they match they are left faceup.

If the two cards do not match, they are returned to their original positino facedown.

The game continues in this fashion until all cards are faceup.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/memory-matching-game.git
   ```
    or [download as ZIP](https://github.com/cramaechi/memory-matching-game/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd memory-matching-game
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./memory_matching
```

Sample Output:
```
Select two cards (enter in coordinates): 12 14                                                                        
                                                                                                                      
                                      *    3    *    3                                                                
                                      *    *    *    *                                                                
                                      *    *    *    *                                                                
                                      *    *    *    *
                                      
Select two cards (enter in coordinates): 11 33                                                                        
                                                                                                                      
                                      5    3    *    3                                                                
                                      *    *    *    *                                                                
                                      *    *    5    *                                                                
                                      *    *    *    *
                       
...
```
