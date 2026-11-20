#include "Core/Vec3.h"

#include <valarray>

using namespace FluidCamera;

Vec3::Vec3(const Vector3 &nativeVector3)
{
	X = nativeVector3.x;
	Y = nativeVector3.y;
	Z = nativeVector3.z;
}

Vec3::Vec3(const float x, const float y, const float z)
{
	X = x;
	Y = y;
	Z = z;
}


Vec3 Vec3::FromGTARot(const Vec3 &nativeRot)
{
	return (Vec3(
		-nativeRot.Z,
		nativeRot.X,
		nativeRot.Y
	));
}

Vec3 Vec3::FromGTARot(const Vector3 &nativeRot)
{
	return (Vec3(
		-nativeRot.z,
		nativeRot.x,
		nativeRot.y
	));
}

Vec3 Vec3::ToGTARot() const
{
	return (Vec3(
		Y,
		Z,
		-X
	));
}

Vec3 Vec3::Lerp(const Vec3 &dest, const float t) const
{
	return (Vec3(
		X + (dest.X - X) * t,
		Y + (dest.Y - Y) * t,
		Z + (dest.Z - Z) * t
	));
}

float Vec3::Magnitude() const
{
	return (std::sqrt(MagnitudeSq()));
}

float Vec3::MagnitudeSq() const
{
	return (X * X + Y * Y + Z * Z);
}

float Vec3::Distance(const Vec3 &target) const
{
	return (std::sqrt(DistanceSq(target)));
}

float Vec3::DistanceSq(const Vec3 &target) const
{
	const float	tX = X - target.X;
	const float	tY = Y - target.Y;
	const float	tZ = Z - target.Z;
	return (tX * tX + tY * tY + tZ * tZ);
}

float Vec3::Dot(const Vec3 &target) const
{
	return (X * target.X + Y * target.Y + target.Z * target.Z);
}

bool Vec3::IsZero(const float tolerance) const
{
	if (std::abs(X) > tolerance)
		return (false);
	if (std::abs(Y) > tolerance)
		return (false);
	if (std::abs(Z) > tolerance)
		return (false);
	return (true);
}

Vec3 Vec3::Cross(const Vec3 &target) const
{
	return (Vec3(
		Y * target.Z - Z * target.Y,
		Z * target.X - X * target.Z,
		X * target.Y - Y * target.X
	));
}

Vec3 &Vec3::Normalize()
{
	if (IsZero())
		return(*this);
	const float	magnitude = Magnitude();

	X *= magnitude;
	Y *= magnitude;
	Z *= magnitude;
	return (*this);
}

// Normalizes as -180~180
Vec3 &Vec3::NormalizeRotation()
{
	X -= 360.f * std::floor((X + 180.f) / 360.f);
	Y -= 360.f * std::floor((Y + 180.f) / 360.f);
	Z -= 360.f * std::floor((Z + 180.f) / 360.f);
	return (*this);
}

Vec3 &Vec3::Rotate(const Vec3 &amountDegrees)
{
	*this += amountDegrees;
	return (this->NormalizeRotation());
}

Vec3 &Vec3::Rotate(const float yawDegrees, const float pitchDegrees, const float rollDegrees)
{
	return (Rotate(Vec3(yawDegrees, pitchDegrees, rollDegrees)));
}

Vec3 &Vec3::RotateRoll(const float amount)
{
	return (Rotate(0, 0, amount));
}

Vec3 &Vec3::RotatePitch(const float amount)
{
	return (Rotate(0, amount));
}

Vec3 &Vec3::RotateYaw(const float amount)
{
	return (Rotate(amount));
}

bool Vec3::operator==(const Vec3 &other) const
{
	return (
		X == other.X &&
		Y == other.Y &&
		Z == other.Z
	);
}

Vec3 Vec3::operator+(const Vec3 &other) const
{
	return (Vec3(
		X + other.X,
		Y + other.Y,
		Z + other.Z
	));
}

Vec3 Vec3::operator-(const Vec3 &other) const
{
	return (Vec3(
		X - other.X,
		Y - other.Y,
		Z - other.Z
	));
}

Vec3 Vec3::operator*(const Vec3 &other) const
{
	return (Vec3(
		X * other.X,
		Y * other.Y,
		Z * other.Z
	));
}

Vec3 Vec3::operator+(const float &other) const
{
	return (Vec3(
		X + other,
		Y + other,
		Z + other
	));
}

Vec3 Vec3::operator-(const float &other) const
{
	return (Vec3(
		X - other,
		Y - other,
		Z - other
	));
}

Vec3 Vec3::operator*(const float &other) const
{
	return (Vec3(
		X * other,
		Y * other,
		Z * other
	));
}

Vec3 &Vec3::operator+=(const Vec3 &other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;
	return (*this);
}

Vec3 &Vec3::operator-=(const Vec3 &other)
{
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;
	return (*this);
}

Vec3 &Vec3::operator*=(const Vec3 &other)
{
	X *= other.X;
	Y *= other.Y;
	Z *= other.Z;
	return (*this);
}
