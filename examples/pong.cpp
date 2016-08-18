#include <fastgfx.h>
#include <fastanim.h>
#include <glm/glm.hpp>
#include <cmath>
#include <cstdlib>

#define PI 3.141592

double lastMoveTime = 0;
bool onLeftSide = true;

int main() {
  int res;
  res = fgfx::init();
  if(res!=0) {
    fgfx_log("FGFX Initialization failed\n");
    return res;
  }

  auto logoSprite = fgfx::engine->getSprite("../deps/FastGFX/assets/logo.png");
  auto ballSprite = fgfx::engine->getSprite("../assets/ball.png");
  auto spriteLayer = fgfx::engine->createSpriteLayer();

  auto scene = std::make_shared<fanim::Node>();
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

  scene->transformation = std::make_shared<fanim::ScaleTransformation>(
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(46,46,46))
  );

  auto paddle1Position = std::make_shared<fanim::LinearTransition<glm::vec3>>(
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(-1,0,0))
  );
  view->animator.add(paddle1Position);

  auto paddle2Position = std::make_shared<fanim::LinearTransition<glm::vec3>>(
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(1,0,0))
  );
  view->animator.add(paddle2Position);

  auto paddle1 = std::make_shared<fanim::SpriteNode>(
      spriteLayer, logoSprite, std::make_shared<fanim::Static<glm::vec4>>(glm::vec4(1,1,1,1)));
  auto paddle1transformation = std::make_shared<fanim::CombinedTransformation>();
  paddle1transformation->elements.push_back(
      std::make_shared<fanim::TranslateTransformation>(paddle1Position)
  );
  paddle1transformation->elements.push_back(
      std::make_shared<fanim::RotateTransformation>(
          std::make_shared<fanim::Static<float>>(PI/2),
          std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0,0,1))
      )
  );
  paddle1transformation->elements.push_back(
      std::make_shared<fanim::ScaleTransformation>(
          std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0.023,0.046,1))
      )
  );
  paddle1->transformation = paddle1transformation;
  scene->children.push_back(paddle1);

  auto paddle2 = std::make_shared<fanim::SpriteNode>(
      spriteLayer, logoSprite, std::make_shared<fanim::Static<glm::vec4>>(glm::vec4(1,1,1,1)));
  auto paddle2transformation = std::make_shared<fanim::CombinedTransformation>();
  paddle2transformation->elements.push_back(
      std::make_shared<fanim::TranslateTransformation>(paddle2Position)
  );
  paddle2transformation->elements.push_back(
      std::make_shared<fanim::RotateTransformation>(
          std::make_shared<fanim::Static<float>>(PI/2),
          std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0,0,1))
      )
  );
  paddle2transformation->elements.push_back(
      std::make_shared<fanim::ScaleTransformation>(
          std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0.023,0.046,1))
      )
  );
  paddle2->transformation = paddle2transformation;
  scene->children.push_back(paddle2);

  auto rocketPosition1 = std::make_shared<fanim::RelativePosition>(scene, paddle1, nullptr);
  auto rocketPosition2 = std::make_shared<fanim::RelativePosition>(scene, paddle2, nullptr);
  auto rocketPosition = std::make_shared<fanim::LinearTransition<glm::vec3>>(
      rocketPosition1
  );
  view->animator.add(rocketPosition);

  auto rocket = std::make_shared<fanim::SpriteNode>(
      spriteLayer, ballSprite, std::make_shared<fanim::Static<glm::vec4>>(glm::vec4(1,1,1,1)));
  scene->children.push_back(rocket);
  auto rocketTransformation = std::make_shared<fanim::CombinedTransformation>();
  rocketTransformation->elements.push_back(std::make_shared<fanim::TranslateTransformation>(rocketPosition));
  rocketTransformation->elements.push_back(
      std::make_shared<fanim::ScaleTransformation>(
          std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0.123,0.123,1))
      )
  );
  rocket->transformation = rocketTransformation;

  auto ballPosition = std::make_shared<fanim::LinearTransition<glm::vec3>>(
      std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0,0,0))
  );
  view->animator.add(ballPosition);

  auto ball = std::make_shared<fanim::SpriteNode>(
      spriteLayer, ballSprite, std::make_shared<fanim::Static<glm::vec4>>(glm::vec4(1,1,1,1)));
  scene->children.push_back(ball);
  auto ballTransformation = std::make_shared<fanim::CombinedTransformation>();
  ballTransformation->elements.push_back(std::make_shared<fanim::TranslateTransformation>(ballPosition));
  ballTransformation->elements.push_back(
      std::make_shared<fanim::ScaleTransformation>(
          std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(0.123,0.123,1))
      )
  );
  ball->transformation = ballTransformation;


  fgfx::engine->setRenderFunction([=](double time, float delta) {
    view->advance(delta/1000);
    view->upload();
    view->render();

    if(time>lastMoveTime+1000) {
      lastMoveTime = time;
      auto paddle1next = std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(-1.0,1-0.02*(rand()%100),0.0));
      paddle1Position->setNext(paddle1next, 1.0);
      auto paddle2next = std::make_shared<fanim::Static<glm::vec3>>(glm::vec3(1.0,1-0.02*(rand()%100),0.0));
      paddle2Position->setNext(paddle2next, 1.0);
      onLeftSide = !onLeftSide;
      rocketPosition->setNext(onLeftSide ? rocketPosition1 : rocketPosition2, 1.0);
      ballPosition->setNext(onLeftSide ? paddle1next : paddle2next,1.0);
    }
  });
}
