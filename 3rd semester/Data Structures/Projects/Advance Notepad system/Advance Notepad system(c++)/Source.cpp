#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
struct node
{
    // Array to store pointers to child nodes for each letter of the alphabet
    node* letters[26]; 
    // The character associated with the current node
    char digit;
    // to indicate if the node represents the end of a word
    bool word;
    // Message associated with the node
    string message;

    // Constructor to initialize a node with a given character
    node(char z = '\0');
};

//class trie tree
class TrieTree
{
    node* root;
    // suggestion array of string to store suggestion
    string suggestion[11];
    int count;

public:
    TrieTree();

    node* Root()
    {
        return root;
    }
    void collect_information(string str);
    string* Suggestion_data(string str);
    bool leaf_node(node* r);

private:
    // display function of tree
    void Display_data(node* head = NULL);
};

// Node constructor
node::node(char k)
{
    for (int i = 0; i < 26; i++)
    {
        letters[i] = NULL;
    }
    digit = k;
    word = false;
}

// Trie Tree Methods
TrieTree::TrieTree()
{
    // Create a new node and assign it as the root of the trie
    root = new node();
    // Initialize the count to 0
    count = 0; 

    // Initialize the letters array of the root node
    for (int i = 0; i < 26; i++)
    {
        // Set each child node pointer to NULL
        root->letters[i] = NULL;
        // Set the word flag of the root to false
        root->word = false;
        // Set the digit of the root to the null character null
        root->digit = NULL;        
    }
}


// load data from file
void TrieTree::collect_information(string str)
{
    int i = 0;
    int pos = 0;
    node* temp = root;

    // Traverse the characters in the input string
    while (str[i] != '\0')
    {
        // Convert uppercase letters to lowercase
        if (isupper(str[i]))
        {
            str[i] = str[i] + 32;
        }

        // Calculate the position of the current character in the trie node
        pos = int(str[i]) - 97;

        // If the current position in the trie is empty, create a new node and update the message
        if (temp->letters[pos] == NULL)
        {
            temp->letters[pos] = new node(str[i]);

            // Update the message of the new node with characters from previous positions
            for (int j = 0; j < i; j++)
            {
                if (temp->message == "")
                    temp->message += str[j];
            }
        }

        // Move to the next node in the trie
        temp = temp->letters[pos];
        i++;
    }

    // Set the message of the current node to the input string
    temp->message = "";
    temp->message = str;
    temp->word = true;
}


// this function return suggestion array

string* TrieTree::Suggestion_data(string str)
{
    // Start at the root of the trie
    node* temp = root;
    int pos = 0;
    int i = 0;

    // Initialize the suggestion array with "NULL"
    for (int i = 0; i < 10; i++)
    {
        suggestion[i] = "NULL";
    }

    // Set the last element of the suggestion array to "false"
    suggestion[10] = "false";

    // Traverse the trie based on the characters in the input string
    while (str[i] != NULL)
    {
        // Convert lowercase letters to uppercase
        if (islower(str[i]))
        {
            str[i] = str[i] - 32;
        }

        // Calculate the position of the current character in the trie node
        pos = int(str[i]) - 65;

        // Move to the next node in the trie
        if (temp != NULL)
            temp = temp->letters[pos];
        i++;
    }

    // Reset the count of suggestions
    count = 0;

    // Call the Display_data function to populate the suggestion array
    Display_data(temp);

    // Return the suggestion array
    return suggestion;
}

// this function check that the node is leaf or not
bool TrieTree::leaf_node(node* r)
{
    int i = 0;
    while (i < 26)
    {
        if (r->letters[i] != NULL)
            return true;
        i++;
    }
    return false;
}

