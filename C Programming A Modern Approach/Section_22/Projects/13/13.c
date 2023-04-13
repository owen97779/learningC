#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMETABLE_SIZE 1024

typedef struct {
    int dep_hour;
    int dep_min;
    int arr_hour;
    int arr_min;
} Timetable;

int compare_timetables(const void *a, const void *b) {
    Timetable *ta = (Timetable *) a;
    Timetable *tb = (Timetable *) b;
    int dep_a = ta->dep_hour * 60 + ta->dep_min;
    int dep_b = tb->dep_hour * 60 + tb->dep_min;
    return dep_a - dep_b;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Error: file not provided\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: file '%s' could not be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int user_hour, user_min;
    printf("Enter a departure time in 24hr format: ");
    scanf("%d:%d", &user_hour, &user_min);
    int user_time = user_hour * 60 + user_min;

    Timetable timetables[MAX_TIMETABLE_SIZE];
    int num_timetables = 0;

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL && num_timetables < MAX_TIMETABLE_SIZE) {
        Timetable *tt = &timetables[num_timetables];
        int num_fields = sscanf(line, "%d:%d %d:%d", &tt->dep_hour, &tt->dep_min, &tt->arr_hour, &tt->arr_min);
        if (num_fields != 4) {
            fprintf(stderr, "Error: could not parse line '%s'\n", line);
            continue;
        }
        num_timetables++;
    }
    fclose(fp);

    if (num_timetables == 0) {
        printf("No timetables found in file '%s'\n", argv[1]);
        exit(EXIT_SUCCESS);
    }

    qsort(timetables, num_timetables, sizeof(Timetable), compare_timetables);

    int closest_index = -1;
    int closest_time_diff = abs(user_time - (timetables[0].dep_hour * 60 + timetables[0].dep_min));
    for (int i = 1; i < num_timetables; i++) {
        int time_diff = abs(user_time - (timetables[i].dep_hour * 60 + timetables[i].dep_min));
        if (time_diff < closest_time_diff) {
            closest_time_diff = time_diff;
            closest_index = i;
        }
    }

    printf("Closest departure time is: %02d:%02d, arriving at %02d:%02d\n",
           timetables[closest_index].dep_hour, timetables[closest_index].dep_min,
           timetables[closest_index].arr_hour, timetables[closest_index].arr_min);

    return EXIT_SUCCESS;
}
