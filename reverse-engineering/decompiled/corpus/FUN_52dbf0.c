/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52dbf0; label: FUN_0052dbf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0052dbf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = true;
  if (0 < param_5) {
    do {
      iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"false");
      if (iVar2 == 0) {
        bVar1 = false;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_5);
    if (!bVar1) {
      _DAT_00923878 = 0;
      return 1;
    }
  }
  _DAT_00923878 = param_2;
  return 1;
}