// display function
void TrieTree::Display_data(node* head)
{
    if (head == NULL)
        return;
    int i = 0;
    bool flag = false;
    while (i < 26)
    {
        if (head->word == true && flag == false)
        {
            if (count < 10)
            {
               
                suggestion[count] = head->message;
                suggestion[10] = "true";
            }
            count++;
            flag = true;
            if (!leaf_node(head))
            {
                return;
            }
        }
        if (head->letters[i] != NULL)
        {
            Display_data(head->letters[i]);
        }
        i++;
    }
}
//make struct node
struct Node
{
    string data;
    Node* next;
};
//class stack
class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        //intialize with Null
        top = NULL;
    }
    bool isEmpty()
    {
        // Check if the top pointer is NULL, indicating an empty stack
        return top == NULL;
    }

    void push(const string& data)
    {
        // Create a new Node object
        Node* newNode = new Node;

        // Assign the input data to the data member variable of the new Node
        newNode->data = data;

        // Set the next pointer of the new Node to the current top of the stack
        newNode->next = top;

        // Update the top pointer to point to the new Node, making it the new top of the stack
        top = newNode;
    }


    string pop()
    {
        // Check if the stack is empty
        if (isEmpty())
        {
            // If the stack is empty, display an error message and return an empty string
            cout << "Stack is empty!" << endl;
            return "";
        }

        // Create a temporary pointer to hold the address of the top node
        Node* temp = top;

        // Retrieve the data from the top node
        string data = top->data;

        // Update the top pointer to the next node in the stack
        top = top->next;

        // Delete the old top node from memory
        delete temp;

        // Return the retrieved data
        return data;
    }


    string peek()
    {
        // Check if the stack is empty
        if (isEmpty())
        {
            // If the stack is empty, display an error message and return an empty string
            cout << "Stack is empty!" << endl;
            return "";
        }

        // Return the data of the top node without modifying the stack
        return top->data;
    }
};
// store previous texts
Stack previousTexts;
// store deleted texts
Stack deletedTexts;

int x = 0, y = 0;
string copy_Text_str;

TrieTree tr;
//insert values function
void Insert_value()
{
    // Variables for input data and control
    string data = "", para;
    int temp = 0;
    cout << "Please Enter position for insert data at x : ";
    cin >> x;
    cout << "Please Enter position for insert data at Y : ";
    cin >> y;

    ofstream file;
    y--;
    y = 191 * y;
    y = y + x;
    bool check = false;

    // Loop to receive input data and insert into file
    while (true)
    {
        if (temp == -1)
        {
            break;
        }
        char keypress;
        file.open("check.txt", ios::app);
        cout << "Please Enter data : ";
        // Ignore the newline character in the input buffer
        cin.ignore();
        getline(cin, data);

        string* suggested = tr.Suggestion_data(data);

        // Display suggested data options to the user
        for (int i = 0; suggested[i] != "NULL" && i < 10; i++)
        {
            cout << i << ":" << suggested[i] << endl;
        }
        int ch;
        if (suggested != NULL)
        {
            cout << "Enter From Choice else press -1 for go further! ";
            cin >> ch;
            if (ch >= 0)
            {
                data = suggested[ch];
            }
        }

        // If it is the first data to be inserted at the given position, fill preceding spaces
        if (check == false)
        {
            for (int i = 0; i < y; i++)
            {
                if ((i) % 191 == 0 && i != 0 && check == false)
                {
                    file << endl;
                }
                file << ' ';
            }
        }
        else
        {
            file << ' ';
        }

        check = true;
        file << data;
        // Store the entered data in the previous Texts stack
        previousTexts.push(data);
        cout << " Please Enter -1 to End program else press 1 to go further! ";
        cin >> temp;
        file.close();
    }
}
//this function is used for undo the text
void undo_text()
{
    if (!previousTexts.isEmpty())
    {
        string lastText = previousTexts.pop();
        // Store the deleted text in the deleted Texts stack
        deletedTexts.push(lastText);
        cout << "Data is Undo successful!" << endl;

        // Rewrite the file with remaining texts from previousTexts stack
        ofstream file("check.txt", ios::trunc);
        bool check2 = false;
        while (!previousTexts.isEmpty())
        {
            if (check2 == false)
            {
                for (int i = 0; i < y; i++)
                {
                    if ((i) % 191 == 0 && i != 0 && check2 == false)
                    {
                        file << endl;
                    }
                    file << ' ';
                }
            }
            else
            {
                file << ' ';
            }
            file << previousTexts.pop() << " ";
            check2 = true;
        }
        file.close();
    }
    //this check is for if text is not found
    else
    {
        cout << "There is no text here for undo!" << endl;
    }
}
//count the total words
void count_total_words()
{
    // Open the file "check.txt"
    ifstream file("check.txt");

    // Initialize word and character counters
    int words = -1; // Set to -1 to exclude the EOF token as a word

    // Check if the file is successfully opened
    if (!file)
    {
        cerr << "File not open!" << endl;
        return;
    }

    // Variables for reading the file line by line
    string line;
    int characters = 0;
    bool check = false;

    // Read the file line by line and count words and characters
    while (!file.eof())
    {
        file >> line;
        words++;
        characters += line.size();
    }

    // Close the file
    file.close();

    // Print the total words and characters count
    cout << "Total Words of the Entered string: " << words << endl;
    cout << "Total Characters of the word: " << characters << endl;
}

