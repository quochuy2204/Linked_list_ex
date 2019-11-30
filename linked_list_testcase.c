#include <gtest/gtest.h>
#include "linked_list.h"


/***************************************************************************/
TEST(addtest,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

    head->next=NULL; 
    head->data=str; 
    head->index=0;

    i=add_to_list(head,str1);
    EXPECT_EQ(1,i);

    i=add_to_list(head,str2);
    EXPECT_EQ(2,i);

    i=add_to_list(head,str3);
    EXPECT_EQ(3,i);

    i=add_to_list(head,str4);
    EXPECT_EQ(4,i);

    i=add_to_list(head,str5);
    EXPECT_EQ(5,i);

    i=add_to_list(head,str6);
    EXPECT_EQ(6,i);

}

TEST(addtest,null_error){
    char str[15]="List Start";
    char str1[10]="zero";
    int i;
	struct linked_list *head = NULL;
    i=add_to_list(head,str1);
    EXPECT_EQ(-1,i);

}

TEST(addtest,add_empty){
	char str[15]="List Start";
    char str1[10]="";
	int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
	head->next=NULL; 
    head->data=str; 
    head->index=0;
	
	i=add_to_list(head,str1);
    EXPECT_EQ(1,i);
}

/***************************************************************************/

/***************************************************************************/
TEST(display_item,add_to_list)
{
    int result;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    display_item(head->next);
    EXPECT_EQ(head->next->index,1);
    EXPECT_EQ(i,1);
    EXPECT_STREQ(head->next->data,str1);

    i=add_to_list(head,str2);
    display_item(head->next->next);
    EXPECT_EQ(head->next->next->index,2);
    EXPECT_EQ(i,2);
    EXPECT_STREQ(head->next->next->data,str2);

    i=add_to_list(head,str3);
    display_item(head->next->next->next);
    EXPECT_EQ(head->next->next->next->index,3);
    EXPECT_EQ(i,3);
    EXPECT_STREQ(head->next->next->next->data,str3);

    i=add_to_list(head,str4);
    display_item(head->next->next->next);
    EXPECT_EQ(head->next->next->next->next->index,4);
    EXPECT_EQ(i,4);
    EXPECT_STREQ(head->next->next->next->next->data,str4);

    i=add_to_list(head,str5);
    display_item(head->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->index,5);
    EXPECT_EQ(i,5);
    EXPECT_STREQ(head->next->next->next->next->next->data,str5);

    i=add_to_list(head,str6);
    display_item(head->next->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->next->index,6);
    EXPECT_EQ(i,6);
    EXPECT_STREQ(head->next->next->next->next->next->next->data,str6);

}

TEST(display_item,null_error){
	char str[15]="List Start";
    char str1[10]="zero";
    int i;

    struct linked_list *head = NULL;
    i=display_item(head);
    EXPECT_EQ(-1,i);
}

TEST(display_item,empty){
	int result;
    char str[15]="List Start";
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->next=NULL;
    head->data=str;
    head->index=0;
    display_item(head);
}

/***************************************************************************/
TEST(display_list,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);


    display_list(head);
}

TEST(display_list,empty)
{
    int result;
    char str[15]="List Start";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    display_list(head);

}

TEST(display_list,null_error){
	char str[15]="List Start";
    char str1[10]="zero";
    int i;

    struct linked_list *head = NULL;
    i=display_list(head);
    EXPECT_EQ(-1,i);
}
/***************************************************************************/
TEST(search,normal)
{
    char str[15]="List Start";
    char str1[15]="second";
    char str2[15]="third";

    linked_list *found;
    struct linked_list *head;

    head = (struct linked_list*) malloc(sizeof(linked_list));
    head->data=str;
    head->index=0;


    head->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->data=str1;
    head->next->index=1;

    head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->next->index=2;
    head->next->next->data=str2;

    head->next->next->next->next = NULL;

    found=search_from_list(head,(char *)"third");

    EXPECT_EQ(found->index,2);
    EXPECT_STREQ(str2,found->data);
}

TEST(search,not_found)
{
    char str[15]="List Start";

    linked_list *found;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    found=search_from_list(head,(char *)"third");

    EXPECT_EQ((int *)found,(int *)NULL);
}

TEST(search,empty){
	 char str[15]="List Start";
    char str1[15]="";
    char str2[15]="third";

    linked_list *found;
    struct linked_list *head;

    head = (struct linked_list*) malloc(sizeof(linked_list));
    head->data=str;
    head->index=0;


    head->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->data=str1;
    head->next->index=1;

    head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->next->index=2;
    head->next->next->data=str2;

    head->next->next->next->next = NULL;
	
	found=search_from_list(head,(char *)"");
	
	EXPECT_EQ(found->index,1);
	 EXPECT_STREQ(str1,found->data);
}
/***************************************************************************/
/*TEST(sort,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    sort_list(head);

    display_list(head);

}
*/
/***************************************************************************/
TEST(delete,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    delete_from_list(head,2);

}

TEST(delete,multi) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    for(i=0; i<40; i++)
        add_to_list(head,str1);

    delete_from_list(head,12);
    delete_from_list(head,22);
    delete_from_list(head,25);
    delete_from_list(head,32);
    delete_from_list(head,38);

    delete_from_list(head,380);
}

TEST(delete,empty){
	char str[15]="List Start";
    char str1[10]="zero";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
	
	i=delete_from_list(head,1);
	EXPECT_EQ(i,0);
}

/***************************************************************************/
TEST(empty,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
    empty_list(head);
}

TEST(empty,null_error){
	char str[15]="List Start";
    char str1[10]="zero";
    int i;
	struct linked_list *head = NULL;
    add_to_list(head,str1);
	i=empty_list(head);
    EXPECT_EQ(-1,i);
}

TEST(empty,empty){
	char str[15]="List Start";
    char str1[10]="";
    char str2[10]="";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    add_to_list(head,str2);
	i=empty_list(head);
	EXPECT_EQ(3,i);
}

/***************************************************************************/

TEST(status,normal){
	char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    add_to_list(head,str2);
    add_to_list(head,str3);
    add_to_list(head,str4);
    add_to_list(head,str5);
    add_to_list(head,str6);
	
	i=linkedlist_status(head);
	EXPECT_EQ(7,i);
}

TEST(status,null_error){
	char str[15]="List Start";
    char str1[10]="zero";
    int i;
	struct linked_list *head = NULL;
    i=linkedlist_status(head);
    EXPECT_EQ(-1,i);
}

TEST(status,empty){
	char str[15]="List Start";
    char str1[10]="";
    char str2[10]="";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    add_to_list(head,str2);
	i=linkedlist_status(head);
	EXPECT_EQ(3,i);
}

/***************************************************************************/

TEST(swap,normal){
	char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
 
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    add_to_list(head,str2);
    add_to_list(head,str3);

	i=swap_items(head, head->next);
	EXPECT_EQ(0,i);
	
	EXPECT_EQ(head->next->data,str2);

	
}