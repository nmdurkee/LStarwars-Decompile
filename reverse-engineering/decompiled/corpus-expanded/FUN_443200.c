/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x443200; label: FUN_00443200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443200(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if ((((param_5 != 0) ||
       ((*(int **)(param_3 + 0xd0) != (int *)0x0 &&
        (param_5 = **(int **)(param_3 + 0xd0), param_5 != 0)))) && (*(int *)(param_5 + 0xcd0) != 0))
     && ((*(char *)(param_5 + 0x7b5) == ';' &&
         (*(short *)(*(int *)(param_5 + 0xcd0) + 0x1064) == DAT_007f1948)))) {
    return (float10)1;
  }
  return (float10)0;
}

