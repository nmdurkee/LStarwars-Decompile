/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da860; label: FUN_005da860
 */

void FUN_005da860(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 != 0) && (param_1 != (int *)0x0)) {
    if ((*(int *)(param_2 + 0x110) != 0) && (param_3 < *(int *)(*(int *)(param_2 + 0x110) + 0x6c)))
    {
      param_1[1] = 0;
      *param_1 = param_2;
      param_1[2] = param_3 * 0xd0 + *(int *)(*(int *)(param_2 + 0x110) + 0x70);
      return;
    }
    if (param_3 < *(int *)(param_2 + 0x24)) {
      *param_1 = param_2;
      iVar1 = *(int *)(param_2 + 0x28);
      param_1[2] = 0;
      param_1[1] = param_3 * 0x4c + iVar1;
      return;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

