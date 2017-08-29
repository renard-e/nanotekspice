//
// 4013.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Fri Mar  3 14:36:25 2017 Rodrigue René
// Last update Sat Mar  4 01:30:06 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

void	Computer::fillerflipflop(nts::Processor *piece, int actual, int clock, int reset, int data, int set,int Q, int Q_, int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (actual == Q)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, clock, reset, data, set, actual]()->nts::Tristate
	{
	  nts::Tristate x = nts::UNDEFINED;
	  if (//std::get<2>(piece->_listPin[clock]) == nts::UNDEFINED ||
	      std::get<2>(piece->_listPin[reset]) == nts::UNDEFINED ||
	      std::get<2>(piece->_listPin[data]) == nts::UNDEFINED  ||
	      std::get<2>(piece->_listPin[set]) == nts::UNDEFINED)
	    return (nts::UNDEFINED);
	  if (std::get<2>(piece->_listPin[data]) == 0 &&
	      std::get<2>(piece->_listPin[reset]) == 0 &&
	      std::get<2>(piece->_listPin[set]) == 0 &&
	      std::get<2>(piece->_listPin[clock]) == 1)
	    std::get<2>(piece->_listPin[actual]) = 0;

	  else if (std::get<2>(piece->_listPin[data]) == 1 &&
	  	   std::get<2>(piece->_listPin[reset]) == 0 &&
	  	   std::get<2>(piece->_listPin[set]) == 0 &&
	  	   std::get<2>(piece->_listPin[clock]) == 1)
	    std::get<2>(piece->_listPin[actual]) = 1;


	  else if (std::get<2>(piece->_listPin[reset]) == 0 &&
	  	   std::get<2>(piece->_listPin[set]) == 0 &&
	  	   std::get<2>(piece->_listPin[clock]) == 0)
	    std::get<2>(piece->_listPin[actual]) = std::get<2>(piece->_listPin[actual]);


	  else if (std::get<2>(piece->_listPin[reset]) == 1 &&
	  	   std::get<2>(piece->_listPin[set]) == 0)
	    std::get<2>(piece->_listPin[actual]) = 0;


	  else if (std::get<2>(piece->_listPin[reset]) == 0 &&
	  	   std::get<2>(piece->_listPin[set]) == 1)
	    std::get<2>(piece->_listPin[actual]) = 1;

	  else if (std::get<2>(piece->_listPin[reset]) == 1 &&
	  	   std::get<2>(piece->_listPin[set]) == 1)
	    std::get<2>(piece->_listPin[actual]) = 1;

	  x = static_cast<nts::Tristate>(std::get<2>(piece->_listPin[actual]));
	  return (static_cast<nts::Tristate>(x));
	};
    }
  else if (actual == Q_)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, clock, reset, data, set, actual]()->nts::Tristate
  	{
  	  nts::Tristate x = nts::UNDEFINED;
  	  if (std::get<2>(piece->_listPin[clock]) == nts::UNDEFINED ||
  	      std::get<2>(piece->_listPin[reset]) == nts::UNDEFINED ||
  	      std::get<2>(piece->_listPin[data]) == nts::UNDEFINED  ||
  	      std::get<2>(piece->_listPin[set]) == nts::UNDEFINED)
  	    return (nts::UNDEFINED);

  	  else if (std::get<2>(piece->_listPin[data]) == 0 &&
  		   std::get<2>(piece->_listPin[reset]) == 0 &&
  		   std::get<2>(piece->_listPin[set]) == 0 &&
  		   std::get<2>(piece->_listPin[clock]) == 1)
  	    std::get<2>(piece->_listPin[actual]) = 1;

  	  else if (std::get<2>(piece->_listPin[data]) == 1 &&
  		   std::get<2>(piece->_listPin[reset]) == 0 &&
  		   std::get<2>(piece->_listPin[set]) == 0 &&
  		   std::get<2>(piece->_listPin[clock]) == 1)
  	    std::get<2>(piece->_listPin[actual]) = 0;

  	  else if (std::get<2>(piece->_listPin[reset]) == 0 &&
  		   std::get<2>(piece->_listPin[set]) == 0 &&
  		   std::get<2>(piece->_listPin[clock]) == 0)
  	    std::get<2>(piece->_listPin[actual]) = std::get<2>(piece->_listPin[actual]);

  	  else if (std::get<2>(piece->_listPin[reset]) == 1 &&
  		   std::get<2>(piece->_listPin[set]) == 0)
  	    std::get<2>(piece->_listPin[actual]) = 1;

  	  else if (std::get<2>(piece->_listPin[reset]) == 0 &&
  		   std::get<2>(piece->_listPin[set]) == 1)
  	    std::get<2>(piece->_listPin[actual]) = 0;

  	  else if (std::get<2>(piece->_listPin[reset]) == 1 &&
  		   std::get<2>(piece->_listPin[set]) == 1)
  	    std::get<2>(piece->_listPin[actual]) = 1;

  	  x = static_cast<nts::Tristate>(std::get<2>(piece->_listPin[actual]));
  	  return (static_cast<nts::Tristate>(x));
  	};
    }
}
// int actual, int clock, int reset, int data, int set,int Q, int Q_, int type) const
nts::IComponent	*Computer::create4013(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4013", value);
  piece->_name = value;
  piece->_typeProc = "4013";

  //pin3 Clock
  filler(piece, 3, 1, 2, 2);
  //pin4 Input Reset 1
  filler(piece, 4, 5, 6, 2);
  //pin5 Input Data 1
  filler(piece, 5, -1, -1, 0);
  //pin6 Input Set 1
  filler(piece, 6, -1, -1, 0);
  //pin7 vss
  filler(piece, 7, -1, -1, 0);
  //pin8
  filler(piece, 8, -1, -1, 0);
  //pin9
  filler(piece, 9, -1, -1, 0);
  //pin10
  filler(piece, 10, 8, 9, 2);
  //pin11
  filler(piece, 11, 12, 13, 2);
  //pin12
  filler(piece, 12, -1, -1, 0);
  //pin13
  filler(piece, 13, -1, -1, 0);
  //pin14 vdd
  filler(piece, 14, -1, -1, 0);
    //pin1 output Q
  fillerflipflop(piece, 1, 3, 4, 5, 6, 1, 2, 2);
  std::get<5>(piece->_listPin[1]).push_back(3);
  std::get<5>(piece->_listPin[1]).push_back(4);
  std::get<5>(piece->_listPin[1]).push_back(5);
  std::get<5>(piece->_listPin[1]).push_back(6);

  //pin2 output Q|
  fillerflipflop(piece, 2, 3, 4, 5, 6, 1, 2, 2);
  std::get<5>(piece->_listPin[2]).push_back(3);
  std::get<5>(piece->_listPin[2]).push_back(4);
  std::get<5>(piece->_listPin[2]).push_back(5);
  std::get<5>(piece->_listPin[2]).push_back(6);

  piece->_maxPin = 14;
  return (dynamic_cast<nts::IComponent *>(piece));
}
