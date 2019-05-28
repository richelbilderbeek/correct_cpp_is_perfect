/** @file */
/** @file */
/** @file */
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

/// Gets the proper divisors of a certain value
std::vector<int> get_proper_divisors(const int value) noexcept
{
  if (value < 2) return {};
  if (value == 2) return { 1 };

  std::vector<int> proper_divisors;
  for (int divisor=1; divisor!=value-1; ++divisor)
  {
    if (!(value % divisor))
    {
      proper_divisors.push_back(divisor);
    }
  }
  return proper_divisors;
}

/// Sums all proper divisors of a certain value
int sum(const std::vector<int>& values) noexcept
{
  return std::accumulate(std::begin(values), std::end(values), 0);
}

/// Checks if a certain value is a perfect number
bool is_perfect(const int value) noexcept
{
  if (value == 0) return false;
  return sum(get_proper_divisors(value)) == value;
}

/// Tests the output of the get_proper_divisors function
void test_get_proper_divisors() noexcept
{
  assert(get_proper_divisors(1) == std::vector<int>() );
  assert(get_proper_divisors(2) == std::vector<int>( {1} ) );
  assert(get_proper_divisors(3) == std::vector<int>( {1} ) );
  assert(get_proper_divisors(4) == std::vector<int>( {1, 2} ) );
  assert(get_proper_divisors(5) == std::vector<int>( {1} ) );
  assert(get_proper_divisors(6) == std::vector<int>( {1, 2, 3} ) );
  assert(get_proper_divisors(7) == std::vector<int>( {1} ) );
  assert(get_proper_divisors(8) == std::vector<int>( {1, 2, 4} ) );
  assert(get_proper_divisors(9) == std::vector<int>( {1, 3} ) );
}

/// Tests the output of the is_perfect function
void test_is_perfect() noexcept
{
  assert(!is_perfect(-1));
  assert(!is_perfect(0));
  assert(!is_perfect(1));
  assert(!is_perfect(2));
  assert(!is_perfect(4));
  assert( is_perfect(6));
  assert(!is_perfect(7));
  assert(!is_perfect(8));
  assert(is_perfect(28));
}

/// Implementation of is_perfect main function
int do_main(const std::vector<std::string>& args) noexcept
{
  if (args.size() != 2) return 1;
  try
  {
    std::cout << std::boolalpha << is_perfect(std::stoi(args[1])) << '\n';
  }
  catch (const std::exception&)
  {
    return 1;
  }
  return 0;
}
 
/// Tests the exit output of the do_main function
void test_do_main() noexcept
{
  assert(do_main( { "is_perfect" } ) == 1);
  assert(do_main( { "is_perfect", "1" } ) == 0);
  assert(do_main( { "is_perfect", "nonsense" } ) == 1);
  assert(do_main( { "is_perfect", "1", "2" } ) == 1);
}

/// Runs all tests for this program
void test() noexcept
{
  test_get_proper_divisors();
  test_is_perfect();
  test_do_main();
}

/// is_perfect main function, that also tests its implementation
int main(int argc, char* argv[])
{
  test();
  const std::vector<std::string> args(argv, argv + argc);
  return do_main(args);
}
