// .h file
// Aqdas Juya , 10/22/2024 ,≈ ajuya@pdx.edu ,  program # 2, cs 163
#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

struct game {
	game();
	~game();
	char * title;
	char * platform;
	char * genre;
	char * prograssion;
	char * achievements;
	char * more_information;
	int copy_game(const game &source);
};
struct stacknode {
	game* all_games;
	stacknode * next;
};

struct series {
        char *s_name;
        char * more_info;
};

struct queuenode {
        game more_game;
        series a_series;
        queuenode *next;
};

const int MAX = 5;
class gamestack {
	public:
		gamestack();
		~gamestack();

		int push(const game & to_add);
		int pop();
		int peek(game &other_game) const;
		int display() const;
	private:
		stacknode * head;
		int index;
};
class queue_game {
	public:
		queue_game();
		~queue_game();

		int enqueue(const game &to_add, const char *s_name, const char *more_info);
		int dequeue();
		int peek(game & other_game,series & other_series) const;
		bool display() const;
	private:
		queuenode * rear;
};

