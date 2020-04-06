#include<exception>
using namespace std;

class LimitException: public exception{	virtual const char* what() const throw(); };
class CommandException: public exception{ virtual const char* what() const throw(); };
class IOException: public exception{ virtual const char* what() const throw(); };
class ParseException: public exception{	virtual const char* what() const throw(); };
class TimeoutException: public exception{ virtual const char* what() const throw(); };