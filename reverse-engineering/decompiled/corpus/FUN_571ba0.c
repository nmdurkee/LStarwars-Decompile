/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571ba0; label: FUN_00571ba0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571ba0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  if ((_DAT_00951000 <= 0.0) && (fVar4 = (float10)FUN_005bec80(param_1 + 0x80), 0.0 < (float)fVar4))
  {
    iVar2 = FUN_006e6b90();
    uVar1 = (&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
    uVar3 = FUN_00650dc0("LegoSingle");
    FUN_00681eb0(uVar3,param_1 + 0x30,uVar1);
    _DAT_00951000 = 0.1;
    return;
  }
  return;
}

