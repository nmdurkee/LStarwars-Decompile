/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x531100; label: FUN_00531100
 */

void FUN_00531100(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_14;
  iVar2 = FUN_00521a30();
  iVar6 = 0;
  if (iVar2 == 0) {
LAB_005311db:
    __security_check_cookie(local_4 ^ (uint)local_14);
    return;
  }
  do {
    iVar6 = iVar6 + 1;
    _sprintf(local_14,"NewSet%d",iVar6);
    iVar3 = FUN_004f1440(DAT_009238e4 + 0x41200);
    while( true ) {
      if (iVar3 == 0) {
        pcVar5 = local_14;
        iVar6 = (iVar2 + 8) - (int)pcVar5;
        do {
          cVar1 = *pcVar5;
          pcVar5[iVar6] = cVar1;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        *(int *)(DAT_009238e4 + 0x41208) = iVar2;
        *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = 0;
        if (*(int *)(DAT_009238e4 + 4) != 0) {
          FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
          *(undefined4 *)(DAT_009238e4 + 4) = 0;
        }
        goto LAB_005311db;
      }
      iVar4 = FUN_004f8b10(local_14,iVar3 + 8);
      if (iVar4 == 0) break;
      iVar3 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar3);
    }
  } while( true );
}

