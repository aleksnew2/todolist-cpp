#include <vector>
#include <string>

void RunLoop();

class TODOElement
{
public:
  std::string title;
  std::string description;

  TODOElement(std::string title, std::string description = "")
  {
    this->title = title;
    this->description = description;
  }

  bool operator==(const TODOElement &other) const
  {
    return title == other.title;
  }
};

struct ToDoList
{
public:
  std::vector<TODOElement> list;

  void OutputElement(TODOElement element);
  void OutputCommand(std::string title, std::string decription);
  void OutputList();
  void Add(TODOElement element);
  void Remove(std::string title);
  void Help();
  void Clear();
};

class Color
{
public:
  void Red(std::string message, bool isWithNewLine);
  void Green(std::string message, bool isWithNewLine);
  void Yellow(std::string message, bool isWithNewLine);
  void Blue(std::string message, bool isWithNewLine);
  void Gray(std::string message, bool isWithNewLine);
};

class Terminal
{
public:
  void Info(std::string message, bool isWithNewLine);
  void Error(std::string message, bool isWithNewLine);
  void Success(std::string message, bool isWithNewLine);
  void Warning(std::string message, bool isWithNewLine);
};