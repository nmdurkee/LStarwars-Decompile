/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ebc0; label: FUN_0061ebc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061ebc0(undefined4 *param_1)

{
  int *piVar1;
  
  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if (((piVar1[2] == 0x13) && (piVar1[0x13] != 0)) && ((*(byte *)(piVar1 + 0x15) & 1) == 0)) {
      *(int *)piVar1[0x14] = *piVar1;
      if (*piVar1 != 0) {
        *(int *)(*piVar1 + 4) = piVar1[0x14];
      }
      *piVar1 = piVar1[0x13];
      *(int **)(piVar1[0x13] + 4) = piVar1;
      piVar1[0x15] = piVar1[0x15] | 1;
    }
  }
  return;
}

