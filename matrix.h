//
// 単位行列を設定する
//
//   m: 単位行列を設定する配列変数
//
extern void loadIdentity(GLfloat *m);

//
// 直交投影変換行列を求める
//
//   m: 直交投影変換行列を格納する配列
//   left, right: ビューボリュームの左右端
//   bottom, top: ビューボリュームの上下端
//   zNear, zFar: 前方面および後方面までの距離
//
extern void ortho(GLfloat *m, float left, float right, float bottom, float top, float zNear, float zFar);

//
// 透視投影変換行列を求める
//
//   m: 透視投影変換行列を格納する配列
//   left, right: 前方面の左右端
//   bottom, top: 前方面の上下端
//   zNear, zFar: 前方面および後方面までの距離
//
extern void frustum(GLfloat *m, float left, float right, float bottom, float top, float zNear, float zFar);

//
// 画角を指定して透視投影変換行列を求める
//
//   m: 透視投影変換行列を格納する配列
//   fovy: 画角（ラジアン）
//   aspect: ウィンドウの縦横比
//   zNear, zFar: 前方面および後方面までの距離
//
extern void perspective(GLfloat *m, float fovy, float aspect, float zNear, float zFar);

//
// ビュー変換行列を求める
//
//   m: ビュー変換行列を格納する配列
//   ex, ey, ez: 視点の位置
//   tx, ty, tz: 目標点の位置
//   ux, uy, uz: 上方向のベクトル
//
extern void lookat(GLfloat *m, float ex, float ey, float ez, float tx, float ty, float tz, float ux, float uy, float uz);

//
// 平行移動変換行列を求める
//
//   m: 平行移動変換行列を格納する配列
//   x, y, z: 平行移動量
//
extern void translate(GLfloat *m, float x, float y, float z);

//
// 拡大縮小変換行列を求める
//
//   m: 平行移動変換行列を格納する配列
//   x, y, z: 拡大縮小率
//
extern void scale(GLfloat *m, float x, float y, float z);

//
// 任意軸周りの回転変換行列を求める
//
//   r: 回転変換行列を格納する配列
//   x, y, z: 中心軸
//   a: 回転角（ラジアン）
//
extern void rotate(GLfloat *r, float x, float y, float z, float a);

//
// 法線変換行列を求める
//
//   g: 法線ベクトルの変換行列を格納する配列
//   m: 元の変換行列
//
extern void normal(GLfloat *g, const float *m);

//
// 逆行列を求める
//
//   m1: 元の変換行列
//   m2: m1 の逆行列
//   逆行列が求められなければ戻り値は false
//
extern bool inverse(GLfloat *m2, const GLfloat *m1);

//
// 4 行 4 列の行列の積を求める
//
//   m ← m1 × m2
//
extern void multiply(GLfloat *m, const GLfloat *m1, const GLfloat *m2);

//
// ベクトルに行列をかける
//
//   v2 ← m * v1
//
extern void transform(GLfloat *v2, const GLfloat *m, const GLfloat *v1);

//
// ベクトル v1 を正規化したものを求める
//
//   v2 ← v1 を正規化
//
extern void normalize(GLfloat *v2, const GLfloat *v1);
