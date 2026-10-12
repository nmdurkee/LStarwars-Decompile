/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53a390; label: FUN_0053a390
 */

int FUN_0053a390(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,&LAB_00527360,"Options");
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(DAT_00801c9c,&DAT_00801cb4,0,0,&LAB_005272b0,"Select Editor Mode");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00538d60,"Save AI Data");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_005273c0,"Go To Player");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00527420,"Move Player");
    FUN_00618e10(iVar1,uVar2);
    if (*(int *)(DAT_009238e4 + 0x383c8) != 0) {
      iVar3 = FUN_00513160(*(undefined4 *)(DAT_009238e4 + 100),0);
      if (iVar3 != 0) {
        uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00530960,"Rename Area");
        FUN_00618e10(iVar1,uVar2);
      }
    }
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x19) >> 0x1f,3,&LAB_00527200,
                         "Stop Platforms");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x1b) >> 0x1f,2,&LAB_005271a0,
                         "Snap Height");
    FUN_00618e10(iVar1,uVar2);
    if (*(int *)(DAT_009238e4 + 0x383c8) != 0) {
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,0,"=================");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627bc0(1,&DAT_00801cb4,*(byte *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x33) & 1,4,
                           &LAB_00521200,"Cylinder");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,0,"=================");
      FUN_00618e10(iVar1,uVar2);
    }
    return iVar1;
  }
  return 0;
}

