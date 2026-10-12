/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62c3b0; label: FUN_0062c3b0
 */

int FUN_0062c3b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  if (iVar2 < param_1[1]) {
    iVar3 = iVar2 * 0x14;
    do {
      iVar1 = FUN_004f8b10(param_2,param_1[2] + 4 + iVar3);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x14;
    } while (iVar2 < param_1[1]);
  }
  return -1;
}

