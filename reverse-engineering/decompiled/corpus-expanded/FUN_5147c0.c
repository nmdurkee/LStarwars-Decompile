/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5147c0; label: FUN_005147c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005147c0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  if (param_2 == 0) {
    return (float10)0;
  }
  if (param_1 != 0) {
    iVar1 = FUN_004f8a70(param_2,"param");
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 4) != 0) {
        iVar1 = 0x18;
        iVar4 = 0;
        do {
          iVar3 = *(int *)(iVar1 + *(int *)(param_1 + 4));
          if (iVar3 != 0) {
            iVar3 = FUN_004f8b10(iVar3,param_2);
            if (iVar3 == 0) {
              return (float10)*(float *)(param_1 + 0x14 + iVar4 * 4);
            }
          }
          iVar1 = iVar1 + 8;
          iVar4 = iVar4 + 1;
        } while (iVar1 < 0x38);
      }
    }
    else {
      uVar2 = FUN_004f29a0(iVar1);
      if (uVar2 < 4) {
        return (float10)*(float *)(param_1 + 0x14 + uVar2 * 4);
      }
    }
  }
  fVar5 = (float10)FUN_004f28e0(param_2);
  return fVar5;
}

