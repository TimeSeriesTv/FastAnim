//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_COMBINEDTRANSFORMATION_H
#define FASTANIM_COMBINEDTRANSFORMATION_H

#include "glm/glm.hpp"
#include "Transformation.h"

namespace fanim {

  class CombinedTransformation : public Transformation {
  public:
    std::vector<std::shared_ptr<Transformation>> elements;
    virtual glm::mat4 getMatrix() override {
      glm::mat4 mat;
      for(auto it = elements.begin(); it!=elements.end(); it++) {
        mat *= (*it)->getMatrix();
      }
      return mat;
    }

    CombinedTransformation() {}
    ~CombinedTransformation() {}
  };

}

#endif //FASTANIM_COMBINEDTRANSFORMATION_H
