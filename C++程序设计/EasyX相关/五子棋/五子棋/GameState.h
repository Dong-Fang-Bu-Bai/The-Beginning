#pragma once

/*
 * 游戏状态枚举类
 * 功能：
 * 1. 定义游戏运行的各个状态阶段
 * 2. 作为状态模式的枚举标识
 * 包含状态：
 * - MAIN_MENU  主菜单界面
 * - IN_GAME    游戏进行中
 * - PAUSE_MENU 暂停菜单
 */
enum class GameState {
    MAIN_MENU,
    IN_GAME,
    PAUSE_MENU
};