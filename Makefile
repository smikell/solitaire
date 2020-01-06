## Solitaire for the Bored Programmer | Makefile

# compiler of choice
CXX = g++

# compiler flags of choice (do more research on these)
CXXFLAGS = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic -O3

# make release will compile program (do more research on this)
solitaire.exe: solitaire.cpp user.h game.h card.h
	$(CXX) $(CXXFLAGS) solitaire.cpp user.cpp game.cpp card.cpp -o $@

# clean up files
clean :
	rm -vrf *.exe *.gch *.dSYM *.stackdump *.out *.o
