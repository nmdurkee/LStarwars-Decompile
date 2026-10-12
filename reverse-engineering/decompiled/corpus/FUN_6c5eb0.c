/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c5eb0; label: FUN_006c5eb0
 */

void FUN_006c5eb0(int *param_1,int param_2)

{
  int in_ECX;
  code *pcVar1;
  
  if (param_1[1] == 0) {
    (**(code **)(*param_1 + 8))(in_ECX + 0xc,4,1);
    (**(code **)(*param_1 + 0x10))(in_ECX + 0x10);
    (**(code **)(*param_1 + 8))(in_ECX + 0x14,4,1);
    (**(code **)(*param_1 + 8))(in_ECX + 0x1c,4,1);
    return;
  }
  if (((*(uint *)(in_ECX + 0x1c) & 0x80000000) == 0) || (param_2 == 0)) {
    pcVar1 = *(code **)(*param_1 + 8);
    param_2 = in_ECX + 0xc;
  }
  else {
    pcVar1 = *(code **)(*param_1 + 8);
    param_2 = param_2 + *(int *)(in_ECX + 0xc) * 4;
  }
  (*pcVar1)(param_2,4,1);
  (**(code **)(*param_1 + 0x10))(in_ECX + 0x10);
  (**(code **)(*param_1 + 8))(in_ECX + 0x14,4,1);
  (**(code **)(*param_1 + 8))(in_ECX + 0x18,4,1);
  (**(code **)(*param_1 + 8))(in_ECX + 0x1c,4,1);
  return;
}

