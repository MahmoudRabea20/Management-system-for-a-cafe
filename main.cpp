#include<iostream>
#include<string>
using namespace std;

void menu();
void Adding_new_client();
void Updating_client_data();
void Deleting_client();
void showing_all_clients();

struct clients
{
	int client_id;
	string time;
	string client_name;
};

clients client[100];
int client_number= 0;

int main()
{
	cout << "\t\tWelcome to the management system for a cafe." << endl;
	menu();
	return 0;
}

void menu()
{
	int choice;
	cout<<" 1) Add new client."<<endl;
	cout<<" 2) Update client."<<endl;
	cout<<" 3) Delete client."<<endl;
	cout<<" 4) Show all clients attended the cafe.\n"<<endl;
	cout <<" Please chose one from above choices : " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: Adding_new_client();
		break;
	case 2: Updating_client_data();
		break;
	case 3: Deleting_client();
		break;
	case 4: showing_all_clients();
		break;
	default: cout << " Error : try again.\n\n"; menu();
	}
}

void Adding_new_client()
{
	int choice;
	if (client_number > 4)
	{
		cout << " Error:you exceeded the maximum number of clients." << endl;
		menu();
	}
	else
	{
		cout << " Please enter the id of the client entered the cafe : ";
		cin >> client[client_number].client_id;
		for (int i = 0; i < client_number; i++)
		{
			if (client[i].client_id == client[client_number].client_id)
			{
				cout << " Error:there is a client with this id." << endl;
				Adding_new_client();
				return;
			}
		}
		cout << " Please enter the time the client entered the cafe : ";
		cin >> client[client_number].time;
		cout << " Please enter the client name : ";
		getline(cin >> ws , client[client_number].client_name);
		cout << "\n To add another client press 1 , To return to the main menu press 0. " << endl;
		cin >> choice;
		if (choice == 1)
		{
			client_number++;
			Adding_new_client();
		}
		else if (choice == 0)
		{
			menu();
		}
	}
}
void Updating_client_data()
{
	int  mychoice, id ,a;
	int counter = 0;
	cout << " Please enter the id of the client to update : ";
	cin >> id;
	for (int j = 0; j <= client_number; j++)
	{
		if (id == client[j].client_id)
		{
			counter++;
			a = j;
		}
	}
	if (counter == 0)
	{
		cout << " Error : there is not client with this id to update." << endl;
		Updating_client_data();
		return;
	}
	else
	{
		cout << " Please enter the new time of the client : ";
		cin >> client[a].time;
		cout << " Please enter the new name of the client : ";
		getline(cin >> ws, client[a].client_name);
	}
	cout << "\n To update another client press 1 , To return to the main menu press 0. " << endl;
	cin >> mychoice;
	if (mychoice == 1)
	{
		if (client_number == 0)
		{
			cout << " Error : there is not any client to delete." << endl;
			menu();
		}
		Updating_client_data();
	}
	else if (mychoice == 0)
	{
		menu();
	}
}
void Deleting_client()
{
	int id,b,my_choice;
	int counter = 0;
	cout << " Please enter the id of the client to delete: ";
	cin >> id;
	for (int j = 0; j <= client_number; j++)
	{
		if (id == client[j].client_id)
		{
			counter++;
			b = j;
			break;
		}
	}
	if (counter == 0)
	{
		cout << " Error : there is not client with this id to delete." << endl;
		Deleting_client();
		return;
	}
	else
	{
		int i = 0;
		while (b+1+i<=client_number)
		{
			client[b+i].client_id = client[b+1+i].client_id;
			client[b+i].time = client[b+1+i].time;
			client[b+i].client_name= client[b+1+i].client_name;
			i++;
		}
		cout << " Deleted successfully. " << endl;
	}
	cout << "\n To delete another client press 1 , To return to the main menu press 0. " << endl;
	cin >> my_choice;
	if (my_choice == 1)
	{
		if (client_number == 0)
		{
			cout << " Error : there is not any client to delete." << endl;
			menu();
		}
		client_number--;
		Deleting_client();
	}
	else if (my_choice == 0)
	{
		menu();
	}
}
void showing_all_clients()
{
	if (client_number == 0)
	{
		cout << " Error : there are not clients to show " << endl;
		menu();
		return;
	}
	else
	{
		cout << " The summary of clients visited the cafe today : " << endl;
		for (int i = 0; i <= client_number; i++)
		{
			cout <<" "<< i + 1 <<") At "<<client[i].time<<" "<<client[i].client_name<<" visited the cafe."<< endl;

		}
	}
}
