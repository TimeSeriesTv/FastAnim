#ifndef FASTANIM_NODE_H
#define FASTANIM_NODE_H

#include <glm/glm.hpp>
#include "../transformation/Transformation.h"
#include "../camera/Camera.h"

namespace fanim {

  class Node {
  public:
    std::shared_ptr<Transformation> transformation;
    std::vector<std::shared_ptr<Node>> children;

    int debugMode;
    glm::vec4 debugColor;

    glm::mat4 computedMatrix;

    Node() {}
    virtual ~Node() {}

    virtual void render() {
      for(auto it = children.begin(); it != children.end(); it++) {
        (*it)->render();
      }
    }
    virtual void remove() {
      for(auto it = children.begin(); it != children.end(); it++) {
        (*it)->remove();
      }
    }
    void computeMatrix(const glm::mat4& parentMatrix, const Camera& camera) {
      computedMatrix = transformation ? parentMatrix * transformation->getMatrix() : parentMatrix;
      for(auto it = children.begin(); it != children.end(); it++) {
        (*it)->computeMatrix(computedMatrix, camera);
      }
    }
    virtual void renderDebug(int debugMode, fgfx::LineLayer *lines) {
      int d = debugMode | this->debugMode;
      if(d>=1) {
        glm::vec3 ul(computedMatrix*glm::vec4(-1,1,0,1));
        glm::vec3 ur(computedMatrix*glm::vec4(1,1,0,1));
        glm::vec3 bl(computedMatrix*glm::vec4(-1,-1,0,1));
        glm::vec3 br(computedMatrix*glm::vec4(1,-1,0,1));
        lines->bufferLine(ul,ur,debugColor);
        lines->bufferLine(ur,br,debugColor);
        lines->bufferLine(br,bl,debugColor);
        lines->bufferLine(bl,ul,debugColor);
      }

      for(auto it = children.begin(); it != children.end(); it++) {
        (*it)->renderDebug(debugMode, lines);
      }
    }
  };

}

#endif //FASTANIM_NODE_H
