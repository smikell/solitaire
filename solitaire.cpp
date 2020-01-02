// Solitaire for the Bored Programmer
//
// by Sam Mikell
//
// 19 December 2019 - Present

#include "xcode_redirect.hpp"
//#include <getopt.h>
#include "user.h"

//char read_command_line(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    xcode_redirect(argc, argv);
    std::ios_base::sync_with_stdio(false);
    //char mode = read_command_line(argc, argv);
    
    //print starting message, ? command should be for help
    
    //while game not over, accept user input and respond accordingly
    
    //moves: <char> OR <to> <from>
        // <char> is <D>
        // <to> can be <F> <Suit> OR <T> <Row> <Col>
        // <from> can be <H> OR <F> <Suit> OR <T> <Row> <Col>
    
    Card c;
    //while game not over
    while (c.is_turned()) {
        try {
            
            
        }
        catch(...) {
            
        }
    }
    
    User test;
    test.shuffle();
    test.deal();
    test.draw();
    //test.move_foundation('S', 'H');
    //test.move_foundation('S', 'T', {0, 1});
    
    //ERROR CHECK COMMAND INPUT IN MAIN
    
    /*
     C++ Solitaire: backend in C++ then figure out how to get that on the web so can play online. Have leaderboards for fastest overall time and personal best times. Also derive a point system and display high scores and personal high scores, gain certain number of points depending on Time Passed and Card Placed. Use SQL for the database behind the scenes rather than something like Firebase. Use Flask framework to get C++ backend through Python onto web app. Use HTML, CSS, or JS for Front end. React Front End! Follow style guidelines and tutorials from EECS 381 Website. Also when get to pushing it to Web, follow 485 Tutorials for HTML, CSS, JS, SQL, and More.
     - Game variation: include jokers, must be in deck, if draw a joker, then something happens (maybe can play it somewhere like a king, but can only last so long, maybe lose points for every round it’s on the board, maybe can use one as a wild card and the other as the negative points, maybe both can be wild cards for certain spots, but cards that are replaced are still needed, so will need to find a replacement location, maybe jokers take on the number that they are replaced with (and suit) and they must be treated as such going forward, and will still need to replace)
     - TWO VERSIONS: one just in C++ for individual use, one pretty shiny version online with a couple more features
     - Two modes: original + wild card (joker)
     - Have user input be int int, int where first represents card column second represents position in column, third represents where want to move card at position
     - Make use of try catch and exceptions when dealing with all sorts of error handling with invalid card moves?
     - Use basic shuffling from euchre project
     - Need to update table each time move cards around. Will be best for printing’s sake. Maybe store all cards in such? Use a 2D vector? Use a terminating card to represent when stop printing, OR store size of each column at top of column for reference when printing. Need to allocate proper size: think about what’s the maximum size of a column in solitaire? 13?
     - For shuffling look into xorshift128+ and also try doing a hash table method where create a hash function, load the cards into the hash table shuffler, then ranged-for through it to load in the table for randomization (will the result always be the same tho?)
    */
    
    return 0;
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
