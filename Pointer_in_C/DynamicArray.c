#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    // Allocate memory for the total number of books in each shelf
    total_number_of_books = (int*)calloc(total_number_of_shelves, sizeof(int));
    
    // Allocate memory for the array of shelves (each shelf holds an array of books)
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));

    // Initialize each shelf as NULL since no books are added yet
    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_pages[i] = NULL;
    }

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            // Query Type 1: Add a new book
            int shelf, pages;
            scanf("%d %d", &shelf, &pages);
            
            // Increment the number of books on the shelf
            total_number_of_books[shelf]++;
            
            // Reallocate memory to accommodate the new book
            total_number_of_pages[shelf] = (int*)realloc(total_number_of_pages[shelf], total_number_of_books[shelf] * sizeof(int));
            
            // Add the number of pages for the new book
            total_number_of_pages[shelf][total_number_of_books[shelf] - 1] = pages;

        } else if (type_of_query == 2) {
            // Query Type 2: Print the number of pages in a specific book
            int shelf, book;
            scanf("%d %d", &shelf, &book);
            printf("%d\n", total_number_of_pages[shelf][book]);

        } else if (type_of_query == 3) {
            // Query Type 3: Print the total number of books on a shelf
            int shelf;
            scanf("%d", &shelf);
            printf("%d\n", total_number_of_books[shelf]);
        }
    }

    // Free allocated memory
    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (total_number_of_pages[i]) {
            free(total_number_of_pages[i]);
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
