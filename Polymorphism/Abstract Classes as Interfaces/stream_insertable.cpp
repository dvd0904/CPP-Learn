#include "stream_insertable.h"




std::ostream& operator<< (std::ostream& out,
                          const StreamInsertable& operand)
{
    /* In here, we are calling the stream_insert method on a reference that we pass here and this is
    going to be resolve this by using dynamic binding. */
    operand.stream_insert(out);
    return out;
}












