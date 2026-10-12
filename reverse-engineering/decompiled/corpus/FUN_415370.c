/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x415370; label: FUN_00415370
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415370(int param_1)

{
  short sVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x50) == 0) {
    return;
  }
  if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) != '\0') ||
     (iVar5 = 0x76, (*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0)) {
    iVar5 = 0x19;
  }
  sVar1 = *(short *)(param_1 + 0x42);
  iVar3 = 1;
  if (sVar1 == 1) {
LAB_004153c6:
    if (*(short *)(param_1 + 0x40) == iVar5) goto LAB_004153e2;
LAB_004153ce:
    if ((sVar1 != iVar5) || (iVar3 = iVar5, *(short *)(param_1 + 0x40) != 1)) goto LAB_004153f3;
  }
  else {
    if (sVar1 == iVar5) {
      if (sVar1 == 1) goto LAB_004153c6;
      goto LAB_004153ce;
    }
    iVar3 = FUN_00415050(param_1);
  }
  if (iVar3 != -1) {
LAB_004153e2:
    FUN_004150d0(param_1,1,iVar3);
    return;
  }
LAB_004153f3:
  if (sVar1 == 1) {
    *(float *)(param_1 + 0x2b8) = *(float *)(param_1 + 0x2b8) + _DAT_00925018;
    fVar2 = *(float *)(param_1 + 700) + _DAT_00925018;
    *(float *)(param_1 + 700) = fVar2;
    if (*(float *)(param_1 + 0x2c0) < fVar2 != (*(float *)(param_1 + 0x2c0) == fVar2)) {
      if (*(short *)(param_1 + 0x2c4) == 1) {
        FUN_004151c0(param_1);
        *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x2c4);
        return;
      }
      FUN_004150d0(param_1,1,1);
    }
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x2c4);
    return;
  }
  if (sVar1 != iVar5) {
    uVar4 = FUN_00415050(param_1);
    FUN_004150d0(param_1,1,uVar4);
    return;
  }
  *(float *)(param_1 + 0x2b8) = *(float *)(param_1 + 0x2b8) + _DAT_00925018;
  fVar2 = *(float *)(param_1 + 700) + _DAT_00925018;
  *(float *)(param_1 + 700) = fVar2;
  if (*(float *)(param_1 + 0x2c0) < fVar2 != (*(float *)(param_1 + 0x2c0) == fVar2)) {
    if (*(short *)(param_1 + 0x2c4) == iVar5) {
      FUN_004151c0(param_1);
      *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x2c4);
      return;
    }
    FUN_004150d0(param_1,1,iVar5);
  }
  *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x2c4);
  return;
}

