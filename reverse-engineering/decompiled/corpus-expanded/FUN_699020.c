/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x699020; label: FUN_00699020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00699020(FILE *param_1,long param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == (FILE *)0x0) {
    return -1;
  }
  iVar1 = _fseek(param_1,param_2,param_4);
  return iVar1;
}

