/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x462c60; label: FUN_00462c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00462c60(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  
  if (param_3 == 0) {
    if (*(char *)(param_1 + 0x12) != '\0') {
      FUN_0045e430(param_2);
      uVar1 = FUN_006e6b90();
      FUN_00485fe0(param_2,0x3f800000,uVar1);
    }
  }
  else if (0 < *(int *)(param_1 + 0x14)) {
    if (0.5 <= *(float *)(param_1 + 0x18)) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x18);
    }
    uVar1 = FUN_006e6b90(fVar3);
    iVar2 = FUN_006e6b90(uVar1);
    FUN_00485fe0(param_2,1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5);
    return;
  }
  return;
}

