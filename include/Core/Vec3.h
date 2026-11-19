#pragma once

namespace FluidCamera
{
	// Expanded version of my other project's Vec2 (RedUI), with extra methods.
	class	Vec3
	{
	public:
		float	X;
		float	Y;
		float	Z;

		explicit	Vec3(float x = 0, float y = 0, float z = 0);
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
		// X: Roll, Y: Pitch, Z: Yaw
		Vec3		&Rotate(const Vec3 &amountDegrees);
		Vec3		&Rotate(float rollDegrees, float pitchDegrees = 0, float yawDegrees = 0);
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
