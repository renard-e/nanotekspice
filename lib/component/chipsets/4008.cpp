//
// 4008.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Wed Mar  1 15:27:53 2017 Rodrigue René
// Last update Sun Mar  5 18:39:33 2017 Rodrigue René
//


#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

void	Computer::filler4008(nts::Processor *piece, int actual, int first,
			     int second, int type,int cIn, int cOut) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (type == 2)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, first, second, cIn, actual, cOut]()->nts::Tristate
	{
	  nts::Tristate x;
	  // if (std::get<2>(piece->_listPin[cIn]) == nts::UNDEFINED)
	  //   return (nts::UNDEFINED);

	  if (std::get<2>(piece->_listPin[cIn]) == nts::TRUE)
	    {
	      x = static_cast<nts::Tristate>(std::get<2>(piece->_listPin[first]) ^
					     std::get<2>(piece->_listPin[second]));
	      if (actual == cOut)
		{
		  x = static_cast<nts::Tristate>(/*A*/( std::get<2>(piece->_listPin[7]) &&
							std::get<2>(piece->_listPin[5]) &&
							std::get<2>(piece->_listPin[3]) &&
							std::get<2>(piece->_listPin[1]) )
						 ||
						 /*B*/( std::get<2>(piece->_listPin[6]) &&
							std::get<2>(piece->_listPin[4]) &&
							std::get<2>(piece->_listPin[2]) &&
							std::get<2>(piece->_listPin[15]) ));
		}
	    }
	  else if (std::get<2>(piece->_listPin[cIn]) == nts::FALSE)
	    {
	      x = static_cast<nts::Tristate>(std::get<2>(piece->_listPin[first]) ^!
					     std::get<2>(piece->_listPin[second]));
	      if (actual == cOut)
		{
		  x = static_cast<nts::Tristate>(/*A*/(std::get<2>(piece->_listPin[7]) &&
						       std::get<2>(piece->_listPin[5]) &&
						       std::get<2>(piece->_listPin[3]) &&
						       std::get<2>(piece->_listPin[1]) )
						 &&
						 /*B*/(std::get<2>(piece->_listPin[6]) &&
						       std::get<2>(piece->_listPin[4]) &&
						       std::get<2>(piece->_listPin[2]) &&
						       std::get<2>(piece->_listPin[15])));
		}
	    }
	  return (x);
	};
    }
}

nts::IComponent	*Computer::create4008(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4008", value);
  //  std::cout<<"create4008"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "4008";
  //pin1 A4
  filler(piece, 1, -1, -1, 0);
  //pin2 B3
  filler(piece, 2, -1, -1, 0);
  //pin3 A3
  filler(piece, 3, -1, -1, 0);
  //pin4 B2
  filler(piece, 4, -1, -1, 0);
  //pin5 A2
  filler(piece, 5, -1, -1, 0);
  //pin6 B1
  filler(piece, 6, -1, -1, 0);
  //pin7 A1
  filler(piece, 7, -1, -1, 0);
  //pin8
  filler(piece, 8, -1, -1, 0);
  //pin9 C in
  filler(piece, 9, -1, -1, 0);
  //pin10 S1
  filler4008(piece, 10, 7, 6, 2, 9, 14);
  std::get<5>(piece->_listPin[10]).push_back(7);
  std::get<5>(piece->_listPin[10]).push_back(6);
  std::get<5>(piece->_listPin[10]).push_back(9);
  //pin11 S2
  filler4008(piece, 11, 5, 4, 2, 9, 14);
  std::get<5>(piece->_listPin[11]).push_back(5);
  std::get<5>(piece->_listPin[11]).push_back(4);
  std::get<5>(piece->_listPin[11]).push_back(9);
  //pin12 S3
  filler4008(piece, 12, 3, 2, 2, 9, 14);
  std::get<5>(piece->_listPin[12]).push_back(3);
  std::get<5>(piece->_listPin[12]).push_back(2);
  std::get<5>(piece->_listPin[12]).push_back(9);
  //pin13 S4
  filler4008(piece, 13, 1, 15, 2, 9, 14);
  std::get<5>(piece->_listPin[13]).push_back(15);
  std::get<5>(piece->_listPin[13]).push_back(1);
  std::get<5>(piece->_listPin[13]).push_back(9);
  //pin14 C out
  filler4008(piece, 14, 1, 1, 2, 9, 14);
  std::get<5>(piece->_listPin[14]).push_back(7);
  std::get<5>(piece->_listPin[14]).push_back(5);
  std::get<5>(piece->_listPin[14]).push_back(3);
  std::get<5>(piece->_listPin[14]).push_back(1);
  std::get<5>(piece->_listPin[14]).push_back(4);
  std::get<5>(piece->_listPin[14]).push_back(6);
  std::get<5>(piece->_listPin[14]).push_back(2);
  std::get<5>(piece->_listPin[14]).push_back(15);
  std::get<5>(piece->_listPin[14]).push_back(9);
  //  std::get<5>(piece->_listPin[14]).push_back(15);
  //pin15 B4
  filler(piece, 15, -1, -1, 0);
  //pin16
  filler(piece, 16, -1, -1, 0);


  std::get<5>(piece->_listPin[3]).push_back(1);
  std::get<5>(piece->_listPin[3]).push_back(2);

  piece->_maxPin = 16;
  return (dynamic_cast<nts::IComponent *>(piece));
}
