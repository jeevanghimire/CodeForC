#include <iostream>
#include <vector>
#include <algorithm>  // For max and min
using namespace std;

class FuzzySet {
    vector<pair<int, double> > elements;

public:
    FuzzySet(const vector<pair<int, double> >& elems) : elements(elems) {}

    FuzzySet unionSet(const FuzzySet& other) {
        vector<pair<int, double> > result;
        for (size_t i = 0; i < elements.size(); ++i)
            result.push_back(make_pair(elements[i].first, max(elements[i].second, other.elements[i].second)));
        return FuzzySet(result);
    }

    FuzzySet intersectionSet(const FuzzySet& other) {
        vector<pair<int, double> > result;
        for (size_t i = 0; i < elements.size(); ++i)
            result.push_back(make_pair(elements[i].first, min(elements[i].second, other.elements[i].second)));
        return FuzzySet(result);
    }

    FuzzySet complementSet() {
        vector<pair<int, double> > result;
        for (size_t i = 0; i < elements.size(); ++i)
            result.push_back(make_pair(elements[i].first, 1.0 - elements[i].second));
        return FuzzySet(result);
    }

    void display() const {
        for (size_t i = 0; i < elements.size(); ++i)
            cout << "Element: " << elements[i].first << ", Membership: " << elements[i].second << endl;
    }
};

int main() {
    vector<pair<int, double> > setA, setB;

    // Manually inserting elements
    setA.push_back(make_pair(1, 0.5));
    setA.push_back(make_pair(2, 0.7));
    setA.push_back(make_pair(3, 0.2));

    setB.push_back(make_pair(1, 0.6));
    setB.push_back(make_pair(2, 0.4));
    setB.push_back(make_pair(3, 0.9));

    FuzzySet fuzzySetA(setA), fuzzySetB(setB);

    cout << "Union of A and B:\n"; fuzzySetA.unionSet(fuzzySetB).display();
    cout << "Intersection of A and B:\n"; fuzzySetA.intersectionSet(fuzzySetB).display();
    cout << "Complement of A:\n"; fuzzySetA.complementSet().display();

    return 0;
}
