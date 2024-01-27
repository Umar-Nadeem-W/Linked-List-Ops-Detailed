//Muhammad Umar Nadeem
//212052
//BSCS-3-C

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
class node{

private:

    int value;
    node* next_node;

public:

    void set_val(int v){value = v;}
    void set_next_node(node* nn){next_node = nn;}

    int get_val(){return value;}
    node* get_next_node(){return next_node;}

    node(){
    value = -1;
    next_node = NULL;}

    ~node()
    {
    delete next_node;
    };
};


class single_ll{


    private :
        node* header;
        node* last_current_node;
        node* current_node;
        node* tail_node;
        int list_size;

    public:

        single_ll()
        {
            header = new node();
            header->set_next_node(NULL);
            header->set_val(0);
            current_node =NULL;
            last_current_node =NULL;
            tail_node =NULL;
            list_size =0;
        }

//--------------------------------------------------CREATE LIST------------------------------------------------//
void create_list(){

cout <<"Please enter the number of elements you wish to store in the list."<<endl;
int NOE;
int val;
cin>>NOE;
for (int i = 1; i<= NOE; i++){

        if (header->get_next_node() == NULL)
            {

                cout <<"Please enter the value you wish to store at node # "<<i<<endl;
                cin>>val;
                node* newnode = new node();
                header->set_next_node(newnode);
                newnode->set_val(val);
                current_node = newnode;
                last_current_node = header;
                newnode->set_next_node(NULL);
                tail_node = newnode;
            }
        else
            {

            cout <<"Please enter the value you wish to store at node # "<<i<<endl;
			cin >> val;
			node* newnode = new node();
			newnode->set_val(val);
			current_node->set_next_node(newnode);
			last_current_node = current_node;
			current_node = newnode;
			newnode->set_next_node(NULL);
			tail_node = newnode;
            }

list_size++;
}

}

//------------------------------------------INSERT-----------------------------------------------//
void insert_at_start(){

int val;
cout <<"Please enter the value you wish to insert at the start of the list"<<endl;
cin>> val;
node* newnode = new node();
newnode->set_val(val);
newnode->set_next_node(header->get_next_node());
header->set_next_node(newnode);
list_size++;
}

void insert_at_end(){
int val;
cout <<"Please enter the value you wish to insert at the end of the list"<<endl;
cin>>val;
node* newnode = new node();
newnode->set_val(val);
tail_node->set_next_node(newnode);

last_current_node = tail_node;
tail_node = newnode;
list_size++;

}



void insert_at_spec_loc(){

int check = 0;

while (check == 0){
cout<<"Please enter the element # where you wish to insert the new value in the list"<<endl<<endl;
int place;
int val;
cin>>place;

if (place>list_size){cout <<"Please enter a valid index within the list's size"<<endl;}
else {node* newnode = new node();
cout <<"Please enter the value you wish to insert at place # "<<place<<endl;
cin>>val;
newnode->set_val(val);

current_node = header;
for (int i = 1; i <place; i++)
    {
        current_node = current_node->get_next_node();
    }

last_current_node = current_node;
current_node = newnode;
newnode->set_next_node(last_current_node->get_next_node());
last_current_node->set_next_node(newnode);

list_size++;
check = -1;
}
}
}

void Insert(){
    int insertion_loop_val = 0;
    while (insertion_loop_val != 27){
    int insertion_option;
    cout <<"Please select your desired option"<<endl;
    cout <<"1. Insert at start."<<endl;
    cout <<"2. Insert at a specific location."<<endl;
    cout <<"3. Insert at end."<<endl;
    cout <<"4. Back to Main Menu"<<endl;

    cin>>insertion_option;

    if (insertion_option == 1)
        {insert_at_start();
        system("CLS");
        }

    else if(insertion_option == 2)
        {insert_at_spec_loc();
        system("CLS");
        }

    else if (insertion_option == 3)
        {insert_at_end();
        system("CLS");
        }

    else if (insertion_option == 4)
        {insertion_loop_val = 27;
        system("CLS");
        }

    else
        {cout <<"Invalid entry. Please enter a valid option."<<endl;
            sleep(5);
            system("CLS");
        }
    }
    }

