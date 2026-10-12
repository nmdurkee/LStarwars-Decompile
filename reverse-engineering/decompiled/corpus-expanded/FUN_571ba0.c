/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571ba0; label: FUN_00571ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

