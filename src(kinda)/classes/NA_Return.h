#pragma once
#include <string>
using std::string;
template<class _template> class NA_Return
{

public:
	NA_Return(void);
	~NA_Return(void);

//private: //these probably should be private, but public removes function overhead
	bool success; //if true then value is useful else value is junk
	_template value;
	string reason; //a string where code can put failure details

};

template <class _template>NA_Return<_template>::NA_Return(void)
{
}


template <class _template>NA_Return<_template>::~NA_Return(void)
{
}