    //-----------------------------------DELETE---------------------------------------------------------------------------------------


void delete_at_start()
{

if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least one value before attempting deletion."<<endl;}
else
    {
     last_current_node = header;
     current_node = header->get_next_node();

     last_current_node->set_next_node(current_node->get_next_node());
     current_node->set_next_node(NULL);
     delete current_node;
     list_size--;

    }

}


void delete_at_spec_loc()
{
    int check = -1;

   if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least one value before attempting deletion."<<endl;}

    else{
    while (check == -1){
    int noden;
    last_current_node = header;
    current_node = header->get_next_node();
    cout <<"Please enter the node number at wish you to delete: ";
    cin>>noden;


    if ((noden < 1) || (noden > list_size)){cout<<endl<<"The node you entered does not exist in the array. Please make a valid entry."<<endl;}
    else
        {
            for (int i =1; i< noden; i++)
                {
                    last_current_node = current_node;
                    current_node = current_node ->get_next_node();
                }
                last_current_node->set_next_node(current_node->get_next_node());
                current_node->set_next_node(NULL);
                delete current_node;
                list_size--;
                check = 100;
        }
    }
}
}

void delete_at_end()
{
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least one value before attempting deletion."<<endl;}
else
{
last_current_node = header;
current_node = header->get_next_node();

for(int i = 1; i < list_size; i++)
    {
     last_current_node = current_node;
    current_node = current_node->get_next_node();
    }
    last_current_node->set_next_node(current_node->get_next_node());
    current_node->set_next_node(NULL);
    delete current_node;
    list_size--;
}
}

void Delete(){

int deletion_loop_val = 0;
int del_option;
while (deletion_loop_val != -1){
cout <<"Please select your desired option"<<endl;
cout <<"1. Delete at start."<<endl;
cout <<"2. Delete at a specific location."<<endl;
cout <<"3. Delete at end."<<endl;
cout <<"4. Back to Main Menu"<<endl;

cin>> del_option;
if (del_option == 1)
    {
        delete_at_start();
        system("CLS");
    }
else if (del_option == 2)
    {
        delete_at_spec_loc();
        system("CLS");
    }
else if (del_option == 3)
    {
        delete_at_end();
        system("CLS");
    }
else if (del_option == 4)
    {
        deletion_loop_val = -1;
        system("CLS");
    }

else {
    cout <<"Please enter a valid choice"<<endl;
    sleep(5);
    system("CLS");
    }
}
}
//---------------------------------------------DISPLAY----------------------------------------------//

void Display(){
current_node = header->get_next_node();
for (int i = 1; i <= list_size; i++)
    {cout <<"Element stored at node # "<<i<<" of the list is: ";
     cout<<current_node->get_val()<<endl;
     current_node = current_node->get_next_node();
    }



}
//------------------------------------------Update---------------------------------------------------//


void update_by_node(){
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least one value before attempting updation."<<endl;}

else {
int nodenum;
int new_val;
current_node = header;
cout<<"Please enter the node number you wish to update."<<endl;
cin>>nodenum;
cout<<"Please enter the value you wish to update the value of node number "<<nodenum<<" to."<<endl;
cin>>new_val;
for(int i = 1; i <= nodenum; i++)
    {current_node = current_node ->get_next_node();}
current_node->set_val(new_val);

}
}


void update_by_value(){

if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least one value before attempting updation."<<endl;}
else

{
        int old_val;
        int new_val;
        int arrsize = 0;
        int* temparray = new int [arrsize];
        current_node = header;
        cout <<"Please enter the value you wish to update"<<endl;
        cin>>old_val;
        for (int i = 1; i<= list_size; i++)
            {
                current_node = current_node->get_next_node();
                if (current_node->get_val() == old_val)
                    {
                        temparray[arrsize] = i;
                        arrsize++;
                    }
            }
            current_node = header;
        if (arrsize <= 0)
            {cout<<"The value you have entered is not present in the array. You must enter a valid value"<<endl;}

        else if(arrsize == 1)
        {
         cout <<old_val<<" is present at node number "<<temparray[0]<<". Please enter the new value you wish to update it to."<<endl;
         cin>>new_val;
         for (int j = 1; j <= temparray[0]; j++)
            {
            current_node = current_node->get_next_node();
            }
         current_node->set_val(new_val);
        }
        else if (arrsize >= 2)
            {
            int choice;
            int check = 0;
            cout <<old_val<<" is present at nodes ";
            for (int a = 0; a < arrsize; a++){cout <<temparray[a]<<", ";}
            cout<<". Which of these nodes would you like to update.?"<<endl;
            cin>>choice;
            for(int m = 0; m<arrsize; m++)
            {
                if (temparray[m] == choice)
                    {check = -1;}
            }
            if (check != -1) {cout<<"Please make a valid entry."<<endl;}
            else
                {
                cout<<"Please emter the new value you wish to update node # "<<choice<<" to :";
                cin>>new_val;
                current_node = header;
                for(int p = 1; p <=choice; p++)
                {current_node = current_node->get_next_node();}

                current_node->set_val(new_val);
                }


            }
delete [] temparray;
}


}


void Update(){

int updation_loop_val = 0;
int choice;
while (updation_loop_val != -1){
cout <<"Please select your desired option"<<endl;
cout <<"1. Update by index"<<endl;
cout <<"2. Update by value"<<endl;
cout <<"3. Back to main menu"<<endl;

cin>>choice;
if (choice == 1)
    {
    update_by_node();
    system("CLS");
    }
else if (choice == 2)
    {
    update_by_value();
    system("CLS");
    }
else if (choice ==3)
    {
    updation_loop_val = -1;
    system("CLS");
    }
else
    {
     cout <<"Please enter a valid choice"<<endl;
     sleep(5);
     system("CLS");
    }

}

}

//===========================================SWAP====================================================//

void swap_by_index()
{
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least two values before attempting swapping."<<endl;}

else
{
    node* nod1 = NULL;
    node* nod2 = NULL;
    int n1, n2;
    cout <<"The list is displayed below for your convenience."<<endl<<endl;
    Display();
    cout<<"Please enter the first node number of the swap's serial number: ";
    cin>>n1;
    cout<<"Please enter the second node number of the swap's serial number: ";
    cin>>n2;
    if (n1 <= 0 || n1> list_size || n2<= 0 || n2> list_size)
    {
       cout<<"One or both of your entered nodes is not present in the list. Please enter a valid serial number for the node"<<endl;
    }
    else
    {
        current_node = header;
        for (int i = 1; i<= n1; i++)
            {current_node  = current_node->get_next_node();}
        nod1 = current_node;
        current_node = header;

        for (int j = 1; j<= n2; j++)
            {current_node = current_node->get_next_node();}
        nod2 = current_node;

        int temp = nod1->get_val();
        nod1->set_val(nod2->get_val());
        nod2->set_val(temp);
    }

}
}

void swap_by_value()
{
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least two values before attempting swapping."<<endl;}
else
    {
        int v1;
        int v2;
        int check1 = -1;
        int check2 = -1;
    cout <<"The list is displayed below for your convenience."<<endl<<endl;
    Display();

    cout<<"Please enter the two values you wish to swap."<<endl;
    cout <<"Value # 1: ";cin>>v1;
    cout <<"Value # 2: ";cin>>v2;
    current_node = header;
    for (int i = 1; i<= list_size; i++)
        {
        current_node = current_node->get_next_node();
        if (current_node->get_val() == v1){check1 = 200;}
        if (current_node->get_val() == v2){check2 = 200;}
        }

    if(check1 != 200 || check2 != 200)
        {cout<<"One or both of your values is not present in the list. Please enter valid values"<<endl;}

    else
        {
        current_node = header;
         int tsize1 = 0;
         int tsize2 = 0;
         int* tarr1 = new int [tsize1];
         int* tarr2 = new int [tsize2];

         for(int j = 1; j<= list_size; j++)
            {
                current_node = current_node->get_next_node();
                if (current_node->get_val() == v1){
                       tsize1++;
                       tarr1[tsize1 - 1] = j;
                }
            }

            current_node = header;

        for(int k = 1; k<= list_size; k++)
            {
             current_node = current_node->get_next_node();
             if(current_node->get_val() == v2)
                {
                    tsize2++;
                    tarr2[tsize2 - 1]= k;
                }
            }


current_node = header;

if(tsize1 == 1 && tsize2 == 1)
    {
        for (int a = 1; a <= tarr1[0]; a++)
        {
         current_node = current_node->get_next_node();
        }
current_node->set_val(v2);

    current_node = header;

    for(int b = 1; b<=tarr2[0]; b++)
        {current_node = current_node->get_next_node();}

        current_node->set_val(v1);


    }

else if (tsize1 == 1 && tsize2 > 1)
    {
        int c1;
        cout<<v1<<" is present at node # "<<tarr1[0]<<" and "<<v2<<" is present at ";
        for (int i = 0; i< tsize2; i++){cout<<tarr2[i]<<", ";}
        cout<<endl<<"Which of these nodes containing "<<v2<<" would you like to swap with "<<v1<<"?"<<endl;
        cin>>c1;
        current_node = header;
         for (int i = 1; i<=tarr1[0]; i++)
            {current_node = current_node->get_next_node();}
         current_node->set_val(v2);
         current_node = header;

          for (int i = 1; i<=c1; i++)
            {current_node = current_node->get_next_node();}
            current_node->set_val(v1);

    }

else if (tsize1 > 1 && tsize2 == 1)
    {
    int c2;
    cout<<v2<<" is present at node # "<<tarr2[0]<<" and "<<v1<<" is present at ";
        for (int i = 0; i< tsize1; i++){cout<<tarr1[i]<<", ";}
        cout<<endl<<"Which of these nodes containing "<<v1<< " would you like to swap with "<<v2<<"?"<<endl;
        cin>>c2;
        current_node = header;
         for (int i = 1; i<=tarr2[0]; i++)
            {current_node = current_node->get_next_node();}
         current_node->set_val(v1);
         current_node = header;

          for (int i = 1; i<=c2; i++)
            {current_node = current_node->get_next_node();}
            current_node->set_val(v2);

    }

else if (tsize1 > 1 && tsize2 > 1)
     {
         int c3;
         int c4;
      current_node = header;

         cout << v1 <<" is present at nodes ";
     for (int i = 0; i<tsize1; i++)
        {cout <<tarr1[i]<<", ";}
     cout <<endl;

     cout<< v2 <<" is present at nodes ";
     for(int j =0; j<tsize2; j++)
        {cout<<tarr2[j]<<", ";}

    cout<<"Please enter the first node (containing "<<v1<<") you wish to swap."<<endl;
    cin>>c3;
    cout<<endl<<"Please enter the second node (containing "<<v2<<") you wish to swap."<<endl;
    cin>>c4;

    for (int i = 1; i<= c3; i++)
    {
        current_node = current_node->get_next_node();
    }
    current_node->set_val(v2);
    current_node = header;
    for(int z = 1; z <= c4; z++){current_node = current_node->get_next_node();}
    current_node->set_val(v1);
     }




delete [] tarr1 ;
delete [] tarr2 ;
    }




    }
}


void Swap()
{
int choice;
int check1;

while (check1 != -1)
{
cout <<"Please select your desired option"<<endl;
cout <<"1. Swap by index"<<endl;
cout <<"2. Swap by value"<<endl;
cout <<"3. Back to main menu"<<endl;
cin>>choice;

if (choice == 1)
    {
    swap_by_index();
    system("CLS");
    }
else if (choice == 2)
    {
    swap_by_value();
    system("CLS");
    }
else if (choice ==3)
    {
    check1 = -1;
    system("CLS");
    }
else
    {
     cout <<"Please enter a valid choice"<<endl;
     sleep(5);
     system("CLS");
    }
}

}

//--------------------------------------------COPY--------------------------------------------------//

void copy_by_index()
{
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least two values before attempting copying."<<endl;}
else{
 cout <<"The list is displayed below for your convenience."<<endl<<endl;
    Display();

    int store = -1;
    int n1;
    int n2;
    current_node = header;
     cout <<"PLease enter the node whose value you wish to copy."<<endl;
     cin>>n1;
     cout <<"Please enter the node you wish to copy the value of "<<n1<<" over."<<endl;
     cin>>n2;

if (n1 <= 0 || n1 > list_size || n2 <= 0 || n2 > list_size)
    {cout<<"One or both of the nodes you have entered doesn't exist in the list. Please enter valid nodes."<<endl;}
else {for (int i = 1; i <= n1; i++){current_node = current_node->get_next_node();}
store = current_node->get_val();

current_node = header;

for (int j = 1; j<=n2; j++){current_node = current_node->get_next_node();}
current_node->set_val(store);
}
}
}


void copy_by_value (){
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least two values before attempting copying."<<endl;}
else
    {
        int v1;
        int v2;
        int check1 = -1;
        int check2 = -1;
    cout <<"The list is displayed below for your convenience."<<endl<<endl;
    Display();

    cout<<"Please enter the value you wish to copy."<<endl;
    cin>>v1;
    cout<<"Please enter the value you wish to copy "<<v1<<" over."<<endl;
    cin>>v2;
    current_node = header;
    for (int i = 1; i<= list_size; i++)
        {
        current_node = current_node->get_next_node();
        if (current_node->get_val() == v1){check1 = 200;}
        if (current_node->get_val() == v2){check2 = 200;}
        }

    if(check1 != 200 || check2 != 200)
        {cout<<"One or both of your values is not present in the list. Please enter valid values"<<endl;}

    else
        {
        current_node = header;
         int tsize2 = 0;
         int* tarr2 = new int [tsize2];

         for(int j = 1; j<= list_size; j++)
            {
                current_node = current_node->get_next_node();
                if (current_node->get_val() == v2){
                       tsize2++;
                       tarr2[tsize2 - 1] = j;
                }
            }



current_node = header;

if( tsize2 == 1)
    {
    current_node = header;

    for(int b = 1; b<=tarr2[0]; b++)
        {current_node = current_node->get_next_node();}

        current_node->set_val(v1);


    }

else if ( tsize2 > 1)
    {
        int c1;
        cout<<v2<<" is present at ";
        for (int i = 0; i< tsize2; i++){cout<<tarr2[i]<<", ";}
        cout<<endl<<"Which of these nodes containing "<<v2<<" would you like to copy "<<v1<<" over ?"<<endl;
        cin>>c1;
         current_node = header;

          for (int i = 1; i<=c1; i++)
            {current_node = current_node->get_next_node();}
            current_node->set_val(v1);

    }


delete [] tarr2 ;
    }




    }
}

void Copy()
 {
     int choice = 0;
     int copy_loop_val = 0;

     while (copy_loop_val != -1){
     cout <<"Please enter your desired option"<<endl;
     cout <<"1. Copy by index"<<endl;
     cout <<"2. Copy by value"<<endl;
     cout <<"3. Back to main menu"<<endl;
     cin>>choice;
     if (choice == 1)
         {
          copy_by_index();
          system("CLS");
         }

     else if (choice == 2)
        {
            copy_by_value();
            system("CLS");
        }

     else if (choice == 3)
        {
        copy_loop_val = -1;
        }
     else
     {
         cout <<"Please enter a valid choice."<<endl;
        system("CLS");
     }


     }

 }
//-----------------------------------------FIND----------------------------

void search_by_index()
{
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least one value before attempting search."<<endl;}
else {int p;
cout<<"Please enter the node number you're searching for."<<endl;
cin>>p;

current_node = header;
for(int i = 1; i<=p; i++){current_node = current_node->get_next_node();}
cout <<"The value at node # "<<p<<" is "<<current_node->get_val()<<endl;
}
}

void search_by_value()
{
if (header->get_next_node() == NULL){cout <<"The list is empty. Please enter at least one value before attempting search."<<endl;}
else {int val;
cout<<"Please enter the value you're searching for"<<endl;
cin>>val;
int tsize = 0;
int* tarr = new int
[tsize];
current_node = header;

for (int i = 1; i<= list_size; i++)
    {
    current_node = current_node->get_next_node();
    if(current_node->get_val() ==  val)
        {tsize++; tarr[tsize - 1] = i;}
    }
cout << val <<" is present at nodes # ";
for(int k = 0; k<tsize; k++){cout<<tarr[k]<<", ";}

}
}

void Search()
{
int m = 200;
while (m != -1){
int entry;
cout <<"Please select your desired option"<<endl;
cout <<"1. Search by index"<<endl;
cout <<"2. Search by value."<<endl;
cout <<"3. Back to main menu"<<endl;
cin>>entry;

if (entry == 1)
{
    search_by_index();
}
else if (entry == 2)
{
    search_by_value();
}
else if (entry  == 3)
    {
        m =-1;
    }

else
    {
        cout <<"Invalid selection. Please select a valid option."<<endl;
    }
}

}
//-----------------------------------------FIND LENGTH
void length_of_list(){
    cout<<endl<<"The list is "<<list_size<<" nodes long."<<endl;
}

//===========================================Delete entire list.
void delete_list()
{
 /*

    last_current_node = header;
    current_node = last_current_node->get_next_node();
    for(int i = 1; i<list_size; i++)
        {
        last_current_node->set_next_node(current_node->get_next_node());
        delete current_node;
        current_node = last_current_node->get_next_node();
        list_size--;
        }
delete current_node;
list_size--;

*/
header->set_next_node(NULL);

}
//
 ~single_ll()
 {
    delete last_current_node;
    delete current_node;
    delete tail_node;
    delete header;
 };
};



