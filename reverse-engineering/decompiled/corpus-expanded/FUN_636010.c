/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x636010; label: FUN_00636010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00636010(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  param_1[9] = 0;
  param_1[3] = 0;
  param_1[10] = 0;
  param_1[4] = 0;
  param_1[0xb] = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  *param_1 = 0;
  param_1[7] = 0;
  param_1[1] = 0;
  param_1[8] = 0;
  param_1[2] = 0;
  param_1[0x48] = 0x3f800000;
  param_1[0x30] = 0;
  param_1[0x24] = 0;
  param_1[0x21] = 0;
  param_1[0x1e] = 0;
  param_1[0x31] = 0;
  param_1[0x25] = 0;
  param_1[0x22] = 0;
  param_1[0x1f] = 0;
  param_1[0x12] = 0;
  param_1[0x32] = 0;
  param_1[0x26] = 0;
  param_1[0x23] = 0;
  param_1[0x20] = 0;
  param_1[0x2d] = DAT_00806588;
  param_1[0x2e] = DAT_0080658c;
  uVar1 = DAT_00806590;
  param_1[0x4d] = 0x3f800000;
  param_1[0x2f] = uVar1;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x2a] = param_1[0x2d];
  param_1[0x2b] = param_1[0x2e];
  param_1[0x27] = param_1[0x2d];
  param_1[0x2c] = param_1[0x2f];
  param_1[0x28] = param_1[0x2e];
  param_1[0x29] = param_1[0x2f];
  if (param_2 != 0) {
    param_1[0x17] = 0;
    param_1[0x13] = 0;
    *(undefined2 *)(param_1 + 0x1d) = 0;
    param_1[0x1c] = 0;
    param_1[0x4c] = 0;
    return;
  }
  return;
}

