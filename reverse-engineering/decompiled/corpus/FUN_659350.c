/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x659350; label: FUN_00659350
 */

void FUN_00659350(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  iVar3 = DAT_02962010;
  if (DAT_02962114 != 0) {
    if (DAT_02923194 != -1) {
      FUN_005da860(local_c,DAT_02962114,DAT_02923194);
      uVar2 = FUN_005cf9c0(local_c);
      FUN_005b3800(&local_18,&DAT_0292fda8,uVar2);
      if (local_10 * local_10 + local_18 * local_18 + local_14 * local_14 == 0.0) {
        return;
      }
    }
    DAT_02923194 = -1;
    DAT_02962010 = -1;
    iVar5 = 0;
    iVar3 = FUN_005da840(DAT_02962114);
    if (0 < iVar3) {
      do {
        FUN_005da860(local_c,DAT_02962114,iVar5);
        uVar2 = FUN_005cf9c0(local_c);
        FUN_005b3800(&local_18,&DAT_0292fda8,uVar2);
        fVar1 = local_10 * local_10 + local_18 * local_18 + local_14 * local_14;
        iVar3 = iVar5;
        if ((0.0 <= param_1) && (param_1 <= fVar1)) {
          iVar3 = DAT_02923194;
          fVar1 = param_1;
        }
        param_1 = fVar1;
        DAT_02923194 = iVar3;
        iVar5 = iVar5 + 1;
        iVar3 = FUN_005da840(DAT_02962114);
      } while (iVar5 < iVar3);
    }
    iVar3 = DAT_02962010;
    if (DAT_02923194 != -1) {
      iVar3 = 0;
      piVar4 = &DAT_0292fe18;
      while (*piVar4 != DAT_02923194) {
        piVar4 = piVar4 + 0xb5;
        iVar3 = iVar3 + 1;
        if (0x293b317 < (int)piVar4) {
          return;
        }
      }
    }
  }
  DAT_02962010 = iVar3;
  return;
}

