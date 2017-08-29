//
// Parser.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Feb  8 23:40:07 2017 Gregoire Renard
// Last update Sun Mar  5 18:29:22 2017 Gregoire Renard
//

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <csignal>
#include "cpp_nanotekspice_parser.hpp"
#include "Parser.hpp"

Parser::Parser()
  : _cmpt(new Computer)
{
  _checkDot.push_back(0);
  _checkDot.push_back(0);
  _next = 1;
}

Parser::~Parser()
{
}

void					Parser::printTree(nts::t_ast_node &root)
{
  std::cout << root.lexeme << " " << root.value << std::endl;
  auto					it = root.children->begin();
  auto					it2 = (*it)->children->begin();
  auto					it3 = (*it2)->children->begin();
  
  while (it != root.children->end())
    {
      it2 = (*it)->children->begin();
      std::cout << "\t" << (*it)->lexeme << " " << (*it)->value << std::endl;
      while (it2 !=(*it)->children->end())
  	{
	  it3 = (*it2)->children->begin();
  	  std::cout << "\t\t" << (*it2)->lexeme << " " << (*it2)->value << std::endl;
  	  while (it3 !=(*it2)->children->end())
  	    {
  	      std::cout << "\t\t\t" << (*it3)->lexeme << " " << (*it3)->value << std::endl;
  	      it3++;
  	    }
  	  it2++;
  	}
      it++;
    }
}

void					Parser::feed(std::string const &imput)
{
  std::cout << imput;
}

void					Parser::parseTree(nts::t_ast_node &root)
{
  std::string				line;
  std::string				section;
  int					start;
  
  section = "none";
  while (std::getline(_file, line) && section != "null")
    {
      start = 0;
      setNext(line, start);
      if (line[start] != '#' && line[start] != '\0' && line[start] != '\n'
	  && section != "null")
	{
	  if (line[start] == '.')
	    section = checkSection(line);
	  else if (section == "chipsets")
	    {
	      if ((rempChipsets(line, root)) == -1)
		section = "null";
	    }
	  else if (section == "links")
	    {
	      if ((rempLinks(line, root)) == -1)
		section = "null";
	    }
	  else
	    {
	      std::cout << "Error : bad line \"" << line << "\"" << std::endl;
	      section = "null";
	    }
	}
    }
  if (section == "null")
    _next = -1;
  if (section != "null")
    checkDot();
  if (_next != -1 && section != "null")
    if ((checkAllLink(root)) == -1)
      _next = -1;
}

nts::t_ast_node				*Parser::createTree()
{
  std::vector<nts::t_ast_node *>	*tab = new std::vector<nts::t_ast_node*>;
  nts::t_ast_node			*base = new nts::t_ast_node(tab);

  if (tab == NULL || base == NULL)
    throw (-1);
  base->type = nts::ASTNodeType::DEFAULT;
  base->value = "ROOT";
  base->lexeme = "ROOT";
  return (base);
}

int					Parser::testEOF(std::string &line)
{
  int					cpt;

  cpt = 0;
  while (line[cpt] != '\0')
    {
      if (line[cpt] == EOF)
	return (1);
      cpt++;
    }
  return (0);
}

int					Parser::startCommandLine(nts::t_ast_node &root)
{
  std::string				line;
  
  line = "";
  simulateFunc(root);
  displayFunc(root);
  while (line != "exit")
    {
      std::cout << "> ";
      if ((getLineFromCin(line)) != -1 && line != "exit")
	{
	  if (testEOF(line) == 1)
	    line = "exit";
	  else if (line[0] == '\n')
	    line = "";
	  else if (line == "display")
	    displayFunc(root);
	  else if (line == "simulate")
	    simulateFunc(root);
	  else if (line == "loop")
	    loopFunc(root);
	  else if (line == "dump")
	    dumpFunc(root);
	  else if ((isInputValue(line)) == 1)
	    {
	      if ((setValue(line, root)) == -1)
		std::cout << "Error : bad name or bad value for input" << std::endl;
	    }
	  else
	    std::cout << "Error : command line not recognized" << std::endl;
	}
    }
  return (0);
}

int					Parser::startLoopMain(char **argv)
{
  nts::t_ast_node			*root;

  try
    {
      root = this->createTree();
      this->_argv = argv;
      _file.open(argv[1]);
      if (_file.is_open())
	this->parseTree(*root);
      else
	throw (-2);
    }
  catch (int &err)
    {
      if (err == -1)
	return (-1);
      if (err == -2)
	{
	  std::cout << "Error : can't open file \"" << argv[1] << "\"" <<std::endl;
	  return (-1);
	}
      else
	std::cout << "Error : Unknows error" << std::endl;
    }
  _file.clear();
  if (_next != -1)
    if ((startCommandLine(*root)) == -1)
      return (-1);
  return (0);
}
