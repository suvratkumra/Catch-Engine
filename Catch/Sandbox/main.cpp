
namespace test {
	__declspec(dllimport) void PrintHelloWorld();
}

void main()
{
	test::PrintHelloWorld();
}