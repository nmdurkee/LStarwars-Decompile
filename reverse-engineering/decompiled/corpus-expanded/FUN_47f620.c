/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47f620; label: FUN_0047f620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0047f620(int param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x108c);
  if (((piVar1 != (int *)0x0) && (*(int *)(param_1 + 0x424) == *piVar1)) &&
     (((char)piVar1[2] == -1 || (*(char *)(param_1 + 0x428) == (char)piVar1[2])))) {
    return param_2 == *(char *)((int)piVar1 + 9);
  }
  return false;
}

