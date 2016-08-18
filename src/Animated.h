//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_ANIMATED_H
#define FASTANIM_ANIMATED_H

namespace fanim {

  class Animated {
  public:
    virtual void advance(float delta) = 0;
  };

}


#endif //FASTANIM_ANIMATED_H