void main_menu(){
    cout<<"Please enter your desired option."<<endl<<endl;
    cout<<"1. Create list."<<endl;
    cout<<"2. Insert."<<endl;
    cout<<"3. Delete."<<endl;
    cout<<"4. Update."<<endl;
    cout<<"5. Swap."<<endl;
    cout<<"6. Copy."<<endl;
    cout<<"7. Find value."<<endl;
    cout<<"8. Find length of list."<<endl;
    cout<<"9. Delete entire list."<<endl;
    cout<<"10. Display."<<endl;
    cout<<"11. Exit."<<endl;
}
single_ll l1;


int main(){

int main_menu_check = 20;

while(main_menu_check == 20)
{
int Main_menu_option;
main_menu();
cin>>Main_menu_option;

if (Main_menu_option == 1) {l1.create_list();}
else if(Main_menu_option == 2){l1.Insert();}
else if(Main_menu_option == 3){l1.Delete();}
else if (Main_menu_option == 4){l1.Update();}
else if (Main_menu_option == 5){l1.Swap();}
else if (Main_menu_option == 6){l1.Copy();}
else if (Main_menu_option == 7){l1.Search();}
else if (Main_menu_option == 8) {l1.length_of_list(); cout<<sleep(4);}
else if (Main_menu_option == 9){l1.delete_list();}
else if (Main_menu_option == 10){l1.Display(); cout<<sleep(7);}
else if (Main_menu_option == 11){main_menu_check = -1; cout<<"Thank you for using our program. Fee Amanillah! :)"<<endl;
sleep(5); }
else {cout <<"Invalid selection. Please make a valid selection."<<endl;sleep(3);}
system("CLS");
}


return 0;
}
