//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_TEXTNODE_H
#define FASTANIM_TEXTNODE_H

#include <fastgfx.h>
#include <string>
#include <memory>
#include "Node.h"
#include "../value/Value.h"


namespace fanim {

  class TextNode : public Node {
  public:
    std::shared_ptr<fgfx::SpriteLayer> layer;
    std::shared_ptr<fgfx::SpriteFont> font;
    std::shared_ptr<Value<glm::vec4>> color;
    std::string text;

    TextNode(
        const std::shared_ptr<fgfx::SpriteLayer>& layerp,
        const std::shared_ptr<fgfx::SpriteFont>& fontp,
        const std::shared_ptr<Value<glm::vec4>>& colorp,
        const std::string &textp
    ) : layer(layerp), font(fontp), color(colorp), text(textp) {}

    virtual ~TextNode() override {}

    virtual void render() override {
      font->renderString(layer, computedMatrix, color->get(), text);
      Node::render();
    }

  };

};

#endif //FASTANIM_TEXTNODE_H
