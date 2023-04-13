#include <stdio.h>
#define NUM_COUNTRIES(x) ((int) (sizeof(x))/sizeof(x[0]))

int main(void)
{
    int code, i;

    struct dialling_code {
        char *country;
        int code;
        char *capital;
    };

    const struct dialling_code country_codes[] =
    {{"Argentina", 54, "Buenos Aires"},
     {"Bangladesh", 880, "Dhaka"},
     {"Brazil", 55, "Brasilia"},
     {"Burma (Myanmar)", 95, "Naypyidaw"},
     {"China", 86, "Beijing"},
     {"Colombia", 57, "Bogota"},
     {"Congo, Dem. Rep. of", 243, "Kinshasa"},
     {"Egypt", 20, "Cairo"},
     {"Ethiopia", 251, "Addis Ababa"},
     {"France", 33, "Paris"},
     {"Germany", 49, "Berlin"},
     {"India", 91, "New Delhi"},
     {"Indonesia", 62, "Jakarta"},
     {"Iran", 98, "Tehran"},
     {"Italy", 39, "Rome"},
     {"Japan", 81, "Tokyo"},
     {"Mexico", 52, "Mexico City"},
     {"Nigeria", 234, "Abuja"},
     {"Pakistan", 92, "Islamabad"},
     {"Philippines", 63, "Manila"},
     {"Poland", 48, "Warsaw"},
     {"Russia", 7, "Moscow"},
     {"South Africa", 27, "Pretoria"},
     {"South Korea", 82, "Seoul"},
     {"Spain", 34, "Madrid"},
     {"Sudan", 249, "Khartoum"},
     {"Thailand", 66, "Bangkok"},
     {"Turkey", 90, "Ankara"},
     {"Ukraine", 380, "Kiev"},
     {"United Kingdom", 44, "London"},
     {"United States", 1, "Washington"},
     {"Vietnam", 84, "Hanoi"}};

     for(;;)
     {
        printf("Enter a country code: ");
        scanf(" %d", &code);

        if(code == 0)
        {
            return 0;
        }

        for(i = 0; i < NUM_COUNTRIES(country_codes); i++)
        {
            if(country_codes[i].code == code)
            {
                printf("%s\n", country_codes[i].country);
                break;
            }
        }

        if(i == NUM_COUNTRIES(country_codes))
        {
            printf("Error, not a valid country code!\n");
        }
     }
    
}