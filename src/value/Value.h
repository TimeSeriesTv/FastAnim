//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_VALUE_H
#define FASTANIM_VALUE_H

namespace fanim {

  template<typename ValueType> class Value {
  public:
    virtual ~Value() {};
    virtual ValueType get() = 0;
  };

}

#endif //FASTANIM_VALUE_H
