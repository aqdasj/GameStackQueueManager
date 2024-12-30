// Aqdas Juya , 10/25/2024 , ajuya@pdx.edu ,  Program # 2, cs 163
#include "game.h"
#include <iostream>

using namespace std;

int main() {

	const int SIZE = 100;
	gamestack my_stack;
	queue_game my_queue;
	game top_game;
	series next_series;
	int choice;

	do {
		cout <<"1. Add a new game: \n";
		cout <<"2. Display all the games: \n";
		cout <<"3. peek at the top game in the stack: \n";
		cout <<"4. pop the top game: \n";
		cout <<"5. Enqueue the most rescent game: \n";
		cout <<"6. Display all the games with queue added: \n";
		cout <<"7. Dequeue the first game int the queue\n";
		cout <<"8. peek at the top of the game in the queue \n";
		cout <<"9. Exit\n";
		cout <<"\nPlease enter your choise: ";
		cin >> choice;
		cin.ignore();

		if(choice == 1) {
			game my_game;
			
			my_game.title = new char[SIZE];
			cout << "Enter the game is name: ";
			cin.get(my_game.title,SIZE,'\n');
			cin.ignore(100,'\n');

                        my_game.platform = new char[SIZE];
                        cout << "Enter the platform: ";
                        cin.get(my_game.platform,SIZE,'\n');
                        cin.ignore(100,'\n');

                        my_game.genre = new char[SIZE];
                        cout << "Enter the genre: ";
                        cin.get(my_game.genre,SIZE,'\n');
                        cin.ignore(100,'\n');

                        my_game.prograssion= new char[SIZE];
                        cout << "Enter the prograssion ";
                        cin.get(my_game.prograssion,SIZE,'\n');
                        cin.ignore(100,'\n');

                        my_game.achievements= new char[SIZE];
                        cout << "Enter the game is achievements: ";
                        cin.get(my_game.achievements,SIZE,'\n');
                        cin.ignore(100,'\n');


                        my_game.more_information= new char[SIZE];
                        cout << "Enter more information: ";
                        cin.get(my_game.more_information,SIZE,'\n');
                        cin.ignore(100,'\n');

			my_stack.push(my_game);
		}else if (choice == 2) {
			if(!my_stack.display()){
				cout << "No stack to display" <<endl;
			}
		}
		else if(choice == 3) {
			game top_game;

			if(my_stack.peek(top_game)) { 
				cout << "the top games:\n";
				cout << "title: " <<top_game.title << "\n";
				cout << "Platform: " <<top_game.platform << "\n";
				cout << "genre: " <<top_game.genre<< "\n";
				cout << "Progression: " <<top_game.prograssion<< "\n";	
				cout << "achievements: " <<top_game.achievements<< "\n";
				cout << "information: " <<top_game.more_information<< "\n";
			} else {
				cout << "the stack is empty\n";
			}

		}
		else if(choice == 4) {
                        if(my_stack.pop()) {
                                cout << "the top game is removed\n";
                        } else {
                                cout << "the stack is empty\n";
                        }
		}
		else if(choice == 5) {
			if(my_stack.peek(top_game)) {
				char series_name[SIZE];
				cout << "Enter the series name; ";
				cin.get(series_name,SIZE,'\n');
				cin.ignore(100, '\n');

				char more_information[SIZE];
				cout << "Enter the develper is name: ";
				cin.get(more_information, SIZE, '\n');
				cin.ignore(100, '\n');

				my_queue.enqueue(top_game, series_name, more_information);
				cout<< "The games are enqueued." << endl;
			}else {
				cout<< "There are no games in the stack to enqueue." << endl;
			}	
		}
		else if(choice == 6) {
			if(!my_queue.display()) {
				cout << "The queue is empty. So no games is to display." << endl;
			} 
		}

		else if(choice == 7) {
			if(!my_queue.dequeue()) {
				cout << "The queue is empty." << endl;
			}else {
				cout << "The first game in the queue have been dequeued." << endl;
			}
		}
		else if(choice == 8) {
			if(my_queue.peek(top_game, next_series)) {
				cout << "Game Title: " << top_game.title << endl;
				cout << "platform:: " << top_game.platform << endl
			   	     << "Genre: " << top_game.genre <<endl
				     << "Progression: " << top_game.prograssion<<endl
				     << "Achievements: " << top_game.prograssion<<endl
				     << "More Information: " << top_game.more_information << endl
				     << "Series Name: " << next_series.s_name<< endl
				     << "the devolper: " << next_series.more_info <<endl << endl;
			}else {
				cout << "There is no game on the queue to display." << endl;
			}
		}
	}while( choice != 9);


	return 0;
}
