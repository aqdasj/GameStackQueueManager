// Aqdas Juya , 10/25/2024 , ajuya@pdx.edu ,  Program # 2, cs 163
// program_one.cpp

#include "game.h"
using namespace std;

gamestack::gamestack() {
	head = nullptr;
	index = 0;
}

int gamestack::push(const game & to_add){
	if(!head || index == 5) {
                stacknode * newnode = new stacknode;
                newnode -> all_games = new game[5];
                newnode->next = head;
                head = newnode;
                index=0;
        }
	head ->all_games[index].copy_game(to_add);

	++index;
        return 1;
}
int  game::copy_game(const game &source) {

	title = new char[strlen(source.title)+1];
        strcpy(title,source.title);

        platform = new char[strlen(source.platform)+1];
        strcpy(platform,source.platform);
        
	genre = new char[strlen(source.genre)+1];
        strcpy(genre,source.genre);
        
	prograssion = new char[strlen(source.prograssion)+1];
        strcpy(prograssion,source.prograssion);

	achievements = new char[strlen(source.achievements)+1];
        strcpy(achievements,source.achievements);

        more_information = new char[strlen(source.more_information)+1];
        strcpy(more_information,source.more_information);

        return 1;		
		
}

int gamestack::pop(){
	if(!head) {
		return 0;
	}
	--index;
	if (index == 0) {
		stacknode * hold = head->next;
		

		delete[] head ->all_games;
		head -> all_games = NULL;
		delete head;
		head = hold;

		index = MAX;
	}
	return 1;
}
int gamestack::peek(game &high_game) const{

	if(!head) {
		return 0;
	}


	high_game.copy_game(head -> all_games[index-1]);
	return 1;
}
int gamestack::display() const {

	if(!head) {
		return 0;
	}

	stacknode * current = head;

	while (current) {
		int i_n;

		if(current == head) {
			i_n = index;
		} else { 
			i_n = 5;
		}
		for( int i =0; i < i_n; ++i) {
		       cout << "\nGame name: " << current -> all_games[i].title << "\n";
		       cout << "\nPlatform: " << current -> all_games[i].platform << "\n";
                       cout << "\nGenre: " << current -> all_games[i].genre << "\n";
                       cout << "\nProgression: " << current -> all_games[i].prograssion<< "\n";
                       cout << "\nAchievements: " << current -> all_games[i].achievements << "\n";
                       cout << "\nMore Information: " << current -> all_games[i].more_information << "\n";
		}
		current = current ->next;
	}
	return 1;
}
game::game() {
	title = NULL;
	platform = NULL;
	genre = NULL;
	prograssion = NULL;
	achievements = NULL;
	more_information = NULL;
}

game::~game(){
	delete[] title;
	title = NULL;
	delete[] platform;
	platform = NULL;
	delete[] genre;
	genre = NULL;
	delete[] prograssion;
	prograssion = NULL;
	delete[] achievements;
	achievements = NULL;
	delete[] more_information;
	more_information = NULL;
}


gamestack::~gamestack(){
     	
	stacknode *hold;

	while(head){
		hold = head -> next;
		for(int i=0; i< index; ++i){
			delete [] head -> all_games;
			head ->all_games =NULL;

		}
		delete[] head->all_games;
		head -> all_games = NULL;
		head = hold;
		index = MAX;


	}
}

