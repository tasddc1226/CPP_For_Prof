#include <iostream>
#include <locale>

using namespace std;

int main()
{
	locale locUSEng("en-US");       // ������
	//locale locUSEng("en_US");     // ������
	locale locBritEng("en-GB");     // ������
	//locale locBritEng("en_GB");   // ������

	wstring dollars = use_facet<moneypunct<wchar_t>>(locUSEng).curr_symbol();
	wstring pounds = use_facet<moneypunct<wchar_t>>(locBritEng).curr_symbol();
	
	wcout << L"In the US, the currency symbol is " << dollars << endl;
	wcout << L"In Great Britain, the currency symbol is " << pounds << endl;

	return 0;
}
