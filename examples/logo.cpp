#include <fastgfx.h>
#include <fastanim.h>
#include <glm/glm.hpp>
#include <cmath>
#include <cstdlib>

#define PI 3.141592

double lastMoveTime = 0;

int main() {
  int res;
  res = fgfx::init();
  if(res!=0) {
    fgfx_log("FGFX Initialization failed\n");
    return res;
  }

  auto logoSprite = fgfx::engine->getSprite("../deps/FastGFX/assets/logo.png");
  auto spriteLayer = fgfx::engine->createSpriteLayer();

  auto scene = std::make_shared<fanim::Node>();
  scene->transformation = std::make_shared<fanim::ScaleTransformation>(
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(6,6,6))
  );
  auto logo = std::make_shared<fanim::SpriteNode>(spriteLayer,logoSprite,
                                                  std::make_shared<fanim::Static<glm::vec4>>(glm::vec4(1,1,1,1)));
  scene->children.push_back(logo);

  auto logoPosition = std::make_shared<fanim::LinearTransition<glm::vec3>>(
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0,0,0))
  );
  logo->transformation = std::make_shared<fanim::TranslateTransformation>(logoPosition);

  auto camera = std::make_shared<fanim::LookAtCamera>(
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0,0,20)),
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0,0,0)),
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0,-1,0)),
      std::make_shared<fanim::Static<float>>(35.0),
      0.1,
      1000
  );

  auto composition = std::make_shared<fanim::LayerComposition>(spriteLayer);

  auto view = std::make_shared<fanim::View>(scene,composition,camera);
  view->animator.add(logoPosition);

  fgfx::engine->setRenderFunction([=](double time, float delta) {
    view->advance(delta/1000);
    view->upload();
    view->render();

    if(time>lastMoveTime+1000) {
      lastMoveTime = time;
      logoPosition->setNext(
          std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0.1*(rand()%100),0.1*(rand()%100),0)), 1.0);
    }
  });
}
