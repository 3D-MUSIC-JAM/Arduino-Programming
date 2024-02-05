#include <PinConstantDefinition.h>
#include <NotePitches.h>
#include <Arduino.h>

int lastSelectedSong = 0;

void playYuuYakeKoyake44(unsigned int bpm){
    unsigned int durationQuarterNote = 60000 / bpm;   // 音の長さを指定
    unsigned int durationDoubleQuarterNote = durationQuarterNote * 2;
    unsigned int durationHalfQuarterNote = durationQuarterNote / 2;   // 音の長さを指定
    unsigned int durationWholeBar = durationQuarterNote * 4;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationDoubleQuarterNote) ;  //ゆう
    delay(durationDoubleQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //や
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //け
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //こ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //や
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //け
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_CS5,durationQuarterNote) ;  //で
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //ひ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //が
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //く
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_CS5,durationQuarterNote) ;  //れ
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_B4,durationWholeBar) ;  //て
    delay(durationWholeBar) ;

    tone(pinDigitalPiezoSpk,NOTE_CS5,durationDoubleQuarterNote) ;  //や
    delay(durationDoubleQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_CS5,durationQuarterNote) ;  //ま
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //の
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //お
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //て
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //ら
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //の
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //か
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //ね
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //が
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //な
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_A5,durationWholeBar) ;  //る
    delay(durationWholeBar) ;

    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote+durationHalfQuarterNote) ;  //お
    delay(durationQuarterNote+durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B5,durationHalfQuarterNote) ;  //ー
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //て
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //て
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //つ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //な
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //い
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //で
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //み
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //な
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //か
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //え
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_CS5,durationWholeBar) ;  //ろ
    delay(durationWholeBar) ;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //か
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_CS5,durationQuarterNote) ;  //ら
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //す
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //と
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //い
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //っ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //しょ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //に
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_CS5,durationQuarterNote) ;  //か
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //え
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //り
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //ま
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_A5,durationWholeBar) ;  //しょ
    delay(durationWholeBar) ;
}


void playUmi34(unsigned int bpm){
    unsigned int durationQuarterNote = 60000 / bpm;   // 音の長さを指定
    unsigned int durationHalfQuarterNote = durationQuarterNote / 2;   // 音の長さを指定
    unsigned int durationWholeBar = durationQuarterNote * 3;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //う
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //み
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationQuarterNote) ;  //は
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E4,durationHalfQuarterNote) ;  //ひ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //ろ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationQuarterNote) ;  //い
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E4,durationQuarterNote) ;  //な
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D4,durationHalfQuarterNote) ;  //お
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D4,durationHalfQuarterNote) ;  //お
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationQuarterNote) ;  //き
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationQuarterNote) ;  //い
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote*3) ;  //な
    delay(durationQuarterNote*3) ;

    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //つ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //き
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //が
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationHalfQuarterNote) ;  //の
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B4,durationHalfQuarterNote) ;  //ぼ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //る
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationQuarterNote) ;  //し
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E4,durationHalfQuarterNote) ;  //ひ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E4,durationHalfQuarterNote) ;  //が
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D4,durationQuarterNote) ;  //し
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //ず
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationWholeBar) ;  //む
    delay(durationWholeBar) ;
}

