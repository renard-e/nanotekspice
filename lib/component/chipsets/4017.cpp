//
// 4017.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sat Mar  4 01:58:29 2017 Rodrigue René
// Last update Sat Mar  4 18:11:04 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

void	Computer::filler4017(nts::Processor *piece, int actual, int first, int , int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (type == 2)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, first, actual]()->nts::Tristate
	{
	  static int x, tour;
	  int i = 0;
	  tour++;
	  if (std::get<2>(piece->_listPin[14]) == nts::FALSE)
	    {
	      x = 0;
	    }
	  else
	    {
	      if (x == 0 && std::get<2>(piece->_listPin[actual]) == nts::TRUE)
		{
		  std::get<2>(piece->_listPin[actual]) = nts::FALSE;
		  switch (actual)
		    {
		    case 1:
		      i = 5;
		      break;
		    case 2:
		      i = 4;
		      break;
		    case 3:
		      i = 2;
		      break;
		    case 4:
		      i = 7;
		      break;
		    case 5:
		      i = 6;
		      break;
		    case 6:
		      i = 9;
		      break;
		    case 7:
		      i = 10;
		      break;
		    case 9:
		      i = 11;
		      break;
		    case 10:
		      i = 5;
		      break;
		    case 11:
		      i = 3;
		      break;
		    }
		  std::get<2>(piece->_listPin[i]) = nts::TRUE;
		  if (i == 2 || i == 3 || i == 4 || i == 7 || i == 10)
		    std::get<2>(piece->_listPin[12]) = nts::TRUE;
		  else
		    std::get<2>(piece->_listPin[12]) = nts::FALSE;
		  x = 1;
		}
	      if (tour == 1)
		{
		  std::get<2>(piece->_listPin[3]) = nts::TRUE;
		  std::get<2>(piece->_listPin[12]) = nts::TRUE;
		  x = 1;
		}
	      else if (std::get<2>(piece->_listPin[actual]) == nts::UNDEFINED)
		std::get<2>(piece->_listPin[actual]) = nts::FALSE;
	    }
	  return static_cast<nts::Tristate>(std::get<2>(piece->_listPin[actual]));
	};
    }
}

nts::IComponent	*Computer::create4017(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4017", value);

  piece->_name = value;
  piece->_typeProc = "4017";
  //pin1 Q5
  filler4017(piece, 1, -1, -1, 2);
  std::get<5>(piece->_listPin[1]).push_back(14);
  //pin2 Q1
  filler4017(piece, 2, -1, -1, 2);
  std::get<5>(piece->_listPin[2]).push_back(14);

  //pin3 Q0
  filler4017(piece, 3, 1, 2, 2);
  std::get<5>(piece->_listPin[3]).push_back(14);

  //pin4 Q2
  filler4017(piece, 4, 5, 6, 2);
  std::get<5>(piece->_listPin[4]).push_back(14);
  //pin5 Q6
  filler4017(piece, 5, -1, -1, 2);
  std::get<5>(piece->_listPin[5]).push_back(14);

  //pin6 Q7
  filler4017(piece, 6, -1, -1, 2);
  std::get<5>(piece->_listPin[6]).push_back(14);

  //pin7 Q3
  filler4017(piece, 7, -1, -1, 2);
  std::get<5>(piece->_listPin[7]).push_back(14);

  //pin8
  filler(piece, 8, -1, -1, 0);

  //pin9 Q8
  filler4017(piece, 9, -1, -1, 2);
  std::get<5>(piece->_listPin[9]).push_back(14);

  //pin10 Q4
  filler4017(piece, 10, 8, 9, 2);
  std::get<5>(piece->_listPin[10]).push_back(14);

  //pin11 O9
  filler4017(piece, 11, -1, 13, 2);
  std::get<5>(piece->_listPin[11]).push_back(14);

  //pin12
  filler4017(piece, 12, -1, -1, 2);
  std::get<5>(piece->_listPin[12]).push_back(14);
  //pin13 CLOCK|
  filler(piece, 13, -1, -1, 0);
  //pin14 CLOCK
  filler(piece, 14, -1, -1, 0);
  //pin15 RESET
  filler(piece, 15, -1, -1, 0);
  //pin16
  filler(piece, 16, -1, -1, 0);

  piece->_maxPin = 16;
  return (dynamic_cast<nts::IComponent *>(piece));
}
