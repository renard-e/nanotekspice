//
// Computer.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sun Feb 12 16:43:38 2017 Rodrigue René
// Last update Sun Mar  5 20:26:33 2017 Rodrigue René
//

#include <string>
#include <tuple>
#include "Computer.hpp"

//typedef nts::IComponent (Computer::*func)(std::string &value)
// std::function<nts::IComponent *(const std::string &)>

T_TUPLECOMP	Computer::filltuple(int nb_pin, func function)
{
  T_TUPLECOMP	myTuple;

  std::get<0>(myTuple) = std::bind(function, this, std::placeholders::_1);
  std::get<1>(myTuple) = nb_pin;
  return (myTuple);
}

Computer::Computer()
{
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("true", filltuple(1, &Computer::createTrue )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("false", filltuple(1, &Computer::createFalse )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("clock", filltuple(1, &Computer::createClock )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("input", filltuple(1, &Computer::createInput )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("output", filltuple(1, &Computer::createOutput )));
  // listComponentValable.insert (std::pair<std::string, int>("2716",24));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4001", filltuple(14, &Computer::create4001 )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4008", filltuple(16, &Computer::create4008 )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4011", filltuple(14, &Computer::create4011 )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4013", filltuple(14, &Computer::create4013 )));

  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4017", filltuple(16, &Computer::create4017 )));

  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4030", filltuple(14, &Computer::create4030 )));

  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4040", filltuple(16, &Computer::create4040 )));

  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4069", filltuple(14, &Computer::create4069 )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4071", filltuple(14, &Computer::create4071 )));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4081", filltuple(14, &Computer::create4081 )));


  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4094", filltuple(16, &Computer::create4094 )));

  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4503", filltuple(16, &Computer::create4503 )));
  // listComponentValable.insert (std::pair<std::string, int>("4512",16));
  listComponentValable.insert (std::pair<std::string, T_TUPLECOMP >
			       ("4514", filltuple(24, &Computer::create4514 )));
  // listComponentValable.insert (std::pair<std::string, int>("i4004",16));
  // listComponentValable.insert (std::pair<std::string, int>("mk4801",24)); A FAIRE
}

Computer::~Computer()
{

}

nts::IComponent *Computer::createComponent(const std::string &type, const std::string &value)
{
  nts::Processor *x;
  auto it = listComponentValable.find(type);

  x = dynamic_cast<nts::Processor *>(std::get<0>(it->second)(value));
  return (x);
}

void  Computer::addComponent(nts::IComponent *chipset, std::string const &name)
{
  std::map<std::string, nts::IComponent *>::iterator it = devices.end();
  devices.insert (it, std::pair<std::string, nts::IComponent *>(name, chipset));
}

void	Computer::dump()
{
  for (auto it = devices.begin(); it != devices.end();it++)
      (it->second)->Dump();
}

void	Computer::display()
{
  for (auto it = devices.begin(); it != devices.end();it++)
    if (dynamic_cast<nts::Processor*>(it->second)->_typeProc == "output")
      std::cout<< dynamic_cast<nts::Processor*>(it->second)->_name<<"="<<(it->second)->Compute(1)<<std::endl;
}

void	Computer::simulate()
{
  for (auto it = devices.begin(); it != devices.end(); it++)
    if (dynamic_cast<nts::Processor*>(it->second)->_typeProc == "output")
      dynamic_cast<nts::Processor*>(it->second)->Simulate();

  for (auto it = devices.begin(); it != devices.end(); it++)
    if (dynamic_cast<nts::Processor*>(it->second)->_typeProc == "clock")
      {
	if (std::get<2>(dynamic_cast<nts::Processor*>(it->second)->_listPin[1]) == nts::TRUE)
	  std::get<2>(dynamic_cast<nts::Processor*>(it->second)->_listPin[1]) = nts::FALSE;
	else
	  std::get<2>(dynamic_cast<nts::Processor*>(it->second)->_listPin[1]) = nts::TRUE;
      }
}
