#pragma once
#include "MyVector2.h"
#include "MyVector3.h"
#include "MyVector4.h"
#include "MyMatrix4x4.h"

// 円周率
const float PI = 3.141592654f;

// 代入演算子オーバーロード
Vector3& operator+=(Vector3& lhs, const Vector3& rhv);
Vector3& operator-=(Vector3& lhs, const Vector3& rhv);
Vector3& operator*=(Vector3& v, float s);
Vector3& operator/=(Vector3& v, float s);

// 2項演算子オーバーロード
const Vector3 operator+(const Vector3& v1, const Vector3& v2);
const Vector3 operator-(const Vector3& v1, const Vector3& v2);
const Vector3 operator*(const Vector3& v, float s);
const Vector3 operator*(float s, const Vector3& v);
const Vector3 operator/(const Vector3& v, float s);

// 代入演算子オーバーロード
Vector2& operator+=(Vector2& lhs, const Vector2& rhv);
Vector2& operator-=(Vector2& lhs, const Vector2& rhv);
Vector2& operator*=(Vector2& v, float s);
Vector2& operator/=(Vector2& v, float s);

// 2項演算子オーバーロード
const Vector2 operator+(const Vector2& v1, const Vector2& v2);
const Vector2 operator-(const Vector2& v1, const Vector2& v2);
const Vector2 operator*(const Vector2& v, float s);
const Vector2 operator*(float s, const Vector2& v);
const Vector2 operator/(const Vector2& v, float s);

// ノルム(長さ)を求める
float Length(const Vector3& v);
// 正規化する
Vector3 Normalize(const Vector3& v);
// 逆行列を求める
Matrix4x4 Inverse(const Matrix4x4& m);

// 単位行列の作成
Matrix4x4 MakeIdentity4x4();
// スケーリング行列の作成
Matrix4x4 MakeScaleMatrix(const Vector3& scale);
// 回転行列の作成
Matrix4x4 MakeRotateXMatrix(float theta);
Matrix4x4 MakeRotateYMatrix(float theta);
Matrix4x4 MakeRotateZMatrix(float theta);
// 平行移動行列の作成
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
// ビューポート行列の作成
Matrix4x4
MakeViewportMatrix(float left, float top, float width, float height, float nearZ, float farZ);
// アフィン変換行列の作成
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

// 射影変換
// 透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
// 平行投影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

// 代入演算子オーバーロード
Matrix4x4& operator*=(Matrix4x4& lhm, const Matrix4x4& rhm);

// 2項演算子オーバーロード
Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);

//// 座標変換（w除算あり）
//Vector3 Transform(const Vector3& v, const Matrix4x4& m);
//// ベクトル変換
//Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);