#include "TemplateSC.h"
#include "Inputs/Input.h"
#include "Config/pch.h"
#include "ECS/ECS.h"

class PlayerManagerScript : public TemplateSC {
public:
	int playerHealth;
	float playerMovementSpeed;
	float playerJumpForce;

	void Start() override {

	}

	void Update() override {
		ecs::ECS* ecs = ecs::ECS::GetInstance();

		if (auto* tc = ecsPtr->GetComponent<ecs::TransformComponent>(entity)) {
			//tc->LocalTransformation.position.x += 0.01f;
			tc->LocalTransformation.position += glm::vec3(0.01f, 0.f, 0.f) * ecs->deltaTime;

			float pitch = tc->LocalTransformation.rotation.x;
			float yaw = tc->LocalTransformation.rotation.y;

			glm::vec3 forward = {
				cos(pitch) * sin(yaw),
				-sin(pitch),
				cos(pitch) * cos(yaw)
			};

			glm::vec3 right = {
				cos(yaw),
				0.0f,
				-sin(yaw)
			};

			if (Input::InputSystem::inputSystem->IsKeyPressed(keys::W)) {
				std::cout << "MOVING FORWARD\n";
				tc->LocalTransformation.position += glm::normalize(forward) * ecs->deltaTime;
			}
		}
	}

	REFLECTABLE(PlayerManagerScript, playerHealth, playerMovementSpeed, playerJumpForce);
};