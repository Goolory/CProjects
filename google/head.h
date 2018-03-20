typedef struct 
{
	char c;
	int value;
	bool leading;
}CharItem;

typedef struct 
{
	bool used;
	int value;
}CharValue;

const int max_number_count = 10;
const int max_char_count = 9;

typedef void (*p)(CharItem ci[max_char_count]);