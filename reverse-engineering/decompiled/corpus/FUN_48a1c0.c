/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48a1c0; label: FUN_0048a1c0
 */

void FUN_0048a1c0(int param_1,int param_2)

{
  int iVar1;
  
  if (-1 < param_1) {
    iVar1 = param_1 * 0x2e28;
    _memset((void *)(iVar1 + DAT_0087b2cc),0,0x2e28);
    *(undefined4 *)(iVar1 + 0x2820 + DAT_0087b2cc) = 0;
    *(undefined4 *)(iVar1 + 0x2814 + DAT_0087b2cc) = 0x49f42400;
    if (param_2 != 0) {
      _memcpy((void *)(iVar1 + DAT_0087b2cc),(void *)(param_2 + 0x15c),0x2800);
    }
  }
  FUN_00559af0(0,param_1);
  FUN_005a0570(param_1);
  return;
}

