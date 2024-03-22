#include <stdio.h>
#include <stdlib.h>

struct Job {
    char title[50];
    char company[50];
    int salary;
};

void addJob() {
    struct Job job;
    FILE *file = fopen("jobs.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter job title: ");
    scanf("%s", job.title);

    printf("Enter company name: ");
    scanf("%s", job.company);

    printf("Enter salary: ");
    scanf("%d", &job.salary);

    fprintf(file, "%s %s %d\n", job.title, job.company, job.salary);
    fclose(file);
    printf("Job added successfully!\n");
}

void listJobs() {
    struct Job job;
    FILE *file = fopen("jobs.txt", "r");

    if (file == NULL) {
        printf("No jobs found!\n");
        return;
    }

    printf("Jobs:\n");
    while (fscanf(file, "%s %s %d", job.title, job.company, &job.salary) != EOF) {
        printf("Title: %s\nCompany: %s\nSalary: %d\n\n", job.title, job.company, job.salary);
    }
    fclose(file);
}

int main() {
    int choice;

    do {
        printf("Job Recruitment System\n");
        printf("1. Add a job\n");
        printf("2. List all jobs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addJob();
                break;
            case 2:
                listJobs();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
