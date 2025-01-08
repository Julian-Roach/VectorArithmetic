#pragma once

//
// Vector Arithmetic for C++
//
// This header file contains and manipulates bool, integer and float vector types from 2 up to 4 dimensions.
//
// Concepts such as scaling, vector addition, magnitude and dot products have been taken into consideration.
//
// They have been designed to make creation of basic vectors fast in any project and int - float vector
// interaction extremely flexible.
//
// To use conversion from a float vector to an int vector, take the macro "ROUNDING_VECTORS" and define it
// BEFORE including the header file. The vectors are rounded component - wise to nearest integer, which
// requires a heavier library <cmath> to be included - avoided by default.
//

#ifdef ROUNDING_VECTORS
#include <cmath>
#endif

// Vector definitions
namespace V {

	// Integer component vectors
	class Vector2i
	{
	public:
		int x, y;

		Vector2i(int init_x = 0, int init_y = 0) : x(init_x), y(init_y) {};
	};

	class Vector3i : public Vector2i
	{
	public:
		int z;

		Vector3i(int init_x = 0, int init_y = 0, int init_z = 0) : Vector2i(init_x, init_y), z(init_z) {};
	};

	class Vector4i : public Vector3i
	{
	public:
		int w;

		Vector4i(int init_x = 0, int init_y = 0, int init_z = 0, int init_w = 0) : Vector3i(init_x, init_y, init_z), w(init_w) {};
	};

	// Float component vectors
	class Vector2f
	{
	public:
		float x, y;

		Vector2f(float init_x = 0, float init_y = 0) : x(init_x), y(init_y) {};
	};

	class Vector3f : public Vector2f
	{
	public:
		float z;

		Vector3f(float init_x = 0, float init_y = 0, float init_z = 0) : Vector2f(init_x, init_y), z(init_z) {};
	};

	class Vector4f : public Vector3f
	{
	public:
		float w;

		Vector4f(float init_x = 0, float init_y = 0, float init_z = 0, float init_w = 0) : Vector3f(init_x, init_y, init_z), w(init_w) {};
	};

	// Boolean component vectors
	class Vector2b
	{
	public:
		bool x, y;

		Vector2b(bool init_x = false, bool init_y = false) : x(init_x), y(init_y) {};
	};

	class Vector3b : public Vector2b
	{
	public:
		bool z;

		Vector3b(bool init_x = false, bool init_y = false, bool init_z = false) : Vector2b(init_x, init_y), z(init_z) {};
	};

	class Vector4b : public Vector3b
	{
	public:
		bool w;

		Vector4b(bool init_x = false, bool init_y = false, bool init_z = false, bool init_w = false) : Vector3b(init_x, init_y, init_z), w(init_w) {};
	};
}

// Vector conversions
namespace V {

	// The vectors are rounded
#ifdef ROUNDING_VECTORS
	inline Vector2i vecftoi(Vector2f vf) { return Vector2i((int)round(vf.x), (int)round(vf.y)); };
	inline Vector3i vecftoi(Vector3f vf) { return Vector3i((int)round(vf.x), (int)round(vf.y), (int)round(vf.z)); };
	inline Vector4i vecftoi(Vector4f vf) { return Vector4i((int)round(vf.x), (int)round(vf.y), (int)round(vf.z), (int)round(vf.w)); };
#endif

	inline Vector2f vecitof(Vector2i vi) { return Vector2f((float)vi.x, (float)vi.y); };
	inline Vector3f vecitof(Vector3i vi) { return Vector3f((float)vi.x, (float)vi.y, (float)vi.z); };
	inline Vector4f vecitof(Vector4i vi) { return Vector4f((float)vi.x, (float)vi.y, (float)vi.z, (float)vi.w); };
}

// Vector operations
namespace V {

