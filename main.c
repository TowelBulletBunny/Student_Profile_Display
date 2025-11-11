#include <stdio.h>
#include <string.h>

// Define enum for contact type
enum ContactType {
    EMAIL = 0,
    PHONE = 1
};

// Define union for contact detail
union Contact {
    char email[100];
    char phone[20];
};

// Define Student structure
struct Student {
    char studentID[20];
    char fullName[100];
    char courseCode[20];
    char courseTitle[100];
    enum ContactType contactType;
    union Contact contact; // union replaces single string
};

// Function to input one student's data
struct Student inputStudent(int number) {
    struct Student s;
    int typeInput;
    char temp[10];

    printf("Enter details for Student %d:\n", number);

    printf("Enter Student ID: ");
    scanf("%s", s.studentID);
    fgets(temp, sizeof(temp), stdin); // clear newline

    printf("Enter full name: ");
    fgets(s.fullName, sizeof(s.fullName), stdin);
    s.fullName[strcspn(s.fullName, "\n")] = '\0';

    printf("Enter Course Code: ");
    fgets(s.courseCode, sizeof(s.courseCode), stdin);
    s.courseCode[strcspn(s.courseCode, "\n")] = '\0';

    printf("Enter Course Title: ");
    fgets(s.courseTitle, sizeof(s.courseTitle), stdin);
    s.courseTitle[strcspn(s.courseTitle, "\n")] = '\0';

    // Validate contact type
    while (1) {
        printf("Contact Type (0 = EMAIL, 1 = PHONE): ");
        if (scanf("%d", &typeInput) != 1) {
            printf("Invalid input. Please enter 0 or 1.\n");
            while (getchar() != '\n');
            continue;
        }
        if (typeInput == 0 || typeInput == 1) break;
        printf("Invalid choice. Please enter 0 or 1.\n");
    }

    s.contactType = (enum ContactType) typeInput;
    fgets(temp, sizeof(temp), stdin); // clear newline

    if (s.contactType == EMAIL) {
        printf("Enter Email: ");
        fgets(s.contact.email, sizeof(s.contact.email), stdin);
        s.contact.email[strcspn(s.contact.email, "\n")] = '\0';
    } else {
        printf("Enter Phone: ");
        fgets(s.contact.phone, sizeof(s.contact.phone), stdin);
        s.contact.phone[strcspn(s.contact.phone, "\n")] = '\0';
    }

    printf("\n");
    return s;
}

// Function to display one student's info
void displayStudent(struct Student s, int number) {
    printf("Student %d:\n", number);
    printf("Student ID   : %s\n", s.studentID);
    printf("Name         : %s\n", s.fullName);
    printf("Course       : %s - %s\n", s.courseCode, s.courseTitle);

    if (s.contactType == EMAIL)
        printf("Contact      : %s (email)\n\n", s.contact.email);
    else
        printf("Contact      : %s (phone)\n\n", s.contact.phone);
}

// Main program
int main(int argc, const char * argv[]) {
    int n = 2;
    struct Student students[n];

    printf("=== Student Information System ===\n");

    for (int i = 0; i < n; i++) {
        students[i] = inputStudent(i + 1);
    }

    printf("=== Displaying Student Details ===\n");
    for (int i = 0; i < n; i++) {
        displayStudent(students[i], i + 1);
    }

    return 0;
}
