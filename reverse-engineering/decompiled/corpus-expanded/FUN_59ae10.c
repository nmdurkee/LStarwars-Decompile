/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59ae10; label: FUN_0059ae10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059ae10(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  if (param_2 == 0) {
    return;
  }
  iVar1 = FUN_005cfac0(param_2);
  if (iVar1 == 0) {
    return;
  }
  FUN_005d0130(param_2,&local_c,&local_18);
  uVar2 = FUN_005cfa20(param_2);
  FUN_005b30a0(&local_c,&local_c,uVar2);
  FUN_005b30a0(&local_18,&local_18,uVar2);
  fVar3 = ABS((local_18 - local_c) * 0.5);
  fVar4 = ABS((local_10 - local_4) * 0.5);
  if (0.01 <= ABS(fVar3 - fVar4)) {
    *(undefined1 *)((int)param_1 + 0x22) = 1;
    if (fVar3 <= fVar4) {
      param_1[3] = fVar4;
      goto LAB_0059af20;
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 0x22) = 0;
  }
  param_1[3] = fVar3;
LAB_0059af20:
  param_1[6] = fVar3;
  param_1[7] = fVar4;
  fVar3 = ABS((local_14 - local_8) * 0.5);
  param_1[4] = -fVar3;
  param_1[5] = fVar3;
  return;
}

