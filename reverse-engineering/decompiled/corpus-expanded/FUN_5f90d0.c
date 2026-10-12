/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f90d0; label: FUN_005f90d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005f90d0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_005f9030(param_1);
  iVar3 = 0;
  iVar2 = iVar1 * param_2 * param_3 >> 3;
  if (0 < param_4) {
    do {
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + ((param_2 >> ((byte)iVar3 & 0x1f)) * (param_3 >> ((byte)iVar3 & 0x1f)) * iVar1
                      >> 3);
    } while (iVar3 < param_4);
  }
  return iVar2;
}

