#include "instructions.hpp"

#include "class/call_site.hpp"

namespace rubinius {
  namespace instructions {
    inline bool call(STATE, CallFrame* call_frame, intptr_t literal, intptr_t count) {
      Object* recv = stack_back(count);
      CallSite* call_site = reinterpret_cast<CallSite*>(literal);

      Arguments args(call_site->name(), recv, cNil, count,
                     stack_back_position(count));

      stack_clear(count + 1);

      Object* value = call_site->execute(state, args);

      CHECK_AND_PUSH(value);
    }
  }
}
