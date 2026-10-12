/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a3b60; label: FUN_004a3b60
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

