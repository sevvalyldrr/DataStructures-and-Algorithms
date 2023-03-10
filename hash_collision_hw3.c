#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct hash
{
    int key;
    int data;
};

struct hash *array;
struct hash *array1;

int capacity = 100;
int size = 0;
int countLinear=0;
int countQuadratic=0;

int division(int key)
{
    return (key % capacity);
}


void init_array()
{
    int i;
    
    array = (struct hash *)malloc(capacity * sizeof(struct hash));
    array1 = (struct hash *)malloc(capacity * sizeof(struct hash));

    for (i = 0; i < capacity; i++)
    {
        array[i].key = 0;
        array[i].data = 0;

        array1[i].key = 0;
        array1[i].data = 0;
    }
}

void linearProbing(int key)
{
    int i;
    countLinear++;

    for (i = key % capacity; i < capacity; i++)
    {

        if (array[i].data == 0)
        {
           
            array[i].key = key;
            array[i].data = 1;
            size++;
            break;
        }
        if (i == capacity - 1)
        {
            i = 0;
        }
        if (size == capacity)
        {
            break;
        }
    }
}

void quadraticProbing(int key)
{
    countQuadratic++;
    int i;
    for (i = 0; i < capacity; i++)
    {
        int m = (division(key) + (i * i)) % capacity;
        if (array1[m].data != 0)
        {
            countQuadratic++;   
            continue;
        }
        else if (array1[m].data == 0)
        {
            array1[m].key = key;
            array1[m].data = 1;
            size++;
            break;
        }
        if (i == capacity - 1)
        {
            i = 0;
        }
    }
}


void insert(int key)
{
    int index = division(key);
    if (array[index].data == 0)
    {
        /*  key not present, insert it  */
        array[index].key = key;
        array[index].data = 1;
        array1[index].key = key;
        array1[index].data = 1;
        size++;
        // printf("\n Key (%d) has been inserted \n", key);
    }
    else if (array[index].key == key)
    {
        /*  updating already existing key  */
        printf("\n Key (%d) already present, hence updating its value \n", key);
        array[index].data += 1;
    }
    else
    {
        /*  key cannot be insert as the index is already containing some other key  */
        // call the collisicon solver functions

        // printf("\n ELEMENT CAN NOT BE INSERTED \n");
        linearProbing(key);
        quadraticProbing(key);
    }
}


/* to display all the elements of a hash table */
void display()
{
    int i;
    for (i = 0; i < capacity; i++)
    {
        if (array[i].data == 0)
        {
            printf("\n Array[%d] has no elements \n", i);
        }
        else
        {
            printf("\n Array[%d] has elements -:\n key(%d) and data(%d) \t\n", i, array[i].key, array[i].data);
        }
    }
     printf("----------------------------\n");
    printf("number of collisions: %d",countLinear);
    printf("----------------------------\n");
    for (i = 0; i < capacity; i++)
    {
        if (array[i].data == 0)
        {
            printf("\n Array[%d] has no elements \n", i);
        }
        else
        {
            printf("\n Array[%d] has elements -:\n key(%d) and data(%d) \t\n", i, array1[i].key, array1[i].data);
        }
    }
    printf("----------------------------\n");
    printf("number of collisions: %d",countQuadratic);

}

int size_of_hashtable()
{
    return size;
}

void main()
{
    int choice, key, data, n, c;
    srand(time(NULL));

    init_array();

    do
    {
        printf("\n Implementation of Hash Table in C \n\n");
        printf("MENU-:  \n1.Inserting item in the Hash Table"
               "\n2.Check the size of Hash Table"
               "\n3.Display a Hash Table"
               "\n\n Please enter your choice -:");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Inserting element in Hash Table\n");
            for (int i = 0; i < capacity; i++)
            {
                key = rand();
                insert(key);
            }
            display();

            break;

        case 2:

            n = size_of_hashtable();
            printf("Size of Hash Table is-:%d\n", n);

            break;

        case 3:

            display();

            break;

        default:

            printf("Wrong Input\n");
        }

        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);

    } while (c == 1);

    getch();
}
