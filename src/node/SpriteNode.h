//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_SPRITENODE_H
#define FASTANIM_SPRITENODE_H

#include <fastgfx.h>
#include <memory>
#include "Node.h"
#include "../value/Value.h"

namespace fanim {

  class SpriteNode : public Node {
  public:
    std::shared_ptr<fgfx::SpriteLayer> layer;
    std::shared_ptr<fgfx::Sprite> sprite;
    std::shared_ptr<Value<glm::vec4>> color;

    SpriteNode(
        const std::shared_ptr<fgfx::SpriteLayer>& layerp,
        const std::shared_ptr<fgfx::Sprite>& spritep,
        const std::shared_ptr<Value<glm::vec4>>& colorp
    ) : layer(layerp), sprite(spritep), color(colorp) {}

    virtual ~SpriteNode() override {}

    virtual void render() override {
      /*const float *values = (const float*)(&computedMatrix);
      fgfx_log("COMPUTED SPACE MATRIX: %d -> %d\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n",this,values,
                     values[0],values[1],values[2],values[3],values[4],values[5],values[6],values[7],
                     values[8],values[9],values[10],values[11],values[12],values[13],values[14],values[15]);*/

      layer->bufferSprite(sprite, computedMatrix, color->get());
      Node::render();
    }



  };

}

#endif //FASTANIM_SPRITENODE_H
