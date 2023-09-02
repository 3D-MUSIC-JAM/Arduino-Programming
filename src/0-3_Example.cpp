#include <Arduino.h> //←これは「おまじない」だと思って、とりあえず書きましょう。

//【コメント】
// このように"//"が出現した場合、同じ行内の以後の文字はコメントとして扱われ、無視されます。

//【複数行コメント】
/*
もし連続する複数行にわたってコメントを書きたい場合は、
このようにすることもできます。
※この３行の前後の行に注目してください。
*/

/* このように変数を宣言します。
vNumberという変数は整数が扱える変数（値を持つ文字列）で、この場合はint型として宣言されています。
この場合は数字の0が代入されます。
intの代わりにconst intと書くと定数になり、書き換えることができなくなります。
*/
int vNumber = 0;

int funcionExample(int number); //この行については後述（※注）参照

/*
以下のように
  void setup() {
ではじまって
  }
で終わるカタマリのことを「関数」といいます。
"{"と"}"で囲まれるのが関数の中身です。
複数行にわたる場合は、処理ごとに行末に
Arduinoの場合、
  void setup();
は起動時に一度だけ実行され、
  void loop();
はそのあと繰り返し実行されます。
*/




void setup() {
  //ここからが関数の中身
  Serial.begin(115200); //シリアルコンソールを開始します。速度(baud rate)は115200bpsです。
  //ここまでが関数の中身
}

void loop() {
  //ここからが関数の中身（●）
  int varNumber; //このように変数を宣言だけすることもできます。
  //関数内で変数や定数を宣言した場合、それらは同じ関数内からのみ呼び出すことができます。
  //つまりvarNumberは、void loop()の中でしか呼び出したり書き換えたりすることができません。
  varNumber = funcionExample(vNumber);
  //functionExample(int)が「与えられた整数を返すだけ」の関数なので、vNumberとして渡した整数が返され、それがvarNumberに代入されます。
  
  //以下2行はTeleplotでグラフにするための書式です。
  Serial.print(">varNumber:"); //Serial.print()は改行しません。
  Serial.println(varNumber); //Serial.println()は改行します。

  Serial.println(varNumber); //Teleplot上での可視化用
  vNumber = vNumber + 1; //ここまでの処理が終わったら、vNumberの値に1を足します。
  delay(1000); // 1000ミリ秒（1秒）待ちます。
  //ここまでが関数の中身（■）
  //●から■まで繰り返されます。
}

/*
以下のように自分で関数を定義することもできます。
※注：ただし、今回のように
  int funcionExample(int number){}
をvoid setup()やvoid loop()の後に定義する場合は、
  int funcionExample(int number);
と、void setup()やvoid loop()の前、かつ
  #include <Arduino.h>
の後にも書きます。
*/

int funcionExample(int number){
  return(number * 10);
}

/*
関数を定義する行の先頭に書かれているvoidやintは、関数の型といいます。void型以外の関数を定義する場合は、関数の中身に必ずreturn()を含める必要があります。
関数や変数の型については、説明および添付資料で扱います。
*/

//最後に：コメントは書きすぎないように気を付けましょう。
//このソースファイルのように、プログラムが読みづらくなります。