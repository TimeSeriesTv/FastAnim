//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_TRANSFORMATION_H
#define FASTANIM_TRANSFORMATION_H

#include "glm/glm.hpp"

namespace fanim {

  class Transformation {
  public:
    virtual glm::mat4 getMatrix() = 0;
    virtual ~Transformation() {};
  };

}


#endif //FASTANIM_TRANSFORMATION_H
