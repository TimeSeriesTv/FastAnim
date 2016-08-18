//
// Created by Michał Łaszczewski on 18/08/16.
//

#ifndef FASTANIM_COMPOSITION_H
#define FASTANIM_COMPOSITION_H

namespace fanim {

  class Composition {
  public:
    std::vector<std::shared_ptr<Composition>> children;

    Composition() {}
    virtual ~Composition() {}
    virtual void reset() {
      for(auto child : children) {
        child->reset();
      }
    }
    virtual void upload() {
      for(auto child : children) {
        child->upload();
      }
    }
    virtual void render(const glm::mat4& cameraMatrix) {
      for(auto child : children) {
        child->render(cameraMatrix);
      }
    }
  };

}

#endif //FASTANIM_COMPOSITION_H
