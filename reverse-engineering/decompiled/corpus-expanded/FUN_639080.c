/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x639080; label: FUN_00639080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00639080(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  
  iVar2 = DAT_02913998;
  fVar1 = *(float *)(param_2 + 0x54);
  _DAT_029134c4 = fVar1;
  if (DAT_02913998 != 0) {
    *(float *)(DAT_02913998 + 0x5c) = fVar1 - *(float *)(DAT_02913998 + 0x58);
    if (fVar1 < _DAT_029134c8) {
      _DAT_029134c8 = fVar1;
    }
    FUN_0061d810(iVar2,_DAT_029134c8,0,0);
  }
  return;
}

