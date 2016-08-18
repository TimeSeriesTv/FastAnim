//
// Created by Michał Łaszczewski on 18/08/16.
//

#ifndef FASTANIM_LOOKATCAMERA_H
#define FASTANIM_LOOKATCAMERA_H

#include "Camera.h"

namespace fanim {

  class LookAtCamera : public Camera{
  public:
    std::shared_ptr<Value<glm::vec3>> position;
    std::shared_ptr<Value<glm::vec3>> target;
    std::shared_ptr<Value<glm::vec3>> up;

    std::shared_ptr<Value<float>> fov;
    float zNear;
    float zFar;

    LookAtCamera(
        std::shared_ptr<Value<glm::vec3>> positionp,
        std::shared_ptr<Value<glm::vec3>> targetp,
        std::shared_ptr<Value<glm::vec3>> upp,
        std::shared_ptr<Value<float>> fovp,
        float zNearp,
        float zFarp
    ) : position(positionp), target(targetp), up(upp), fov(fovp), zNear(zNearp), zFar(zFarp) {}
    virtual ~LookAtCamera() {}

    virtual void computeMatrix(int width, int height) override {
      float aspectRatio = 1.0 * width / height;
      projection = glm::perspective(35.0f, aspectRatio, 0.1f, 1000.0f);
      view = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0, 0, 0),glm::vec3(0, -1, 0));
      camera = projection * view;
    }
  };

}

#endif //FASTANIM_LOOKATCAMERA_H
