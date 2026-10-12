/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443ec0; label: FUN_00443ec0
 */

float10 FUN_00443ec0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(char *)(*piVar1 + 0x283) == '\t')) {
    return (float10)1;
  }
  return (float10)0;
}

