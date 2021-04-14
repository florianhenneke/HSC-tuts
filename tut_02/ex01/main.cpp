// test class PrioQueue

#include "prioQueue.h"

int main()
{
   PrioQueue pq, pq2;
   char choice;
   int prio;
   string s, a;
  
   pq2.insert(10, "test1");
   pq2.insert(11, "test2", "illness1");

   cout << "\n\t********  waiting patients"<< "*******\n";
   pq2.display();
  
   pq=pq2;
  
   pq.deleteMax(s);
   if( s == "")
     cout << "\n\tNo patient." << endl;
   else
     cout << "\n\tNext patient: Mr/Ms " << s << endl;
   pq.deleteMax(s);
   if( s == "")
     cout << "\n\tNo patient." << endl;
   else
     cout << "\n\tNext patient: Mr/Ms " << s << endl;
   pq.deleteMax(s);
   if( s == "")
     cout << "\n\tNo patient." << endl;
   else
     cout << "\n\tNext patient: Mr/Ms " << s << endl;
  
    return 0;
}


