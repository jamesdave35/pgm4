
/*
 * Output.h
 *
 *  Created on: Feb 11, 2018
 *      Author: Joe
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Array.h"
#include "Ticket.hpp"

/**
 * The Output class allows output of various values to the console
 */
class Output {
public:
	// Output list of tickets
	static void outputTickets(const ContainerTemplate::Array<Ticket>& tickets);

	// Output summary of totals for list of tickets
	static void outputSummary(const ContainerTemplate::Array<Ticket>& tickets);

private:
	// Default constructor (use private to prevent creation)
	Output();
};

#endif /* OUTPUT_H_ */
