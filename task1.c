#include <stdio.h>

int main() {

    int score = 0;

    // Asks for NFL score until 1 is entered
    while (score != 1) {
        printf("Enter the NFL score (Enter 1 to stop): ");

        // Checks for valid input
        if (scanf("%d", &score) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        // Stops if score is 1
        if (score == 1) {
            break;
        }

        // Prevents negative scores
        if (score < 0) {
            printf("Invalid score.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Runs through all possible combinations of the 5 scoring play types
        for (int td2 = 0; td2 * 8 <= score; td2++) {
            for (int td1 = 0; td2 * 8 + td1 * 7 <= score; td1++) {
                for (int td = 0; td2 * 8 + td1 * 7 + td * 6 <= score; td++) {
                    for (int fg = 0; td2 * 8 + td1 * 7 + td * 6 + fg * 3 <= score; fg++) {
                        for (int safety = 0; td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2 <= score; safety++) {

                            // Prints the combination if the scoring plays add up to the entered score
                            if (td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                td2, td1, td, fg, safety);
                            }        
                        }
                    }
                }
            }
        }
    }
    return 0;
}