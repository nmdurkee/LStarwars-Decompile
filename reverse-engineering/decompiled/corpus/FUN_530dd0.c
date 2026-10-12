/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x530dd0; label: FUN_00530dd0
 */

void FUN_00530dd0(void)

{
  void *in_EAX;
  int iVar1;
  
  if (in_EAX != (void *)0x0) {
    for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x41200); iVar1 != 0;
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar1)) {
      FUN_00521ad0();
    }
    FUN_004f1410(DAT_009238e4 + 0x3cbd8);
    _memset(in_EAX,0,0x48);
    FUN_004f1310(DAT_009238e4 + 0x3cbd0);
  }
  return;
}

