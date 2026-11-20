#pragma once
#include "ScriptHookV/inc/types.h"

namespace FluidCamera
{
	// Expanded version of my other project's Vec2 (RedUI), with extra methods. Y-up, rotations in Yaw, Pitch, Roll.
	class	Vec3
	{
	public:
		float	X;
		float	Y;
		float	Z;

		explicit	Vec3(const Vector3 &nativeVector3);
		explicit	Vec3(float x = 0, float y = 0, float z = 0);
		static Vec3	FromGTARot(const Vec3 &nativeRot);
		static Vec3	FromGTARot(const Vector3 &nativeRot);
		Vec3		ToGTARot() const;
		Vec3		Lerp(const Vec3 &dest, float t) const;
		float		Magnitude() const;
		// Magnitude squared. Prefer.
		float		MagnitudeSq() const;
		float		Distance(const Vec3 &target) const;
		// Distance squared. Prefer.
		float		DistanceSq(const Vec3 &target) const;
		float		Dot(const Vec3 &target) const;
		bool		IsZero(float tolerance = 0.000001) const;
		Vec3		Cross(const Vec3 &target) const;
		Vec3		&Normalize();
		Vec3		&NormalizeRotation();
		// X: Yaw, Y: Pitch, Z: Roll
		Vec3		&Rotate(const Vec3 &amountDegrees);
		Vec3		&Rotate(float yawDegrees, float pitchDegrees = 0, float rollDegrees = 0);
		Vec3		&RotateRoll(float amount);
		Vec3		&RotatePitch(float amount);
		Vec3		&RotateYaw(float amount);
		bool		operator==(const Vec3 &other) const;
		Vec3		operator+(const Vec3 &other) const;
		Vec3		operator-(const Vec3 &other) const;
		Vec3		operator*(const Vec3 &other) const;
		Vec3		operator+(const float &other) const;
		Vec3		operator-(const float &other) const;
		Vec3		operator*(const float &other) const;
		Vec3		&operator+=(const Vec3 &other);
		Vec3		&operator-=(const Vec3 &other);
		Vec3		&operator*=(const Vec3 &other);
	};

}
