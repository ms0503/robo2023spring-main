//
// Created by ms0503 on 23/03/08.
//

#ifndef MAIN_CONTROLLER_HH
#define MAIN_CONTROLLER_HH

#include "Motor.hh"
#include <cstdint>
#include <map>
#include <string>

/// スティックの角度(右0・反時計回り・rad)
typedef struct {
    long double left;
    long double right;
} StickTheta;

/// コントローラー入力変換クラス
class Controller {
public:
    Controller();
    ~Controller();
    /**
     * スティック入力を基にモーター信号を生成する
     * @param leftX 左スティック横方向
     * @param leftY 左スティック縦方向
     * @param rightX 右スティック横方向
     * @param rightY 右スティック縦方向
     * @return モーター信号
     */
    static MotorState stickToMotor(int8_t leftX, int8_t leftY, int8_t rightX, int8_t rightY);

private:
    /// スティックのデッドゾーン
    static const std::map<EnumMotor, int8_t> DEAD_ZONES;

    /**
     * スティック入力から角度を導出する
     * @param x スティック横方向
     * @param y スティック縦方向
     * @return 角度(rad)
     */
    static long double stickToTheta(int8_t x, int8_t y);
    /**
     * 左右スティック入力から各角度を導出する
     * @param leftX 左スティック横方向
     * @param leftY 左スティック縦方向
     * @param rightX 右スティック横方向
     * @param rightY 右スティック縦方向
     * @return 左右スティックの角度(rad)
     */
    static StickTheta sticksToTheta(int8_t leftX, int8_t leftY, int8_t rightX, int8_t rightY);
};

#endif //MAIN_CONTROLLER_HH
