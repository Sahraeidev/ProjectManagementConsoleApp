#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Task
{
public:
    Task(string sn,string d,string date,string st) : shortName(sn),description(d),due(date),status(st){}

    string GetShortName() const{return shortName;}
    string GetDescription() const{return description;}
    string GetDate() const{return due;}
    string GetStatus() const{return status;}

    
    void SetShortName(string sn) {shortName=sn;}
    void SetDescription(string d) {description=d;}
    void SetDate(string d) {due=d;}
    void SetStatus(string s) {status=s;}
private:
    string shortName;
    string description;
    string due;
    string status;
};

namespace TaskManager
{
    Task* Create(){
        cout << ">Create Task" << endl;
        cout << ">Enter short name :";
        string name;
        cin.ignore();
        getline(cin, name);
        
        cout << ">Enter description :";
        cin.ignore();
        string description;
        getline(cin, description);

        cout << ">Enter due date :";
        cin.ignore();
        string dueDate;
        getline(cin, dueDate);
    
        Task* task = new Task(name,description,dueDate,"To Do");
        return task;
    }

    void Print(Task* task)
    {
        cout << ">----------" << endl;
        cout << ">Name :" << task->GetShortName() << endl;
        cout << ">Description :" << task->GetDescription() << endl;
        cout << ">Due Date :" << task->GetDate() << endl;
        cout << ">Status :" << task->GetStatus() << endl;
    }
    
    void ChangeTaskStatus(Task* task)
    {
        cout << ">Changing Task Status" << endl;
        cout << ">Enter status(1:To Do/2:Doing/3:Done) :" << endl;
        int s;
        cin >> s;
        switch (s)
        {
        case 1:
            task->SetStatus("To Do");
            break;
        case 2:
            task->SetStatus("Doing");
            break;
        case 3:
            task->SetStatus("Done");
            break;
        default:
            {
                cout << "Invalid input!" << endl;
                cout << "Please enter a valid input!" << endl;  
                ChangeTaskStatus(task);
            }
        }
        
    }

    void Edit(Task* task)
    {
        cout << ">Editing Task" << endl;
        cout << ">Edit Task" << endl;
        cout << "1)Edit task name" << endl;
        cout << "2)Edit task description" << endl;
        cout << "3)Edit task status" << endl;
        cout << "4)Edit task due date" << endl;
        int s;
        cin >> s;
        switch (s)
        {
        case 1:
            {
                cout << ">Enter task's new name : " << endl;
                string name;
                cin.ignore();
                getline(cin, name);
                task->SetShortName(name);
            }
            break;
        case 2:
            {
                cout << ">Enter task's new description : " << endl;
                string description;
                cin.ignore();
                getline(cin, description);
                task->SetDescription(description);
            }
            break;
        case 3:
            {
                ChangeTaskStatus(task);
            }
            break;
        case 4:
            {
                cout << ">Enter task's new status : " << endl;
                string status;
                cin.ignore();
                getline(cin, status);
                ChangeTaskStatus(task);
            }
            break;
        default:
            cout << "Invalid input!" << endl;
            cout << "Please enter a valid input!" << endl;
            Edit(task);
        }
    }
}

class Project
{
    public:
    Project(string name,string description) : name(name),description(description){}

    //Getters and setters
    string GetName() const{return name;}
    string GetDescription() const{return description;}
    
    void SetName(string name){this->name=name;}
    void SetDescription(string description){this->description=description;}

    vector<Task*> GetTasks() const{return tasks;}
    
    //Tasks
    void AddTask(Task* t)
    {
        tasks.push_back(t);
    }

    void DeleteTask(Task* t)
    {
        tasks.erase(find(tasks.begin(),tasks.end(),t));
    }

    Task* SelectTask()
    {
        for(int i=0;i<tasks.size();i++)
        {
            cout << ">" << tasks[i]->GetShortName() << endl;
        }
        cout << ">Select a task:" << endl;
        cin.ignore();
        int choice;
        cin >> choice;
        return tasks[choice-1];
    }

    void ShowTask()
    {
        TaskManager::Print(SelectTask());
    }

    void EditTask()
    {
        TaskManager::Edit(SelectTask());
    }

private:
    string name;
    string description;

    string tasksdirectory = "tasks.txt";
    string infofile = "info.txt";
    
    vector<Task*> tasks;
    
};

namespace ProjectManager
{
    Project* Create()
    {
        cout << ">Create Project" << endl;
        cout << ">Enter name :";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << ">Enter description :";
        cin.ignore();
        string description;
        getline(cin, description);
        Project* project = new Project(name,description);
        return project;
    }
    
    void Edit(Project* project)
    {
        cout << ">Edit Project" << endl;
        cout << "1)Edit project name" << endl;
        cout << "2)Edit project description" << endl;
        cout << ">Enter your choice :";
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                cout << ">Enter project's new name :";
                string name;
                cin.ignore();
                getline(cin, name);
                project->SetName(name);
            }
            break;
        case 2:
            {
                cout << ">Enter project's new description :";
                string description;
                cin.ignore();
                getline(cin, description);
                project->SetDescription(description);
            }
        default:
            cout << "Invalid input!" << endl;
            cout << "Please enter a valid input!" << endl;
            Edit(project);
        }
    }

    void Print(Project* project)
    {
        cout << ">----------" << endl;
        cout << ">Name :" << project->GetName() << endl;
        cout << ">Description :" << project->GetDescription() << endl;
    }
}

