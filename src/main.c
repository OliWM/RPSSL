// main.c
// Small programme to play RPSSL against the computer, first to 5 wins

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const char *SHAPE_STRINGS[] = {"🖖", "✂️", "️🗒️", "🪨", "🦎"};
int playerScore;
int computerScore;

int main() {
  int userInput;
  puts("Welcome to 🪨  ✂️  🗒️  🖖  🦎 !");
  while (true) {
    sleep(5 / 10);
    puts("Please choose an option: \nFor single player press "
         "s"
         "\nTo exit the game press "
         "e"
         "");
    userInput = getchar();
    if (userInput == 's') {
      getchar();
      puts("Starting game 🎉\n");
      while (playerScore < 5 && computerScore < 5) {
        puts("Select a shape:\n0🖖  || 1✂️  || 2🗒️  || 3🪨  || "
             "🦎4 or select 9 to exit.");
        char playerChoice[MAX_INPUT];
        fgets(playerChoice, sizeof(playerChoice), stdin);
        int choiceAsInt;

        if (sscanf(playerChoice, "%d", &choiceAsInt),
            choiceAsInt == 0 || choiceAsInt == 1 || choiceAsInt == 2 ||
                choiceAsInt == 3 || choiceAsInt == 4) {
          srand(time(NULL));
          int computerChoice = rand() % 5;

          printf("Player chose %s, ", SHAPE_STRINGS[choiceAsInt]);
          printf("Computer chose %s\n\n", SHAPE_STRINGS[computerChoice]);

          // could probably use modulo to make it smarter if
          // handling minus case.. Maybe add to base first
          if (choiceAsInt - computerChoice == -4 ||
              choiceAsInt - computerChoice == -2 ||
              choiceAsInt - computerChoice == 1 ||
              choiceAsInt - computerChoice == 3) {
            puts("Computer wins!");
            ++computerScore;
            printf("👫:🤖 %d:%d\n\n", playerScore, computerScore);
          } else if (choiceAsInt - computerChoice == -3 ||
                     choiceAsInt - computerChoice == -1 ||
                     choiceAsInt - computerChoice == 2 ||
                     choiceAsInt - computerChoice == 4) {
            puts("Player wins!");
            ++playerScore;
            printf("👫:🤖 %d:%d\n\n", playerScore, computerScore);
          } else if (choiceAsInt == computerChoice) {
            puts("It's a tie!");
            printf("👫:🤖 %d:%d\n\n", playerScore, computerScore);
          } else {
            puts("Sorry, something went wrong.");
          }
        } else if (choiceAsInt == 9) {
          puts("Thank you for playing.");
        } else {
          printf("You entered: %sThat is not a valid input.", playerChoice);
        }
      }
      if (playerScore == 5) {
        puts("Congratulations, player won! 🥳");
      }
      if (computerScore == 5) {
        puts("Better luck next time. Computer wins! 🤖");
      }
      break;
    } else if (userInput == 'e') {
      puts("Goodbye!");
      getchar();
      break;
    } else {
      puts("Input not recognized");
      getchar();
      continue;
    }
  }
}
