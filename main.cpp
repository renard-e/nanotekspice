//
// main.cpp for tekSpice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Mon Jan 23 04:22:53 2017 Rodrigue René
// Last update Thu Mar  2 18:58:30 2017 Rodrigue René
//

#include <iostream>
#include <vector>
#include "libnanotekspice.hpp"
#include "Computer.hpp"
#include "Processor.hpp"
#include "Parser.hpp"


int	main(int argc, char **argv)
{
  // Computer *monstre = new Computer;

  //#########################################################################
  // //#########################################################################
  // monstre->addComponent(monstre->createComponent("4071", "p81#"), "p81#");
  // monstre->addComponent(monstre->createComponent("4071", "p82#"), "p82#");
  // monstre->addComponent(monstre->createComponent("input", "I01"), "I01");
  // monstre->addComponent(monstre->createComponent("input", "I02"), "I02");
  // monstre->addComponent(monstre->createComponent("input", "I03"), "I03");
  // monstre->addComponent(monstre->createComponent("input", "I04"), "I04");
  // monstre->addComponent(monstre->createComponent("output", "OUT01"), "OUT01");
  // //#########################################################################
  // //#########################################################################


  // // monstre->devices.find("p81#")->second->Dump();
  // // monstre->devices.find("p82#")->second->Dump();

  // // // p81->SetLink((size_t)1, *I01,(size_t) 1);
   // monstre->devices.find("a0")->second->SetLink((size_t)1,
   // 						 *monstre->devices.find("decoder")->second,(size_t) 2);
  // monstre->devices.find("p81#")->second->SetLink((size_t)2,
  // 						   *monstre->devices.find("I02")->second,(size_t) 1);
  // monstre->devices.find("p81#")->second->SetLink((size_t)6,
  // 						   *monstre->devices.find("I03")->second,(size_t) 1);
  // monstre->devices.find("p81#")->second->SetLink((size_t)5,
  // 						   *monstre->devices.find("I04")->second,(size_t) 1);
  // monstre->devices.find("p81#")->second->SetLink((size_t)3,
  // 						   *monstre->devices.find("p82#")->second,(size_t) 1);
  // monstre->devices.find("p81#")->second->SetLink((size_t)4,
  // 						   *monstre->devices.find("p82#")->second,(size_t) 2);
  // monstre->devices.find("p82#")->second->SetLink((size_t)3,
  // 						   *monstre->devices.find("OUT01")->second,(size_t) 1);


  // std::cout<<"here comes the king"<<
  //   monstre->devices.find("p82#")->second->Compute(3) << std::endl;

   // std::get<2>(dynamic_cast<nts::Processor *>
   // 	      (monstre->devices.find("I01")->second)->_listPin[1]) = nts::FALSE;

  // std::cout<<"nonono 1"<<std::endl;
  // std::get<2>(dynamic_cast<nts::Processor *>
  // 	      (monstre->devices.find("I02")->second)->_listPin[1]) = nts::TRUE;
  // std::cout<<"nonono 2"<<std::endl;
  // std::get<2>(dynamic_cast<nts::Processor *>
  // 	      (monstre->devices.find("I03")->second)->_listPin[1]) = nts::FALSE;
  // std::cout<<"nonono 3"<<std::endl;
  //  std::get<2>(dynamic_cast<nts::Processor *>
  //  	      (monstre->devices.find("I04")->second)->_listPin[1]) = nts::FALSE;
  // monstre->devices.find("I01")->second->Dump();
  // monstre->devices.find("I02")->second->Dump();
  // monstre->devices.find("I03")->second->Dump();
  // monstre->devices.find("I04")->second->Dump();
  // monstre->devices.find("p81#")->second->Dump();
  // monstre->devices.find("OUT01")->second->Dump();


  // std::cout<<"ici out01 = "<<monstre->devices.find("OUT01")->second->Compute(1)<<std::endl;
  // //  monstre->devices.find("OUT01")->second->Simulate();

  // dynamic_cast<nts::Processor *>(monstre->devices.find("OUT01")->second)->Simulate();

  // std::cout<<"ici out01 = "<<monstre->devices.find("OUT01")->second->Compute(1)<<std::endl;
  // monstre->devices.find("I01")->second->Dump();
  // monstre->devices.find("I02")->second->Dump();
  // monstre->devices.find("I03")->second->Dump();
  // monstre->devices.find("I04")->second->Dump();
  // monstre->devices.find("p81#")->second->Dump();
  // monstre->devices.find("OUT01")->second->Dump();

  // monstre->devices.find("OUT01")->second->Compute(1);
  Parser	parse;

  if (argc < 2)
    {
      std::cout << "Error : bad usage" << std::endl << "Usage : " << argv[0]
  		<< " file input1=value input2=value etc..." << std::endl;
      return (-1);
    }
  if ((parse.startLoopMain(argv)) == -1)
    return (-1);
  return (0);
}
