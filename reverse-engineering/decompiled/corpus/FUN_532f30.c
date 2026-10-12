/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x532f30; label: FUN_00532f30
 */

void FUN_00532f30(void)

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
  iVar2 = FUN_004f1440(DAT_009238e4 + 0x486c);
  if (iVar2 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x486c,iVar2);
    FUN_004f1310(DAT_009238e4 + 0x4874,iVar2);
  }
  iVar6 = 0;
  if (iVar2 == 0) {
LAB_00533040:
    __security_check_cookie(local_4 ^ (uint)local_14);
    return;
  }
  do {
    iVar6 = iVar6 + 1;
    _sprintf(local_14,"NewPath%d",iVar6);
    iVar3 = FUN_004f1440(DAT_009238e4 + 0x4874);
    while( true ) {
      if (iVar3 == 0) {
        pcVar5 = local_14;
        iVar6 = (iVar2 + 8) - (int)pcVar5;
        do {
          cVar1 = *pcVar5;
          pcVar5[iVar6] = cVar1;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        *(uint *)(iVar2 + 0x2c) = *(uint *)(iVar2 + 0x2c) & 0xfffffffe;
        *(int *)(DAT_009238e4 + 0x4868) = iVar2;
        if (*(int *)(DAT_009238e4 + 4) != 0) {
          FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
          *(undefined4 *)(DAT_009238e4 + 4) = 0;
        }
        goto LAB_00533040;
      }
      iVar4 = FUN_004f8b10(local_14,iVar3 + 8);
      if (iVar4 == 0) break;
      iVar3 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar3);
    }
  } while( true );
}

