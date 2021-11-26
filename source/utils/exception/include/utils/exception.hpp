#ifndef SOURCE_UTILS_EXCEPTION_INCLUDE_UTILS_EXCEPTION_HPP_
#define SOURCE_UTILS_EXCEPTION_INCLUDE_UTILS_EXCEPTION_HPP_

#include <stdexcept>

namespace DException {
// All exception classes should derive by template class which is
// out of my skills right now.
// Exception classes
class EmptyVectorException : public std::runtime_error {
   public:
    explicit EmptyVectorException(const std::string &what_message)
        : std::runtime_error{what_message} {}
};

class TargetNotFoundException : public std::runtime_error {
   public:
    explicit TargetNotFoundException(const std::string &what_message)
        : std::runtime_error{what_message} {}
};

class FileOpenFailureException : public std::runtime_error {
   public:
    explicit FileOpenFailureException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

class IncorrectInputDataException : public std::runtime_error {
   public:
    explicit IncorrectInputDataException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

class IncorrectInputDataFormatException : public std::runtime_error {
   public:
    explicit IncorrectInputDataFormatException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

class IncorrectReadingsException : public std::runtime_error {
   public:
    explicit IncorrectReadingsException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

class DuplicateReadingsException : public std::runtime_error {
   public:
    explicit DuplicateReadingsException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

class NoInputDataException : public std::runtime_error {
   public:
    explicit NoInputDataException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

class IncorrectMonthException : public std::runtime_error {
   public:
    explicit IncorrectMonthException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

class UnknownTemperatureUnitException : public std::runtime_error {
   public:
    explicit UnknownTemperatureUnitException(const std::string &error_msg)
        : std::runtime_error(error_msg) {}
};

}  // namespace DException

#endif  // SOURCE_UTILS_EXCEPTION_INCLUDE_UTILS_EXCEPTION_HPP_
