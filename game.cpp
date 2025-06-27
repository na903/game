#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

class RiverGame {
    std::vector<std::string> leftBank = {"M1", "M2", "M3", "A1", "A2", "A3"};
    std::vector<std::string> rightBank;
    std::vector<std::string> boat;
    std::string boatPosition = "left";
    bool gameOver = false;

    void displayState() {
        std::cout << "\nLeft Bank: ";
        for (auto& c : leftBank) std::cout << c << " ";
        
        std::cout << "\nBoat (" << boatPosition << "): ";
        for (auto& c : boat) std::cout << c << " ";
        
        std::cout << "\nRight Bank: ";
        for (auto& c : rightBank) std::cout << c << " ";
        std::cout << "\n";
    }

    bool checkDanger(std::vector<std::string>& bank) {
        int men = 0, animals = 0;
        for (auto& c : bank) {
            if (c[0] == 'M') men++;
            else if (c[0] == 'A') animals++;
        }
        return (animals > men) && (men > 0);
    }

    void checkGameState() {
        if (checkDanger(leftBank) || checkDanger(rightBank)) {
            std::cout << "Animals outnumber men! Game Over!\n";
            gameOver = true;
        }
        else if (rightBank.size() == 6) {
            std::cout << "All characters crossed safely! You Win!\n";
            gameOver = true;
        }
    }

    void moveCharacter(std::vector<std::string>& source, std::vector<std::string>& destination, const std::string& charName) {
        auto it = std::find(source.begin(), source.end(), charName);
        if (it != source.end()) {
            destination.push_back(charName);
            source.erase(it);
        }
    }

public:
    void play() {
        std::cout << "River Crossing Game\n";
        std::cout << "Commands: load [char], unload [char], move, exit\n";

        while (!gameOver) {
            displayState();
            std::cout << "> ";
            std::string command;
            std::cin >> command;

            if (command == "exit") break;

            if (command == "load") {
                std::string character;
                std::cin >> character;
                std::transform(character.begin(), character.end(), character.begin(), ::toupper);

                if (boat.size() < 2) {
                    if (boatPosition == "left") moveCharacter(leftBank, boat, character);
                    else moveCharacter(rightBank, boat, character);
                }
                else std::cout << "Boat full!\n";
            }
            else if (command == "unload") {
                std::string character;
                std::cin >> character;
                std::transform(character.begin(), character.end(), character.begin(), ::toupper);

                auto it = std::find(boat.begin(), boat.end(), character);
                if (it != boat.end()) {
                    if (boatPosition == "left") leftBank.push_back(character);
                    else rightBank.push_back(character);
                    boat.erase(it);
                }
                else std::cout << "Character not in boat!\n";
            }
            else if (command == "move") {
                if (boat.empty()) {
                    std::cout << "Boat needs at least one character to move!\n";
                    continue;
                }
                boatPosition = (boatPosition == "left") ? "right" : "left";
                std::cout << "Boat moved to " << boatPosition << " bank\n";
                checkGameState();
            }
            else if (rightBank.size() == 6) {
    std::cout << "All characters crossed safely! You Win!\n";
    gameOver = true;
}

            else std::cout << "Invalid command!\n";
        }
    }
};

int main() {
    RiverGame game;
    game.play();
    return 0;
}
