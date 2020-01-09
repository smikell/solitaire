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

//EFFECTS: checks for cin failure and cleans up and throws exception if necessary
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
                std::cin >> in.to_col >> in.to_row;
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
                std::cin >> in.from_col >> in.from_row;
                check_cin();
                game.check_coords(in.from_row, in.from_col);
            }
            else {
                //no matching <FROM>, eat remaining line, throw invalid input error
                std::string junk;
                getline(std::cin, junk);
                throw InvalidInput("Invalid Input, no matching <FROM> move");
            }
            //eat remaining line
            std::string junk;
            getline(std::cin, junk);
            //call move
            game.move(in);
        }
        catch (const InputError& input) {
            std::cerr << input.error() << "\n";
            continue;
        }
        catch (const MoveError& move) {
            std::cerr << move.error() << "\n";
            continue;
        }
        catch (...) {
            std::cerr << "Caught unknown error\n";
            continue;
        }
    }
    //game.game_ending();
    
    return 0;
}

//EFFECTS: checks for cin failure and cleans up and throws exception if necessary
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
