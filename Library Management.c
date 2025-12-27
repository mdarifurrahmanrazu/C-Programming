#include<stdio.h>
#include<string.h>
int countBook=0;
struct book
{
    char title[50];
    char author[50];
    float price;
    int copies;
};
struct book books[500];
void showWelcomeMessage()
{
    for(int i=0; i<=40; i++)
    {
        printf("*");
    }
    printf("\n\n");
    printf("Welcome to Simple Book Management System.\n\n");
    for(int i=0; i<=40; i++)
    {
        printf("*");
    }
}
void showGoodByeMessage()
{
    for(int i=0; i<=50; i++)
    {
        printf("*");
    }
    printf("\n\n");
    printf("Thank you for using Simple Book Management System.\n\n");
    for(int i=0; i<=50; i++)
    {
        printf("*");
    }
}
showMenuOptions()
{
    printf("Please select a menu option number:\n");
    printf("1)Display this menu.\n");
    printf("2)Show all available books.\n");
    printf("3)Add a book to the  book shop.\n");
    printf("4)Search a book by title.\n");
    printf("5)Display the total number of books.\n");
    printf("6)Exit from this book shop system.\n\n");
}
void showBooks()
{
    if(countBook==0)
    {
        printf("There is no books available");
        return;
    }
    printf("List of books:\n");
    for(int i=0; i<countBook; i++)
    {
        printf("Book title:%s\n",books[i].title);
        printf("Book author:%s\n",books[i].author);
        printf("Book price:%.2f\n",books[i].price);
        printf("Copies:%d\n",books[i].copies);
        printf("\n");
    }

}
void addBook()
{
    if(countBook>=500)
    {
        printf("\n\nCannot add more books as the maximum limit reached. ");
    }
    else{
        printf("\nEnter book title:");
        scanf(" %[^\n]",books[countBook].title);
        printf("Enter book author:");
        scanf(" %[^\n]",books[countBook].author);
        printf("Enter book price:");
        scanf("%f",&books[countBook].price);
        printf("Enter number of copies:");
        scanf("%d",&books[countBook].copies);
        countBook++;
        printf("\n\n Book added successfully");
    }
}
void searchBook()
{
    char title[50];
    printf("Enter book title to search:");
    scanf(" %[^\n]",title);
    for(int i=0; i<countBook; i++)
    {
        if(strcmp(books[i].title,title)==0)
        {
            printf("Book title:%s\n",books[i].title);
            printf("Book author:%s\n",books[i].author);
            printf("Book price:%.2f\n",books[i].price);
            printf("Number of copies:%d\n",books[i].copies);
            break;
        }
        else if(strcmp(books[i].title,title)!=0)
        {
            printf("\n Book not found.");
            break;
        }
    }


}
void showNumberOfBooks()
{
    int total_copy=0;
    for(int i=0; i<countBook; i++)
    {
        total_copy+=books[i].copies;
    }
    printf("Total number of books in the shop: %d",total_copy);
}
void main()
{
    int n;
    showWelcomeMessage();
    do
    {
        printf("\n\n");
        showMenuOptions();
        printf("\n\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            break;
        case 2:
            showBooks();
            break;
        case 3:
            addBook();
            break;
        case 4:
            searchBook();
            break;
        case 5:
            showNumberOfBooks();
            break;
        case 6:
            showGoodByeMessage();
            break;
        default:
            printf("Could not find anything!Please try again later.");

        }
    }
    while(n!=6);

}
