#include<iostream>
#include<algorithm>
#include<conio.h>
using namespace std;

struct process
{
	int id,at,bt,priority,stat;
}
pro[100];
bool compare(process a, process b)
{
	return a.at < b.at;
}

int main()
{
	int l,i;
	cout<<"Enter the number of processes you require:\n";
	cin>>l;
	
	
	cout<<"Enter the arrival time of each process you want to enter:\n";
	for(i=0;i<l;i++)
	{
		cout<<"Enter the arrival time (at) of Process"<<i+1<<":"<<endl;
		cin>>pro[i].at;
		pro[i].id = i+1;
	}

	cout<<"Enter the burst time (bt) of each process you have entered already:\n";
	for(i=0;i<l;i++)
	{
		cout<<"Enter the burst time of P"<<i+1<<":"<<endl;
		cin>>pro[i].bt;
	}
	
	cout<<"Enter the priority of each process you have choosed:\n";
	for(i=0;i<l;i++)
	{
		cout<<"Enter the priority of Process"<<i+1<<":"<<endl;
		cin>>pro[i].priority;
	}
	
	for(i=0;i<l;i++)
		pro[i].stat = 0;
		
	sort(pro, pro+l, compare);	
	
	
	int time = 0;			
	int count = 0, count2 = 0;
	i=0;
	while(count!=l)
	{
		if(pro[i].stat!=1 && pro[i].stat!=2)
		{	
			cout<<"Processing "<<pro[i].id<<endl;
			for(int j=i+1;j<l;j++)
			{
				if(pro[j].stat!= 1 && pro[j].stat!=2 && (pro[j].priority < pro[i].priority) && (pro[j].at <= time))
				{
					cout<<"Process P"<<pro[i].id<<" is interuppted by P"<<pro[j].id<<".Pushing it into queue2"<<endl;
					cout<<"Process P"<<pro[j].id<<" is processing"<<endl;
					pro[i].stat = 2;
					count2++;
					time += pro[j].bt;
					pro[j].stat = 1;
					cout<<"Process P"<<pro[j].id<<" is completely processed"<<endl;
					count += 2;
					break;
				}
			}
			if(pro[i].stat != 2)
			{
				time += pro[i].bt;
				pro[i].stat = 1;
				cout<<"Process P"<<pro[i].id<<" is completely processed"<<endl;
				count++;
			}
		}
		i = (i+1)%l;
	}
	
	int tq = 2;
	time = 0;
	count = 0;
	
	cout<<"Executing Queue2"<<endl;
	
	i=0;
	while(count != count2)
	{
		if(pro[i].stat == 2)
		{
			if(pro[i].bt<2)
			{
				pro[i].bt -= 1;
				time += 1;
				pro[i].stat = 1;
				cout<<"Completed P"<<pro[i].id<<endl;
				count++; 
			}
			else
			{
				pro[i].bt -= 2;
				time += tq;
				cout<<"Processing P"<<pro[i].id<<endl;
			}
		}
		i = (i+1)%l;
	}
			
	return 0;
}
