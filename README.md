# Solitaire for the Bored Programmer
by Sam Mikell | [19 December 2019, Present]

My first project beyond the scope of school projects with specifications and guidance.

Solitaire is a game I first discovered on an iPod Nano when I was nine years old, and the game has stuck with me for years since.
As such, this project is focused on implementing Solitaire to be playable within Terminal or other Unix-based Shells. Below describes how to play my version and other details about this project.

## Quick start

```console
$ make solitaire.exe
$ ./solitaire.exe
```

## The Game

Another name for this game is Patience, and this implementation of the game certainly requires it.

It's classic Solitaire, but since input is meant for Shells, it's more detailed and restricted compared to a click-and-drag version. The instructions are printed at the start of the game, which explains valid moves, but the input style causes the game to take much longer. A typical Solitaire game may take roughly 5-7 minutes, whereas this version (in the beginning) takes roughly 15-18 minutes. After playing a couple times, a complete game can be as fast as 10 minutes, but it most likely averages 12-14 minutes. This sounds rather tedious, so if any users have better ideas for getting input, please suggest them!

In the future, I plan to periodically add features to this game. Some ideas include an alternate version of the game that includes Jokers and potentially attempting to implement a web or application version that is similar to existing implementations.

Additionally, I'd love to hear from anyone who plays the game and has recommendations for input style, output style, game features, or anything else!
