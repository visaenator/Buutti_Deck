#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <optional>

template <typename T>
class Deck{
    public:
        std::optional<T> top(){
            if(isEmpty()){
                std::cout << "The deck is empty." << std::endl;
                return std::nullopt;
            }
            return cards.back();
        }
        std::optional<T> bottom(){
            if(isEmpty()){
                std::cout << "The deck is empty." << std::endl;
                return std::nullopt;
            }
            return cards.front();
        }
        std::optional<T> draw(){
            if(isEmpty()){
                std::cout << "The deck is empty." << std::endl;
                return std::nullopt;
            }
            auto card = top();
            cards.pop_back();
            return card;
        }
        void add(T value){
            cards.push_back(value);
        }
        void shuffle(uint8_t style = 0){
            auto rng = std::default_random_engine {};
            bool cheat = false;
            std::cout << "Shuffling";
            switch(style){
                case 1:
                    rng = std::default_random_engine {time(0)};
                    break;
                case 2:
                    {
                    std::random_device rd;
                    std::mt19937_64 gen(rd());
                    std::shuffle(std::begin(cards), std::end(cards), gen);
                    std::cout << " vigorously";
                    break;
                    }
                case 3:
                    cheat = true;
                    rng = std::default_random_engine {time(0)};
                    std::cout << " ;) ";
                    break;
                default:
                    std::cout << " not so well";
            }
            std::cout << "..." << std::endl;
            std::shuffle(std::begin(cards), std::end(cards), rng);
            if(cheat){
                //Works only with the default deck... and only with poker... and only 1vs1... and the first card is dealt to opponent
                std::vector<std::string> aces{"H1", "S1", "C1", "D1"};
                uint8_t cheat_position = 50;
                for(auto &ace : aces){
                    auto it = std::find(cards.begin(), cards.end(), ace);
                    size_t original_pos = std::distance(cards.begin(), it);
                    if(!(original_pos == cheat_position)){
                        cards.erase(it);
                        cards.insert(cards.begin() + cheat_position, ace);
                    }
                    cheat_position = cheat_position - 2;
                }
                    
            }

        }
        bool isEmpty(){
            return cards.empty();
        }
    private:
        //Vector back is the top of the deck and front the bottom 
        std::vector<T> cards;
};