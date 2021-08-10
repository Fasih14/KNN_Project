#include<iostream>
#include<cmath>
using namespace std;

void display_Arr(int arr[],int size)
{
    int index;
    for(index=0;index<size;index++)
    {
        cout<<arr[index]<<" ";
    }
}
float euclidean_Distance(float x1,float x2,float y1,float y2)
{
    float x;
    float y;
    float sqr;
    x=x2-x1;
    y=y2-y1;
    x=pow(x,2);//power function to find square
    y=pow(y,2);//power function to find square
    sqr=x+y;
    sqr=sqrt(sqr);//square root function
    return sqr;
}
void table(float x1,float batting_Avg_x2[],float y1 ,float bowling_Avg_y2[],float Distance[])
{
    int index;
    float result=0;
    float x2,y2;
    for(index=0;index<11;index++)
    {
        x2=batting_Avg_x2[index];
        y2=bowling_Avg_y2[index];
        result=euclidean_Distance(x1,x2,y1,y2);
        Distance[index]=result;
        cout<<result<<" ";												//(Optional)
    }
}

void bubble_Sort(float arr[], int size)
{
	for (int i = 0;i < size-1;i++)
    {
        for (int j = 0;j <size-1 ;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void min_Order(float distance[],float order[])
{

    float copied_Arr[11]={};
    int index;
    for(index=0;index<11;index++)
    {
        copied_Arr[index]=distance[index];         //coping Array
    }
    bubble_Sort(copied_Arr,11);                   //sorting copied Array
    cout<<endl;										//(optional)
	for(index=0;index<11;index++)                //index ==for copied array           //index1 for equiline distance array
    {
        for(int index1=0;index1<11;index1++)        //minimum orde sortng index only
            {
                if(copied_Arr[index]==distance[index1]&&distance[index1]!=-1)
                {
                    order[index]=index1;
                   cout<<order[index]<<" ";             //(Optional)
                    distance[index1]=-1;
                }
            }
    }
	cout<<endl;											//(Optional)
}

void approximate_Attributes(float order[],float label[],int k)
{
	int Batsman=0;
	int Bowler=0;
	int Allrounder=0;
	for(int order_index1=0;order_index1<k;order_index1++)
	{
	for(int label_index=0;label_index<11;label_index++)
	{
		if(order[order_index1]==label_index)
		{
			if(label[label_index]==0)
			{
				Batsman++;                    //for Batsman=0
			}
			else if(label[label_index]==1)
			{
				Bowler++;                  //for Bowler=1
			}
			else if(label[label_index]==2)
			{
				Allrounder++;             //for Allrounder=2

			}
		}
	}

}
	cout<<"If value of 'k' is "<<k<<"."<<endl;
	cout<<"Allrounder:"<<Allrounder<<endl;
	cout<<"Batsman:"<<Batsman<<endl;
	cout<<"Bowler:"<<Bowler;

	cout<<endl;
	if(Allrounder>=Batsman&&Allrounder>=Bowler)
	{
		{
			cout<<"New player is Allrounder."<<endl<<endl;
		}
	}
	else if(Bowler>Batsman)
	{
		{
			cout<<"New player is Bowler."<<endl<<endl;
		}
	}
	else if(Batsman>Bowler)
	{
		{
			cout<<"New Player is Batsman."<<endl<<endl;
		}
	}
}

int main()
{
    float x1,bat_avg_x2[11] = {16,39,15,33,38,18,28,37,32,35,36};
    float y1,bowl_avg_y2[11] = {33,47,37,35,43,31,37,39,38,32,46};
    float label[11] = {1,0,1,2,0,1,2,0,0,2,0};
    float Distance[11]={0};
    float order[11]={0};
    float result=0;

    cout<<"x 1:";
    cin>>x1;
    cout<<"y 1:";
    cin>>y1;

	table(x1,bat_avg_x2,y1,bowl_avg_y2,Distance);
    min_Order(Distance,order);
    cout<<endl;
    	//k=5
    approximate_Attributes(order,label,5);
	    //k=7
    approximate_Attributes(order,label,7);
    	//k=9
	approximate_Attributes(order,label,9);
		//k=11
    approximate_Attributes(order,label,11);
}
