/*
    PreDoc - Symptom Checker
    Introduction to Programming - Mini Project
    Author: Mannat (B.Tech CSE AI/ML with EY)
    ----------------------------------------
    How it works:
    1. User enters up to 3 symptoms they are experiencing.
    2. Program compares entered symptoms with a predefined database.
    3. Condition with the MOST matching symptoms is shown as the result.
    4. A safety disclaimer is always printed.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONDITIONS 20
#define MAX_SYMPTOMS_PER_CONDITION 5
#define MAX_USER_SYMPTOMS 3

struct Disease {
    char name[50];
    char symptoms[MAX_SYMPTOMS_PER_CONDITION][30];
    int symptomCount;
    char advice[120];
};

/* ---------- Symptom Database ---------- */
struct Disease diseaseList[MAX_CONDITIONS] = {
    {"Common Cold/Flu", {"fever", "cough", "sore throat"}, 3, "Rest, stay hydrated."},
    {"Possible Dengue", {"fever", "body ache", "rash"}, 3, "See a doctor immediately."},
    {"Migraine", {"headache", "nausea", "light sensitivity"}, 3, "Rest in a dark room; consult if frequent."},
    {"Possible Cardiac Issue", {"chest pain", "shortness of breath"}, 2, "Seek emergency care immediately."},
    {"Food Poisoning", {"stomach pain", "vomiting", "diarrhea"}, 3, "Stay hydrated; see a doctor if it persists."},
    {"Possible Malaria", {"fever", "chills", "joint pain"}, 3, "See a doctor and get tested."},
    {"Bronchitis", {"cough", "chest congestion", "fatigue"}, 3, "Rest; consult if it worsens."},
    {"Tonsillitis", {"sore throat", "difficulty swallowing", "fever"}, 3, "Consult a doctor."},
    {"Allergic Reaction", {"itchy skin", "redness", "swelling"}, 3, "Take antihistamine; see a doctor if severe."},
    {"Possible Diabetes Symptoms", {"frequent urination", "excessive thirst", "fatigue"}, 3, "Get blood sugar tested."},
    {"Common Allergy/Cold", {"runny nose", "sneezing", "watery eyes"}, 3, "Rest; consider antihistamines."},
    {"Indigestion", {"abdominal pain", "bloating", "constipation"}, 3, "Try dietary changes; consult if persistent."},
    {"Possible Anemia", {"fatigue", "pale skin", "dizziness"}, 3, "Blood test recommended."},
    {"Ear Infection", {"ear pain", "fever", "hearing difficulty"}, 3, "Consult an ENT specialist."},
    {"Conjunctivitis", {"eye redness", "itching", "discharge"}, 3, "Consult a doctor; avoid touching eyes."}
};
int totalDiseases = 15;

/* ---------- Function Prototypes ---------- */
void getUserSymptoms(char userSymptoms[MAX_USER_SYMPTOMS][30], int count);
int countMatches(struct Disease d, char userSymptoms[MAX_USER_SYMPTOMS][30], int count);
void toLowerCase(char *str);
void trimSpaces(char *str);

int main() {
    char userSymptoms[MAX_USER_SYMPTOMS][30];
    int numSymptoms;

    printf("=====================================\n");
    printf("        Welcome to PreDoc\n");
    printf("   Know Before You Go (Symptom Checker)\n");
    printf("=====================================\n\n");

    printf("How many symptoms would you like to enter? (1-%d): ", MAX_USER_SYMPTOMS);
    while (scanf("%d", &numSymptoms) != 1 || numSymptoms < 1) {
        /* invalid input: clear the buffer and ask again */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        if (c == EOF) return 1;
        printf("Please enter a number between 1 and %d: ", MAX_USER_SYMPTOMS);
    }
    if (numSymptoms > MAX_USER_SYMPTOMS) numSymptoms = MAX_USER_SYMPTOMS;

    getUserSymptoms(userSymptoms, numSymptoms);

    int bestMatchIndex = -1;
    int bestMatchCount = 0;

    for (int i = 0; i < totalDiseases; i++) {
        int matches = countMatches(diseaseList[i], userSymptoms, numSymptoms);
        if (matches > bestMatchCount) {
            bestMatchCount = matches;
            bestMatchIndex = i;
        }
    }

    printf("\n-------------------------------------\n");
    if (bestMatchIndex != -1 && bestMatchCount > 0) {
        printf("Possible Condition: %s\n", diseaseList[bestMatchIndex].name);
        printf("Advice: %s\n", diseaseList[bestMatchIndex].advice);
    } else {
        printf("No strong match found in our database.\n");
        printf("Please consult a doctor for accurate diagnosis.\n");
    }
    printf("-------------------------------------\n");
    printf("\nDISCLAIMER: PreDoc does not provide medical diagnosis.\n");
    printf("This tool is for awareness only. Please consult a certified doctor.\n");

    return 0;
}

/* ---------- Function Definitions ---------- */

void getUserSymptoms(char userSymptoms[MAX_USER_SYMPTOMS][30], int count) {
    printf("\nEnter your symptoms (one word/phrase each, e.g. 'fever', 'cough'):\n");
    for (int i = 0; i < count; i++) {
        printf("Symptom %d: ", i + 1);
        scanf(" %29[^\n]", userSymptoms[i]);   /* 29 chars max: prevents buffer overflow */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }   /* discard any extra characters */
        trimSpaces(userSymptoms[i]);
        toLowerCase(userSymptoms[i]);
    }
}

int countMatches(struct Disease d, char userSymptoms[MAX_USER_SYMPTOMS][30], int count) {
    int matchCount = 0;
    char temp[30];

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < d.symptomCount; j++) {
            strcpy(temp, d.symptoms[j]);
            toLowerCase(temp);
            if (strcmp(userSymptoms[i], temp) == 0) {
                matchCount++;
                break;
            }
        }
    }
    return matchCount;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

/* Removes trailing spaces so "fever " still matches "fever" */
void trimSpaces(char *str) {
    int len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
}
