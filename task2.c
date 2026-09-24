#include <stdio.h>

int main() {

    double temperature;
    double celsius;
    double convertedTemp;
    char originalScale;
    char targetScale;
    char *tempCat;
    char *advisory;

    // User inputs for temp, original scale, and scale to convert to
    while (1) {
        printf("Enter the temperature: ");

        if (scanf("%lf", &temperature) == 1) {
            break;
        }

        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');
    }

    do {
        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &originalScale);

        if (originalScale != 'C' && originalScale != 'F' && originalScale != 'K') {
            printf("Invalid scale. Please enter C, F, or K.\n");
            while (getchar() != '\n');
        }

    } while (originalScale != 'C' && originalScale != 'F' && originalScale != 'K');

    do {
        printf("Enter the scale to convert to (C, F, or K): ");
        scanf(" %c", &targetScale);

        if (targetScale != 'C' && targetScale != 'F' && targetScale != 'K') {
            printf("Invalid scale. Please enter C, F, or K.\n");
            while (getchar() != '\n');
        }

    } while (targetScale != 'C' && targetScale != 'F' && targetScale != 'K');

    // Converts temp to celsius for a basis
    if (originalScale == 'C') {
        celsius = temperature;
    }
    else if (originalScale == 'F') {
        celsius = (temperature - 32) * 5/9;
    }
    else if (originalScale == 'K') {
        celsius = temperature - 273.15;
    }

    // Converts temp to target
    if (targetScale == 'C') {
        convertedTemp = celsius;
    } else if (targetScale == 'F') {
        convertedTemp = (celsius * 9/5) + 32;
    } else if (targetScale == 'K') {
        convertedTemp = celsius + 273.15;
    } 

    // Temperature category and advisory message
    if (celsius < 0) {
        tempCat = "Freezing";
        advisory = "Stay indoors and keep warm!"; 
    }
    else if (celsius >= 0 && celsius < 10) {
        tempCat = "Cold";
        advisory = "Wear a jacket!";
    }
    else if (celsius >= 10 && celsius < 25) {
        tempCat = "Comfortable";
        advisory = "Enjoy the weather!";
    }
    else if (celsius >= 25 && celsius < 35) {
        tempCat = "Hot";
        advisory = "Drink lots of water!";
    }
    else {
        tempCat = "Extreme Heat";
        advisory = "Stay indoors!";
    }

    printf("Converted temperature: %.2f %c\n", convertedTemp, targetScale);
    printf("Temperature category: %s\n", tempCat);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}