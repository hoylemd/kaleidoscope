#include <string>
#include <vector>
#include <iostream>
#include <sstream>

struct result {
  bool pass;
  std::string name;
  std::string comment;
  std::string expected;
  std::string actual;
  int asserts;
  int failedAsserts;
  result(std::string n) : pass(true), name(n), comment(""),
    expected(""), actual(""), asserts(0), failedAsserts(0) {}
};

std::string doubleToString(double value) {
  std::stringstream s;
  s << value;
  return s.str();
}

std::string pointerToString(void * value) {
  std::stringstream s;
  s << value;
  return s.str();
}

result* reportFailure(result* out, std::string comment,
    std::string expected, std::string actual) {
  out->pass = false;
  out->failedAsserts += 1;
  out->comment = comment;
  out->expected = expected;
  out->actual = actual;

  return out;
}

bool assertInteger(int expected, int actual, result* out,
    const std::string failureComment) {
  if (out->pass) {
    out->asserts += 1;
    if (expected != actual) {
      reportFailure(out, failureComment,
        doubleToString(expected), doubleToString(actual));
    }
  }
  return out->pass;
}

bool assertDouble(double expected, double actual, result* out,
    const std::string failureComment) {
  if (out->pass) {
    out->asserts += 1;
    if (expected != actual) {
      reportFailure(out, failureComment,
        doubleToString(expected), doubleToString(actual));
    }
  }
  return out->pass;
}

bool assertChar(char expected, char actual, result* out,
    const std::string failureComment) {
  if (out->pass) {
    out->asserts += 1;
    if (expected != actual) {
      reportFailure(out, failureComment,
        std::string(1, expected), std::string(1, actual));
    }
  }
  return out->pass;
}

bool assertString(std::string expected, std::string actual, result* out,
    const std::string failureComment) {
  if (out->pass) {
    out->asserts += 1;
    if (expected != actual) {
      reportFailure(out, failureComment, expected, actual);
    }
  }
  return out->pass;
}

bool assertPointer(void* expected, void* actual, result* out,
    const std::string failureComment) {
  if (out->pass) {
    out->asserts += 1;
    if (expected != actual) {
      reportFailure(out, failureComment,
        pointerToString(expected), pointerToString(actual));
    }
  }
  return out->pass;
}

void print_results(std::vector<result*>* results) {
  int total = results->size(), i = 0, passes = 0, failures = 0,
    asserts = 0, passedAsserts = 0, failedAsserts = 0;
  std::string failBuffer = "";
  result * current = NULL;

  for (i = 0; i < total; i += 1) {
    current = (*results)[i];
    asserts += current->asserts;
    passedAsserts += current->asserts - current->failedAsserts;
    failedAsserts += current->failedAsserts;
    if (current->pass) {
      passes += 1;
    } else {
      failures += 1;
      if (failBuffer != "") {
        failBuffer = failBuffer + '\n';
      }
      failBuffer += current->name + ": " + current->comment;
      if (current->expected != "") {
        failBuffer += "\n\texpected:" + current->expected;
        failBuffer += "\n\tactual  :" + current->actual;
      }
    }
  }

  std::cout << "Test Summary" << std::endl;
  std::cout << "============" << std::endl;
  std::cout << "all cases : " << total << ", pass: " << passes;
  std::cout << ", failures: " << failures << std::endl;
  std::cout << "assertions: " << asserts << ", pass: " << passedAsserts;
  std::cout << ", failures: " << failedAsserts << std::endl;
  if (failures) {
    std::cout << "Specific Failures:" << std::endl << failBuffer << std::endl;
  }

  return;
}
