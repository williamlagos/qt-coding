#include"Exceptions.h"

const char* LimitException::what() const throw(){ return "Numero fora do alcance desejado."; }
const char* CommandException::what() const throw(){ return "Comando invalido."; }
const char* IOException::what() const throw(){ return "Nao foi possivel ler do arquivo."; }
const char* ParseException::what() const throw(){ return "Nao foi possivel executar o parse do arquivo."; }
const char* TimeoutException::what() const throw(){ return "Tempo de requisicao esgotado."; }