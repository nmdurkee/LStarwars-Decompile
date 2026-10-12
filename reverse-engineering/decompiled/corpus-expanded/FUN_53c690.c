/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53c690; label: FUN_0053c690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0053c690(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,FUN_00527360,"Options");
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(DAT_00801c9c,&DAT_00801cb4,0,0,&LAB_005272b0,"Select Editor Mode");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00538d60,"Save AI Data");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00533d90,"Create New Route");
    FUN_00618e10(iVar1,uVar2);
    if ((*(int *)(DAT_009238e4 + 0x4868) != 0) &&
       (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) != 0)) {
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_005263f0,"Rename Current Route");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,FUN_00533ed0,"Destroy Current Route");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00526560,"Route Users");
      FUN_00618e10(iVar1,uVar2);
    }
    return iVar1;
  }
  return 0;
}

