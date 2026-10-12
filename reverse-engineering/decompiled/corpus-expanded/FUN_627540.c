/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627540; label: FUN_00627540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00627540(undefined4 param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  undefined8 uVar3;
  
  if (param_2 != 0) {
    uVar3 = FUN_0061f870(param_2);
    if (((int)uVar3 != 0) && ((*(byte *)((int)((ulonglong)uVar3 >> 0x20) + 0x70) & 0x40) == 0)) {
      _DAT_0080f550 = 320.0;
      _DAT_0080f554 = 112.0;
      goto LAB_0062759b;
    }
  }
  fVar2 = (float10)FUN_006d5bf0();
  _DAT_02912ebc = (float)(-fVar2 * (float10)0.10000000149011612);
  fVar2 = (float10)FUN_006d5c10();
  _DAT_02912ec0 = (float)(-fVar2 * (float10)0.10000000149011612);
LAB_0062759b:
  iVar1 = FUN_006d6c20(0x38);
  if (iVar1 == 0) {
    _DAT_0080f550 = _DAT_0080f550 + _DAT_02912ebc;
    _DAT_0080f554 = _DAT_0080f554 + _DAT_02912ec0;
  }
  DAT_02912ed0 = (uint)(iVar1 != 0);
  FUN_0061f8d0();
  _DAT_02912ecc = DAT_02912ec4;
  DAT_02912ec4 = 0;
  iVar1 = FUN_006d58b0();
  DAT_02912ec4 = DAT_02912ec4 | (-(uint)(iVar1 != 1) & 0xffffffc0) + 0x40;
  iVar1 = FUN_006d58b0();
  DAT_02912ec4 = DAT_02912ec4 | (-(uint)(iVar1 != 2) & 0xfffffff0) + 0x10;
  DAT_02912ec8 = (DAT_02912ec4 ^ _DAT_02912ecc) & DAT_02912ec4;
  return;
}

