//
// 4094.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sun Mar  5 11:53:25 2017 Rodrigue René
// Last update Sun Mar  5 20:32:53 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

void	Computer::filler4094(nts::Processor *piece, int actual, int clock, int OE,
			     int strobe,int data, int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (type == 2)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, clock, strobe, data, actual, OE]()->nts::Tristate
	{
	  int x;

	  if (std::get<2>(piece->_listPin[clock]) == 1 && std::get<2>(piece->_listPin[OE]) == 0)
	    {
	      x = nts::TRUE;
	      if (actual == 9)
		x = std::get<2>(piece->_listPin[12]);
	    }
	  else if (std::get<2>(piece->_listPin[clock]) == 0 && std::get<2>(piece->_listPin[OE]) == 0)
	    {
	      x = nts::TRUE;
	      if (actual == 10)
		x = std::get<2>(piece->_listPin[12]);
	    }
	  else if (std::get<2>(piece->_listPin[clock]) == 1 &&
		   std::get<2>(piece->_listPin[OE]) == 1 &&
		   std::get<2>(piece->_listPin[strobe]) == 0)
	    {
	      x = std::get<2>(piece->_listPin[actual]);
	      if (actual == 9)
		x = std::get<2>(piece->_listPin[12]);
	    }
	  else if (std::get<2>(piece->_listPin[clock]) == 1 &&
		   std::get<2>(piece->_listPin[OE]) == 1  &&
		   std::get<2>(piece->_listPin[strobe]) == 1 &&
		   std::get<2>(piece->_listPin[data]) == 0)
	    {
	      x = nts::FALSE;
	      if (actual == 9)
		x = std::get<2>(piece->_listPin[12]);
	    }
	  else if (std::get<2>(piece->_listPin[clock]) == 1 &&
		   std::get<2>(piece->_listPin[OE]) == 1  &&
		   std::get<2>(piece->_listPin[strobe]) == 1 &&
		   std::get<2>(piece->_listPin[data]) == 1)
	    {
	      x = nts::TRUE;
	      if (actual == 9)
		x = std::get<2>(piece->_listPin[12]);
	    }
	  else if (std::get<2>(piece->_listPin[clock]) == 0 &&
		   std::get<2>(piece->_listPin[OE]) == 1  &&
		   std::get<2>(piece->_listPin[strobe]) == 1 &&
		   std::get<2>(piece->_listPin[data]) == 1)
	    {
	      x = std::get<2>(piece->_listPin[actual]);
	      if (actual == 10)
		x = std::get<2>(piece->_listPin[12]);
	    }
	  std::get<2>(piece->_listPin[actual]) = x;
	  return static_cast<nts::Tristate>(x);
	};

    }

}

nts::IComponent	*Computer::create4094(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4094", value);
  //  std::cout<<"create4081"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "4094";
  //pin1 STROBE
  filler(piece, 1, -1, -1, 0);
  //pin2 DATA
  filler(piece, 2, -1, -1, 0);
  //pin3 CLOCK
  filler(piece, 3, 1, 2, 2);
  //pin4 Q1
  filler4094(piece, 4, 3, 15, 1, 2 ,2);
  std::get<5>(piece->_listPin[4]).push_back(1);
  std::get<5>(piece->_listPin[4]).push_back(2);
  std::get<5>(piece->_listPin[4]).push_back(3);
  std::get<5>(piece->_listPin[4]).push_back(15);

  //pin5 Q2
  filler4094(piece, 5, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[5]).push_back(1);
  std::get<5>(piece->_listPin[5]).push_back(2);
  std::get<5>(piece->_listPin[5]).push_back(3);
  std::get<5>(piece->_listPin[5]).push_back(15);

  //pin6 Q3
  filler4094(piece, 6, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[6]).push_back(1);
  std::get<5>(piece->_listPin[6]).push_back(2);
  std::get<5>(piece->_listPin[6]).push_back(3);
  std::get<5>(piece->_listPin[6]).push_back(15);

  //pin7 Q4
  filler4094(piece, 7, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[7]).push_back(1);
  std::get<5>(piece->_listPin[7]).push_back(2);
  std::get<5>(piece->_listPin[7]).push_back(3);
  std::get<5>(piece->_listPin[7]).push_back(15);

  //pin8 VSS
  filler(piece, 8, -1,-1, 0);
  //pin9 QS
  filler4094(piece, 9,3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[9]).push_back(1);
  std::get<5>(piece->_listPin[9]).push_back(2);
  std::get<5>(piece->_listPin[9]).push_back(3);
  std::get<5>(piece->_listPin[9]).push_back(15);

  //pin10 QS'
  filler4094(piece, 10, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[10]).push_back(1);
  std::get<5>(piece->_listPin[10]).push_back(2);
  std::get<5>(piece->_listPin[10]).push_back(3);
  std::get<5>(piece->_listPin[10]).push_back(15);

  //pin11 Q8
  filler4094(piece, 11, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[11]).push_back(1);
  std::get<5>(piece->_listPin[11]).push_back(2);
  std::get<5>(piece->_listPin[11]).push_back(3);
  std::get<5>(piece->_listPin[11]).push_back(15);

  //pin12 Q7
  filler4094(piece, 12, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[12]).push_back(1);
  std::get<5>(piece->_listPin[12]).push_back(2);
  std::get<5>(piece->_listPin[12]).push_back(3);
  std::get<5>(piece->_listPin[12]).push_back(15);

  //pin13 Q6
  filler4094(piece, 13, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[13]).push_back(1);
  std::get<5>(piece->_listPin[13]).push_back(2);
  std::get<5>(piece->_listPin[13]).push_back(3);
  std::get<5>(piece->_listPin[13]).push_back(15);

  //pin14 Q5
  filler4094(piece, 14, 3, 15, 1, 2, 2);
  std::get<5>(piece->_listPin[14]).push_back(1);
  std::get<5>(piece->_listPin[14]).push_back(2);
  std::get<5>(piece->_listPin[14]).push_back(3);
  std::get<5>(piece->_listPin[14]).push_back(15);

  //pin15 OE
  filler(piece, 15, -1, -1, 0);
  //pin16 VDD
  filler(piece, 16, -1, -1, 0);




  piece->_maxPin = 16;
  return (dynamic_cast<nts::IComponent *>(piece));
}
