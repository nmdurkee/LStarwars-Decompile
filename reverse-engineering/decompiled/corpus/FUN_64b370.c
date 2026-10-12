/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64b370; label: FUN_0064b370
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0064b370(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (param_1 == -1) {
    return -1;
  }
  if ((&DAT_02913ae8)[param_1 * 0xbc] == -1) {
    return -1;
  }
  iVar2 = FUN_0064b1c0(param_1,param_2);
  fVar1 = _DAT_02920a90;
  if (iVar2 != -1) {
    (&DAT_0291f7dc)[iVar2 * 0x1b] = param_3;
    (&DAT_0291f7cc)[iVar2 * 0x1b] = fVar1;
    fVar3 = (float10)FUN_005b9d90(&DAT_008102e8);
    fVar4 = (float10)_DAT_02920a90;
    (&DAT_0291f7d0)[iVar2 * 0x1b] =
         (float)(fVar3 * (float10)(float)(&DAT_02913b48)[param_1 * 0x5e] +
                fVar4 + (float10)(float)(&DAT_02913b44)[param_1 * 0x5e]);
    (&DAT_0291f7c8)[iVar2 * 0x1b] =
         (float)(fVar4 - (float10)1 / (float10)(float)(&DAT_02913b24)[param_1 * 0x5e]);
  }
  return iVar2;
}

