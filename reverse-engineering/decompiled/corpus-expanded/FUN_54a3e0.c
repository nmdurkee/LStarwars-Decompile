/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x54a3e0; label: FUN_0054a3e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054a3e0(undefined *param_1,float param_2,undefined4 param_3,int param_4)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_008021b4;
  }
  if ((0.0 < param_2) && (param_1[0x22c] != -1)) {
    *(undefined4 *)(param_1 + 0x1c4) = param_3;
    *(undefined2 *)(param_1 + 0x21c) = *(undefined2 *)(param_1 + 0x21e);
    *(undefined4 *)(param_1 + 0x1bc) = 0;
    *(float *)(param_1 + 0x1c0) = param_2;
    *(undefined2 *)(param_1 + 0x220) = *(undefined2 *)(param_1 + 0x222);
    *(undefined2 *)(param_1 + 0x224) = *(undefined2 *)(param_1 + 0x226);
    param_1[0x22b] = (param_4 != 0) + '\x01';
    param_1[0x22e] = param_1[0x22d];
    *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x140);
    *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 0x144);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 0x128);
    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x148);
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 300);
    *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_1 + 0x130);
    *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x140);
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x144);
    *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0x128);
    *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x148);
    *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 300);
    param_1[0x22a] = 1;
    *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x130);
    return;
  }
  return;
}

