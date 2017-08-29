//
// Gate.hpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/includes
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sun Feb 12 00:25:18 2017 Rodrigue René
// Last update Thu Feb 16 11:44:20 2017 Rodrigue René
//

#ifndef GATE_H_
# define GATE_H_

#include <iostream>

namespace nts
{
  class Gate
  {
    std::string		_type;
    std::map<int, std::map<int, nts::Gate *> >	_links;
    //    link[2][5] = 1;

    nts::Tristate in0;
    nts::Tristate in1;
    nts::Tristate out;

  public:
    Gate(std::string type);
    Gate();
    ~Gate();

    void	logic_Gate(void);
    void	setLinkBetweenGate(int port, nts::Gate *gate, int gatePort);
    nts::Tristate AND_g(nts::Tristate const &in1, nts::Tristate const &in2);
    nts::Tristate OR_g(nts::Tristate const &in1, nts::Tristate const &in2);
    nts::Tristate XOR_g(nts::Tristate const &in1, nts::Tristate const &in2);
    /////    NEG
    nts::Tristate NOR_g(nts::Tristate const &in1, nts::Tristate const &in2);
    nts::Tristate NAND_g(nts::Tristate const &in1, nts::Tristate const &in2);
    nts::Tristate XNOR_g(nts::Tristate const &in1, nts::Tristate const &in2);
    nts::Tristate NOT_g(nts::Tristate const &in1, nts::Tristate const &in2);

    Gate &operator=(Gate const &);

  };
}
#endif /* !GATE_H_ */
