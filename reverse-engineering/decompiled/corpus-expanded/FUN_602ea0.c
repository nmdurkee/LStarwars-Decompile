/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x602ea0; label: FUN_00602ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00602ea0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    do {
      piVar2 = piVar1;
      piVar1 = (int *)*piVar2;
    } while ((int *)*piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      *piVar2 = param_2;
      return;
    }
  }
  *(int *)(param_1 + 0x2c) = param_2;
  return;
}

