/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53ac10; label: FUN_0053ac10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0053ac10(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,FUN_00527360,"Options");
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(DAT_00801c9c,&DAT_00801cb4,0,0,&LAB_005272b0,"Select Editor Mode");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00538d60,"Save AI Data");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_005273c0,"Go To Player");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00527420,"Move Player");
    FUN_00618e10(iVar1,uVar2);
    if (*(int *)(DAT_009238e4 + 0x3cbe0) != 0) {
      iVar3 = FUN_00513160(*(undefined4 *)(DAT_009238e4 + 100),0);
      if (iVar3 != 0) {
        uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00530f60,"Rename Locator");
        FUN_00618e10(iVar1,uVar2);
      }
    }
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00531100,"Create Locator Set");
    FUN_00618e10(iVar1,uVar2);
    iVar3 = FUN_004f1440(DAT_009238e4 + 0x41200);
    if (iVar3 != 0) {
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00531920,"Select Locator Set");
      FUN_00618e10(iVar1,uVar2);
      if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
        uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,FUN_005311f0,"Delete Locator Set");
        FUN_00618e10(iVar1,uVar2);
        uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00531450,"Rename Locator Set");
        FUN_00618e10(iVar1,uVar2);
        uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00531700,"Add Locators To Set By Name");
        FUN_00618e10(iVar1,uVar2);
        uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,FUN_00531300,"Empty Locator Set");
        FUN_00618e10(iVar1,uVar2);
      }
    }
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x19) >> 0x1f,3,FUN_00527200,
                         "Stop Platforms");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x1b) >> 0x1f,2,FUN_005271a0,"Snap Height"
                        );
    FUN_00618e10(iVar1,uVar2);
    return iVar1;
  }
  return 0;
}