	// Float vectors
	inline float operator&(Vector2f v1, Vector2f v2) { return v1.x * v2.x + v1.y * v2.y; }
	inline float operator&(Vector3f v1, Vector3f v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
	inline float operator&(Vector4f v1, Vector4f v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w; }

	inline float dot(Vector2f v1, Vector2f v2) { return v1 & v2; }
	inline float dot(Vector3f v1, Vector3f v2) { return v1 & v2; }
	inline float dot(Vector4f v1, Vector4f v2) { return v1 & v2; }

	inline Vector2f operator+(Vector2f v1, Vector2f v2) { return Vector2f(v1.x + v2.x, v1.y + v2.y); };
	inline Vector3f operator+(Vector3f v1, Vector3f v2) { return Vector3f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); };
	inline Vector4f operator+(Vector4f v1, Vector4f v2) { return Vector4f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w); };

	inline Vector2f operator*(float scalar, Vector2f v1) { return Vector2f(scalar * v1.x, scalar * v1.y); }
	inline Vector3f operator*(float scalar, Vector3f v1) { return Vector3f(scalar * v1.x, scalar * v1.y, scalar * v1.z); }
	inline Vector4f operator*(float scalar, Vector4f v1) { return Vector4f(scalar * v1.x, scalar * v1.y, scalar * v1.z, scalar * v1.w); }
	inline Vector2f operator*(Vector2f v1, float scalar) { return scalar * v1; }
	inline Vector3f operator*(Vector3f v1, float scalar) { return scalar * v1; }
	inline Vector4f operator*(Vector4f v1, float scalar) { return scalar * v1; }

	inline float magnitude_sqr(Vector2f v) { return v & v; }
	inline float magnitude_sqr(Vector3f v) { return v & v; }
	inline float magnitude_sqr(Vector4f v) { return v & v; }

	inline double magnitude(Vector2f v) { return sqrt(v & v); }
	inline double magnitude(Vector3f v) { return sqrt(v & v); }
	inline double magnitude(Vector4f v) { return sqrt(v & v); }

	// Integer vectors
	inline int operator&(Vector2i v1, Vector2i v2) { return v1.x * v2.x + v1.y * v2.y; }
	inline int operator&(Vector3i v1, Vector3i v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
	inline int operator&(Vector4i v1, Vector4i v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w; }

	inline int dot(Vector2i v1, Vector2i v2) { return v1 & v2; }
	inline int dot(Vector3i v1, Vector3i v2) { return v1 & v2; }
	inline int dot(Vector4i v1, Vector4i v2) { return v1 & v2; }

	inline Vector2i operator+(Vector2i v1, Vector2i v2) { return Vector2i(v1.x + v2.x, v1.y + v2.y); }
	inline Vector3i operator+(Vector3i v1, Vector3i v2) { return Vector3i(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
	inline Vector4i operator+(Vector4i v1, Vector4i v2) { return Vector4i(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w); }

	inline Vector2i operator*(int scalar, Vector2i v1) { return Vector2i(scalar * v1.x, scalar * v1.y); }
	inline Vector3i operator*(int scalar, Vector3i v1) { return Vector3i(scalar * v1.x, scalar * v1.y, scalar * v1.z); }
	inline Vector4i operator*(int scalar, Vector4i v1) { return Vector4i(scalar * v1.x, scalar * v1.y, scalar * v1.z, scalar * v1.w); }
	inline Vector2i operator*(Vector2i v1, int scalar) { return scalar * v1; }
	inline Vector3i operator*(Vector3i v1, int scalar) { return scalar * v1; }
	inline Vector4i operator*(Vector4i v1, int scalar) { return scalar * v1; }

	inline int magnitude_sqr(Vector2i v) { return v & v; }
	inline int magnitude_sqr(Vector3i v) { return v & v; }
	inline int magnitude_sqr(Vector4i v) { return v & v; }

	inline double magnitude(Vector2i v) { return sqrt(v & v); }
	inline double magnitude(Vector3i v) { return sqrt(v & v); }
	inline double magnitude(Vector4i v) { return sqrt(v & v); }

	// Inter-type operations
	inline float operator&(Vector2i v1, Vector2f v2) { return v1.x * v2.x + v1.y * v2.y; }
	inline float operator&(Vector2f v1, Vector2i v2) { return v2 & v1; }
	inline float operator&(Vector3i v1, Vector3f v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
	inline float operator&(Vector3f v1, Vector3i v2) { return v2 & v1; }
	inline float operator&(Vector4i v1, Vector4f v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w; }
	inline float operator&(Vector4f v1, Vector4i v2) { return v2 & v1; }

	inline float dot(Vector2i v1, Vector2f v2) { return v1 & v2; };
	inline float dot(Vector2f v1, Vector2i v2) { return v1 & v2; };
	inline float dot(Vector3i v1, Vector3f v2) { return v1 & v2; };
	inline float dot(Vector3f v1, Vector3i v2) { return v1 & v2; };
	inline float dot(Vector4i v1, Vector4f v2) { return v1 & v2; };
	inline float dot(Vector4f v1, Vector4i v2) { return v1 & v2; };

	inline Vector2f operator+(Vector2i v1, Vector2f v2) { return Vector2f((float)v1.x + v2.x, (float)v1.y + v2.y); };
	inline Vector3f operator+(Vector3i v1, Vector3f v2) { return Vector3f((float)v1.x + v2.x, (float)v1.y + v2.y, (float)v1.z + v2.z); };
	inline Vector4f operator+(Vector4i v1, Vector4f v2) { return Vector4f((float)v1.x + v2.x, (float)v1.y + v2.y, (float)v1.z + v2.z, (float)v1.w + v2.w); };
	inline Vector2f operator+(Vector2f v1, Vector2i v2) { return v2 + v1; };
	inline Vector3f operator+(Vector3f v1, Vector3i v2) { return v2 + v1; };
	inline Vector4f operator+(Vector4f v1, Vector4i v2) { return v2 + v1; };

	inline Vector2f operator*(int   scalar, Vector2f v1) { return Vector2f(scalar * v1.x, scalar * v1.y * scalar); }
	inline Vector2f operator*(float scalar, Vector2i v1) { return Vector2f(scalar * v1.x, scalar * v1.y * scalar); }
	inline Vector3f operator*(int   scalar, Vector3f v1) { return Vector3f(scalar * v1.x, scalar * v1.y * scalar, scalar * v1.z); }
	inline Vector3f operator*(float scalar, Vector3i v1) { return Vector3f(scalar * v1.x, scalar * v1.y * scalar, scalar * v1.z); }
	inline Vector4f operator*(int   scalar, Vector4f v1) { return Vector4f(scalar * v1.x, scalar * v1.y * scalar, scalar * v1.z, scalar * v1.w); }
	inline Vector4f operator*(float scalar, Vector4i v1) { return Vector4f(scalar * v1.x, scalar * v1.y * scalar, scalar * v1.z, scalar * v1.w); }
	inline Vector2f operator*(Vector2f v1, int   scalar) { return scalar * v1; }
	inline Vector2f operator*(Vector2i v1, float scalar) { return scalar * v1; }
	inline Vector3f operator*(Vector3f v1, int   scalar) { return scalar * v1; }
	inline Vector3f operator*(Vector3i v1, float scalar) { return scalar * v1; }
	inline Vector4f operator*(Vector4f v1, int   scalar) { return scalar * v1; }
	inline Vector4f operator*(Vector4i v1, float scalar) { return scalar * v1; }

}






