/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a3b60; label: FUN_004a3b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004a3b60(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  if ((((((*(uint *)(in_EAX + 0x1fc) & 1) != 0) && ((*(uint *)(in_EAX + 0x1fc) & 0x1000) != 0)) &&
       (*(char *)(in_EAX + 0x28b) == '\0')) && ((in_EAX != param_1 && (in_EAX != param_2)))) &&
     ((*(char *)(in_EAX + 0x280) == -1 && ((*(uint *)(in_EAX + 0xeec) & 0x8000000) == 0)))) {
    iVar1 = FUN_0058b7f0();
    if (((iVar1 == 0) && ((*(uint *)(*(int *)(in_EAX + 0x54) + 4) & 0x4002010) == 0x10)) &&
       (iVar1 = *(int *)(*(int *)(in_EAX + 0x54) + 0x24), (*(byte *)(iVar1 + 0x90) & 0x40) == 0)) {
      return ~(*(uint *)(iVar1 + 0x94) >> 9) & 1;
    }
  }
  return 0;
}

