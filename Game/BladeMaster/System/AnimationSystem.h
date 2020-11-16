#pragma once 
#include "../Core/SystemBase.h"
/*
    For an entity to be qualified to use this system, it must have:
		-> animation component
		-> position component
    
    If an entity has animation, it must knows which animations are active,
	and iterates over these on each update cycle. For each active animation, it does various checks to
	determine whether the frame index should be incremented, or if the frame needs to be repeated. When an animation has completed,
	it checks if it is a looping animation, and if so, resets the frame index to 0 for that animation.
	Otherwise, it deactivates the animation and fires off an event so that any other systems that care about it find out.
	If there are no system care about deactivation of animation, this system will set entity back to default sprite

    More information about animation, AnimationComponent.h
*/
class AnimationSystem : public SystemBase {
public:
	AnimationSystem();
    void AnimationRender();
    void Update();
};