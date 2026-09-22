/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:44:48 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/04 20:44:48 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <exception>

Base *	generate() {
	int seed = std::clock();
	std::srand (seed);
	int random_value = std::rand() % 3;
	if (random_value == 0) {
		std::cout << "A created" << std::endl;
		return (new A);
	}
	else if (random_value == 1) {
		std::cout << "B created" << std::endl;
		return (new B);
	}
	else {
		std::cout << "C created" << std::endl;
		return (new C);
	}
}

void	identify(Base &p) {
	std::string type;
	try {
		A& AType = dynamic_cast<A&>(p);
		type = "Class A object.";
		(void)AType;
	}
	catch (std::exception &e) {
		type = "";
	}
	if (type == "") {
		try {
			B& BType = dynamic_cast<B&>(p);
			type = "Class B object.";
			(void)BType;
		}
		catch (std::exception &e) {
			type = "";
		}
	}
	if (type == "") {
		try {
			C& CType = dynamic_cast<C&>(p);
			type = "Class C object.";
			(void)CType;
		}
		catch (std::exception &e) {
			type = "";
		}
	}
	if (type != "")
		std::cout << "Input is a reference to " << type << std::endl;
	else
		std::cout << "input is not a reference to any object derived of Base class"
				<< std::endl;
}

void	identify(Base *p) {
	A*	AType = dynamic_cast<A*>(p);
	B*	BType = dynamic_cast<B*>(p);
	C*	CType = dynamic_cast<C*>(p);
	if (AType != 0)
		std::cout << "Input is a ptr to Class A object." << std::endl;
	else if (BType != 0)
		std::cout << "Input is a ptr to Class B object." << std::endl;
	else if (CType != 0)
		std::cout << "Input is a ptr to Class C object." << std::endl;
	else
	std::cout << "input is not a ptr to any object derived of Base class"
			<< std::endl;
}

int	main(void) {
	std::cout << std::endl << "----POINTER TEST----" << std::endl;
	Base* a = generate();
	Base* b = generate();
	Base* c = generate();
	Base* d = generate();
	identify(a);
	identify(b);
	identify(c);
	identify(d);
	std::cout << std::endl << "----REFERENCE TEST----" << std::endl;
	Base& e = *a;
	Base& f = *b;
	Base& g = *c;
	Base& h = *d;
	identify(e);
	identify(f);
	identify(g);
	identify(h);
	delete a;
	delete b;
	delete c;
	delete d;
}
