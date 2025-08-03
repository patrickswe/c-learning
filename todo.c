#include <stdio.h>

void add_task(void) {
    FILE *fp = fopen("todo.txt", "a");
    if (fp != NULL) {
        char task[100];
        printf("Enter task: ");
        scanf(" %[^\n]", task);
        fprintf(fp, "%s\n", task);
        fclose(fp);
    }
}

void view_task() {
    FILE *fp = fopen("todo.txt", "r");
    if (fp != NULL) {
        char line[100];
        int i = 1;
        while (fgets(line, sizeof(line), fp)) {
            printf("%d. %s", i, line);
            i++;
        }
        fclose(fp);
    } else {
        printf("No Tasks Yet :( /n");
    }
}

void start_app(void) {
    int choice = 0;
    while (choice != 3) {
        printf("1. Add Task\n2. View Tasks \n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_task();
        }else if (choice == 2) {
            view_task();
        }
    }
}

int main() {
    start_app();
    return 0;
}
