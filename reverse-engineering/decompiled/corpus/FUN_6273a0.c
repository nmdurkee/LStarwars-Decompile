/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x6273a0; label: FUN_006273a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006273a0(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  float10 fVar3;
  undefined8 uVar4;
  
  bVar1 = false;
  if (param_2 == 0) {
LAB_006273da:
    fVar3 = (float10)FUN_006d5bf0();
    _DAT_02912ebc = (float)(-fVar3 * (float10)0.10000000149011612);
    fVar3 = (float10)FUN_006d5c10();
    _DAT_02912ec0 = (float)(-fVar3 * (float10)0.10000000149011612);
  }
  else {
    uVar4 = FUN_0061f870(param_2);
    if (((int)uVar4 == 0) || ((*(byte *)((int)((ulonglong)uVar4 >> 0x20) + 0x70) & 0x40) != 0))
    goto LAB_006273da;
    bVar1 = true;
    _DAT_0080f550 = 320.0;
    _DAT_0080f554 = 112.0;
  }
  iVar2 = FUN_006d6c20(0x38);
  if (iVar2 == 0) {
    if (DAT_02912ed0 == 1) {
      FUN_006dddf0(1);
      DAT_02912ed0 = 0;
    }
    else if (DAT_02912ed0 != 0) goto LAB_006274fa;
    if (!bVar1) {
      FUN_006dde00(&DAT_0080f550,&DAT_0080f554);
      _DAT_0080f550 = _DAT_0080f550 * 640.0;
      _DAT_0080f554 = _DAT_0080f554 * 224.0;
    }
  }
  else {
    if (DAT_02912ed0 == 0) {
      FUN_006dddf0(0);
      DAT_02912ed0 = 1;
    }
LAB_006274fa:
    FUN_006dde30(_DAT_0080f550 / 640.0,_DAT_0080f554 / 224.0);
  }
  FUN_0061f8d0();
  _DAT_02912ecc = DAT_02912ec4;
  DAT_02912ec4 = 0;
  iVar2 = FUN_006d58b0();
  DAT_02912ec4 = DAT_02912ec4 | (-(uint)(iVar2 != 1) & 0xffffffc0) + 0x40;
  iVar2 = FUN_006d58b0();
  DAT_02912ec4 = DAT_02912ec4 | (-(uint)(iVar2 != 2) & 0xfffffff0) + 0x10;
  DAT_02912ec8 = (DAT_02912ec4 ^ _DAT_02912ecc) & DAT_02912ec4;
  return;
}

