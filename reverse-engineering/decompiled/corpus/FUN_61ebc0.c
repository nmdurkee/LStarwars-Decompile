/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61ebc0; label: FUN_0061ebc0
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

