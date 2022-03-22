#include <bits/stdc++.h> // header Files
using namespace std;

struct country // struct is used for user defined data type
{
    // declairing all variables
    string name;
    double population;
    // pointers to point next and previous country
    country *next;
    country *previous;

    country(string Name, double pop) // constructor
    {
        name = Name;
        population = pop;
        next = NULL;
        previous = NULL;
    }
};
struct DoublyLinkedList
{

    country *head;
    int size;

public:
    DoublyLinkedList()
    {
        head = NULL;
        size = 0;
    }
    // Function to insert at begining
    void insert_first(string new_name, double new_population)
    {
        // if not head then make the new node as head
        if (head == NULL)
        {
            head = new country(new_name, new_population);
        }
        // else make new node and insert it at begining
        country *ch = new country(new_name, new_population);
        ch->next = head;
        head->previous = ch;
        head = ch;
        size++;
    }
    // function to add node before a given node
    void insert_before_given_country(string given_country_name, string new_name, double new_population)
    {
        // if size is zero then no node then no addition
        if (size == 0)
        {
            cout << "NOT FOUND" << endl;
        }

        country *temp = head;
        // if  head is given node
        if (temp->name == given_country_name)
        {
            country *insert_new_node = new country(new_name, new_population);
            head->previous = insert_new_node;
            insert_new_node->next = head;
        }
        // variable for checking whether the given node found or not
        bool mila = false;

        while (temp->next)
        {
            if (temp->next->name == given_country_name) // ccondition for checking given name
            {
                mila = true; // if found mark it true
                country *insert_new_node = new country(new_name, new_population);
                insert_new_node->next = temp->next;
                insert_new_node->previous = temp;
                temp->next = insert_new_node;
            }
            temp = temp->next;
        }
        if (!mila) // if not found then simply print not found
            cout << "NOT FOUND\n";
    }
    // function to print alternative elements
    void print_alternative_country()
    {

        country *temp = head;
        while (temp && temp->next)
        {
            cout << temp->name << "," << temp->population << " million  ";
            temp = temp->next->next;
        }
    }
    // function to calculate total population
    void calculate_total_population()
    {
        double ans = 0;

        country *temp = head;
        while (temp->next)
        {

            ans += temp->population;
            cout << ans << endl;
            temp = temp->next;
        }
        cout << ans << " million" << endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insert_first("india", 10);

    dll.insert_first("usa", 0);

    dll.insert_first("china", 30);
    dll.insert_first("bangla", 40);
    dll.insert_first("australia", 50);
    dll.print_alternative_country();
    return 0;
}
