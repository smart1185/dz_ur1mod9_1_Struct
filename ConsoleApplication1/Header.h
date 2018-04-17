struct Player
{
	char *Name;
	int *Age;
	int *Games;
	int *Goals;
};

struct Goods
{
	char *Product;
	char *Producer;
	int *Year;
	int *Qnt;
	double *Price;
};


struct ExpDate
{
	int *day;
	int *month;
	int *year;
};
struct MeGoods
{
	char *Product;
	int *Qnt;
	double *Price;
	char *Producer;
	ExpDate *Date;

};

struct Worker
{
	char *Name;
	int *Year;
	char *Position;
	double *Payment;
	char *Education;
};

struct Students
{
	char *Name;
	char *Group;
	int *Year;
	int *FisMark;
	int *MathMark;
	int *InfoMark;
};

void generateName(char * name);
void generateAge(int *plAge);
void generateGames(int *games);
void generateGoals(int *goals);

void generateProduct(char *product);
void generateProducer(char *producer);
void generateYear(int *year, int start, int end);
void generateQnt(int *qnt);
void generatePrice(double *qnt);

void generateExpDate(ExpDate *date);

void generatePosition(char *Pos);
void generateEducation(char *Education);

void genetrateGroup(char *group);