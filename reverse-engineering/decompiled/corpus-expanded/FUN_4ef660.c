/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef660; label: FUN_004ef660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef660(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_1 < param_2) {
    if (param_3 != 0) {
      iVar2 = (int)param_2 - (int)param_1;
      do {
        param_3 = param_3 + -1;
        *param_1 = param_1[iVar2];
        param_1 = param_1 + 1;
      } while (param_3 != 0);
      return;
    }
  }
  else {
    param_2 = param_2 + param_3;
    param_1 = param_1 + param_3;
    for (; param_3 != 0; param_3 = param_3 + -1) {
      puVar1 = param_2 + -1;
      param_2 = param_2 + -1;
      param_1 = param_1 + -1;
      *param_1 = *puVar1;
    }
  }
  return;
}

