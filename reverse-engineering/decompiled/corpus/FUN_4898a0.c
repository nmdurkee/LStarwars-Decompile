/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x4898a0; label: FUN_004898a0
 */

void FUN_004898a0(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int unaff_EDI;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  if (*(int *)(unaff_EDI + 0x140) != 0) {
    DAT_0087b2c8 = 0;
    if (0 < DAT_00956294) {
      puVar4 = &DAT_0087ab50;
      iVar3 = 1;
      do {
        _sprintf(local_44,"EP_%i",iVar3);
        FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),puVar4,local_44,1);
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 1;
          _sprintf(local_44,"EP_%i_CH_%i",iVar3,iVar2);
          FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),&DAT_0087abc8 + DAT_0087b2c8 * 0xc,
                       local_44,1);
          DAT_0087b2c8 = DAT_0087b2c8 + 1;
        } while (iVar2 < 8);
        puVar4 = puVar4 + 0xc;
        bVar1 = iVar3 < DAT_00956294;
        iVar3 = iVar3 + 1;
      } while (bVar1);
    }
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),&DAT_0087abc8 + DAT_0087b2c8 * 0xc,"pod_race",1)
    ;
    DAT_0087b2c8 = DAT_0087b2c8 + 1;
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),&DAT_0087abc8 + DAT_0087b2c8 * 0xc,
                 "anakin_flight",1);
    DAT_0087b2c8 = DAT_0087b2c8 + 1;
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),&DAT_0087abc8 + DAT_0087b2c8 * 0xc,"gunship",1);
    DAT_0087b2c8 = DAT_0087b2c8 + 1;
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),&DAT_0087abc8 + DAT_0087b2c8 * 0xc,"new_hope",1)
    ;
    DAT_0087b2c8 = DAT_0087b2c8 + 1;
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),&DAT_0087abc8 + DAT_0087b2c8 * 0xc,"lego_city",1
                );
    DAT_0087b2c8 = DAT_0087b2c8 + 1;
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x140),&DAT_0087abc8 + DAT_0087b2c8 * 0xc,"new_town",1)
    ;
    DAT_0087b2c8 = DAT_0087b2c8 + 1;
  }
  DAT_0087a9d0 = 0;
  DAT_0087a9cc = 0;
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

