#include <string>
#include <vector>
#include <iostream>

struct result {
  bool pass;
  std::string name;
  std::string comment;
  result(bool p, std::string n, std::string c) : pass(p), name(n), comment(c) {}
};

void print_results(std::vector<result*>* results) {
  int total = results->size(), i = 0, passes = 0, failures = 0;
  std::string failBuffer = "";
  result * current = NULL;

  for (i = 0; i < total; i += 1) {
    current = (*results)[i];
    if (current->pass) {
      passes += 1;
    } else {
      failures += 1;
      if (failBuffer != "") {
        failBuffer = failBuffer + '\n'; // TODO: use endl
      }
      failBuffer += current->name + ": " + current->comment;
    }
  }

  std::cout << "Test Summary" << std::endl;
  std::cout << "============" << std::endl;
  std::cout << "total: " << total << ", pass: " << passes;
  std::cout << ", failures: " << failures << std::endl;
  std::cout << std::endl;
  std::cout << "Specific Failures:" << std::endl << failBuffer << std::endl;

  return;
}
