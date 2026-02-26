// ROCK PAPER SCISSORS GAME
// Created by: Gabriel Starfire
// simple rock paper scissors game to practice switches, if statements, loops, etc..

#include <iostream>
#include <ctime>
using namespace std;
void welcomeIn();
string getName();
void displayMenu();
char userChoice();
char compChoice();
bool displayUI(char choice, int win_count, int loss_count);
char displayCI();
void chooseWinner(char choice, char comp_choice, string name, int& win_count, int& loss_count);
int playAgain();
double winlossRatio(int win_count, int loss_count);

int main() {
    cout << endl;
    int win_count = 0;
    int loss_count = 0;

    welcomeIn();
    string name = getName();

    while (true) {   // entire game loop

        char choice;

        // ---- Input Validation Loop ----
        do {
            displayMenu();
            choice = userChoice();

            if (choice != 'r' && choice != 'p' && choice != 's' && choice != 'v') {
                cout << "Invalid input, please enter 'r', 'p', 's', or 'v'.\n\n";
            }

        } while (choice != 'r' && choice != 'p' && choice != 's' && choice != 'v');

        // If user just wants to view ratio, skip round
        if (choice == 'v') {
            displayUI(choice, win_count, loss_count);
            continue;
        }

        displayUI(choice, win_count, loss_count);

        char comp_choice = displayCI();

        chooseWinner(choice, comp_choice, name, win_count, loss_count);

        // ---- Play Again Logic ----
        int play;

        do {
            play = playAgain();
        } while (play == 3);

        if (play == 2) {
            cout << "Thanks for playing!\n";
            cout << "\n--------------------------------------PROGRAM TERMINATED--------------------------------------\n\n";
            break;   // exit while(true)
        } else if (play == 1) {
            continue;
        }

        
    }

    return 0;
}

void welcomeIn() {
    cout << "Welcome to Rock Paper Scissors PvE. You will be facing our top RPS AI: Erik.\n";
    cout << "PS: Erik happens to be a giant, so he has REALLY big hands :D.\n";
    cout << '\n';
}
string getName() {
    cout << "Please enter your username: ";
    string username;
    getline(cin,username);
    cout << "Welcome " << username << "!\n";
    return username;
}

void displayMenu() {
    cout << "---------------------------------------------MENU---------------------------------------------\n" << endl;
    cout << "'r' = Rock\n";
    cout << "'p' = Paper\n";
    cout << "'s' = Scissors\n" << endl;
    cout << "'v' = view win/loss ratio\n" << endl;
    cout <<  "Please enter your choice: ";
}


char userChoice() {
    char user_input;
    cin >> user_input;
    cout << '\n';
    return user_input;
}

char compChoice(){
    srand(time(NULL)); // seed the random number generator with the current time
    int choice = rand() % 3 + 1; // generate a random number between 1 and 3
    switch (choice) {
        case 1:
            return 'r';
            break;
        case 2:
            return 'p';
            break;
        case 3:
            return 's';
            break;
        default:
            return 'L';
            break;        
    }
}

