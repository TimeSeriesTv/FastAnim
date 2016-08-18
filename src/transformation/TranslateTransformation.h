//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_TRANSLATETRANSFORMATION_H
#define FASTANIM_TRANSLATETRANSFORMATION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transformation.h"

namespace fanim {

  class TranslateTransformation : public Transformation {
  public:
    std::shared_ptr<Value<glm::vec3>> vector;
    virtual glm::mat4 getMatrix() {
      return glm::translate(glm::mat4(), vector->get());
    }
    TranslateTransformation(std::shared_ptr<Value<glm::vec3>> vectorp) : vector(vectorp) {}
    ~TranslateTransformation() {}
  };

}

#endif //FASTANIM_POSITIONTRANSFORMATION_H
