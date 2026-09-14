#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[50];
    int priority;
};

struct Patient queue[MAX];
int size = 0;

void addPatient(char name[], int priority) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    strcpy(queue[size].name, name);
    queue[size].priority = priority;
    size++;

    printf("Patient %s added with priority %d.\n", name, priority);
}

void treatNextPatient() {
    if (size == 0) {
        printf("No patients waiting.\n");
        return;
    }

    int index = 0;

    // Find the patient with the lowest priority number.
    for (int i = 1; i < size; i++) {
        if (queue[i].priority < queue[index].priority) {
            index = i;
        }
    }

    printf("Treating patient: %s (Priority %d)\n",
           queue[index].name, queue[index].priority);

    // Remove the treated patient.
    for (int i = index; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

int main() {
    // Step 3 test: Add P1-P6.
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\n--- Treatment Order ---\n");

    while (size > 0) {
        treatNextPatient();
    }

    // Test emergency patient joining after 2-3 patients.
    printf("\n--- New Test ---\n");

    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\nTreating first 3 patients:\n");
    treatNextPatient();
    treatNextPatient();
    treatNextPatient();

    printf("\nAdding new Emergency patient:\n");
    addPatient("Emergency", 1);

    printf("\n--- Remaining Treatment Order ---\n");

    while (size > 0) {
        treatNextPatient();
    }

    return 0;
}
