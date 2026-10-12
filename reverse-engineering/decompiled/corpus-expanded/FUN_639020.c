/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x639020; label: FUN_00639020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00639020(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = DAT_0291399c;
  fVar1 = *(float *)(param_2 + 0x54);
  _DAT_029134c8 = fVar1;
  if (DAT_0291399c != 0) {
    *(float *)(DAT_0291399c + 0x58) = fVar1 + fVar1;
    fVar3 = fVar1 + 1.0;
    if (fVar1 + 1.0 < _DAT_029134c4) {
      fVar3 = _DAT_029134c4;
    }
    _DAT_029134c4 = fVar3;
    FUN_0061d810(iVar2,_DAT_029134c4,0,0);
  }
  return;
}

