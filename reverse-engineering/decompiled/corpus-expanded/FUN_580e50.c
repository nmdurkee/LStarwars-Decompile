/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x580e50; label: FUN_00580e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580e50(undefined4 param_1,int param_2,int param_3)

{
  int *in_ECX;
  int iVar1;
  int iVar2;
  
  if (in_ECX[1] != 0) {
    iVar1 = param_2 * param_3;
    FUN_004ef660(in_ECX[3] + in_ECX[1],param_1,iVar1);
    if (((*in_ECX != 0) && (1 < param_2)) && (iVar2 = in_ECX[3] + in_ECX[1], 0 < param_3)) {
      do {
        if (param_2 == 2) {
          FUN_00621180(iVar2);
        }
        else if (param_2 == 4) {
          FUN_00621190(iVar2);
        }
        iVar2 = iVar2 + param_2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    in_ECX[3] = in_ECX[3] + iVar1;
  }
  return;
}

