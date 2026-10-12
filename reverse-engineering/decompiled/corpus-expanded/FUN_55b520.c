/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b520; label: FUN_0055b520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0055b520(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((((DAT_0093b27c != 0) && (piVar2 = (int *)(DAT_0093b27c + param_2 * 0x10), *piVar2 != 0)) ||
      (piVar2 = (int *)(param_2 * 0x10 + *(int *)(param_1 + 0x2980)), *piVar2 != 0)) &&
     ((piVar2 = piVar2 + 1, piVar2 == (int *)0x0 || (iVar1 = FUN_005cfac0(piVar2), iVar1 != 0)))) {
    return piVar2;
  }
  return (int *)0x0;
}

