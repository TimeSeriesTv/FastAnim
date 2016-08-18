//
// Created by Michał Łaszczewski on 18/08/16.
//

#ifndef FASTANIM_LAYERCOMPOSITION_H
#define FASTANIM_LAYERCOMPOSITION_H

#include <fastgfx.h>
#include <memory>

namespace fanim {

  class LayerComposition : public Composition{
  public:
    std::shared_ptr<fgfx::Layer> layer;

    GLenum source_blending;
    GLenum destination_blending;

    LayerComposition(std::shared_ptr<fgfx::Layer> layerp, GLenum srcp, GLenum destp)
        : layer(layerp), source_blending(srcp), destination_blending(destp) {}
    LayerComposition(std::shared_ptr<fgfx::Layer> layerp)
        : layer(layerp), source_blending(GL_SRC_ALPHA), destination_blending(GL_ONE_MINUS_SRC_ALPHA) {}

    virtual ~LayerComposition() {}
    virtual void reset() {
      Composition::reset();
      layer->reset();
    }
    virtual void upload() {
      Composition::upload();
      layer->upload();
    };
    virtual void render(const glm::mat4& cameraMatrix) {
      glEnable(GL_BLEND);
      glBlendFunc(source_blending, destination_blending);
      layer->render(cameraMatrix);
      Composition::render(cameraMatrix);
    };
  };

}


#endif //FASTANIM_LAYERCOMPOSITION_H
