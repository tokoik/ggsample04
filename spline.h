//
// 任意の数の点列の Catmull-Rom Spline による補間
//
//   p: 補間する点列の座標値
//   t: 補間する点列のタイムライン（値は昇順に格納されている）
//   n: 点の数
//   u: 補間値を得るパラメータ (t[0]≦u≦t[n - 1]）
//
extern void spline(float *q, const float (*p)[3], const float *t, int n, float u);