bool displayUI(char choice, int win_count, int loss_count) {
    cout << "You selected...........";
    switch (choice) {
        case 'r':
            cout << "ROCK!\n";
            cout << endl;
            cout << "    _______\n";
            cout << "---'   ____)\n";
            cout << "      (_____)\n";
            cout << "      (_____)\n";
            cout << "      (____)\n";
            cout << "---.__(___)\n";
            cout << endl;
            return true;
            break;
        case 'p':
            cout << "PAPER!\n";
            cout << endl;
            cout << "    _______\n";
            cout << "---'   ____)____\n";
            cout << "          ______)\n";
            cout << "          _______)\n";
            cout << "         _______)\n";
            cout << "---.__________)\n";
            cout << endl;
            return true;
            break;
        case 's':
            cout << "SCISSORS!\n";
            cout << endl;
            cout << "    _______\n";
            cout << "---'   ____)____\n";
            cout << "          ______)\n";
            cout << "          _______)\n";
            cout << "      (____)\n";
            cout << "---.__(___)\n";
            cout << endl;
            return true;
            break;
        case 'v': {
            cout << "statistics!\n";
            double ratio = winlossRatio(win_count, loss_count);
            cout << "You win " << ratio << "% of your games.\n";

            if (ratio > 50) {
                cout << "That's pretty good!\n";
            } else if (ratio < 50) {
                cout << "You can do better than that...\n";
            }
            return true;
        }
        default:
            cout << "bruh.\n";
            return false;
    }
}
char displayCI() {
    cout << "Erik chose...........";
    switch(compChoice()) {
        case 'r':
            cout << "ROCK!\n";
            cout << endl;
            cout << "                         -##**=                                          \n";
            cout << "                    *@@%%%%=*%#*##+=                                     \n";
            cout << "                 :%@@@-           +#=%#                                  \n";
            cout << "                @%@#                 #%%%*                               \n";
            cout << "    .%@@@@@@@@@%@@:                     %@%#                             \n";
            cout << "  %@@@%#+======%@@           =+           %%@%                           \n";
            cout << " #@%           -@@           @@-            *@@@                         \n";
            cout << " @@=           -@%           ++               *@@%                       \n";
            cout << " @@#           -@@           *+                 +@%@@@@@@@@@@@@@@@@@@@@@ \n";
            cout << "  @@%          =@@           @@:                                     .%% \n";
            cout << "  *%%%%@@@@@@@@@@@           ++.                                      @@ \n";
            cout << " @@@%#.        *@@           ***=                                     @@ \n";
            cout << "@@@            :@@           %%@@=                                    @@ \n";
            cout << "%@-            :@@           +----:                                   @@ \n";
            cout << "@@#            :@@           ++  +**:         #@%@                    @@ \n";
            cout << ".@%#           .@@+        %%@.    *@@@%@@@@@@%%.                     @@ \n";
            cout << "  #@@@@@@%%%@@@@%%%%#=-=#@@%%          @@@@%#                         @@ \n";
            cout << "   %%@#======-===+%@%%%@%*.                                           @@ \n";
            cout << "  @@#               @@@                                               @@ \n";
            cout << "  @%                @@@                                               @@ \n";
            cout << "  @@                @@@                                               @@ \n";
            cout << "  %@@-             %@@                                                @@ \n";
            cout << "   -%@@@@@@@@@@@%@@@@                                                 @@ \n";
            cout << "    -@@@*:        +@@%                          -@%@@@@@@%%%%%%%@@@@@@@@ \n";
            cout << "    @%=             @@%                        %@@*...                   \n";
            cout << "    @@.             @%%                      %@@#                        \n";
            cout << "    %@%             .:=                   %@%%*                          \n";
            cout << "     *@@@@@@%%@%:=#++*#:+@@@@%@%%@@%@@@@@@@%                             \n" << endl;
            return 'r';
            break;
        case 'p':
            cout << "PAPER!\n";
            cout << endl;
            cout << "                                                                                                    \n";
            cout << "                                                 *%%%                                               \n";
            cout << "                                              +%%%%%@@%                                             \n";
            cout << "                                             %@%     %@@%                                           \n";
            cout << "                                            %@%        *@%%                                         \n";
            cout << "                                           #@@=          %%%#                                       \n";
            cout << "                                           @%@=            @@%%                                     \n";
            cout << "                                            @@@              @@@.                                   \n";
            cout << "                                             @@%              :@@#                                  \n";
            cout << "            :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%@@@@@              #@@%                                \n";
            cout << "         -@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*              #%%%                              \n";
            cout << "        #@@                                       @%%*              %@%+                            \n";
            cout << "        @@.                                         #@@               @@@*                          \n";
            cout << "        @@.                                          +@@@               @@@@@@@@@@%%%%@@@@@@@@%+    \n";
            cout << "        @@%                                           %@@.               :@@@@@@@@@@@@@@@@@@@@@@    \n";
            cout << "         #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#             @@@                                    @@%    \n";
            cout << "       .%@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@                                    %@@    \n";
            cout << "     =@@@+                                            %@@                                    %@@    \n";
            cout << "     @@:                                               %%#                                   %%@    \n";
            cout << "     @@                                                 %@@-                                 %%@    \n";
            cout << "     %@#                                                 =@@@@      -%%@                     %%@    \n";
            cout << "      @@@%#.                                                %@@%@@@@@@=                      %%@    \n";
            cout << "        +%%@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@                                                    %@@    \n";
            cout << "          %@@+                                                                               %@@    \n";
            cout << "         -@@                                                                                 %%@    \n";
            cout << "         +@%                                                                                 %@@    \n";
            cout << "         -%%                                                                                 %%@    \n";
            cout << "          #@@%-                                                                              @@@    \n";
            cout << "            *%%%%%%@@@@@@%%%%%@@@@@@@@@@#                                -###*****####%@@@@@@@@@    \n";
            cout << "                   @@*                                                  @%%%%%@@@@@@@@@@@@@@@@@*    \n";
            cout << "                   @%                                                -@@@@                          \n";
            cout << "                   @%                                             -%%@@=                            \n";
            cout << "                   =@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+                               \n";
            cout << "                      *%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=                                   \n";
            cout << "                                                                                                    \n";
            cout << endl;
            return 'p';
            break;
        case 's':
            cout << "SCISSORS!\n";
            cout << endl;
            cout << "                                                                                                \n";
            cout << "                                                    ==                                          \n";
            cout << "                                              #%@@@@@@@@@@@=                                    \n";
            cout << "            =#%@%#+-:                     :@@@%%:        =@@@@+                                 \n";
            cout << "          @%@%###%@@@@@%@@%@%@*          %@@-                %@@%                               \n";
            cout << "         #@#             .+#%%@@@@%@@@@#@@@                    #@%@-                            \n";
            cout << "         @@                        -#%%@@@@          *@%         =%@@#                          \n";
            cout << "         @@                             @@@          %@@            %%@+                        \n";
            cout << "         +@@#                           %@@          %@%              %@@%                      \n";
            cout << "           #@@@@@%%@%@#                 %@@          #%%                #@@@@@@@@@@@@@@@@@@@@@@%#   \n";
            cout << "                 =#%@@@%%@@@@@%%+       @@@          #@@                                     :@@@   \n";
            cout << "           =*#***##*#%@@@%%@@%@%@%@%@%@@@@@          @%%                                      @@@   \n";
            cout << "       %@@@@@%%%%@@%@@%%%%%%%%%%%%%%%@%@@%%          @@%                                      @@@   \n";
            cout << "      %@@                               @@%          @@@@                                     @@@   \n";
            cout << "     %%*                                @@%          @@@@@                                    @@@   \n";
            cout << "     @%-                                @@%         *@% %%@@           %#                     @@%   \n";
            cout << "     %@*                                @@%        #@@    @@@%+=--=*@%@@%                     @@%   \n";
            cout << "      @@@%=:-------=+*####%%%%##%%%%%%%%@@%%*    %@@@       =@%%%%%%%-                        @@%   \n";
            cout << "       +%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@%                                           @@@   \n";
            cout << "                          *@@@             @@@#                                               @@@   \n";
            cout << "                          #@#               #@%                                               @@@   \n";
            cout << "                          #@%               %@@                                               @@@   \n";
            cout << "                           %%@             @@@#                                               @@@   \n";
            cout << "                            %@@@@@%%%%%%@@@@%                                                 @@@   \n";
            cout << "                             %@@+         +%%%                           %%@@%%@@@%%%@@@@@@@%%@@@   \n";
            cout << "                             @@             %@%                         %@@%%%%%%@@@@@@@@@@@@@@%    \n";
            cout << "                             @@             @@%                       %@@%                           \n";
            cout << "                             @@*           *@%@                   -%%@@*                             \n";
            cout << "                              @@@@@@@@@@@%@@%%%@@@@@@@@@@@@@@@@@@%%%*                                \n";
            cout << "                                 @@@@%%%@%@@@@@%#*+=-::::.                                          \n";
            return 's';
            break;
        default:
            return 'r'; // fallback, should never happen, but compiler demandsa default case in case anything other than r p or s is inputted.
    }
}

