# ggsample04 - 四元数の球面線形補間 (Slerp) による回転アニメーション

## 1. 概要

本プログラムは、[ゲームグラフィックス特論](https://tokoik.github.io/gg/)の講義資料 [ggnote04.pdf](https://tokoik.github.io/gg/ggnote04.pdf) に対応する宿題のひな型プログラムです。

- 講義ポータル: [ゲームグラフィックス特論 - 床井研究室](https://tokoik.github.io/gg/)
- 講義資料: [ggnote04.pdf](https://tokoik.github.io/gg/ggnote04.pdf)

## 2. 宿題の内容

線画の立方体を平行移動するアニメーションに対し、四元数の球面線形補間（Slerp）を用いて回転アニメーションを加えてください。

- 起点で立方体を $(1, 0, 0)$ を軸に 1 ラジアン回転し、終点において $(0, 0, 1)$ を軸に 2 ラジアン回転した状態に至る回転アニメーションを作成してください。
- 軸と回転角から単位四元数を求める関数を作成してください。
- 単位四元数を球面線形補間する関数を作成してください。
- 単位四元数から回転変換行列を求める関数を作成してください。

## 3. 対応環境

- **Windows**: Visual Studio 2019 / 2022 / 2026 (CMake 経由で GLFW 3.4 を自動ダウンロード)
- **macOS**: Xcode (GLFW 3.4 を自動ダウンロード、OpenGL Framework を使用)
- **Ubuntu Linux**: GCC / Make (システム標準の libglfw3-dev, libgl1-mesa-dev を使用)

## 4. ビルド手順

### Windows (Visual Studio)

```pwsh
cmake -B build -S .
cmake --build build --config Release
```

### macOS (Xcode)

```bash
cmake -B build -G Xcode
cmake --build build --config Release
```

### Ubuntu Linux (Makefile)

```bash
sudo apt-get update
sudo apt-get install -y libglfw3-dev libgl1-mesa-dev
cmake -B build -S .
cmake --build build
```

## 5. 起動方法

ビルド完了後、生成された実行ファイルを実行します。

- **Windows**: `build/Release/ggsample04.exe`
- **macOS**: `build/Release/ggsample04.app`
- **Linux**: `build/ggsample04`

## 6. 操作方法

- **マウス左ドラッグ**: シーンの視点回転
- **マウス右ドラッグ**: 視点の平行移動
- **マウスホイール**: ズームイン / ズームアウト
- **[q] / [Q] / [ESC]**: プログラムの終了
