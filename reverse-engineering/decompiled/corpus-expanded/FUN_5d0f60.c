/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0f60; label: FUN_005d0f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0f60(undefined4 param_1,int param_2,undefined4 param_3,float param_4)

{
  **(undefined4 **)(param_2 + 0x2c) = param_3;
  if (((byte)DAT_009738c4 & 4) != 0) {
    **(float **)(param_2 + 0x30) = param_4;
    return;
  }
  **(float **)(param_2 + 0x30) = param_4 * 0.5;
  return;
}

