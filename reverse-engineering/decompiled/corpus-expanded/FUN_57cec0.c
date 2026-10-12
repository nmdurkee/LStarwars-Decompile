/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cec0; label: FUN_0057cec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057cec0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (int *)0x0) && (iVar2 = 0, 0 < param_1[1])) {
    do {
      iVar1 = *(int *)(*(int *)(*param_1 + iVar2 * 4) + 4);
      if (iVar1 != 0) {
        FUN_00505e10(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[1]);
  }
  return;
}

