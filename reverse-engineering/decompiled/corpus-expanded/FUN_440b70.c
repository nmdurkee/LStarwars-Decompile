/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440b70; label: FUN_00440b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440b70(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int *piVar1;
  
  if (((param_5 != 0) ||
      ((((param_3 != 0 && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
        (*piVar1 != 0)) && (param_5 = *piVar1, param_5 != 0)))) &&
     (*(char *)(param_5 + 0x7b5) == '\x1b')) {
    return (float10)1;
  }
  return (float10)0;
}

