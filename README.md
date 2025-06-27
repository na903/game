

# River Crossing Game

A classic logic puzzle implemented in C++. Help 3 men and 3 animals cross a river safely using a boat that can carry up to two characters at a time. Beware: if animals ever outnumber men on either bank, the men get eaten and you lose!

## Game Rules

- **Characters:** 3 men (M1, M2, M3) and 3 animals (A1, A2, A3).
- **Boat Capacity:** 1 or 2 characters per trip.
- **Boat Movement:** The boat can travel back and forth between banks.
- **Danger Rule:** If, on either bank, animals outnumber men (and at least one man is present), you lose.
- **Goal:** Get all characters safely to the right bank.

## How to Play

1. **Start the Game:**  
   Compile and run the program (see below).

2. **Commands:**
   - `load [CHAR]` — Load a character (e.g., `load M1`) onto the boat from the current bank.
   - `unload [CHAR]` — Unload a character (e.g., `unload A1`) from the boat onto the current bank.
   - `move` — Move the boat to the opposite bank (must have at least one character in the boat).
   - `exit` — Quit the game.

3. **Win Condition:**  
   All characters are on the right bank.

4. **Lose Condition:**  
   Animals outnumber men on any bank with at least one man present.

## Example Play

```text
Left Bank: M1 M2 M3 A1 A2 A3 
Boat (left): 
Right Bank: 

> load M1
> load A1
> move
Boat moved to right bank

Left Bank: M2 M3 A2 A3 
Boat (right): M1 A1 
Right Bank: 

> unload M1
> unload A1
...
```

Continue until you win or lose!

## Compilation & Running

1. **Compile:**
    ```sh
    g++ -std=c++17 river_game.cpp -o river_game
    ```

2. **Run:**
    ```sh
    ./river_game
    ```

## Tips

- Only load characters from the same bank as the boat.
- The boat must have at least one character to move.
- Plan moves carefully to avoid losing!
