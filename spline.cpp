#include <cmath>
#include "spline.h"

//
// Catmull-Rom Spline
//
//   x0, x1, x2, x3: 制御点
//   t: パラメータ
//   戻り値: 補間値
//
static float catmull_rom(float x0, float x1, float x2, float x3, float t)
{
  float v1 = (x2 - x0) * 0.5f, v2 = (x3 - x1) * 0.5f;

  return (((2.0f * x1 - 2.0f * x2 + v1 + v2) * t
    - 3.0f * x1 + 3.0f * x2 - 2.0f * v1 - v2) * t
    + v1) * t + x1;
}

//
// Catmull-Rom Spline による点列の補間
//
//   p: 補間値
//   p0, p1, p2, p3: 制御点
//   t: パラメータ
//
static void interpolate(float *p, const float *p0, const float *p1, const float *p2, const float *p3, float t)
{
  p[0] = catmull_rom(p0[0], p1[0], p2[0], p3[0], t);
  p[1] = catmull_rom(p0[1], p1[1], p2[1], p3[1], t);
  p[2] = catmull_rom(p0[2], p1[2], p2[2], p3[2], t);
}

//
// 任意の数の点列の Catmull-Rom Spline による補間
//
//   p: 補間する点列の座標値
//   t: 補間する点列のタイムライン（値は昇順に格納されている）
//   n: 点の数
//   u: 補間値を得るパラメータ (t[0]≦u≦t[n - 1]）
//
void spline(float *q, const float (*p)[3], const float *t, int n, float u)
{
  if (--n < 0)
    return;
  else if (n == 0)
  {
    q[0] = p[0][0];
    q[1] = p[0][1];
    q[2] = p[0][2];
  }
  else
  {
    int i = 0, j = n;

    // u を含む t の区間 [t[i], t[i+1]) を二分法で求める
    while (i < j)
    {
      int k = (i + j) / 2;
      if (t[k] < u)
        i = k + 1;
      else
        j = k;
    }

    if (--i < 0) i = 0;

    if (i < n)
    {
      int i0 = i - 1;
      if (i0 < 0) i0 = 0;
      int i1 = i + 1;
      int i2 = i1 + 1;
      if (i2 > n) i2 = n;

      // タイムラインを線形（折れ線）補間する場合
      interpolate(q, p[i0], p[i], p[i1], p[i2], (u - t[i]) / (t[i1] - t[i]));
    }
    else {
      q[0] = p[n][0];
      q[1] = p[n][1];
      q[2] = p[n][2];
    }
  }
}
