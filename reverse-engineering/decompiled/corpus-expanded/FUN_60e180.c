/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60e180; label: FUN_0060e180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0060e180(int param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    do {
      if ((piVar1[2] == *(int *)(param_1 + 8)) && ((char)piVar1[3] == *(char *)(param_1 + 0xc))) {
        return piVar1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return (int *)0x0;
}

