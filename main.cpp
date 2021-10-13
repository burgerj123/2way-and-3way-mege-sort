/* 
 * File:   main.cpp
 * Author: Jackson Burger
 *
 * Created on July 5, 2021, 11:50 AM
 */

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int MAX = 500000;
void merge_sort(int data[], int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      merge_sort(data, low, mid);
      merge_sort(data, mid + 1, high);

      // Create temporary array for merged data
      int *copy = new int[range];

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	 if (data[index1] < data[index2])
	    copy[index++] = data[index1++];
	 else
	    copy[index++] = data[index2++];
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
	 copy[index++] = data[index1++];

      // Copy any remaining entries from the second half
      while (index2 <= high)
	 copy[index++] = data[index2++];

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
	 data[low + index] = copy[index];
      delete []copy;
   }
}

void merge_3sort(int data[], int low, int high)
{
    int range = high - low + 1;   
    if (range == 2)
    {
       if (data[low] > data[high])
       {
           int temp = data[low];
           data[low] = data[high];
           data[high] = temp;
       }
    }
    else if (range > 2)
    {
        int mid1 = low + ((high - low) / 3); 
        int mid2 = low + 2*((high - low) / 3) + 1;         
        merge_3sort(data, low, mid1); 
        merge_3sort(data, mid1 + 1, mid2); 
        merge_3sort(data, mid2 + 1, high);  
        
        int *copy = new int[range];
        int index = 0;
        int index1 = low;
        int index2 = mid1 + 1;
        int index3 = mid2 + 1;
        
        while ((index1 <= mid1) && (index2 <= mid2) && (index3 <= high)) //while none of the indexes cross into the next array
        { 
            if(data[index1] < data[index2]) //Compares the first two arrays and then increments for the one that is smaller
            {
                if(data[index1] <= data[index3]) //Checks 1st array with 3rd array
                    copy[index++] = data[index1++];
                else
                    copy[index++] = data[index3++];
            }
            else                            //2nd array value greater than 1st array
            {
                if(data[index2] <= data[index3]) //Checks 2nd array with 3rd array
                    copy[index++] = data[index2++];
                else
                    copy[index++] = data[index3++];
            }
        } 
  
        //1st and 2nd arrays have values still but 3rd is finished
        while ((index1 <= mid1) && (index2 <= mid2)) 
        { 
            if(data[index1] <= data[index2])
                copy[index++] = data[index1++];
            else
                copy[index++] = data[index2++];
        } 
  
        // 2nd and 3rd arrays have values till but 1st is finished
        while ((index2 <= mid2) && (index3 <= high)) 
        { 
            if(data[index2] <= data[index3])
                copy[index++] = data[index2++];
            else
                copy[index++] = data[index3++];
        } 
  
        //1st and third arrays have values still but 2nd is finished
        while ((index1 <= mid1) && (index3 <= high)) 
        { 
            if(data[index1] <= data[index3])
                copy[index++] = data[index1++];
            else
                copy[index++] = data[index3++];
        } 
  
        //Copy any remaining entries from the 1st array
        while (index1 <= mid1) 
            copy[index++] = data[index1++]; 

        //Copy any remaining entries from the 2nd array
        while (index2 <= mid2) 
            copy[index++] = data[index2++]; 

        //Copy any remaining entries from the 3rd array
        while (index3 <= high) 
            copy[index++] = data[index3++]; 
        
        for (index = 0; index < range; index++) //Move all data from temporary array into the actual data array
            data[low + index] = copy[index];
          delete []copy;
     }        
}

// Extra code that was a potential solution
void merge_3Asort(int data[], int low, int high)
{
    int range = high - low + 1;   
    if (range == 2)
    {
       if (data[low] > data[high])
       {
           int temp = data[low];
           data[low] = data[high];
           data[high] = temp;
       }
    }
    else if (range > 2)
    {
        int mid1 = low + ((high - low) / 3); 
        int mid2 = low + 2*((high - low) / 3) + 1;         
        merge_3Asort(data, low, mid1); 
        merge_3Asort(data, mid1 + 1, mid2); 
        merge_3Asort(data, mid2 + 1, high);  
        
int *temp = new int[range];

int index = 0;

int index1 = low;

int index2 = mid1 + 1;

int index3 = mid2 + 1;




while (index1 <= mid1 || index2<=mid2 || index3<=high)
{

if ((index1<=mid1) && (index2 > mid2 || data[index1]
<= data[index2]) && (index3>high || data[index1]
<= data[index3]))

temp[index++] = data[index1++];

else if (index2<=mid2 && (index1 > mid1
|| data[index2] <= data[index1]) && (index3>high
|| data[index2] <= data[index3])) 

temp[index++] = data[index2++];

else if (index3<=high && (index1 > mid1
|| data[index3] <= data[index1]) && (index2>mid2
|| data[index3] <= data[index2])) 

temp[index++] = data[index3++];

}




for (index = 0; index < range; index++)

{

data[low+index] = temp[index];

}

delete [] temp;
     }        
}

void create_random_data(int data[], const int count, const int range)
{
   // Put specified count of random numbers into data array
   for (int index = 0; index < count; index++)
      data[index] = rand() % range;
}

void print(int data[], const int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int countF()
{   
    int value = 0;
    cout << "How many values would you like to include? (0-500000)" << endl;
    cin >> value;
    while (value < 0 || value > MAX)
    {
        cout << "Please enter a more suitable number (0-500000)";
        cin >> value;
    }
    return value;
}

int rangeF()
{
    int range = 0;
    cout << "What range would you like to use? (0-500000)" << endl;
    cin >> range;
    while (range < 0 || range > MAX)
    {
        cout << "Please enter a more suitable range (0-500000)";
        cin >> range;
    }
    return range;
}

void outputFile(int data[], const int count,const string filename)
{
    ofstream outfile;
    outfile.open(filename); //Creates a text file
    if (outfile.is_open())
    {    
        for (int i = 0; i < count; i++)
        {
            outfile << data[i] << " ";
        }
    }
}
int main()
{
    int data[500000];
    int count = 0;
    int range = 0;
    int answer = 0;
    
    while (answer != 3)
    {
        cout << "What would you like to do?" << endl
         << "1. Merge Sort" << endl << "2. 3-way Merge Sort" << endl 
         << "3. Quit" << endl;
        cin >> answer;
        switch (answer)
        {
            case 1:
            {
                count = countF();
                range = rangeF();
                create_random_data(data,count,range);
                outputFile(data,count,"unsorted.txt");               
                clock_t time1=clock();
                merge_sort(data,0,count);
                clock_t time2=clock();
                double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
                outputFile(data,count,"sorted.txt");
                cout << "Merge sort with a range " << range << " and count " << count
                     << " ran at a time of " << run_time << " seconds" << endl;                
                break;
            }

            case 2:
            {
                count = countF();
                range = rangeF();
                create_random_data(data,count,range);
                //print(data,count);
                outputFile(data,count,"unsorted.txt");               
                clock_t time1=clock();
                merge_3Asort(data,0,count);
                //print(data,count);
                clock_t time2=clock();
                double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
//                merge_sort(data,0,count);
                outputFile(data,count,"sorted.txt");
                cout << "3 way merge sort with a range " << range << " and count " << count
                     << " ran at a time of " << run_time << " seconds" << endl;
                break;
            }

            case 3:
            {
                break;
            } 
            default:
            {
                cout << "Improper input";
            }
        }
    }
    return 0;
}
