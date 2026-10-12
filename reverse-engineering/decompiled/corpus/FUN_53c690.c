/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53c690; label: FUN_0053c690
 */

int FUN_0053c690(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,&LAB_00527360,"Options");
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(DAT_00801c9c,&DAT_00801cb4,0,0,&LAB_005272b0,"Select Editor Mode");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00538d60,"Save AI Data");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00533d90,"Create New Route");
    FUN_00618e10(iVar1,uVar2);
    if ((*(int *)(DAT_009238e4 + 0x4868) != 0) &&
       (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) != 0)) {
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_005263f0,"Rename Current Route");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,&LAB_00533ed0,"Destroy Current Route");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00526560,"Route Users");
      FUN_00618e10(iVar1,uVar2);
    }
    return iVar1;
  }
  return 0;
}

