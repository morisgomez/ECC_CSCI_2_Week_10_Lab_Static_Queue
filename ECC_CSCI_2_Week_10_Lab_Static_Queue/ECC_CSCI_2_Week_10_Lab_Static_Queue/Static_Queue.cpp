/*
 Program Name: Static_Queue.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/14/2024
 Version Control: 6.0
 About: Week 10, CSCI 2, Lab.
 Description:
 Write a program that reads 2 sentences & reads them
 into 2 separate queues. The program should then
 determine whether the sentences are identical by
 comparing the characters in the queues. When 2
 non-identical characters are encountered, the
 program should display a message indicating that the
 sentences are not the same. If both queues contain
 the same set of characters, message should be
 displayed indicating that the sentences are
 identical.
*/

#include <iostream>
#include <string>
using namespace std;

//create class StringQueue:
class StringQueue
{
private:
    char *qArray; //holds the address of the array //used to access it via pointer.
    long int qSize; //holds size of the array //how many elements or indexes should it hold?
    long int front; //holds the index of the front value in array.
    long int rear; //holds the index of the rear value in array.
    long int numItems; //holds the number values? # of indexes with an actual value.
    
public:
//FUNCTION 1. constructor:
    StringQueue(long int size)
    {
        qArray = new char[size];
        front = -1;
        rear = -1;
        numItems = 0;
        qSize = size;
    } //end constructor.
    
//FUNCTION 2. enqueue():
    void enqueue(char ch)
    {
        if(isFull()) //if array is full, no space to insert a value at rear.
        {
            cout << "QUEUE IS FULL, NO SPACE TO ADD NEW VALUES!" << endl;
        }
        else //if not full, space to insert new value at rear.
        {
            rear = (rear + 1) % qSize; //determines new rear (where we insert new value).
            qArray[rear] = ch; //the value located at qArray[rear] is assigned to num.
            //NOTE: cannot enqueue to to array w/ empty elemetns in the middle (cannot cut line).
            //NOTE: works only for array w/ empty values at left and right.
            numItems = numItems + 1;
        }
    } //end enqueue() function.

//FUNCTION 3. dequeue():
    void dequeue(char &ch) //changes to num in local function scope appear in main.
    //num has the value we want to remove.
    {
        if(isEmpty()) //if array empty, nothing to remove.
        {
            cout << "QUEUE IS EMPTY, NOTHING TO REMOVE!" << endl;
        }
        else //if array has some values, return num from front which is removed.
        {
            //special case. one element in array:
            if(front == rear)
            {
                ch = qArray[front]; //num gets value of only index bc the only we can delete.
                front = -1; //reset to array w/ no values so -1 is front & rear.
                rear = -1;
                numItems = 0; //reset num items to zero.
            }
            else //remove value stored in front element:
            {
                ch = qArray[front];
                front = (front + 1) % qSize; //new front.
                numItems = numItems - 1;
            } //end inner else.
        } //end outer else.
    } //end dequeue() function.

//FUNCTION 4. isEmpty():
    bool isEmpty() const //const bc no need to change anything in func.
    {
        if(numItems == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    } //end isEmpty() function.

//FUNCTION 5. isFull():
    bool isFull() const
    {
        if(numItems < qSize)
        {
            return false;
        }
        else
        {
            return true;
        }
    } //end isFull() function.
    
//FUNCTION 6. clear():
    void clear()
    {
        front = qSize - 1; //will be at last index.
        rear = qSize -1; //will be at last index.
        numItems = 0;
    } //end clear() function.
//FUNCTION 7. check();
    //pass in an array as argument.
    

//FUNCTION 7. display():
    void display()
    {
        if(numItems == 0)
        {
            cout << "The Queue is empty!" << endl;
        }
        else
        {
            cout << "------queue info so far:------" << endl;
            cout << "size of array: " << qSize <<endl;
            cout << "num of items: " << numItems << endl;
            cout << "front: " << front << endl;
            cout << "rear: " << rear << endl;
            
            for(int i = 0; i < qSize; i++)
            {
                cout << "index " << i << " has value of: " << qArray[i] << endl;
            } //end for loop.
            cout << "------------------------------" << endl;
        } //end else.
    } //end display() function.

}; //close IntQueue class.




int main()
{
    
    //1. make 2 strings.
    string sOne;
    cout << "Enter sentence 1:";
    getline(cin, sOne);
    
    string sTwo;
    cout << "Enter sentence 2:";
    getline(cin, sTwo);
    //2. store size of each string.
    long int sizeStringOne = sOne.size();
    long int sizeStringTwo = sTwo.size();

    //3. create a queue for each string.
    StringQueue qOne(sizeStringOne);
    StringQueue qTwo(sizeStringTwo);
    
    //4. push string characters to corresponding queue.
    //a. for string one:
    for (int i = 0; i < sizeStringOne; i++)
    {
        qOne.enqueue(sOne[i]);
    }
    
    //b. for string two:
    for (int j = 0; j < sizeStringTwo; j++)
    {
        qTwo.enqueue(sTwo[j]);
    }
    
    //5. check for queues to be full.
    qOne.display();
    qTwo.display();
    
    //6. logic to determine if strings are identical:
    int index = 0;
    
    if(sizeStringOne != sizeStringTwo)
    {
        cout << "sentences are not identical" << endl;
    }
    else
    {
        while(index < sizeStringOne && sOne[index] == sTwo[index])
        {
            index++;
        }
        if(sOne[index] != sTwo[index])
        {
            cout << "sentences are not identical" << endl;
        }
        else
        {
            cout << "sentences are identical" << endl;
        }
    } //end outer else.
    return 0;
} //end main function.
