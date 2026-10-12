/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da600; label: FUN_005da600
 */

int FUN_005da600(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  param_1 = param_1 + param_2;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 4) + param_2;
    }
    *(int *)(param_1 + 4) = iVar1;
    if (*(int *)(param_1 + 8) != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_2;
      return param_1;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return param_1;
}

