//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_ANIMATOR_H
#define FASTANIM_ANIMATOR_H

#import "FastSet.h"
#import "Animated.h"

namespace fanim {

  class Animator : public FastSet<Animated> {
  public:
    void advance(float by) {
      for(auto animated : *this) {
        animated->advance(by);
      }
    }
  };

}

#endif //FASTANIM_ANIMATOR_H