void similarity_checker()
{
    // Open the files "folder1.txt" and "folder2.txt" for reading
    ifstream folder1("folder1.txt");
    ifstream folder2("folder2.txt");

    // Check if both files are successfully opened
    if (!folder1 || !folder2)
    {
        cerr << "Both files or one not open!" << endl;
        return;
    }

    // Variables to store characters and counts
    char char1, char2;
    int similarChars = 0;
    int totalChars = 0;

    // Compare characters from both files
    while (folder1.get(char1) && folder2.get(char2))
    {
        totalChars++;
        if (char1 == char2)
        {
            similarChars++;
        }
    }

    // Close the files
    folder1.close();
    folder2.close();

    // Calculate similarity percentage
    float similarityPercentage = (static_cast<float>(similarChars) / totalChars) * 100;

    // Print the similarity percentage
    cout << "The Similarity in percentage: " << similarityPercentage << "%" << endl;
}
//suggestion
void sugesstions_upgrade()
{
    // Get search and replace words from the user
    string search_string_word, replace_string_Word;
    cout << "Please Enter the word which you want to search: ";
    cin >> search_string_word;
    cout << "Please Enter the word which you want to replace with: ";
    cin >> replace_string_Word;

    // Open the file "suggestion.txt" for reading
    ifstream file("suggestion.txt");
    if (!file)
    {
        cerr << "File not open!" << endl;
        return;
    }

    // Variables for file processing
    string line;
    vector<string> fileContents;
    bool found = false;

    // Process each line of the file
    while (getline(file, line))
    {
        // Find and replace the search word with the replace word
        size_t pos = line.find(search_string_word);
        while (pos != string::npos)
        {
            found = true;
            line.replace(pos, search_string_word.length(), replace_string_Word);
            pos = line.find(search_string_word, pos + replace_string_Word.length());
        }

        // Store the modified line in a vector
        fileContents.push_back(line);
    }

    // Close the file
    file.close();

    // If the search word is found and replaced, write the modified contents back to the file
    if (found)
    {
        // Open the file "suggestion.txt" for writing
        ofstream outFile("suggestion.txt");
        if (!outFile)
        {
            cerr << "File not open for writing!" << endl;
            return;
        }

        // Write the modified contents back to the file
        for (const auto& line : fileContents)
        {
            outFile << line << endl;
        }

        // Close the file
        outFile.close();

        cout << "Your Word is replaced successfully!" << endl;
    }
    else
    {
        cout << "There is no word found!" << endl;
    }
}
//copy 
void copy_string_Text()
{
    // Get the start and end points for copying
    int st1, st2, en1, en2;
    cout << "Please Enter start point X: ";
    cin >> st1;
    cout << "Please Enter start point Y: ";
    cin >> st2;

    cout << "Please Enter end point X: ";
    cin >> en1;
    cout << "Please Enter end point Y: ";
    cin >> en2;

    // Open the file "check.txt" for reading
    ifstream file("check.txt");
    if (!file)
    {
        cerr << "File not open!" << endl;
        return;
    }

    // Variables for file processing
    string line;
    string copiedString;
    int lineNumber = 0;
    bool copyInProgress = false;

    // Copy the specified portion of the file
    while (getline(file, line))
    {
        lineNumber++;

        if (lineNumber >= st2 && lineNumber <= en2)
        {
            if (lineNumber == st2)
            {
                int startPos = st1 - 1;
                int endPos = (lineNumber == en2) ? (en1 - 1) : line.size();
                copiedString += line.substr(startPos, endPos - startPos + 1);
            }
            else if (lineNumber == en2)
            {
                int endPos = en1 - 1;
                copiedString += line.substr(0, endPos + 1);
            }
            else
            {
                copiedString += line;
            }

            copyInProgress = true;
        }
        else if (copyInProgress)
        {
            break;
        }
    }

    // Close the file
    file.close();

    // Store the copied text in a global variable
    copy_Text_str = copiedString;

    cout << "Your Text is copied successfully!" << endl;
}
//paste
void paste_string_Text()
{
    // Get the paste points
    int p1, p2;
    cout << "Please Enter paste point X: ";
    cin >> p1;
    cout << "Please Enter paste point Y: ";
    cin >> p2;

    // Open the file "check.txt" for reading
    ifstream file("check.txt");
    if (!file)
    {
        cerr << "File is not open!" << endl;
        return;
    }

    // Variables for file processing
    string line;
    vector<string> fileContents;
    int lineNumber = 0;
    bool pasteSuccessful = true;

    // Process each line in the file
    while (getline(file, line))
    {
        lineNumber++;

        if (lineNumber == p2)
        {
            int pastePos = p1 - 1;
            if (pastePos >= 0 && pastePos <= line.size())
            {
                if (line[pastePos] != ' ')
                {
                    // Text already present at the paste position
                    char choice;
                    cout << "Text is already found!" << endl;
                    cout << "Do you still want to paste the text? Press 'y' for yes, 'n' for no: ";
                    cin >> choice;
                    if (choice != 'y' && choice != 'Y')
                    {
                        pasteSuccessful = false;
                        break;
                    }
                }
                line.replace(pastePos, copy_Text_str.size(), copy_Text_str);
            }
        }

        // Store the modified line
        fileContents.push_back(line);
    }

    // Close the file
    file.close();

    if (pasteSuccessful)
    {
        // Open the file "check.txt" for writing
        ofstream outFile("check.txt");
        if (!outFile)
        {
            cerr << "File not open for writing!" << endl;
            return;
        }

        // Write the modified contents to the file
        for (const auto& line : fileContents)
        {
            outFile << line << endl;
        }

        // Close the file
        outFile.close();
        cout << "Your Text is pasted successfully!" << endl;
    }
}
//delete
void delete_string_text()
{
    // Get the string to delete
    string del_str;
    cout << "Please Enter the string which you want to delete: ";
    cin.ignore();
    getline(cin, del_str);

    // Open the file "test.txt" for reading
    ifstream file("check.txt");
    if (!file)
    {
        cerr << "File is not open!" << endl;
        return;
    }

    // Variables for file processing
    string line;
    vector<string> fileContents;
    bool deleteSuccessful = false;

    // Process each line in the file
    while (getline(file, line))
    {
        // Check if the line contains the string to delete
        if (line.find(del_str) != string::npos)
        {
            // String found, mark delete operation as successful
            deleteSuccessful = true;
        }
        else
        {
            // String not found, store the line in the vector
            fileContents.push_back(line);
        }
    }

    // Close the file
    file.close();

    if (deleteSuccessful)
    {
        // Open the file "check.txt" for writing
        ofstream outFile("check.txt");
        if (!outFile)
        {
            cerr << "File is not open for writing!" << endl;
            return;
        }

        // Write the modified contents to the file
        for (const auto& line : fileContents)
        {
            outFile << line << endl;
        }

        // Close the file
        outFile.close();
        cout << "Your Text is deleted successfully!" << endl;
    }
    else
    {
        cout << "There is no matching data and text found here!" << endl;
    }
}
//search
void search_Words_string()
{
    // Get the string to search for
    string search_str;
    cout << "Please Enter the string which you want to search: ";
    cin.ignore();
    getline(cin, search_str);

    // Open the file "check.txt" for reading
    ifstream file("check.txt");
    if (!file)
    {
        cerr << "File not open!" << endl;
        return;
    }

    // Variables for file processing
    string line;
    int lineNumber = 0;
    bool found = false;

    // Process each line in the file
    while (getline(file, line))
    {
        lineNumber++;

        // Find the position of the search string in the line
        size_t pos = line.find(search_str);

        // Search for the string in the line
        while (pos != string::npos)
        {
            found = true;
            // Display the position of the string
            cout << "The String is found at position (" << pos + 1 << ", " << lineNumber << ")" << endl;
            // Continue searching for the string in the line
            pos = line.find(search_str, pos + 1);
        }
    }

    // Close the file
    file.close();

    if (!found)
    {
        cout << "There is no String found here!" << endl;
    }
}

