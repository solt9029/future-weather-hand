## 手をかざすと未来の天気が分かるシステム
窓から手をかざして雨を確かめる体験をもとに、手をかざすと未来の天気が分かるシステムを作りました。翌日が雨だと水が垂れてきます☂️

<img width="739" alt="Screen Shot 2022-01-20 at 22 56 43" src="https://user-images.githubusercontent.com/21151010/150352359-dc4a3cf9-82cd-434a-bf2b-ccd0fdb768ad.png">

### 技術スタック
- Arduino
- Processing

### 仕組み
Processingから天気のWebAPIを叩いています。
翌日の天気が雨の場合には、シリアル通信でArduinoにデータを送ります。
Arduino側は、そのデータを受信している&距離センサで手が中にいることを感知している場合に、水中ポンプを作動させます。
