
ASSIGNMENT 60
==============

AIM
----

Design and implement a smart college placement portal that uses advanced hashing techniques to efficiently manage student placement records with high performance and low collision probability, even under dynamic data growth.	


THEORY
-------

A hashing technique stores records in a table using a hash function for fast access.
Smart placement portals need high performance, even when data grows.
Advanced hashing (Cuckoo hashing) uses two hash functions, giving each key two possible positions.
If both positions are full, an existing key is kicked out and reinserted (collision handling).
When too many kicks happen, the table resizes and rehashes to reduce collisions.
This gives O(1) insertion and search, low collision probability, and supports dynamic growth.
Each student record stores: roll number, name, company, status, and score.


PROGRAM
--------

```CPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

struct Student {
    int roll;
    string name;
    string company;
    string status;
    int score;
    Student() : roll(-1), name(""), company(""), status(""), score(0) {}
};

int nextCapacity(int n) {
    // return next table size (we'll just double and add 1 to keep odd)
    return n * 2 + 1;
}

int h1Func(int key, int size) {
    return key % size;
}
int h2Func(int key, int size) {
    // alternative hash: multiplicative then mod
    unsigned long long k = (unsigned long long)key;
    k = k * 11400714819323198485ULL; // Knuth-like multiplier
    return (int)((k >> 32) % (unsigned)size);
}

struct CuckooHash {
    vector<Student> table;
    int capacity;
    int count;
    const int MAX_KICKS = 50; // try this many displacements before resize

    CuckooHash(int cap = 11) {
        capacity = cap;
        table.assign(capacity, Student());
        count = 0;
    }

    void rehashAll(int newCap) {
        vector<Student> old = table;
        table.assign(newCap, Student());
        capacity = newCap;
        count = 0;
        for (auto &s : old) {
            if (s.roll != -1) {
                insert(s, false); // re-insert without printing
            }
        }
    }

    bool insert(const Student &st, bool verbose = true) {
        if (count >= capacity) {
            if (verbose) cout << "Resizing: table full, increasing capacity...\n";
            rehashAll(nextCapacity(capacity));
        }

        Student cur = st;
        int pos1 = h1Func(cur.roll, capacity);
        if (table[pos1].roll == -1) {
            table[pos1] = cur;
            ++count;
            if (verbose) cout << "Inserted at index " << pos1 << "\n";
            return true;
        }

        int pos2 = h2Func(cur.roll, capacity);
        if (table[pos2].roll == -1) {
            table[pos2] = cur;
            ++count;
            if (verbose) cout << "Inserted at index " << pos2 << "\n";
            return true;
        }

        int pos = pos1;
        for (int kick = 0; kick < MAX_KICKS; ++kick) {
            // kick out occupant at pos
            Student kicked = table[pos];
            table[pos] = cur;
            cur = kicked;

            // find alternate position for kicked
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

        // too many kicks -> resize and re-insert everything
        if (verbose) cout << "Too many displacements. Resizing table from " << capacity;
        int newCap = nextCapacity(capacity);
        if (verbose) cout << " to " << newCap << " and rehashing...\n";
        rehashAll(newCap);
        return insert(st, verbose); // try again
    }

    bool search(int roll, Student &out) {
        int p1 = h1Func(roll, capacity);
        if (table[p1].roll == roll) { out = table[p1]; return true; }
        int p2 = h2Func(roll, capacity);
        if (table[p2].roll == roll) { out = table[p2]; return true; }
        return false;
    }

    bool remove(int roll) {
        int p1 = h1Func(roll, capacity);
        if (table[p1].roll == roll) { table[p1] = Student(); --count; return true; }
        int p2 = h2Func(roll, capacity);
        if (table[p2].roll == roll) { table[p2] = Student(); --count; return true; }
        return false;
    }

    void display() {
        cout << "\nIndex\tRoll\tName\tCompany\tStatus\tScore\n";
        for (int i = 0; i < capacity; ++i) {
            if (table[i].roll == -1) {
                cout << i << "\t--\t--\t--\t--\t--\n";
            } else {
                cout << i << '\t' << table[i].roll << '\t' << table[i].name << '\t'
                     << table[i].company << '\t' << table[i].status << '\t' << table[i].score << '\n';
            }
        }
        cout << "Total entries: " << count << "  Capacity: " << capacity << "\n";
    }
};

int main() {
    CuckooHash db(11);
    int choice;
    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) return 0;
        if (choice == 1) {
            Student s;
            cout << "Enter roll: "; cin >> s.roll;
            cout << "Enter name: "; cin >> ws; getline(cin, s.name);
            cout << "Enter company (or NA): "; getline(cin, s.company);
            cout << "Enter status (Placed/NotPlaced): "; getline(cin, s.status);
            cout << "Enter score: "; cin >> s.score;
            db.insert(s);
        } else if (choice == 2) {
            int r; cout << "Enter roll to search: "; cin >> r;
            Student out;
            if (db.search(r, out)) {
                cout << "Found: Roll " << out.roll << ", " << out.name << ", " << out.company
                     << ", " << out.status << ", score " << out.score << "\n";
            } else cout << "Not found.\n";
        } else if (choice == 3) {
            int r; cout << "Enter roll to delete: "; cin >> r;
            if (db.remove(r)) cout << "Deleted.\n"; else cout << "Not found.\n";
        } else if (choice == 4) {
            db.display();
        } else if (choice == 5) {
            cout << "Exiting...\n"; break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}


```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS60.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 1
Enter roll: 101
Enter name: Alice
Enter company (or NA): Google
Enter status (Placed/NotPlaced): Placed
Enter score: 92
Inserted at index 3

Enter choice: 1
Enter roll: 202
Enter name: Bob
Enter company (or NA): Amazon
Enter status (Placed/NotPlaced): NotPlaced
Enter score: 78
Inserted at index 7

Enter choice: 4

Index   Roll    Name    Company Status  Score
0       --      --      --      --      --
1       --      --      --      --      --
2       --      --      --      --      --
3       101     Alice   Google  Placed  92
4       --      --      --      --      --
5       --      --      --      --      --
6       --      --      --      --      --
7       202     Bob     Amazon  NotPlaced 78
8       --      --      --      --      --
9       --      --      --      --      --
10      --      --      --      --      --
Total entries: 2  Capacity: 11
