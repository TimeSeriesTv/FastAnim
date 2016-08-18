//
// Created by Michał Łaszczewski on 17/08/16.
//

#ifndef FASTANIM_VIEW_H
#define FASTANIM_VIEW_H

#include <fastgfx.h>
#include <memory>
#include "../value/Value.h"
#include "../camera/Camera.h"
#include "../node/Node.h"
#include "../Animated.h"

namespace fanim {

  class View {
  public:
    std::shared_ptr<Value<glm::vec4>> backgroundColor;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Node> scene;

    Animator animator;

    std::shared_ptr<Composition> composition;

    View(
        std::shared_ptr<Node> scenep,
        std::shared_ptr<Composition> compositionp,
        std::shared_ptr<Camera> camerap)
        : camera(camerap), scene(scenep), composition(compositionp) {
    }
    ~View() {
    }

    void advance(float delta) {
      animator.advance(delta);
    }
    void upload() {
      camera->computeMatrix(fgfx::engine->width, fgfx::engine->height);
      composition->reset();
      scene->computeMatrix(glm::mat4(),*camera);
      scene->render();
      composition->upload();
    }
    void render() {
      if(backgroundColor) {
        glm::vec4 color = backgroundColor->get();
        glClearColor(color.r, color.g, color.b, color.a);
      } else {
        glClearColor(0, 0, 0, 0);
      }
      glClear(GL_COLOR_BUFFER_BIT);

      composition->render(camera->camera);
    }

  };


}

#endif //FASTANIM_VIEW_H
