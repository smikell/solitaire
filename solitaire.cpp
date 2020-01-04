// Solitaire for the Bored Programmer
//
// by Sam Mikell
//
// 19 December 2019 - Present

#include "xcode_redirect.hpp"
//#include <getopt.h>
#include "user.h"

//TODO: ADD RMEs TO ALL FUNCTIONS AS DOCUMENTATION
//TODO: in successful move messages, add which card specifically moved (and from where) and to where it moved

//char read_command_line(int argc, char* argv[]);

//check cin status after each input read
void check_cin();

int main(int argc, char* argv[]) {
    xcode_redirect(argc, argv);
    std::ios_base::sync_with_stdio(false);
    
    //start game, shuffle, and deal
    User game;
    game.shuffle();
    game.deal();
    //accept input from user while game continues
    while (!game.is_game_over()) {
        //print prompt to accept input
        std::cout << "% ";
        //user input object
        UserInput in;
        //read first character of user input <TO> char
        std::cin >> in.to;
        try {
            check_cin();
            if (toupper(in.to) == 'D') {
                //eat remaining line
                std::string junk;
                getline(std::cin, junk);
                //draw card from hand
                game.draw();
                continue;
            }
            else if (toupper(in.to) == 'F') {
                //read following suit and error check
                std::cin >> in.to_suit;
                check_cin();
                game.check_suit(in.to_suit);
            }
            else if (toupper(in.to) == 'T') {
                //read following coords and error check
                std::cin >> in.to_row >> in.to_col;
                check_cin();
                game.check_coords(in.to_row, in.to_col);
            }
            else if (toupper(in.to) == '?') {
                //reprint move options
                game.help_message();
                continue;
            }
            else if (toupper(in.to) == 'Q') {
                //quit game
                break;
            }
            else {
                //no matching <TO>, eat remaining line, throw invalid input error
                std::string junk;
                getline(std::cin, junk);
                throw InvalidInput("Invalid Input, no matching <TO> move");
            }
            std::cout << "to success\n";
            //read <FROM> char
            std::cin >> in.from;
            check_cin();
            if (toupper(in.from) == 'H') {
                //nothing to do here
            }
            else if (toupper(in.from) == 'F') {
                //read following suit and error check
                std::cin >> in.from_suit;
                check_cin();
                game.check_suit(in.from_suit);
            }
            else if (toupper(in.from) == 'T') {
                //read following coords and error check
                std::cin >> in.from_row >> in.from_col;
                check_cin();
                game.check_coords(in.from_row, in.from_col);
            }
            else {
                //no matching <FROM>, eat remaining line, throw invalid input error
                std::string junk;
                getline(std::cin, junk);
                throw InvalidInput("Invalid Input, no matching <FROM> move");
            }
            std::cout << "from success\n";
            //eat remaining line
            std::string junk;
            getline(std::cin, junk);
            //call move
            game.move(in);
        }
        catch (const InputError& input) {
            std::cout << input.error() << "\n";
            continue;
        }
        catch (const MoveError& move) {
            std::cout << move.error() << "\n";
            continue;
        }
        catch (...) {
            std::cout << "Caught unknown error\n";
            continue;
        }
    }
    game.game_ending();
    
    return 0;
}

//check cin status after each input read
void check_cin() {
    //if cin in fail state
    if (std::cin.fail()) {
        //fix cin and remove junk
        std::cin.clear();
        std::string junk;
        getline(std::cin, junk);
        //throw exception to handle error
        throw BadInput("Bad Input caused cin failure");
    }
}

    /*
     C++ Solitaire: backend in C++ then figure out how to get that on the web so can play online. Have leaderboards for fastest overall time and personal best times. Also derive a point system and display high scores and personal high scores, gain certain number of points depending on Time Passed and Card Placed. Use SQL for the database behind the scenes rather than something like Firebase. Use Flask framework to get C++ backend through Python onto web app. Use HTML, CSS, or JS for Front end. React Front End! Follow style guidelines and tutorials from EECS 381 Website. Also when get to pushing it to Web, follow 485 Tutorials for HTML, CSS, JS, SQL, and More.
     - Game variation: include jokers, must be in deck, if draw a joker, then something happens (maybe can play it somewhere like a king, but can only last so long, maybe lose points for every round it’s on the board, maybe can use one as a wild card and the other as the negative points, maybe both can be wild cards for certain spots, but cards that are replaced are still needed, so will need to find a replacement location, maybe jokers take on the number that they are replaced with (and suit) and they must be treated as such going forward, and will still need to replace)
     - TWO VERSIONS: one just in C++ for individual use, one pretty shiny version online with a couple more features
     - Two modes: original + wild card (joker)
     - Have user input be int int, int where first represents card column second represents position in column, third represents where want to move card at position
     - Make use of try catch and exceptions when dealing with all sorts of error handling with invalid card moves?
     - Use basic shuffling from euchre project
     - Need to update table each time move cards around. Will be best for printing’s sake. Maybe store all cards in such? Use a 2D vector? Use a terminating card to represent when stop printing, OR store size of each column at top of column for reference when printing. Need to allocate proper size: think about what’s the maximum size of a column in solitaire? 13?
    */

/*
char read_command_line(int argc, char* argv[]) {
    char mode = '\0';
    
    int opt_index = 0, opt = 0;
    
    //this implementation will handle invalid arguments instead
    opterr = false;
    
    //list of options to find in the command line
    struct option long_opts[] = {
        { "help", no_argument, nullptr, 'h' },
        { "user", no_argument, nullptr, 'u' },
        { nullptr, 0, nullptr, '\0' }
    };
    
    //parse arguments from command line
    while((opt = getopt_long(argc, argv, "hu", long_opts, &opt_index)) != -1) {
        switch(opt) {
            case 'h':
                std::cout << "Help Message: " << std::endl;
                exit(0);
                break;
            case 'u':
                mode = 'u';
                break;
            default:
                std::cerr << "Error: invalid flag" << std::endl;
                exit(1);
                break;
        } //switch
    } //while
    
    return mode;
} //read_command_line
*/


//secret easter egg function for rare scenario where a King ends up at bottom of 7th column and stack cards all the way down to bottom: maybe hide a gift card or something (must pull from something online or something, like an API call because otherwise would be revealed in the code)
