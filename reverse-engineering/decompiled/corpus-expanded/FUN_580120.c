/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x580120; label: FUN_00580120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580120(int *param_1,int param_2)

{
  code *pcVar1;
  
  *(undefined1 *)(param_1 + 0x40) = 0;
  if (((param_2 != 0) && (*param_1 != 0)) &&
     (pcVar1 = *(code **)(*param_1 + 0x4c), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1);
  }
  return;
}

