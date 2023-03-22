//
// Created by ms0503 on 23/03/09.
//

#ifndef MAIN_ARM_HH
#define MAIN_ARM_HH

#include "LowLayer/GPIO.hh"
#include "params.hh"

/// 回収用アーム
class Arm : public LMLL::GPIO {
public:
    using LMLL::GPIO::GPIO;

    /**
     * 掴む
     */
    void close() const;
    /**
     * 離す
     */
    void open() const;
    /**
     * 射出機構へ移動する
     */
    void move() const;
    /**
     * 元に戻る
     */
    void back() const;

private:
    static constexpr const std::size_t HAND_INDEX = 0;
    static constexpr const std::size_t MOVER_LEFT_INDEX = 1;
    static constexpr const std::size_t MOVER_RIGHT_INDEX = 2;
};

#endif // MAIN_ARM_HH
