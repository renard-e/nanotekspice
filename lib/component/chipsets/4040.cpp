//
// 4040.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sat Mar  4 18:11:52 2017 Rodrigue René
// Last update Sat Mar  4 19:52:10 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

void	Computer::filler4040(nts::Processor *piece, int actual, int first, int , int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (type == 2)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, first, actual]()->nts::Tristate
	{
	  static int x, tour;
	  int i = 0;
	  if (std::get<2>(piece->_listPin[11]) == nts::TRUE)
	    {
	      std::get<2>(piece->_listPin[actual]) = nts::FALSE;
	      tour = 0;
	      return static_cast<nts::Tristate>(std::get<2>(piece->_listPin[actual]));
	    }
	  else if (std::get<2>(piece->_listPin[10]) == nts::TRUE)
	    {
	      x = 0;
	    }
	  else
	    {
	      tour++;
	      if (x == 0 && std::get<2>(piece->_listPin[actual]) == nts::TRUE)
		{
		  std::get<2>(piece->_listPin[actual]) = nts::FALSE;
		  switch (actual)
		    {
		    case 1:
		      i = 9;
		      break;
		    case 2:
		      i = 4;
		      break;
		    case 3:
		      i = 2;
		      break;
		    case 4:
		      i = 13;
		      break;
		    case 5:
		      i = 3;
		      break;
		    case 6:
		      i = 5;
		      break;
		    case 7:
		      i = 6;
		      break;
		    case 9:
		      i = 7;
		      break;
		    case 12:
		      i = 14;
		      break;
		    case 13:
		      i = 12;
		      break;
		    case 14:
		      i = 15;
		      break;
		    case 15:
		      i = 1;
		      break;
		    }
		  std::get<2>(piece->_listPin[i]) = nts::TRUE;
		  x = 1;
		}
	    }
	  if (tour == 1 && std::get<2>(piece->_listPin[10]) == nts::FALSE)
	    {
	      std::get<2>(piece->_listPin[9]) = nts::TRUE;
	      x = 1;
	    }
	  if (std::get<2>(piece->_listPin[actual]) == nts::UNDEFINED)
	    std::get<2>(piece->_listPin[actual]) = nts::FALSE;
	  return static_cast<nts::Tristate>(std::get<2>(piece->_listPin[actual]));
	};
    }
}

nts::IComponent	*Computer::create4040(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4040", value);

  piece->_name = value;
  piece->_typeProc = "4040";
  //pin1 Q12
  filler4040(piece, 1, -1, -1, 2);
  std::get<5>(piece->_listPin[1]).push_back(10);
  std::get<5>(piece->_listPin[1]).push_back(11);
  //pin2 Q6
  filler4040(piece, 2, -1, -1, 2);
  std::get<5>(piece->_listPin[2]).push_back(10);
  std::get<5>(piece->_listPin[2]).push_back(11);
  //pin3 Q5
  filler4040(piece, 3, 1, 2, 2);
  std::get<5>(piece->_listPin[3]).push_back(10);
  std::get<5>(piece->_listPin[3]).push_back(11);
  //pin4 Q7
  filler4040(piece, 4, 5, 6, 2);
  std::get<5>(piece->_listPin[4]).push_back(10);
  std::get<5>(piece->_listPin[4]).push_back(11);
  //pin5 Q4
  filler4040(piece, 5, -1, -1, 2);
  std::get<5>(piece->_listPin[5]).push_back(10);
  std::get<5>(piece->_listPin[5]).push_back(11);
  //pin6 Q3
  filler4040(piece, 6, -1, -1, 2);
  std::get<5>(piece->_listPin[6]).push_back(10);
  std::get<5>(piece->_listPin[6]).push_back(11);
  //pin7 Q2
  filler4040(piece, 7, -1, -1, 2);
  std::get<5>(piece->_listPin[7]).push_back(10);
  std::get<5>(piece->_listPin[7]).push_back(11);
  //pin8 VSS
  filler(piece, 8, -1, -1, 0);
  //pin9 Q1
  filler4040(piece, 9, -1, -1, 2);
  std::get<5>(piece->_listPin[9]).push_back(10);
  std::get<5>(piece->_listPin[9]).push_back(11);
  //pin10 C
  filler(piece, 10, 8, 9, 0);
  //pin11 R
  filler(piece, 11, -1, 13, 0);

  //pin12 Q9
  filler4040(piece, 12, -1, -1, 2);
  std::get<5>(piece->_listPin[12]).push_back(10);
  std::get<5>(piece->_listPin[12]).push_back(11);
  //pin13 Q8
  filler(piece, 13, -1, -1, 2);
  std::get<5>(piece->_listPin[13]).push_back(10);
  std::get<5>(piece->_listPin[13]).push_back(11);
  //pin14 Q10
  filler4040(piece, 14, -1, -1, 2);
  std::get<5>(piece->_listPin[14]).push_back(10);
  std::get<5>(piece->_listPin[14]).push_back(11);
  //pin15 Q11
  filler4040(piece, 15, -1, -1, 2);
  std::get<5>(piece->_listPin[15]).push_back(10);
  std::get<5>(piece->_listPin[15]).push_back(11);
  //pin16//VDD
  filler(piece, 16, -1, -1, 0);

  piece->_maxPin = 16;
  return (dynamic_cast<nts::IComponent *>(piece));
}
