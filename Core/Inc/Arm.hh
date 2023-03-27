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
    using GPIO::GPIO;

    explicit Arm(const std::vector<Pin> &pin);

    /**
     * 掴む
     */
    inline void close() {
        high(HAND_INDEX);
    }
    /**
     * 離す
     */
    inline void open() {
        low(HAND_INDEX);
    }
    /**
     * 射出機構へ移動する
     */
    inline void move() {
        high(MOVER_LEFT_INDEX);
        high(MOVER_RIGHT_INDEX);
    }
    /**
     * 元に戻る
     */
    inline void back() {
        low(MOVER_LEFT_INDEX);
        low(MOVER_RIGHT_INDEX);
    }

private:
    static constexpr const std::size_t HAND_INDEX = 0;
    static constexpr const std::size_t MOVER_LEFT_INDEX = 1;
    static constexpr const std::size_t MOVER_RIGHT_INDEX = 2;
};

#endif // MAIN_ARM_HH
