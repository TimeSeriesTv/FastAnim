//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_SCALETRANSFORMATION_H
#define FASTANIM_SCALETRANSFORMATION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transformation.h"

namespace fanim {

  class ScaleTransformation : public Transformation {
  public:
    std::shared_ptr<Value<glm::vec3>> vector;
    virtual glm::mat4 getMatrix() {
      return glm::scale(glm::mat4(), vector->get());
    }
    ScaleTransformation(std::shared_ptr<Value<glm::vec3>> vectorp) : vector(vectorp) {}
    ~ScaleTransformation() {}
  };

}

#endif //FASTANIM_POSITIONTRANSFORMATION_H
