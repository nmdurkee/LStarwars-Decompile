/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x515620; label: FUN_00515620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00515620(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  float10 fVar1;
  float10 fVar2;
  float local_10;
  undefined1 local_c [12];
  
  local_10 = 3.4028235e+38;
  if (param_3 == 0) {
    return (float10)3.4028235e+38;
  }
  if (param_1 == 0) goto LAB_005156de;
  if ((param_5 == 0) && (param_5 = *(int *)(param_2 + 0xa4), param_5 == 0)) {
LAB_005156b8:
    fVar2 = (float10)local_10;
  }
  else {
    if (*(int *)(param_1 + 0x138c) != 0) {
      fVar1 = (float10)FUN_005b3c50(*(int *)(param_1 + 0x138c) + 0x5c,param_5 + 0x10,local_c);
      local_10 = (float)fVar1;
    }
    if (*(int *)(param_1 + 0x1390) == 0) goto LAB_005156b8;
    fVar1 = (float10)FUN_005b3c50(*(int *)(param_1 + 0x1390) + 0x5c,param_5 + 0x10,local_c);
    fVar2 = (float10)local_10;
    local_10 = (float)fVar1;
    if ((float10)(float)fVar1 < fVar2) goto LAB_005156b8;
  }
  if (fVar2 == (float10)3.4028234663852886e+38) {
    return fVar2;
  }
  fVar1 = (float10)FUN_005c0240((float)fVar2);
  local_10 = (float)fVar1;
LAB_005156de:
  return (float10)local_10;
}

