//
// Created by Michał Łaszczewski on 17/08/16.
//

#ifndef FASTANIM_CAMERA_H
#define FASTANIM_CAMERA_H

#include <fastgfx.h>
#include <memory>
#include "../value/Value.h"

namespace fanim {

  class Camera {
  public:

    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 camera;

    virtual ~Camera() {}
    virtual void computeMatrix(int width, int height) = 0;

  };

}

#endif //FASTANIM_CAMERA_H