void playNatsuNoOmoide44(unsigned int bpm){
    unsigned int durationQuarterNote = 60000 / bpm;   // 音の長さを指定
    unsigned int durationHalfQuarterNote = durationQuarterNote / 2;   // 音の長さを指定
    unsigned int durationWholeBar = durationQuarterNote * 2;
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //な
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //つ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //が
    delay(durationHalfQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_C5,durationQuarterNote) ;  //く
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //れ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //ば
    delay(durationHalfQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //お
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //も
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //い
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //だ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationWholeBar) ;  //す
    delay(durationWholeBar) ;

    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //は
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //る
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //か
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //な
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationHalfQuarterNote) ;  //お
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote+durationQuarterNote) ;  //ぜ
    delay(durationHalfQuarterNote+durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //とお
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //い
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //そ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_F4,durationWholeBar) ;  //ら
    delay(durationWholeBar) ;

    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //き
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //り
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //の
    delay(durationHalfQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_C5,durationQuarterNote) ;  //な
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //か
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //に
    delay(durationHalfQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //う
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //か
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //び
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //く
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationWholeBar) ;  //る
    delay(durationWholeBar) ;

    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //や
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //さ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //し
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //い
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationHalfQuarterNote) ;  //か
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote+durationQuarterNote) ;  //げ
    delay(durationHalfQuarterNote+durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_A4,durationQuarterNote) ;  //のの
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //こ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //み
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_F4,durationWholeBar) ;  //ち
    delay(durationWholeBar) ;




    tone(pinDigitalPiezoSpk,NOTE_D5,durationHalfQuarterNote) ;  //み
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationHalfQuarterNote) ;  //ず
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationHalfQuarterNote) ;  //ば
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationHalfQuarterNote) ;  //しょ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_F5,durationQuarterNote) ;  //う
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationHalfQuarterNote) ;  //の
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationHalfQuarterNote) ;  //は
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationHalfQuarterNote) ;  //な
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationHalfQuarterNote) ;  //が
    delay(durationHalfQuarterNote) ;
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationHalfQuarterNote) ;  //さい
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationHalfQuarterNote) ;  //てい
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //る
    delay(durationHalfQuarterNote) ;
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_F4,durationHalfQuarterNote) ;  //ゆ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //め
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //み
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //て
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationQuarterNote) ;  //さいて
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //い
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //る
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationQuarterNote) ;  //み
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //ず
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //の
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //ほ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //と
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationQuarterNote) ;  //り
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //しゃ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //く
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //な
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //げ
    delay(durationHalfQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_C5,durationQuarterNote) ;  //い
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationHalfQuarterNote) ;  //ろ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //に
    delay(durationHalfQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //た
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //そ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //が
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //れ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_AS4,durationWholeBar) ;  //る
    delay(durationWholeBar) ;

    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //は
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //る
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A4,durationHalfQuarterNote) ;  //か
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationHalfQuarterNote) ;  //な
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationHalfQuarterNote) ;  //お
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationHalfQuarterNote+durationQuarterNote) ;  //ぜ
    delay(durationHalfQuarterNote+durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_D4,durationQuarterNote) ;  //とお
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E4,durationHalfQuarterNote) ;  //い
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G4,durationHalfQuarterNote) ;  //そ
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_F4,durationWholeBar) ;  //ら
    delay(durationWholeBar) ;
}

void playAlpsIchimannjaku24(unsigned int bpm){
    unsigned int durationQuarterNote = 60000 / bpm;   //
    unsigned int durationHalfQuarterNote = durationQuarterNote / 2;   //
    unsigned int durationWholeBar = durationQuarterNote * 2;

    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //あ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //る
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //ぷ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B5,durationQuarterNote) ;  //す
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G5,durationHalfQuarterNote) ;  //い
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationHalfQuarterNote) ;  //ち
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B5,durationQuarterNote) ;  //まん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //じゃ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //く
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //こ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //や
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //り
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B5,durationQuarterNote) ;  //の
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G5,durationWholeBar) ;  //う
    delay(durationWholeBar) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //え
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //で
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //あ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //る
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //ぺ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B5,durationQuarterNote) ;  //ん
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_C6,durationQuarterNote) ;  //お
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_B5,durationQuarterNote) ;  //ど
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //り
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //を
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //さ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //あ
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //お
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //ど
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //り
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //ま
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //しょ
    delay(durationQuarterNote) ;
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote+durationHalfQuarterNote) ;  //らん
    delay(durationQuarterNote+durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationHalfQuarterNote) ;  //ら
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote+durationHalfQuarterNote) ;  //らん
    delay(durationQuarterNote+durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationHalfQuarterNote) ;  //ら
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_B4,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_C5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote+durationHalfQuarterNote) ;  //らん
    delay(durationQuarterNote+durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationHalfQuarterNote) ;  //ら
    delay(durationHalfQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_E5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_D5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_G5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_FS5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;
    tone(pinDigitalPiezoSpk,NOTE_A5,durationQuarterNote) ;  //らん
    delay(durationQuarterNote) ;

    tone(pinDigitalPiezoSpk,NOTE_G5,durationWholeBar) ;  //らん
    delay(durationWholeBar) ;
    delay(durationWholeBar) ;

}


int songSelector(){
    return((random(1023)+127)/256);
    //return((analogRead(pinAnalogVolDiv)-200)/256);
}

void setup() {
    analogReference(DEFAULT);
}

void loop() {
    int selectedSong = songSelector();
    if (lastSelectedSong != selectedSong){
        if (selectedSong == 0){
            playUmi34(90);
            delay(2000);
        }
        if (selectedSong == 1){
            playNatsuNoOmoide44(65);
            delay(2000);
        }
        if (selectedSong == 2){
            playAlpsIchimannjaku24(160);
            delay(2000);
        }
        if (selectedSong == 3){
            playYuuYakeKoyake44(85);
            delay(2000);
        }
        lastSelectedSong = selectedSong;
    }
}