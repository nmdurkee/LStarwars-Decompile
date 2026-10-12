/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x5293d0; label: FUN_005293d0
 */

void FUN_005293d0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,&LAB_00528d00,"Respawn Values"),
     iVar1 != 0)) {
    iVar2 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
    if (iVar2 != 0) {
      iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x88);
      if (iVar2 == 0) {
        _sprintf(local_24,"Respawn Locator NONE");
      }
      else {
        _sprintf(local_24,"Respawn Locator \"%s\"",iVar2 + 8);
      }
      uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_005292c0,local_24);
      FUN_00618e10(iVar1,uVar3);
    }
    uVar3 = FUN_00625240(1,&DAT_00801cb4,0,&LAB_00528fd0,0xffffffff,0x21,
                         (int)*(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8d),"Min Num Respawns")
    ;
    FUN_00618e10(iVar1,uVar3);
    uVar3 = FUN_00625240(1,&DAT_00801cb4,0,&LAB_00529050,0xffffffff,0x21,
                         (int)*(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8e),"Max Num Respawns")
    ;
    FUN_00618e10(iVar1,uVar3);
    uVar3 = FUN_00625150(1,&DAT_00801cb4,0,&LAB_005290d0,0,0x42700000,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x90),"Min Respawn Time"
                        );
    FUN_00618e10(iVar1,uVar3);
    uVar3 = FUN_00625150(1,&DAT_00801cb4,0,&LAB_00529150,0,0x42700000,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x94),"Max Respawn Time"
                        );
    FUN_00618e10(iVar1,uVar3);
    FUN_006279b0(param_1,iVar1);
  }
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

