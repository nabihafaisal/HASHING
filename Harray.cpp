#include <iostream>
using namespace std;
class Harray
{

    int size;
    int *array;
    
public:
    Harray(int s)
    {
        this->size = s;

        array = new int[s];
    };

    void makingArrayNull()    // // array have garbage value so we initialize all values of array with -1
    {

        cout << "____WE ARE INITIALIZING ALL ARRAY VALUES TO -1____" << endl;

        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
            cout << "array[" << i << "] => " << array[i] << endl;
        }
    }

    int hashindex(int key)
    {

        return key % size;
    }

    void insert(int value)
    {

        int ht = hashindex(value);

        if (array[ht] == -1)          //  no collision
        {
            array[ht] = value;
        }
  //      collusion happened
        else{
            while (array[ht]!=-1){//if index is not empty
            
                
                ht=(ht+1)%size;//move to empty inde
                   
            }
             array[ht]=value;
                ht++; 
            
        }
    }

    void display()
    {
        cout << "_____DISPLAY ARRAY_____" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "hashtable[" << i << "] =>" << array[i] << endl;
        }
    }
};

int main()
{
    Harray hashing(5);
    hashing.makingArrayNull();

    hashing.insert(15);
    hashing.insert(11);
    hashing.insert(34);
    hashing.insert(21);
    hashing.insert(33);
    hashing.display();

    return 0;
}
