#include <stdio.h>

int InputArray(int arr[]);
void PrintArray(int arr[], int size);

int main() {
    int option = -1, arr[100], arr2[100], arr3[100], size, size2, size3, element, location, i, j;

    do {
        printf("\n========================================");
        printf("\n0) Exit");
        printf("\n1) Input Array");
        printf("\n2) Traverse");
        printf("\n3) Insert element at end");
        printf("\n4) Insert element at a location");
        printf("\n5) Delete element at end");
        printf("\n6) Delete element at a location");
        printf("\n7) Merge unsorted array");
        printf("\n8) Merge sorted array");
        printf("\n========================================");
        printf("\nSelect option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            size = InputArray(arr);
            break;

        case 2:
            PrintArray(arr, size);
        break;

        case 3:
            printf("\nEnter the element to insert : ");
            scanf("%d", &element);

            arr[size] = element;
            size++;

            printf("Inserted");
        break;

        case 4:
            printf("\nEnter the element to insert : ");
            scanf("%d", &element);

            printf("\nEnter location : ");
            scanf("%d", &location);

            for(int i = size-1; i >= location; i--){
                arr[i + 1] = arr[i];
            }
            arr[location] = element;
            size++;

            printf("Inserted");
        break;

        case 5:
            size--;

            printf("Deleted");
        break;

        case 6:
            printf("\nEnter location : ");
            scanf("%d", &location);

            for(int i = location + 1; i < size; i++){
                arr[i-1] = arr[i];
            }
            size--;

            printf("Deleted");
        break;

        case 7:
            size2 = InputArray(arr2);
            size3 = 0;

            for(int i = 0; i < size; i++){
                arr3[i] = arr[i];
                size3++;
            }
            for(int i = 0; i < size2; i++){
                arr3[size3] = arr2[i];
                size3++;
            }

            PrintArray(arr3, size3);
        break;

        case 8:
            size2 = InputArray(arr2);

            i = 0;
            j = 0;
            size3 = 0;
            while(i < size && j < size2) {
                if(arr[i] < arr2[j]) {
                    arr3[size3] = arr[i];
                    i++;
                }
                else {
                    arr3[size3] = arr2[j];
                    j++;
                }
                size3++;
            }

            while(i < size) {
                arr3[size3] = arr[i];
                i++;
                size3++;
            }
            
            while(j < size2) {
                arr3[size3] = arr2[j];
                j++;
                size3++;
            }

            PrintArray(arr3, size3);
        break;
        
        default:
            break;
        }
    } while(option != 0);
    return 0;
}

int InputArray(int arr[]) {
    int n, i;

    printf("\nEnter number of elements in array : ");
    scanf("%d", &n);

    for(i = 0; i<n; i++){
        printf("\nEnter element %d : ", i);
        scanf("%d", &arr[i]);
    }

    return n;
}

void PrintArray(int arr[], int size) {
    printf("\nElements of array are : ");
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
}