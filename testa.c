#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // For toupper()
#include <time.h>

void to_uppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int is_valid_choice(char choice[]) {
    return (strcmp(choice, "ROCK") == 0 || strcmp(choice, "PAPER") == 0 || strcmp(choice, "SCISSOR") == 0);
}

int compute(char choice[], char compchoice[]) {
    int res;
    // ROCK->1
    // PAPER->2
    // SCISSOR->3
    // CHOICE FOR ROCK (1)
    if (strcmp(choice, "ROCK") == 0) {
        if (strcmp(compchoice, "ROCK") == 0) {
            res = 0;
        } else if (strcmp(compchoice, "PAPER") == 0) {
            res = -1;
        } else if (strcmp(compchoice, "SCISSOR") == 0) {
            res = 1;
        }
    }
    // CHOICE FOR PAPER (2)
    else if (strcmp(choice, "PAPER") == 0) {
        if (strcmp(compchoice, "PAPER") == 0) {
            res = 0;
        } else if (strcmp(compchoice, "SCISSOR") == 0) {
            res = -1;
        } else if (strcmp(compchoice, "ROCK") == 0) {
            res = 1;
        }
    }
    // CHOICE FOR SCISSOR (3)
    else if (strcmp(choice, "SCISSOR") == 0) {
        if (strcmp(compchoice, "SCISSOR") == 0) {
            res = 0;
        } else if (strcmp(compchoice, "ROCK") == 0) {
            res = -1;
        } else if (strcmp(compchoice, "PAPER") == 0) {
            res = 1;
        }
    }
    return res;
}

int main() {
    int res, Score_for_User = 0, Score_for_Computer = 0;
    char choice[10], compchoice[10];

    srand(time(NULL));

    while (1) {
        // Get user input and convert it to uppercase
        while (1) {
            printf("\nEnter your choice (ROCK, PAPER, or SCISSOR): ");
            scanf("%s", choice);

            // Convert the input to uppercase to handle lowercase letters
            to_uppercase(choice);

            // Check if input is valid, if not, prompt again
            if (is_valid_choice(choice)) {
                break;
            } else {
                printf("Invalid choice! Please enter ROCK, PAPER, or SCISSOR.\n");
            }
        }

        // Generate computer's random choice
        int random = rand() % 3;
        char compchoices[3][10] = {"ROCK", "PAPER", "SCISSOR"};
        strcpy(compchoice, compchoices[random]);  // Copy random choice to compchoice
        printf("Computer choice: %s\n", compchoice);

        res = compute(choice, compchoice);
        if (res == 0) {
            printf("DRAW\n");
        } else if (res == 1) {
            printf("WINNER WINNER\n");
            Score_for_User++;
        } else if (res == -1) {
            printf("LOSER! BETTER LUCK NEXT TIME\n");
            Score_for_Computer++;
        }

        printf("THE SCORE AT THE END OF THE GAME - Computer: %d | User: %d\n", Score_for_Computer, Score_for_User);
    }

    return 0;
}
