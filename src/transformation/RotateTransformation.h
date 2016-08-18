//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_RotateTRANSFORMATION_H
#define FASTANIM_RotateTRANSFORMATION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transformation.h"

namespace fanim {

  class RotateTransformation : public Transformation {
  public:
    std::shared_ptr<Value<glm::vec3>> axis;
    std::shared_ptr<Value<float>> angle;
    virtual glm::mat4 getMatrix() {
      return glm::rotate(glm::mat4(), angle->get(), axis->get());
    }
    RotateTransformation(std::shared_ptr<Value<float>> anglep, std::shared_ptr<Value<glm::vec3>> axisp) : axis(axisp), angle(anglep) {}
    ~RotateTransformation() {}
  };

}

#endif //FASTANIM_POSITIONTRANSFORMATION_H