class Category
{
    public:
    Category(string name) : name(name){}
    
    string GetName() const{return name;}
    vector<Project*> GetProjects() const{return projects;}
    
    void SetName(string n){this->name=n;}
    
    void AddProject(Project* project)
    {
        projects.push_back(project);
    }
    void DeleteProject(Project* project)
    {
        projects.erase(find(projects.begin(),projects.end(),project));
    }
    Project* SelectProject()
    {
        cout << ">Select a project :" << endl;
        for(int i=0;i<projects.size();i++)
        {
            cout << i+1 <<")" << projects[i]->GetName() << endl;
        }
        cout << ">Enter your choice :";
        int choice;
        cin >> choice;
        return projects[choice-1];
    }
    
private:
    string projectdirectory="projects.txt";
    
    vector<Project*> projects;
    string name;
};

namespace CategoryManager
{
    Category* Create()
    {
        cout << ">Create Category" << endl;
        cout << ">Enter name :";
        string name;
        cin.ignore();
        getline(cin, name);
        Category* c = new Category(name);
        return c;
    }
    
    void Edit(Category* c)
    {
        cout << ">Edit Category:" << endl;
        cout << "Enter new name :";
        string name;
        cin.ignore();
        getline(cin, name);
        c->SetName(name);
    }

    void Print(Category* c)
    {
        cout << ">Print Category:" << endl;
        cout << "Name:" << c->GetName() << endl;
        cout << "Projects : " << endl;
        for (int i = 0; i < c->GetProjects().size(); i++)
        {
            cout << "    >" << c->GetProjects()[i]->GetName() << endl;
        }
    }
    
}

class Manager
{
    public:
    void AddCategory(Category* c)
    {
        categories.push_back(c);
    }
    void DeleteCategory(Category* c)
    {
        categories.erase(find(categories.begin(),categories.end(),c));
    }

    Category* SelectCategory()
    {
        cout << ">Select Category:" << endl;
        for (int i = 0; i < categories.size(); i++)
        {
            cout << i + 1<< ")" << categories[i]->GetName() << endl;
        }
        cout << "Enter your selection : ";
        int i;
        cin >> i;
        return categories[i-1];
    }
    
    vector<Category*> GetCategories() const {return categories;}
    
    private:
    vector<Category*> categories;
    string fileDirectory = "Categories.txt";
};

void TaskMenu(Task* T)
{
    
}
void ProjectMenu(Project* P)
{
    while (true)
    {
        cout << ">Project Menu:" << endl;
        cout << "1.View project details" << endl;
        cout << "2.View all tasks" << endl;
        cout << "3.View TODO list" << endl;
        cout << "4.View DOING list" << endl;
        cout << "5.View DONE list" << endl;
        cout << "6.Edit project" << endl;
        cout << "7.Go back" << endl;
        cout << ">Select a option:";
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
                ProjectManager::Print(P);
            break;
            case 2:
                //Print all tasks
                    break;
            case 3:
                
        }
    }
}

void CategoryMenu(Category* C)
{
    while (true)
    {
        cout << ">Category Menu :" << endl;
        cout << "1)Edit Category" << endl;
        cout << "2)Create a new project" << endl;
        cout << "3)Select a project" << endl;
        cout << "4)Delete a project" << endl;
        cout << "5)Go Back" << endl;
        cout << ">Select your option:" << endl;
        cin.ignore();
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
            CategoryManager::Edit(C);
            break;
        case 2:
            C->AddProject(ProjectManager::Create());
            break;
        case 3:
            ProjectMenu(C->SelectProject());
            break;
        case 4:
            C->DeleteProject(C->SelectProject());
            break;
        case 5:
            return;
            break;
        default:
            cout << "Invalid input!" << endl;
            CategoryMenu(C);
    }
    }
   
}
void ManagerMenu(Manager* M)
{
    while(true)
    {
        cout << ">Manager Menu :" << endl;
        cout << "1)Add a new category" << endl;
        cout << "2)Select a category" << endl;
        cout << "3)Delete category" << endl;
        cout << "4)Exit menu" << endl;
        cout << ">Select your option:" << endl;
        cin.ignore();
        int choice;
        cin >> choice;
    
        switch (choice)
        {
        case 1:
            M->AddCategory(CategoryManager::Create());
            break;
        case 2:
            CategoryMenu(M->SelectCategory());
            break;
        case 3:
            M->DeleteCategory(M->SelectCategory());
            break;
        case 4:
            return;
            break;
        default:
            cout << "Invalid Choice." << endl;
            ManagerMenu(M);
        }
    }
    
}

int main()
{
    Manager* Management = new Manager();
    ManagerMenu(Management);
    return 0;
}
