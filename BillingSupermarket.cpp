#include<iostream>
#include<string>
#include <sstream>

using namespace std;
int search(int);
int display();
string check(int);

struct node {
	int ID;
	double prePrice;
	string proName;
	int quantity;
struct    node* next;
};
struct node *head=NULL;

 void beg()
{
	system("cls");
	int id,quant;
	string name;
	double pre;
	struct node *t=new node;
	cout<<"\t\t\tEnter product ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	t->prePrice=pre;
	cout<<"Enter product quantity:-";
	cin>>quant;
	t->quantity=quant;
	t->next=head;
	head=t;
	system("cls");
		cout<<"\nPRODUCT ENTERED\n";
	}

	void end()
	{
	system("cls");
	int id,quant;
	string name;
	double pre;
	struct node *t=new node;
	struct node *p=head;
	cout<<"\t\t\tEnter product ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	t->prePrice=pre;
	cout<<"\t\t\tEnter product quantity:-";
	cin>>quant;
	t->quantity=quant;
		while(p->next!=NULL)
		{
		p=p->next;
		}
			p->next=t;
			t->next=NULL;
		system("cls");
		cout<<"\nPRODUCT INSERTED\n";
	}
	void delProduct()
	{
		system("cls");
		display();
		int id;
		struct node *cur=head;
		struct node *pre=head;
		cout<<"\nID OF THE PRODUCT TO DELETE\n";
		cin>>id;
		 if (head == NULL)
    {
    	system("cls");
        cout<<"EMPTY LIST"<<endl;
    }
	int pos=0;
	int count=display();
	pos=search(id);
	if(pos<=count){

		while(cur->ID!=id){
			pre=cur;
			cur=cur->next;
}
		pre->next=cur->next;
		system("cls");
		cout<<"\nITEM DELETED\n";
	}else{
		cout<<"\nNOT FOUND\n\n";
	}
	}
void modify()
    {
		int id;
		double pre;
		int quant;
		string pName;
		if (head == NULL)
    {
    	system("cls");
        cout<<"EMPTY LIST"<<endl;
    }else
	{
		cout<<"\n\nEnter ID to modify product Name and its price:\n";
		cin>>id;
		struct node *cur=head;
		int pos=0;
		int count=display();
	pos=search(id);
	if(pos<=count){

		while(cur->ID!=id){
			cur=cur->next;
		}
		cout<<"\nOLD NAME : "<<cur->proName;
		cout<<"\nOLD PRICE : "<<cur->prePrice<<endl;
		cout<<"ENTER NEW NAME:";
		cin>>pName;
		cur->proName=pName;
		cout<<"ENTER NEW PRICE:";
		cin>>pre;
		cur->prePrice=pre;
		cout<<"ENTER NEW QUANTITY:";
		cin>>quant;
		cur->quantity=quant;
	}else{
		cout<<id<<" -NOT FOUND\n\n";
	}
	}
}


int display(){
		system("cls");
		int c=0;
		struct node *p=head;
		cout<<"Existing products are:\n";
		cout<<"ID\t\tProduct Name\t\Price\tQuantity\n";
		while(p!=NULL)
		{
			cout<<p->ID<<"\t\t"<<p->proName<<"\t\t "<<p->prePrice<<"\t\t"<<check(p->quantity)<<"\n";
			p=p->next;
			c=c+1;
		}
		cout<<"\nTOTAL PRODUCTS : "<<c<<"\n";
		return c;
	    }
string check(int quant){
       int a = quant;
       stringstream ss;
       ss << a;
       string quantity = ss.str();

	    	if(quant<=0)
	    	return "out of stock!";
	    	else
	    	return quantity;
		}

void buy(){
		system("cls");
		string products[20];
		int pay=0,no,c=0,price,id,i=1;
		if(head==NULL) {
	cout<<"\n<<<<There is no items to buy>>>>\n\n";
	}
	else{
		cout<<"NUMBER OF ITEMS TO BUY!\n";
		cin>>no;
			int count=display();
		while (i<=no){
			struct node *cur=head;

		int quant,cho;
	cout<<"ENTER THE ID: ";
int id,pos=0;
	cin>>id;
	pos=search(id);
	if(pos<=count){

		while(cur->ID!=id){
			cur=cur->next;
		}

	cout<<"ENTER THE QUANTITY:";
	cin>>quant;
	products[c]=cur->proName; c++;
	pay=pay+(cur->prePrice*quant);
	cur->quantity=cur->quantity-quant;
	i++;
	}
	else{
		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
	    }
}



	system("cls");
cout<<"\n\n\n\n\t\t\tPRODUCTS NAME : ";
for(int i=0;i<no;i++){
	cout<<products[i]<<",";
}
price=pay*(0.90);
	cout<<"\n\nOriginal price : "<<pay;
    cout<<"\n with 10% discount: "<<price<<"\nThank you! \n\n";
}
}

	int search(int id)
 {
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }

int main(){


	cout<<"________SUPERMARKET PRODUCT BILLING AND PRODUCTS INFORMATION________ \n";

	int temp=1;
	while(true){
	int ch;
	cout<<"\t\t 1 for ADD a new product \n\n\t\t 2 to display all products \n\n\t\t 3 for MODIFY Existing product\n\n";
	cout<<"\t\t 4 for Delete a particular product item\n\n\t\t 5 for Buy something\n\n\t\tEnter 0 for exit\n\n";
    cin>>ch;
	switch(ch){
	case 1:
	if (temp==0){
	end();
	}
	if(temp==1){
	beg();
	temp=0;
	}
	break;
case 2:
	system("cls");

    display();
    break;
case 3:
	modify();
	break;
case 4:
	delProduct();
	break;
case 5:
	buy();
	break;
case 0:

	    exit(true);
        break;
default: system("cls");
         cout<<"\t\tWRONG CHOICE\n\n";
	}
}
}




