#include <iostream>
#include <string>
#include <map>
using namespace std;

int main( int argc, char * argv[] )
{
  map<string, int> players;
  int points[10] = {2,4,8,16,32,48,64,96,128,256};

  string p1;
  cout << "Enter player 1 name: ";
  getline(cin, p1);
  players[p1] = 0;

  string p2;
  cout << "Enter player 2 name: ";
  getline(cin, p2);
  players[p2] = 0;

  string p3;
  cout << "Enter player 3 name: ";
  getline(cin, p3);
  players[p3] = 0;

  string p4;
  cout << "Enter player 4 name: ";
  getline(cin, p4);
  players[p4] = 0;

  int game_num = 1;
  bool countinue_game = true;
  while (countinue_game) {
    cout << "Game number: " << game_num << endl;

    string winner;
    while (players.count(winner) == 0) {
      cout << "Enter winner's name: ";
      getline(cin, winner);
    }

    string type_of_win;
    cout << "Enter s for self-draw or d for discarder: ";
    getline(cin, type_of_win);

    string fan;
    cout << "Number of Fan (1-10): ";
    getline(cin, fan);

    if (type_of_win == "d") {

      string nine_card_penalty;
      cout << "Was 9-cards shown (y/n)? ";
      getline(cin, nine_card_penalty);

      string discarder;
      while (players.count(discarder) == 0) {
        cout << "Enter discarder's name: ";
        getline(cin, discarder);
      }

      players[winner] += points[stoi(fan)]*2;
      if (nine_card_penalty == "y") {
        players[discarder] -= points[stoi(fan)]*2;
      } else {
        std::map<std::string, int>::iterator it = players.begin();
        while (it != players.end()) {
      		std::string player = it->first;
          if (player != winner) {
            if (player == discarder) {
              players[player] -= points[stoi(fan)];
            } else {
              players[player] -= points[stoi(fan)]/2;
            }
          }
          it++;
      	}
      }
    } else {
      players[winner] += points[stoi(fan)] * 3;
      std::map<std::string, int>::iterator it = players.begin();
      while (it != players.end()) {
    		std::string player = it->first;
        if (player != winner) {
          players[player] -= points[stoi(fan)];
        }
        it++;
    	}
    }

    std::map<std::string, int>::iterator it = players.begin();
    while (it != players.end()) {
  		std::string word = it->first;
  		int count = it->second;
  		std::cout << word << ": " << count << std::endl;
  		it++;
  	}

    string finished_game;
    cout << "Finished Game (y/n): ";
    getline(cin, finished_game);

    if (finished_game == "y") {
      countinue_game = false;
    } else {
      game_num++;
    }
  }

  return 0;
}
