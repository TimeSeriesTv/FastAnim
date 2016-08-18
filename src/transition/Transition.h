//
// Created by Michał Łaszczewski on 04/07/16.
//

#ifndef ENGINE_TRANSITION_H
#define ENGINE_TRANSITION_H

namespace fanim {

  template<typename ValueType> class Transition : public Value<ValueType>, public Animated {
  public:

    virtual ~Transition() {};
    virtual void advance(float delta) = 0;
    virtual void setNext(std::shared_ptr<Value<ValueType>> nextValuep, float timep) = 0;
    virtual void setCurrent(std::shared_ptr<Value<ValueType>> currentp) = 0;
    virtual ValueType get() = 0;
  };

}

#endif //ENGINE_TRANSITION_H
