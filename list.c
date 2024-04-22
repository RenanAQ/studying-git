#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* list = malloc(3 * sizeof(int)); //This is the same thing as: int list[3];

    //checking if it is out of memory (Segmentation Fault)
    if (list == NULL)
    {
        return 1;
    }
    

    *list = 1; // This is the same as: list[0] = 1;
    *(list+1) = 2; //same as: list[1] = 2;
    *(list+2) = 3; //same as: list[2] = 3;

    //In case I need more space in my array
    int* tmp = malloc(4 * sizeof(int)); //we can't use int* list again because it would leak memory*/
    
    printf("Address: %p\n", &tmp);
    if (tmp == NULL)
    {
        free(list); //Before breaking the code, i need to free the memory alloc of the first malloc
        return 1;
    }
    
     for (int i = 0; i < 3; i++)
     {
         tmp[i] = list[i]; //allocating the info to the tmp array
     }
    
    printf("Address: %p\n", &tmp);
    printf("Address: %p\n", &list);
    tmp[3] = 4;
    list = tmp; //pointing list to the new pointer array
    
    //free(list); //freeing the old list pointer

    for (int i = 0; i < 4; i++)
    {
        printf("Value: %i ---> Addres: %p\n", list[i], &list[i]);
    }
    
    free(list);
    return 0;
}

/*
Final version:
    int* list = malloc(3 * sizeof(int)); //This is the same thing as: int list[3];

    //checking if it is out of memory (Segmentation Fault)
    if (list == NULL)
    {
        return 1;
    }
    

    *list = 1; // This is the same as: list[0] = 1;
    *(list+1) = 2; //same as: list[1] = 2;
    *(list+2) = 3; //same as: list[2] = 3;

    //NOT NECESSARY BECAUSE WE'RE USING REALLOC
    //int* tmp = malloc(4 * sizeof(int)); //we can't use int* list again because it would leak memory
    
    //In case I need more space in my array
    int* tmp = realloc(list, 4 * sizeof(int));
    printf("Address: %p\n", &tmp);
    if (tmp == NULL)
    {
        free(list); //Before breaking the code, i need to free the memory alloc of the first malloc
        return 1;
    }
    
    //NOT NECESSARY BECAUSE WE'RE USING REALLOC
    // for (int i = 0; i < 3; i++)
    // {
    //     tmp[i] = list[i]; //allocating the info to the tmp array
    // }
    
    list = tmp; //pointing list to the new pointer array
    printf("Address: %p\n", &tmp);
    printf("Address: %p\n", &list);
    tmp[3] = 4;
    
    //free(list); //freeing the old list pointer

    for (int i = 0; i < 4; i++)
    {
        printf("Value: %i ---> Addres: %p\n", list[i], &list[i]);
    }
    
    free(list);
    return 0;
*/