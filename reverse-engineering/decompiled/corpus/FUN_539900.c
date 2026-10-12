/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x539900; label: FUN_00539900
 */

int FUN_00539900(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_00619250(200,0x46,0xf0,0x14a,DAT_02912e80,&LAB_00527360,"Options");
  iVar3 = 1;
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(DAT_00801c9c,&DAT_00801cb4,0,0,&LAB_005272b0,"Select Editor Mode");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00538d60,"Save AI Data");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_005273c0,"Go To Player");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00527420,"Move Player");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00529a00,"Select Creature Type");
    FUN_00618e10(iVar1,uVar2);
    if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
      iVar3 = FUN_00513160(*(undefined4 *)(DAT_009238e4 + 100),0);
      if (iVar3 != 0) {
        uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00529c90,"Select Script");
        FUN_00618e10(iVar1,uVar2);
      }
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00534810,"Script Params");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00625240(1,&DAT_00801cb4,0,&LAB_00529200,0,DAT_00801cdc,
                           *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5a),
                           "Assigned To Set");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_0052a160,"Rename Creature");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00528e00,"Activation Conditions");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_005293d0,"Respawn Values");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00534bc0,"Group Values");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00529730,"Vision");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627bc0(1,&DAT_00801cb4,*(uint *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x68) & 1,1,
                           &LAB_0052a2c0,"Ignore Wall Splines");
      FUN_00618e10(iVar1,uVar2);
      iVar3 = 2;
    }
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x19) >> 0x1f,iVar3,&LAB_00527200,
                         "Stop Platforms");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x1b) >> 0x1f,iVar3 + 1,&LAB_005271a0,
                         "Snap Height");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x15) >> 0x1f,iVar3 + 2,&LAB_00527240,
                         "Show Current Set");
    FUN_00618e10(iVar1,uVar2);
    return iVar1;
  }
  return 0;
}

