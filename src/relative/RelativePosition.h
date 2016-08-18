//
// Created by Michał Łaszczewski on 18/08/16.
//

#ifndef FASTANIM_RELATIVEPOSITION_H
#define FASTANIM_RELATIVEPOSITION_H

#include <fastgfx.h>
#include <glm/glm.hpp>

namespace fanim {

  class RelativePosition : public Value<glm::vec3> {
  public:
    std::shared_ptr<Node> from;
    std::shared_ptr<Node> to;
    std::shared_ptr<Value<glm::vec3>> position;

    RelativePosition(
        std::shared_ptr<Node> fromp,
        std::shared_ptr<Node> top,
        std::shared_ptr<Value<glm::vec3>> positionp)
        : from(fromp), to(top), position(positionp) {}

    virtual ~RelativePosition() {};
    virtual glm::vec3 get() {
      glm::vec4 point = position ? glm::vec4(position->get(),1) : glm::vec4(0,0,0,1);
      glm::vec4 global = to->computedMatrix * point;
      glm::vec4 local = glm::inverse(from->computedMatrix) * global;
      return glm::vec3(local.x, local.y, local.z);
    }
  };

}

#endif //FASTANIM_RELATIVEPOSITION_H