void replace_Word_string()
{
    // Get the word to search for and the word to replace with
    string search_Word_str, replace_Word_str;
    cout << "Please Enter the word which you want to search: ";
    cin >> search_Word_str;
    cout << "Please Enter the word which you want to replace with: ";
    cin >> replace_Word_str;

    // Open the file "check.txt" for reading
    ifstream file("check.txt");
    if (!file)
    {
        cerr << "File not open!" << endl;
        return;
    }

    // Variables for file processing
    string line;
    vector<string> fileContents;
    bool found = false;

    // Process each line in the file
    while (getline(file, line))
    {
        // Find the position of the search word in the line
        size_t pos = line.find(search_Word_str);

        // Search for the word in the line
        while (pos != string::npos)
        {
            found = true;
            // Replace the word with the replacement word
            line.replace(pos, search_Word_str.length(), replace_Word_str);
            // Continue searching for the word in the line
            pos = line.find(search_Word_str, pos + replace_Word_str.length());
        }

        // Store the modified line in the vector
        fileContents.push_back(line);
    }

    // Close the file
    file.close();

    if (found)
    {
        // Open the file "check.txt" for writing
        ofstream outFile("check.txt");
        if (!outFile)
        {
            cerr << "File not open for writing!" << endl;
            return;
        }

        // Write the modified contents to the file
        for (const auto& line : fileContents)
        {
            outFile << line << endl;
        }

        // Close the file
        outFile.close();
        cout << "Your Word is replaced successfully!" << endl;
    }
    else
    {
        cout << "There is no match Word found here!" << endl;
    }
}


