/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x648b00; label: FUN_00648b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00648b00(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_02920970 != 0) {
    DAT_029209c4 = FUN_00619250(0x46,0x46,300,0xfa,DAT_02912e80,FUN_00648ae0,"Instance Flags");
    if (DAT_029209c4 != 0) {
      uVar1 = FUN_00627bc0(1,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) & 1,1,FUN_006476e0,
                           "Die when stopped");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(2,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 1 & 1,2,FUN_006476e0,
                           "Collide with Characters");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(4,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 2 & 1,3,FUN_006476e0,
                           "Interact only with Active Chars");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(8,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 3 & 1,4,FUN_006476e0,
                           "Damage Characters");
      FUN_00618e10(DAT_029209c4,uVar1);
      iVar2 = 5;
      if (*(short *)(DAT_02920970 + 0x90) != 9999) {
        uVar1 = FUN_00627bc0(0x10,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 4 & 1,5,
                             FUN_006476e0,"Don\'t die when off-screen");
        FUN_00618e10(DAT_029209c4,uVar1);
        iVar2 = 6;
      }
      uVar1 = FUN_00627bc0(0x40,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 6 & 1,iVar2,
                           FUN_006476e0,"Is a Collectible");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x80,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 7 & 1,iVar2 + 1,
                           FUN_006476e0,"Rotate Randomly");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x100000,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0x14 & 1,
                           iVar2 + 2,FUN_006476e0,"Ordered Rotate Randomly");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x100,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 8 & 1,iVar2 + 3,
                           FUN_006476e0,"No Bounce");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x200,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 9 & 1,iVar2 + 4,
                           FUN_006476e0,"Slot Cannot be Stolen");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x400,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 10 & 1,iVar2 + 5,
                           FUN_006476e0,"Ignore Terrain");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x800,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0xb & 1,iVar2 + 6,
                           FUN_006476e0,"Face Direction of Movement");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x1000,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0xc & 1,iVar2 + 7
                           ,FUN_006476e0,"Disable Draw");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x2000,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0xd & 1,iVar2 + 8
                           ,FUN_006476e0,"Real Time Lighting");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x4000,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0xe & 1,iVar2 + 9
                           ,FUN_006476e0,"Ignore Creature");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x8000,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0xf & 1,
                           iVar2 + 10,FUN_006476e0,"Thrown");
      FUN_00618e10(DAT_029209c4,uVar1);
      uVar1 = FUN_00627bc0(0x10000,&DAT_008109d8,*(byte *)(DAT_02920970 + 0x116) & 1,iVar2 + 0xb,
                           FUN_006476e0,"Can Damage Owner");
      FUN_00618e10(DAT_029209c4,uVar1);
    }
    FUN_006279b0(param_1,DAT_029209c4);
    *(int *)(DAT_029209c4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209c4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

