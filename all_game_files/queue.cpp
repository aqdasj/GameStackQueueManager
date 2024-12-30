// Aqdas Juya , 10/25/2024 , ajuya@pdx.edu ,  Program # 2, cs 163
#include"game.h"
#include <cstring>
#include <iostream>

using namespace std;


queue_game::queue_game(){

	rear = nullptr;
}


int queue_game::enqueue(const game &to_add, const char *s_name, const char *more_info){
	if(!rear) {
		rear = new queuenode;
		rear -> next = rear;
	}else {
		queuenode * hold = rear -> next;
		rear -> next = new queuenode;
		rear = rear -> next;
		rear -> next = hold;

	}
	rear -> more_game.copy_game(to_add);

	rear -> a_series.s_name = new char[strlen (s_name)+ 1];
	strcpy(rear -> a_series.s_name, s_name);

	rear -> a_series.more_info = new char[strlen(more_info) +1];
	strcpy(rear -> a_series.more_info, more_info);

	return 1;
}

bool queue_game::display() const {
	if (!rear) {
		return 0;
	}
	if(rear == rear-> next) {   // only displaying if one node is there
		cout << "Game Title: " << rear -> more_game.title << endl;
		cout << "platform:: " << rear -> more_game.platform << endl
		     << "Genre: " << rear -> more_game.genre <<endl
		     << "Progression: " <<rear -> more_game.prograssion<<endl			    
		     << "Achievements: " <<rear -> more_game.prograssion<<endl
		     << "More Information: " << rear -> more_game.more_information << endl
		     << "Series Name: " << rear -> a_series. s_name<< endl
		     << "the devolper: " << rear -> a_series.more_info <<endl << endl;
	     return 1;
	}
	queuenode * current = rear -> next;    // displaying if there are multiple nodes
	int i = 1;
	do {
                cout << "Game Title: " << rear -> more_game.title << endl;
                cout << "platform:: " << rear -> more_game.platform << endl
                     << "Genre: " << rear -> more_game.genre <<endl
                     << "Progression: " <<rear -> more_game.prograssion<<endl                        
                     << "Achievements: " <<rear -> more_game.prograssion<<endl
                     << "More Information: " << rear -> more_game.more_information << endl
                     << "Series Name: " << rear -> a_series. s_name<< endl
                     << "the devolper: " << rear -> a_series.more_info <<endl << endl;
		     current = current -> next;
		     ++i;
	}while (current != rear -> next); 
	return 1;
}	
int queue_game::dequeue(){
	if(!rear) 
		return 0;

	if(rear == rear -> next) {
		delete rear;
		rear = nullptr;
		return 1;
	}

	queuenode * hold = rear -> next -> next;
	delete rear -> next;
	rear -> next = hold;

	return 1;

}
int queue_game::peek(game & other_game, series &other_series) const{
	if (!rear) {
		return 0;
	}
	queuenode * front = rear -> next;

	other_game.copy_game(front -> more_game);

	other_series.s_name = new char [strlen(front -> a_series. s_name) + 1];
	strcpy(other_series.s_name, front -> a_series.s_name);

	other_series.more_info = new char[strlen(front-> a_series.more_info) + 1];
	strcpy(other_series.more_info, front-> a_series.more_info);
/*
	cout << "Game Title: " << other_game.title << endl;
        cout << "platform:: " << other_game.platform << endl
	     << "Genre: " << other_game.genre <<endl
             << "Progression: " <<other_game.prograssion<<endl
	     << "Achievements: " <<other_game.prograssion<<endl
	     << "More Information: " << other_game.more_information << endl
	     << "Series Name: " << other_series. s_name<< endl
	     << "the devolper: " << other_series.more_info <<endl << endl;
*/	return 1;
}

queue_game::~queue_game(){
	if(!rear) {
		return;
	}

	queuenode *current = rear ->next;
	queuenode *temp = nullptr;

	do {
		temp = current;
		current = current ->next;

		delete[] temp -> more_game.title;
		delete[] temp ->more_game.platform;
		delete[] temp -> more_game.genre;
		delete[] temp -> more_game.prograssion;
		delete[] temp -> more_game.achievements;
		delete[] temp -> more_game.more_information;

		delete[] temp ->a_series.s_name;
		delete[] temp ->a_series.more_info;

		delete temp;
	}while(current != rear ->next);
	rear = nullptr;


}




