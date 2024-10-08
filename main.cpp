#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
  string* opts = new string[argc - 1];

  for (int i = 1; i < argc; ++i)
  {
    std::string curr_arg = argv[i];

    if (curr_arg == "f")
    {
      opts[i - 1] = "feature/";
    }
    else if (curr_arg == "h")
    {
      opts[i - 1] = "hotfix/";
    }
    else
    {
      opts[i - 1] = curr_arg;
    }
  }

  std::ostringstream stream;
  for (int i = 0; i < argc - 1; ++i)
  {
    if (i > 0) stream << '-';
    stream << opts[i];
  }

  std::string output = stream.str();
  std::cout << output << '\n';

  delete[] opts;

  return 0;
}
