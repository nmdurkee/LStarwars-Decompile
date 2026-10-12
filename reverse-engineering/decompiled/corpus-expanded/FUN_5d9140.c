/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9140; label: FUN_005d9140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d9140(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint extraout_ECX;
  undefined8 uVar4;
  
  uVar4 = CONCAT44(DAT_00966388,DAT_0096d9c0);
  uVar3 = (DAT_0096d9c0 + 0xf & 0xfffffff0) + 0xa0;
  if (DAT_00966388 <= uVar3) {
    uVar4 = FUN_005c12e0();
    uVar3 = extraout_ECX;
  }
  iVar2 = (int)uVar4;
  *(uint *)(iVar2 + 0x80) = uVar3;
  DAT_0096d9c0 = uVar3 + in_EAX * 0x10;
  if ((uint)((ulonglong)uVar4 >> 0x20) <= DAT_0096d9c0) {
    iVar2 = FUN_005c12e0();
  }
  piVar1 = DAT_00963f98;
  *(short *)(iVar2 + 0x9c) = (short)in_EAX;
  *(int *)(DAT_00963e00 + *piVar1 * 4) = iVar2;
  *piVar1 = *piVar1 + 1;
  if (0xf < *piVar1) {
    FUN_005c12e0();
    return;
  }
  return;
}