int main()
{

    fstream suggestion;
    suggestion.open("suggestion.txt", ios::in);
    int opt = -1;
    if (!suggestion)
    {
        cout << "File not found";
    }
    string s;
    // loading a suggestion words from file
    while (!suggestion.eof())
    {
        suggestion >> s;
        tr.collect_information(s);
    }
    suggestion.close();

    cout << "\t\t\t\t\t\t----------------------" << endl;
    cout << "\t\t\t\t\t\tAdvance Notepad System                " << endl;
    cout << "\t\t\t\t\t\t----------------------" << endl;
    cout << endl << endl << endl << endl << endl;
    cout << "\n\n\n\t\t\t\t\t\t    LOADING .";
    Sleep(1000);
    cout << " .";
    Sleep(1500);
    cout << " .";
    system("cls");
    while (opt != 0)
    {

        cout << "                       ------------------------------------------------------------------------  " << endl;
        cout << "                      |         1-> Insert text at any particular position :                   | " << endl;
        cout << "                      |         2-> Delete Text from data :                                    | " << endl;
        cout << "                      |         3-> Search Words from a data :                                 | " << endl;
        cout << "                      |         4-> Copy Text data as string :                                 | " << endl;
        cout << "                      |         5-> Paste Text data as string :                                | " << endl;
        cout << "                      |         6-> Find a Word in data and Replace in given data              | " << endl;
        cout << "                      |         7-> Undo the text :                                            | " << endl;
        cout << "                      |         8-> Count the total words :                                    | " << endl;
        cout << "                      |         9-> suggestion :                                               | " << endl;
        cout << "                      |         10-> Similarity checker data :                                 | " << endl;
        cout << "                      |         11-> Exit                                                      | " << endl;
        cout << "                       ------------------------------------------------------------------------  " << endl;
        cout << endl;


        cout << "\nEnter your choice: ";
        cin >> opt;
        //call function in menu
        if (opt == 1)
        {
            Insert_value();
        }
        else if (opt == 2)
        {
            delete_string_text();
        }
        else if (opt == 3)
        {
            search_Words_string();
        }
        else if (opt == 4)
        {
            copy_string_Text();
        }

        else if (opt == 5)
        {
            paste_string_Text();
        }
        else if (opt == 6)
        {
            replace_Word_string();
        }
        else if (opt == 7)
        {
            undo_text();
        }
        else if (opt == 8)
        {
            count_total_words();

        }
        else if (opt == 9)
        {
            sugesstions_upgrade();
        }
        else if (opt == 10)
        {
            similarity_checker();

        }
        else if (opt == 11)
        {
            cout << "**********" << endl;
            cout << "App closed" << endl;
            cout << "**********" << endl;
            cout << "Good Bye" << endl;
            break;
        }

        system("pause");
        system("cls");
    }
}