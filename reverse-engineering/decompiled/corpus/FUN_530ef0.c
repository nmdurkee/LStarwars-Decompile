/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x530ef0; label: FUN_00530ef0
 */

void FUN_00530ef0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar1);
    if ((*(int *)(iVar1 + 0x2c) == param_1) &&
       (FUN_00530dd0(), iVar1 == *(int *)(DAT_009238e4 + 0x3cbe0))) {
      *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = 0;
    }
  }
  return;
}

