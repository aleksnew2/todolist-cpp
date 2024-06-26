#include <print>
#include <iostream>
#include <format>
#include <cstdlib>
#include "todolist.hpp"

auto td_list = ToDoList{};

void ToDoList::OutputElement(TODOElement element)
{
  if (element.description.empty())
  {
    std::cout << "- TODO: " << element.title << std::endl;
  }
  else
  {
    std::cout << "- TODO: " << element.title << " - " << element.description << std::endl;
  }
}

void ToDoList::OutputCommand(std::string title, std::string description)
{
  Color color;
  auto message = std::format("/ # {}: {}", title, description);
  color.Gray(message, true);
}

void ToDoList::OutputList()
{
  for (TODOElement i : td_list.list)
  {
    td_list.OutputElement(TODOElement(i.title, i.description));
  }
}

void ToDoList::Add(TODOElement element)
{
  if (element.description.empty())
  {
    Terminal terminal;
    td_list.list.push_back(TODOElement(element.title));
    terminal.Warning("You've created non-description TODO element", true);
  }
  else
  {
    td_list.list.push_back(TODOElement(element.title, element.description));
  }
}

void ToDoList::Remove(std::string title)
{
  td_list.list.erase(std::remove(
                         td_list.list.begin(),
                         td_list.list.end(),
                         TODOElement(title)),
                     td_list.list.end());
}

void ToDoList::Help()
{
  OutputCommand("add", "Adds TODO element to list.");
  OutputCommand("remove", "Removes TODO element from list.");
  OutputCommand("show-list", "Shows TODO elements.");
  OutputCommand("clear", "Clears previous history of commands.");
}

void ToDoList::Clear()
{
  int clear = system("clear");
}

void RunLoop()
{

  while (true)
  {
    Terminal terminal;

    std::println("Type `help` for commands.");
    std::print(">>> ");

    std::string command;
    std::getline(std::cin, command);

    if (command == "help")
    {
      td_list.Help();
    }
    else if (command == "show-list")
    {
      td_list.OutputList();
    }
    else if (command == "add")
    {
      std::print("Title: ");

      std::string inputTitle;
      std::getline(std::cin, inputTitle);

      std::print("Description (Optional): ");

      std::string inputDescription;
      std::getline(std::cin, inputDescription);

      td_list.Add(TODOElement(inputTitle, inputDescription));
    }
    else if (command == "remove")
    {

      if (td_list.list.empty())
      {
        terminal.Error("List is empty.", true);
      }
      else
      {
        std::print("Type element's title, which you want to remove: ");

        std::string inputTitle;
        std::getline(std::cin, inputTitle);

        td_list.Remove(inputTitle);

        terminal.Success("Element removed.", true);
      }
    }
    else if (command == "clear")
    {
      td_list.Clear();
    }
    else
    {
      terminal.Error("Wrong command", true);
    }
  }
}

void Color::Red(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[31m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[31m" << message << "\033[0m";
  }
}

void Color::Green(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[32m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[32m" << message << "\033[0m";
  }
}

void Color::Yellow(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[33m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[33m" << message << "\033[0m";
  }
}

void Color::Blue(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[34m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[34m" << message << "\033[0m";
  }
}

void Color::Gray(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[90m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[90m" << message << "\033[0m";
  }
}

void Terminal::Error(std::string message, bool isWithNewLine)
{
  Color color;
  color.Red("ERROR: ", false);

  if (isWithNewLine)
    std::cout << message << std::endl;
  else
    std::cout << message;
}

void Terminal::Warning(std::string message, bool isWithNewLine)
{
  Color color;
  color.Yellow("WARNING: ", false);

  if (isWithNewLine)
    std::cout << message << std::endl;
  else
    std::cout << message;
}

void Terminal::Info(std::string message, bool isWithNewLine)
{
  Color color;
  color.Blue("INFO: ", false);

  if (isWithNewLine)
    std::cout << message << std::endl;
  else
    std::cout << message;
}

void Terminal::Success(std::string message, bool isWithNewLine)
{
  Color color;
  color.Green("SUCCESS: ", false);

  if (isWithNewLine)
    std::cout << message << std::endl;
  else
    std::cout << message;
}

int main()
{
  RunLoop();
  return 0;
}