#include <intersect/intersect.h>

#include <iostream>
#include <fmt/format.h>

using namespace hytano;
using namespace std;

int main(int argc, char *argv[])
{
	intersect m(5);

	cout << fmt::format("Value: {}", m.value()) << endl;

	m.add(5);

	cout << fmt::format("Value: {}", m.value()) << endl;

	return 0;
}