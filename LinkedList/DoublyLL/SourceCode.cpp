//Q-> Write a program to read a list of students from a file and create a list.
// The program should use a linked list for implementation.
//Each node in the linked list should have the student’s name, a pointer to the next
//student, and a pointer to a linked list of scores.
//There may be up to four scores for each student.

#include <bits/stdc++.h>
#include <fstream>
// The Input file
std::ifstream file("input.txt");
using namespace std;

// Class of Node for each student score
class ScoreNode
{
public:
    string score;
    ScoreNode *next;
};

// Class of node for each student
class StudentNode
{
public:
    string name;
    ScoreNode *scores; //score's Pointer
    StudentNode *next;
};

//Function to push Students in Linked list
void pushStudent(StudentNode **head, string new_name) //**head is a pointer to a pointer
{
    StudentNode *new_Studentnode = new StudentNode();
    new_Studentnode->name = new_name;
    new_Studentnode->scores = NULL; //Intiallizes the Score Linked List for each student
    new_Studentnode->next = (*head);
    (*head) = new_Studentnode;
}

// Function to push scores of each student in a Linked List
void pushScore(ScoreNode **head, string new_score) //**head is a pointer to a pointer
{
    ScoreNode *new_Scorenode = new ScoreNode();
    new_Scorenode->score = new_score;
    new_Scorenode->next = (*head);
    (*head) = new_Scorenode;
}

int main()
{
    StudentNode *head = NULL;
    // Access the Input file
    if (file.is_open())
    {
        // Now read Line by line
        std::string line;
        while (getline(file, line))
        {
            // Each line contains the student Info
            string StudentInfo = line.c_str();
            // Split the info using stringstream
            istringstream ss(StudentInfo);
            // Collect the name of the student
            string name;
            ss >> name;
            // Insert the name in the linked list
            pushStudent(&head, name);
            // Now collect all the scores of the student
            while (ss)
            {
                string score;
                ss >> score;
                // Push the collected score to the linked list of that student
                if (score != "")
                    pushScore(&head->scores, score);
                // While there is more to read
            }
            cout << endl;
        }
    }
    //Driver function
    // To Display each student with their scores in each line
    cout << "List of Students" << endl;
    StudentNode *node = head;
    while (node != NULL)
    {
        cout << node->name << " ";
        cout << "Linked List of Scores :> ";
        ScoreNode *p = node->scores;
        while (p != NULL)
        {
            cout << p->score << "->";
            p = p->next;
        }
        cout << endl;
        node = node->next;
    }
    return 0;
}