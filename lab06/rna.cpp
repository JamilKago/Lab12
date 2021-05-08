#include "rna.h"

std::ostream& operator<<(std::ostream& out, const RNA & seq_)
{
  for(unsigned i=0;i<seq_.chain.size();i++)   out<< static_cast<char>(seq_.chain[i]) << " ";
  out<<std::endl;
  return out;
}

	RNA& RNA::mutate()
  {
    chain.push_back( chain.front() );
    chain.erase( chain.begin() );
    return *this;
  }
