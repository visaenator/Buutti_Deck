#include "deck.h"
#include <string>

int main()
{
    Deck<std::string> deck;
    std::vector<std::string> suits{"H", "S", "C", "D"};
    for(auto &suit : suits){
        for(int x = 1; x <= 13; ++x){
            std::string card = suit + std::to_string(x);
            deck.add(card);
        }
    }

    int shuffle_style = 0;
    std::cout << "How do you want to shuffle the deck?" << std::endl;
    std::cout << "0: Not so well (default)" << std::endl;
    std::cout << "1: Normal" << std::endl;
    std::cout << "2: Better" << std::endl;
    std::cout << "3: CHEAT! I don't have morals!" << std::endl;
    std::cin >> shuffle_style;
    std::cout << shuffle_style << std::endl;
    deck.shuffle(shuffle_style);
    while(1){
        auto card = deck.draw();
        if(!card.has_value()){
            break;
        }
        std::cout << card.value() << " ";
    }
    std::cout << std::endl;
    return 0;
}