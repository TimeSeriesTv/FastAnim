//
// Created by Michał Łaszczewski on 04/07/16.
//

#ifndef ENGINE_LINEARTRANSITION_H
#define ENGINE_LINEARTRANSITION_H

#include <glm/glm.hpp>
namespace fanim {

  template<typename ValueType>
  class LinearTransition : public Transition<ValueType> {
  public:
    ValueType currentValue;
    std::shared_ptr<Value<ValueType>> lastValue;
    std::shared_ptr<Value<ValueType>> nextValue;
    float remainingTime;
    float transitionTime;

    LinearTransition(std::shared_ptr<Value<ValueType>> firstValuep) {
      setCurrent(firstValuep);
    }

    virtual ~LinearTransition() override { }

    virtual void advance(float delta) override {
      ValueType next = nextValue->get();
      ValueType last = lastValue->get();
      remainingTime -= delta;
      if (remainingTime <= 0) {
        remainingTime = 0;
        currentValue = next;
        return;
      }
      currentValue = next - (next - last) * (remainingTime / transitionTime);
      return;
    }

    virtual void setNext(std::shared_ptr<Value<ValueType>> nextValuep, float timep) override {
      lastValue = nextValue;
      nextValue = nextValuep;
      transitionTime = timep;
      remainingTime = timep;
      if(remainingTime != 0) {
        lastValue = std::make_shared < Static < ValueType >> (currentValue);
      }
    }

    virtual void setCurrent(std::shared_ptr<Value<ValueType>> currentp) override {
      nextValue = currentp;
      lastValue = currentp;
      currentValue = currentp->get();
      remainingTime = 0;
      transitionTime = 0;
    }

    virtual ValueType get() override {
      return currentValue;
    }

  };

}

#endif //ENGINE_LINEARTRANSITION_H
