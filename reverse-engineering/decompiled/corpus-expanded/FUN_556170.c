/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x556170; label: FUN_00556170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00556170(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_005549e0();
    return iVar1 == param_2;
  }
  return false;
}

