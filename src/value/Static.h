//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_STATIC_H
#define FASTANIM_STATIC_H

#include "Value.h"

namespace fanim {

  template<typename ValueType> class Static : public Value<ValueType> {
  private:
    ValueType value;
  public:
    Static(const ValueType& valuep) : value(valuep) {}
    virtual ~Static() {}
    virtual ValueType get() {
      return value;
    }
  };

}

#endif //FASTANIM_VALUE_H
