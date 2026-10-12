/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x538e50; label: FUN_00538e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00538e50(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,FUN_00527360,"Options");
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(DAT_00801cac,&DAT_00801cb4,0,0,&LAB_005272b0,"Select Editor Mode");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00538d60,"Save AI Data");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_005273c0,"Go To Player");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00527420,"Move Player");
    FUN_00618e10(iVar1,uVar2);
    if (*(int *)(DAT_009238e4 + 0x4381c) != 0) {
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00527880,"Select Antinode Type");
      FUN_00618e10(iVar1,uVar2);
    }
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x17) >> 0x1f,1,&LAB_005271e0,
                         "Solid Antinode Display");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x19) >> 0x1f,2,FUN_00527200,
                         "Stop Platforms");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x1b) >> 0x1f,3,FUN_005271a0,"Snap Height"
                        );
    FUN_00618e10(iVar1,uVar2);
    if (*(int *)(DAT_009238e4 + 0x4381c) != 0) {
      uVar2 = FUN_00627bc0(0x80,&DAT_00801cb4,
                           *(byte *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x48) >> 7,4,FUN_005276e0,
                           "Never On A Platform");
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627bc0(2,&DAT_00801cb4,
                           *(byte *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x48) >> 1 & 1,5,
                           FUN_005276e0,"Disbale direction memory");
      FUN_00618e10(iVar1,uVar2);
    }
    return iVar1;
  }
  return 0;
}

