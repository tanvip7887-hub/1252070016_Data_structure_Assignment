/*Design and implement a smart college placement portal that uses advanced hashing techniques to efficiently manage student placement records 
with high performance and low collision probability, even under dynamic data growth.	*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

struct Student 
{
    int roll;
    string name;
    string company;
    string status;
    int score;
    Student() : roll(-1), name(""), company(""), status(""), score(0) {}
};

int nextCapacity(int n) 
{
   
    return n * 2 + 1;
}

int h1Func(int key, int size) {

    return key % size;
}

int h2Func(int key, int size) 
{
    unsigned long long k = (unsigned long long)key;
    k = k * 11400714819323198485ULL; 
    return (int)((k >> 32) % (unsigned)size);
}

struct CuckooHash 
{
    vector<Student> table;
    int capacity;
    int count;
    const int MAX_KICKS = 50; 

    CuckooHash(int cap = 11) 
    {
        capacity = cap;
        table.assign(capacity, Student());
        count = 0;
    }

    void rehashAll(int newCap) 
    {
        vector<Student> old = table;
        table.assign(newCap, Student());
        capacity = newCap;
        count = 0;

        for (auto &s : old) 
        {
            if (s.roll != -1) 
            {
                insert(s, false); 
            }
        }
    }

    bool insert(const Student &st, bool verbose = true) 
    {
        if (count >= capacity) 
        {
            if (verbose) cout << "Resizing: table full, increasing capacity...\n";
            rehashAll(nextCapacity(capacity));
        }

        Student cur = st;
        int pos1 = h1Func(cur.roll, capacity);
        if (table[pos1].roll == -1) 
        
            table[pos1] = cur;
            ++count;
            if (verbose) cout << "Inserted at index " << pos1 << "\n";
            return true;
        }

        int pos2 = h2Func(cur.roll, capacity);
        if (table[pos2].roll == -1) 
        {
            table[pos2] = cur;
            ++count;
            if (verbose) cout << "Inserted at index " << pos2 << "\n";
            return true;
        }

        int pos = pos1;
        for (int kick = 0; kick < MAX_KICKS; ++kick)
        {
            Student kicked = table[pos];
            table[pos] = cur;
            cur = kicked;

            int alt1 = h1Func(cur.roll, capacity);
            int alt2 = h2Func(cur.roll, capacity);
            pos = (pos == alt1) ? alt2 : alt1;

            if (table[pos].roll == -1) {
                table[pos] = cur;
                ++count;
                if (verbose) cout << "Inserted after kicks at index " << pos << "\n";
                return true;
            }
        }

        if (verbose) cout << "Too many displacements. Resizing table from " << capacity;
        int newCap = nextCapacity(capacity);
        if (verbose) cout << " to " << newCap << " and rehashing...\n";
        rehashAll(newCap);
        return insert(st, verbose);
    }

    bool search(int roll, Student &out) 
    {
        int p1 = h1Func(roll, capacity);
        if (table[p1].roll == roll) 
        {
             out = table[p1]; 
             return true; 
        }

        int p2 = h2Func(roll, capacity);

        if (table[p2].roll == roll) 
        { 
            out = table[p2]; 
            return true; 
        }

        return false;
    }

    bool remove(int roll) 
    {
        int p1 = h1Func(roll, capacity);
        if (table[p1].roll == roll) 
        {
             table[p1] = Student(); 
             --count; 
             return true; 
        }

        int p2 = h2Func(roll, capacity);

        if (table[p2].roll == roll) 
        { 
            table[p2] = Student();
            --count; 
            return true; 
        }

        return false;
    }

    void display() 
    {
        cout << "\nIndex\tRoll\tName\tCompany\tStatus\tScore\n";
        for (int i = 0; i < capacity; ++i) {

            if (table[i].roll == -1) 
            {
                cout << i << "\t--\t--\t--\t--\t--\n";
            } 
            else 
            {
                cout << i << '\t' << table[i].roll << '\t' << table[i].name << '\t'
                     << table[i].company << '\t' << table[i].status << '\t' << table[i].score << '\n';
            }
        }
        cout << "Total entries: " << count << "  Capacity: " << capacity << "\n";
    }

int main() 
{
    CuckooHash db(11);
    int choice;

    while (true) 
    {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) 
            return 0;

        if (choice == 1) 
        {
            Student s;
            cout << "Enter roll: "; cin >> s.roll;
            cout << "Enter name: "; cin >> ws; getline(cin, s.name);
            cout << "Enter company (or NA): "; getline(cin, s.company);
            cout << "Enter status (Placed/NotPlaced): "; getline(cin, s.status);
            cout << "Enter score: "; cin >> s.score;
            db.insert(s);
        } 
        else if (choice == 2) 
        {
            int r; cout << "Enter roll to search: "; cin >> r;
            Student out;

            if (db.search(r, out)) 
            {
                cout << "Found: Roll " << out.roll << ", " << out.name << ", " << out.company
                     << ", " << out.status << ", score " << out.score << "\n";
            } 
            else cout << "Not found.\n";

        } 
        else if (choice == 3) 
        {
            int r; cout << "Enter roll to delete: "; cin >> r;
            if (db.remove(r)) 
                cout << "Deleted.\n"; else cout << "Not found.\n";
        } 
        else if (choice == 4) 
        {
            db.display();
        } 
        else if (choice == 5) 
        {
            cout << "Exiting...\n"; break;
        } 
        else 
        {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}
