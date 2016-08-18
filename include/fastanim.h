//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_FASTANIM_H
#define FASTANIM_FASTANIM_H

#include <fastgfx.h>

namespace fanim {

}

#include "../src/FastSet.h"
#include "../src/Animator.h"
#include "../src/Animated.h"

#include "../src/node/Node.h"
#include "../src/node/SpriteNode.h"
#include "../src/node/TextNode.h"

#include "../src/value/Static.h"
#include "../src/value/Value.h"

#include "../src/transition/Transition.h"
#include "../src/transition/LinearTransition.h"

#include "../src/transformation/Transformation.h"
#include "../src/transformation/CombinedTransformation.h"
#include "../src/transformation/TranslateTransformation.h"
#include "../src/transformation/ScaleTransformation.h"
#include "../src/transformation/RotateTransformation.h"

#include "../src/camera/Camera.h"
#include "../src/camera/LookAtCamera.h"

#include "../src/composition/Composition.h"
#include "../src/composition/LayerComposition.h"

#include "../src/view/View.h"

#include "../src/relative/RelativePosition.h"

#endif //FASTANIM_FASTANIM_H