void chooseWinner(char choice, char comp_choice, string name, int& win_count, int& loss_count) {
    // Player wins
    if ((choice == 'r' && comp_choice == 's') ||
        (choice == 'p' && comp_choice == 'r') ||
        (choice == 's' && comp_choice == 'p')) {
        
        win_count++;
        cout << name << " is the winner!\n";
    }

    // Computer wins
    else if ((comp_choice == 'r' && choice == 's') ||
             (comp_choice == 'p' && choice == 'r') ||
             (comp_choice == 's' && choice == 'p')) {

        loss_count++;
        cout << "Erik is the winner!\n";
    }

    // Tie
    else {
        cout << "It's a tie!\n";
    }
}




int playAgain() {
        cout << "Would you like to play again? (Y/N): ";
        char answer;
        cin >> answer;
        if (answer == 'Y') {
            return 1;
        } else if (answer == 'N') {
            return 2;
        } else {
            cout << "Not a valid input, please enter either Y for yes or N for no.\n" << endl;
            return 3;
        }
}

double winlossRatio(int win_count, int loss_count) {
    cout << endl;
    cout << "You have won " << win_count << " games.\n";
    cout << "You have lost " << loss_count << " games.\n";

    int total_games = win_count + loss_count;

    if (total_games == 0) {
        return 0.0;
    }

    return (static_cast<double>(win_count) / total_games) * 100.0;
}
