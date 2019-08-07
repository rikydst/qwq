#pragma once

#include "quantum.h"

void send_unicode_hex_string(const char* str);

/* use X(n) to call the  */
#ifdef UNICODEMAP_ENABLE
enum unicode_name {
BANG,     // ‽
IRONY,    // ⸮
DEGREE,   // °
THINK,    // 🤔 
GRIN,     // �
MONOCL,   // 🧐
DRUG0,    // 🤪
DRUG1,    // 🥴 
CLOWN,    // 🤡
MNDBLWN,  // 🤯
MONEY,    // 🤑
SHTUP,    // 🤐
PARTY,    // 🥳
SMRK,     // 😏
WEARY,    // 😩
UNAMU,    // 😒
SPY,      // 🕵
DAFUQ,    // 👺
FIST0,    // 🤛
FIST1,    // 🤜
FIST2,    // ✊
FIST3,    // 👊
WIFIHAND, // 👌
EFFU,     // 🖕
SPOCK,    // 🖖
INUP,     // 👆
THDN,     // 👎
THUP,     // 👍
TUMBLER,  // 🥃
DRAGON0,  // 🐉
DRAGON1,  // 🐅
TIGER0,   // 🐅
TIGER1,   // 🐯
COOL,     // 🆒
UCHART,   // 📈
DCHART,   // 📉
BCHART,   // 📊
NOPRCY,   // 🕲
PRCY,     // 🕱
BBB,      // 🅱
POO,      // 💩
HUNDR,    // 💯
EGGPL,    // 🍆
WATER,    // 💦
LIT,      // 🔥
SNEK,     // 🐍
PENGUIN,  // 🐧
BOAR,     // 🐗
MONKEY,   // 🐒
CHICK,    // 🐥
DASH,     // 💨
DIZZY,    // 💫
KEEB,     // 🖮
HOLE,     // 🕳
SAUCER    // 🛸
};
#endif
