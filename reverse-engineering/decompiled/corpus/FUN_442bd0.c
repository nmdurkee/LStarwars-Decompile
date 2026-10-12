/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442bd0; label: FUN_00442bd0
 */

float10 FUN_00442bd0(undefined4 param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  if (*(int *)(param_3 + 0xd0) != 0) {
    uVar3 = FUN_005be2d0(*(float *)(*(int *)(param_3 + 0xd0) + 0x80) - 5.5,
                         *(float *)(*(int *)(param_3 + 0xd0) + 0x88) - 3.65);
    piVar6 = &DAT_0093d7f0;
    do {
      iVar5 = *piVar6;
      if (((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 1) != 0)) &&
         ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) {
        fVar1 = *(float *)(iVar5 + 0x80) - 5.5;
        fVar2 = *(float *)(iVar5 + 0x88) - 3.65;
        if (fVar1 * fVar1 + fVar2 * fVar2 < 25.0) {
          uVar4 = FUN_005be2d0(fVar1,fVar2);
          iVar5 = FUN_005be5b0(uVar4,uVar3);
          if (iVar5 < 0xe38) {
            return (float10)1;
          }
        }
      }
      piVar6 = piVar6 + 1;
    } while ((int)piVar6 < 0x93d7f8);
  }
  return (float10)0;
}

