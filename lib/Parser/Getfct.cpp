//
// Getfct.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Feb 15 00:23:33 2017 Gregoire Renard
// Last update Fri Mar  3 16:22:16 2017 Gregoire Renard
//

#include <iostream>
#include <string>
#include "Parser.hpp"

int					Parser::testLine(std::string &line)
{
  int					cpt;
  
  cpt = 0;
  while (line[cpt] != '\0')
    {
      if (line[cpt] == '=')
	return (1);
      cpt++;
    }
  if (line[0] == '\n')
    return (1);
  if ((testEOF(line)) == 1)
    return (1);
  return (0);
}

int					Parser::constructLine(std::string &line, int cpt)
{
  std::string				tmp;
    
  while (line[cpt] != '\0')
    {
      while (line[cpt] != ' ' && line[cpt] != '\t' && line[cpt] != '\0')
	{
	  tmp += line[cpt];
	  cpt++;
	}
      setNext(line, cpt);
      if (line[cpt] != '\0')
	{
	  std::cout << "Error : bad commande line \"" << line << "\"" << std::endl;
	  return (-1);
	}
    }
  line = tmp;
  return (0);
}

int					Parser::getLineFromCin(std::string &line)
{
  int					cpt;

  setLine(line);
  if ((testLine(line)) == 1)
    return (0);
  if (line.length() >= 2)
    line[line.length() - 2] = '\0';
  cpt = 0;
  setNext(line, cpt);
  if ((constructLine(line, cpt)) == -1)
    return (-1);
  return (0);
}

int					Parser::getInput(char const *input,
							 std::vector<std::string> &params)
{
  int					cpt;
  std::string				str;
  
  cpt = 0;
  while (input[cpt] != '\0')
    {
      while ((input[cpt] == '\t' || input[cpt] == ' ') && input[cpt] != '\0')
	cpt++;
      if (input[cpt] == '=')
	{
	  params.push_back(str);
	  str = "";
	}
      else if (input[cpt] != '\0')
	str += input[cpt];
      cpt++;
    }
  params.push_back(str);
  return (0);
}

void					Parser::getParams(std::string &line,
							  std::vector<std::string> &params)
{
  std::string				param;
  int					cpt;
  
  cpt = 0;
  setNext(line, cpt);
  while (line[cpt] != '\0' && line[cpt] != '#')
    {
      while (line[cpt] != '\0' && line[cpt] != ' '
	     && line[cpt] != '\t' && line[cpt] != '#'
	     && line[cpt] != '(' && line[cpt] != ')')
	{
	  param += line[cpt];
	  cpt++;
	}
      params.push_back(param);
      param = "";
      while ((line[cpt] == ' ' || line[cpt] == '\t'
	      || line[cpt] == '(' || line[cpt] == ')') && line[cpt] != '\0')
	cpt++;
    }
}
