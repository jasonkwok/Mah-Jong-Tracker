#include <iostream>
#include <string>
#include <map>

using namespace std;

int main( int argc, char * argv[] )
{
  map<string, int> players;
  int points[11] = {2,4,8,16,32,48,64,96,128,256,512};

  string test = "8";
  cout << stoi(test);

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
    while (type_of_win == "") {
      cout << "Enter s for self-draw or d for discarder: ";
      getline(cin, type_of_win);
      if (type_of_win != "s" && type_of_win != "d") {
        type_of_win = "";
        cout << "Incorrect input, enter s or d" << endl;
      }
    }


    int fan = 0;
    string fan_input = "";
    while(fan_input == "") {
      try {
        cout << "Number of Fan (1-10): ";
        getline(cin, fan_input);
        fan = stoi(fan_input);
        if (fan < 1 || fan > 10) {
          fan_input = "";
          cout << "Incorrect input" << endl;
        }
      } catch (...) {
        fan_input = "";
        cout << "Incorrect input" << endl;
      }
    }

    if (type_of_win == "d") {

      string nine_card_penalty;
      while (nine_card_penalty == "") {
        cout << "9 card penalty (y/n)? ";
        getline(cin, nine_card_penalty);
        if (nine_card_penalty != "y" && nine_card_penalty != "n") {
          nine_card_penalty = "";
          cout << "Incorrect input, enter y or n" << endl;
        }
      }

      string discarder;
      while (players.count(discarder) == 0 || discarder == winner) {
        cout << "Enter discarder's name: ";
        getline(cin, discarder);
        if (players.count(discarder) == 0 || discarder == winner) {
          cout << "Incorrect input." << endl;
        }
      }
      players[winner] += points[fan]*2;
      if (nine_card_penalty == "y") {
        players[discarder] -= points[fan]*2;
      } else {
        std::map<std::string, int>::iterator it = players.begin();
        while (it != players.end()) {
      		std::string player = it->first;
          if (player != winner) {
            if (player == discarder) {
              players[player] -= points[fan];
            } else {
              players[player] -= points[fan]/2;
            }
          }
          it++;
      	}
      }
    } else {
      string tweleve_card_penalty;
      while (tweleve_card_penalty == "") {
        cout << "12 card penalty (y/n)? ";
        getline(cin, tweleve_card_penalty);
        if (tweleve_card_penalty != "y" && tweleve_card_penalty != "n") {
          tweleve_card_penalty = "";
          cout << "Incorrect input, enter y or n" << endl;
        }
      }

      if (tweleve_card_penalty == "y") {
        string discarder;
        while (players.count(discarder) == 0 || discarder == winner) {
          cout << "Enter discarder's name: ";
          getline(cin, discarder);
          if (players.count(discarder) == 0 || discarder == winner) {
            cout << "Incorrect input." << endl;
          }
        }
        players[discarder] -= points[fan] * 3;
        players[winner] += points[fan] * 3; 
      } else {
        std::map<std::string, int>::iterator it = players.begin();
        while (it != players.end()) {
      		std::string player = it->first;
          if (player != winner) {
            players[player] -= points[fan];
          }
          it++;
      	}
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
