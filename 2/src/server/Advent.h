#ifndef ADVENT_H
#define ADVENT_H

#include <string>

#include "Formatter.h"
#include "AdventData.h"
#include "Interpreter.h"
#include "Executioner.h"

const static std::string filepathAdventdat = "../advent/advent.dat";
const static unsigned adventurerStartingLocation = 1;

class Advent {
public:
	Advent( int p_sockfd, std::string p_player );
	~Advent();

	bool load();
	bool play( std::string p_in );
protected:
private:
	bool m_running;
	AdventData m_ad;

	Formatter*		m_formatter;
	Interpreter* 	m_interpreter;
	Executioner* 	m_executioner;
};

#endif // ADVENT_H