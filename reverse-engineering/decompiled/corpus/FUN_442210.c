/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x442210; label: FUN_00442210
 */

float10 FUN_00442210(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) ||
      (((param_3 != 0 && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
       (param_5 = **(int **)(param_3 + 0xd0), param_5 != 0)))) &&
     (((*(char *)(param_5 + 0x7b5) == 'F' && (*(int *)(param_5 + 0x798) != 0)) &&
      (*(char *)(*(int *)(param_5 + 0x798) + 0x1c) != '\0')))) {
    return (float10)1;
  }
  return (float10)0;
}

