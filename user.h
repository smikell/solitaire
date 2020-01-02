//
//  user.h
//  solitaire
//
//  Created by Sam Mikell on 12/28/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#ifndef user_h
#define user_h

#include "game.h"
#include <utility>

class User : public Game {
public:
    User() : Game() {}
    
    //draw card from hand
    void draw() override;
    //move card to foundation
    //dest is destination suit
    //move is tableau or hand
    //optional pair of coordinates
    void move_foundation(char dest, char move,
                         std::pair<size_t, size_t> move_coords={0,0});
    //move card to or within tableau
    //move is tableau or hand
    //optional pair of coordinates
    void move_tableau(char dest, std::pair<size_t, size_t> dest_coords,
                      char move, std::pair<size_t, size_t> move_coords={0,0});
    
    
    
    //move card from hand to foundation
    void move_hand_to_foundation(char suit) override;
    //move card from hand to tableau
    void move_hand_to_tableau() override;
    //move card from tableau to foundation
    void move_tableau_to_foundation() override;
    //move card from foundation to tableau
    void move_foundation_to_tableau() override;
    //move card within tableau columns
    void move_in_tableau() override;
    
private:
    
    //when move multiple cards, loop through from that row to bottom (if statement to check if up, then move below other)
};

#endif /* user_h */
