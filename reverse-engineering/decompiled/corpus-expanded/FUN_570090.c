/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x570090; label: FUN_00570090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00570090(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = **(int **)(param_1 + 0x50b8);
    if ((iVar2 != 0) && (iVar3 = 0, 0 < (*(int **)(param_1 + 0x50b8))[2])) {
      do {
        iVar1 = FUN_004f8b10(iVar2,param_2);
        if (iVar1 == 0) {
          return iVar2;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x2c;
      } while (iVar3 < *(int *)(*(int *)(param_1 + 0x50b8) + 8));
    }
  }
  return 0;
}

