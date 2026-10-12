/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cf00; label: FUN_0057cf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057cf00(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    iVar3 = 0;
    if (0 < param_1[1]) {
      do {
        iVar1 = *(int *)(*(int *)(*param_1 + iVar3 * 4) + 4);
        if (iVar1 != 0) {
          FUN_00507c00(iVar1);
          *(undefined4 *)(*(int *)(*param_1 + iVar3 * 4) + 4) = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[1]);
    }
    iVar3 = 0;
    if (0 < param_1[1]) {
      do {
        piVar2 = *(int **)(*param_1 + iVar3 * 4);
        if (*piVar2 != 0) {
          FUN_00505b20(*piVar2);
          **(undefined4 **)(*param_1 + iVar3 * 4) = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[1]);
    }
  }
  return;
}

