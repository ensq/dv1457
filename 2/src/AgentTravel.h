#ifndef AGENTTRAVEL_H
#define AGENTTRAVEL_H

#include "Executioner.h"

class AgentTravel {
public:
	AgentTravel();
	~AgentTravel();

	static bool execute( ActionTravel* p_action, Result& io_result );
protected:
private:
	static bool executeLook();
	static bool executeTravel( ActionTravel* p_action, Result& io_result );

	static bool condObjectCarry(unsigned int p_objectId);
	static bool condObjectLocation(unsigned int p_objectId);
};

#endif // AGENTTRAVEL_H