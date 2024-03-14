#include <iostream>
#include <algorithm>
using namespace std;
 
struct process{
  int arr_time,proc_time,response_time,turnaround_time,delay;
  char name_proc;
};

void insert_proc(process proc[],int num){
  for(int i=0;i<num;i++)
    cin>>proc[i].name_proc>>proc[i].arr_time>>proc[i].proc_time;
}


bool compare1(process proc1,process proc2){
  return proc1.arr_time<proc2.arr_time;
}

bool compare2(process proc1,process proc2){
  return proc1.proc_time>proc2.proc_time;
}


void Work(process proc[],int n){
    
    sort(proc,proc+n,compare2);
    sort(proc,proc+n,compare1);
    
    int time=0,i;
    int j,Proc_Time[n];
    for(i=0;i<n;i++){
        j=i;
        while(proc[j].arr_time<=time&&j!=n){
            j++;
        }
        sort(proc+i,proc+j,compare2);
        time+=proc[i].proc_time;
        Proc_Time[i]=time;
    }
    Proc_Time[i] = time;
    
    for (i=0; i<n; i++){
        cout<<proc[i].name_proc<<": ("<<"response="<<(Proc_Time[i]-proc[i].arr_time)-proc[i].proc_time<<", turnaround="<<Proc_Time[i]-proc[i].arr_time<<", delay="<<(Proc_Time[i]-proc[i].arr_time)-proc[i].proc_time<<")\n";
    }
    for (i=0; i<n; i++){
        cout<<proc[i].name_proc;
    }
    
}

int main() {
    
  long num;
  cin>>num;
  process proc[num];
  insert_proc(proc,num);
  cout<<"\n";
  Work(proc,num);
  
return 0;
}