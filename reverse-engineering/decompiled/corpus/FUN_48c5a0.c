/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48c5a0; label: FUN_0048c5a0
 */

int FUN_0048c5a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_c [12];
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    iVar1 = FUN_005cfed0(param_1);
    if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1)) {
      do {
        if (iVar3 == 0) {
          FUN_005cfef0(param_1,local_c,1);
        }
        else {
          FUN_005cff50(local_c);
        }
        iVar2 = FUN_005d0450(local_c,param_3);
        if (iVar2 != 0) {
          return param_2 + iVar3 * 8;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  return 0;
}

