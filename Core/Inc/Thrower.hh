//
// Created by ms0503 on 23/03/09.
//

#ifndef MAIN_THROWER_HH
#define MAIN_THROWER_HH

/// 射出機構クラス
class Thrower {
public:
    Thrower();
    ~Thrower();
    /// 発射
    static void dispatch();
    /// リロード
    static void reload();
};

#endif //MAIN_THROWER_HH
