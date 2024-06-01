#include <bits/stdc++.h>
using namespace std;

class Office
{
    string HigestPersonalName;
    int rooms;
    string NameofOfficers[10];
    int chairs;
    int NumberofWorkers;

public:
    void AcessOfficeInfo(string MainPersonName,int roomss, int chairs_i, int NumberofWorkers_i)
    {
        HigestPersonalName = MainPersonName;
        rooms = roomss;
        chairs = chairs_i;
        NumberofWorkers = NumberofWorkers_i;
        cout<<HigestPersonalName<<endl<<rooms<<endl<<chairs<<endl<<NumberofWorkers<<endl;
    }
};

int main()
{
    Office WardOffice,NagarOffice,PMOffice;
    WardOffice.AcessOfficeInfo("Jeevan",3,3,8);
    return 0;
}