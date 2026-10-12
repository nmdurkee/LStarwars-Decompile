/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53f7a0; label: FUN_0053f7a0
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

