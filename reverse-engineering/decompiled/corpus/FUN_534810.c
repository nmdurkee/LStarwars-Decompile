/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x534810; label: FUN_00534810
 */

void FUN_00534810(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  local_28 = param_1;
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,&LAB_00528d00,"Script Params"),
     iVar1 != 0)) {
    iVar2 = FUN_004f1440(DAT_009238e4 + 0x383c0);
    if (iVar2 != 0) {
      iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x80);
      if (iVar2 == 0) {
        _sprintf(local_24,"Trigger Area NONE");
      }
      else {
        _sprintf(local_24,"Trigger Area \"%s\"",iVar2 + 8);
      }
      uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00529df0,local_24);
      FUN_00618e10(iVar1,uVar3);
    }
    iVar2 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
    if (iVar2 != 0) {
      iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x84);
      if (iVar2 == 0) {
        _sprintf(local_24,"Locator NONE");
      }
      else {
        _sprintf(local_24,"Locator \"%s\"",iVar2 + 8);
      }
      uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00529fb0,local_24);
      FUN_00618e10(iVar1,uVar3);
    }
    iVar2 = FUN_00513010(*(undefined4 *)(DAT_009238e4 + 100),*(int *)(DAT_009238e4 + 0x371b0) + 0x18
                         ,1,1,1);
    iVar4 = 0;
    puVar5 = (undefined4 *)(iVar2 + 0x18);
    do {
      if ((iVar2 == 0) || ((char *)*puVar5 == (char *)0x0)) {
        _sprintf(local_24,"Param%d",iVar4);
      }
      else {
        _sprintf(local_24,(char *)*puVar5);
      }
      uVar3 = FUN_00625150(iVar4,&DAT_00801cb4,0,FUN_00534780,0,0x42c80000,(&DAT_00921f3c)[iVar4],
                           local_24);
      FUN_00618e10(iVar1,uVar3);
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 2;
    } while (iVar4 < 4);
    DAT_009242b8 = 0;
    if (((byte)DAT_00921f4c & 0x1e) != 0) {
      uVar3 = FUN_00627bc0(1,&DAT_00801cb4,1,1,FUN_005346d0,"Reset Params");
      DAT_009242b8 = FUN_00618e10(iVar1,uVar3);
    }
    FUN_006279b0(local_28,iVar1);
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

