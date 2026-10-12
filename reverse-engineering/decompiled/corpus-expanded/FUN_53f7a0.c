/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f7a0; label: FUN_0053f7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0053f7a0(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    if (*(char *)(param_2 + 1) != -1) {
      iVar1 = *(short *)(param_2 + 2) * 0x80 +
              *(int *)(*(char *)(param_2 + 1) * 0x13c + 0x34 + *param_1);
      return (float10)(*(float *)(iVar1 + 0x78) * *(float *)(param_2 + 4) + *(float *)(iVar1 + 0x7c)
                      );
    }
  }
  return (float10)0;
}

