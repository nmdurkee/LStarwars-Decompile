/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab0f0; label: FUN_005ab0f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ab0f0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    if (*(short *)(param_2 + 2) != 0) {
      _memset(*(void **)(param_2 + 4),0,(int)*(short *)(param_2 + 2) << 4);
      *(undefined2 *)(param_2 + 2) = 0;
    }
    if (DAT_0095dfd0 != (code *)0x0) {
      (*DAT_0095dfd0)(param_1);
    }
  }
  return;
}

