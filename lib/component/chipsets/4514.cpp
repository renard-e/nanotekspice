//
// 4514.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sat Mar  4 20:44:50 2017 Rodrigue René
// Last update Sun Mar  5 03:43:43 2017 Rodrigue René
//

#include "Computer.hpp"

void	Computer::filler4514(nts::Processor *piece, int actual, int a, int b, int c, int d, int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (type == 2)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, actual,a,b,c,d]()->nts::Tristate
	{
	  bool x;
	  if (actual == 11)//S0
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 9)//S1
	    x = (std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 10)//S2
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 8)//S3
	    x = (std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 7)//S4
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 6)//S5
	    x = (std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 5)//S6
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 4)//S7
	    x = (std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 !std::get<2>((piece->_listPin[d])));
	  else if (actual == 18)//S8
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  else if (actual == 17)//S9
	    x = (std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  else if (actual == 20)//S10
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  else if (actual == 19)//S11
	    x = (std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 !std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  else if (actual == 14)//S12
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  else if (actual == 13)//S13
	    x = (std::get<2>((piece->_listPin[a])) &&
		 !std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  else if (actual == 16)//S14
	    x = (!std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  else if (actual == 15)//S15
	    x = (std::get<2>((piece->_listPin[a])) &&
		 std::get<2>((piece->_listPin[b])) &&
		 std::get<2>((piece->_listPin[c])) &&
		 std::get<2>((piece->_listPin[d])));
	  if (std::get<2>(piece->_listPin[23]) == 1)
	    x = 0;
	  std::get<2>(piece->_listPin[actual]) = static_cast<nts::Tristate>( x );

	  return static_cast<nts::Tristate>( x );
	};

    }


}

nts::IComponent	*Computer::create4514(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4514", value);
  piece->_name = value;
  piece->_typeProc = "4514";
  //pin1 STROBE
  filler(piece, 1, -1, -1, 0);
  //pin2 A
  filler(piece, 2, -1, -1, 0);
  //pin3 B
  filler(piece, 3,-1, -1, 0);
  //pin4
  filler4514(piece, 4, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[4]).push_back(2);
  std::get<5>(piece->_listPin[4]).push_back(3);
  std::get<5>(piece->_listPin[4]).push_back(21);
  std::get<5>(piece->_listPin[4]).push_back(22);
  std::get<5>(piece->_listPin[4]).push_back(1);
  std::get<5>(piece->_listPin[4]).push_back(23);
  //pin5
  filler4514(piece, 5, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[5]).push_back(2);
  std::get<5>(piece->_listPin[5]).push_back(3);
  std::get<5>(piece->_listPin[5]).push_back(21);
  std::get<5>(piece->_listPin[5]).push_back(22);
  std::get<5>(piece->_listPin[5]).push_back(1);
  std::get<5>(piece->_listPin[5]).push_back(23);

  //pin6
  filler4514(piece, 6, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[6]).push_back(2);
  std::get<5>(piece->_listPin[6]).push_back(3);
  std::get<5>(piece->_listPin[6]).push_back(21);
  std::get<5>(piece->_listPin[6]).push_back(22);
  std::get<5>(piece->_listPin[6]).push_back(1);
  std::get<5>(piece->_listPin[6]).push_back(23);

  //pin7
  filler4514(piece, 7, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[7]).push_back(2);
  std::get<5>(piece->_listPin[7]).push_back(3);
  std::get<5>(piece->_listPin[7]).push_back(21);
  std::get<5>(piece->_listPin[7]).push_back(22);
  std::get<5>(piece->_listPin[7]).push_back(1);
  std::get<5>(piece->_listPin[7]).push_back(23);

  //pin8
  filler4514(piece, 8, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[8]).push_back(2);
  std::get<5>(piece->_listPin[8]).push_back(3);
  std::get<5>(piece->_listPin[8]).push_back(21);
  std::get<5>(piece->_listPin[8]).push_back(22);
  std::get<5>(piece->_listPin[8]).push_back(1);
  std::get<5>(piece->_listPin[8]).push_back(23);

  //pin9
  filler4514(piece, 9, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[9]).push_back(2);
  std::get<5>(piece->_listPin[9]).push_back(3);
  std::get<5>(piece->_listPin[9]).push_back(21);
  std::get<5>(piece->_listPin[9]).push_back(22);
  std::get<5>(piece->_listPin[9]).push_back(1);
  std::get<5>(piece->_listPin[9]).push_back(23);

  //pin10
  filler4514(piece, 10, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[10]).push_back(2);
  std::get<5>(piece->_listPin[10]).push_back(3);
  std::get<5>(piece->_listPin[10]).push_back(21);
  std::get<5>(piece->_listPin[10]).push_back(22);
  std::get<5>(piece->_listPin[10]).push_back(1);
  std::get<5>(piece->_listPin[10]).push_back(23);

  //pin11
  filler4514(piece, 11, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[11]).push_back(2);
  std::get<5>(piece->_listPin[11]).push_back(3);
  std::get<5>(piece->_listPin[11]).push_back(21);
  std::get<5>(piece->_listPin[11]).push_back(22);
  std::get<5>(piece->_listPin[11]).push_back(1);
  std::get<5>(piece->_listPin[11]).push_back(23);

  //pin12
  filler4514(piece, 12, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[12]).push_back(2);
  std::get<5>(piece->_listPin[12]).push_back(3);
  std::get<5>(piece->_listPin[12]).push_back(21);
  std::get<5>(piece->_listPin[12]).push_back(22);
  std::get<5>(piece->_listPin[12]).push_back(1);
  std::get<5>(piece->_listPin[12]).push_back(23);

  //pin13
  filler4514(piece, 13, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[13]).push_back(2);
  std::get<5>(piece->_listPin[13]).push_back(3);
  std::get<5>(piece->_listPin[13]).push_back(21);
  std::get<5>(piece->_listPin[13]).push_back(22);
  std::get<5>(piece->_listPin[13]).push_back(1);
  std::get<5>(piece->_listPin[13]).push_back(23);

  //pin14
  filler4514(piece, 14, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[14]).push_back(2);
  std::get<5>(piece->_listPin[14]).push_back(3);
  std::get<5>(piece->_listPin[14]).push_back(21);
  std::get<5>(piece->_listPin[14]).push_back(22);
  std::get<5>(piece->_listPin[14]).push_back(1);
  std::get<5>(piece->_listPin[14]).push_back(23);


  //pin15
  filler4514(piece, 15, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[15]).push_back(2);
  std::get<5>(piece->_listPin[15]).push_back(3);
  std::get<5>(piece->_listPin[15]).push_back(21);
  std::get<5>(piece->_listPin[15]).push_back(22);
  std::get<5>(piece->_listPin[15]).push_back(1);
  std::get<5>(piece->_listPin[15]).push_back(23);

  //pin16
  filler4514(piece, 16, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[16]).push_back(2);
  std::get<5>(piece->_listPin[16]).push_back(3);
  std::get<5>(piece->_listPin[16]).push_back(21);
  std::get<5>(piece->_listPin[16]).push_back(22);
  std::get<5>(piece->_listPin[16]).push_back(1);
  std::get<5>(piece->_listPin[16]).push_back(23);

  //pin17
  filler4514(piece, 17, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[17]).push_back(2);
  std::get<5>(piece->_listPin[17]).push_back(3);
  std::get<5>(piece->_listPin[17]).push_back(21);
  std::get<5>(piece->_listPin[17]).push_back(22);
  std::get<5>(piece->_listPin[17]).push_back(1);
  std::get<5>(piece->_listPin[17]).push_back(23);

  //pin18
  filler4514(piece, 18, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[18]).push_back(2);
  std::get<5>(piece->_listPin[18]).push_back(3);
  std::get<5>(piece->_listPin[18]).push_back(21);
  std::get<5>(piece->_listPin[18]).push_back(22);
  std::get<5>(piece->_listPin[18]).push_back(1);
  std::get<5>(piece->_listPin[18]).push_back(23);

  //pin19
  filler4514(piece, 19, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[19]).push_back(2);
  std::get<5>(piece->_listPin[19]).push_back(3);
  std::get<5>(piece->_listPin[19]).push_back(21);
  std::get<5>(piece->_listPin[19]).push_back(22);
  std::get<5>(piece->_listPin[19]).push_back(1);
  std::get<5>(piece->_listPin[19]).push_back(23);

  //pin20
  filler4514(piece, 20, 2, 3, 21, 22, 2);
  std::get<5>(piece->_listPin[20]).push_back(2);
  std::get<5>(piece->_listPin[20]).push_back(3);
  std::get<5>(piece->_listPin[20]).push_back(21);
  std::get<5>(piece->_listPin[20]).push_back(22);
  std::get<5>(piece->_listPin[20]).push_back(1);
  std::get<5>(piece->_listPin[20]).push_back(23);

  //pin21 C
  filler(piece, 21, -1, -1, 0);

  //pin22 D
  filler(piece, 22, -1, -1, 0);

  //pin23 INHIBIT
  filler(piece, 23, -1, -1, 0);

  piece->_maxPin = 14;
  return (dynamic_cast<nts::IComponent *>(piece));
}
