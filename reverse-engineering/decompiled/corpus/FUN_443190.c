/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443190; label: FUN_00443190
 */

float10 FUN_00443190(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if ((((param_5 != 0) ||
       ((*(int **)(param_3 + 0xd0) != (int *)0x0 &&
        (param_5 = **(int **)(param_3 + 0xd0), param_5 != 0)))) && (*(int *)(param_5 + 0xcd0) != 0))
     && (*(char *)(param_5 + 0x7b5) == ';')) {
    return (float10)1;
  }
  return (float10)0;
}

