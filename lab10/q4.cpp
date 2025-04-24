#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct Task {
    string task;
    bool isDone;

    Task(const string& taskDescription) : task(taskDescription), isDone(false) {}
};

// Function to add a task to the file
void addTask(const string& filename, const string& taskDescription) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << taskDescription << ",false\n"; // false indicates the task is not done yet
        file.close();
    } else {
        cout << "Error opening file for writing.\n";
    }
}

// Function to load tasks from the file
vector<Task> loadTasks(const string& filename) {
    ifstream file(filename);
    vector<Task> tasks;
    string line;
    string taskDescription;
    bool isDone;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, taskDescription, ',');
        ss >> isDone;
        tasks.push_back(Task(taskDescription));
        tasks.back().isDone = isDone;
    }

    file.close();
    return tasks;
}

// Function to display all tasks
void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". " << tasks[i].task << " [" << (tasks[i].isDone ? "Done" : "Not Done") << "]\n";
    }
}

// Function to mark a task as done
void markTaskAsDone(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex].isDone = true;
    } else {
        cout << "Invalid task index.\n";
    }
}

// Function to save tasks to the file
void saveTasks(const string& filename, const vector<Task>& tasks) {
    ofstream file(filename, ios::trunc); // Truncate file to overwrite it
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.task << "," << (task.isDone ? "true" : "false") << "\n";
        }
        file.close();
    } else {
        cout << "Error opening file for writing.\n";
    }
}

int main() {
    string filename = "todo_list.txt";
    int choice;
    vector<Task> tasks;
    string taskDescription;
    int taskIndex;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after choice input

        switch (choice) {
            case 1:
                cout << "Enter the task description: ";
                getline(cin, taskDescription);
                addTask(filename, taskDescription);
                break;

            case 2:
                tasks = loadTasks(filename);
                displayTasks(tasks);
                break;

            case 3:
                tasks = loadTasks(filename);
                displayTasks(tasks);
                cout << "Enter the task number to mark as done: ";
                cin >> taskIndex;
                cin.ignore();
                markTaskAsDone(tasks, taskIndex - 1); // Convert to 0-indexed
                saveTasks(filename, tasks);
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
