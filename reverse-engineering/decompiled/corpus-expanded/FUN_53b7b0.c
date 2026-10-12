/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53b7b0; label: FUN_0053b7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0053b7b0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,FUN_00527360,"Options");
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = FUN_00627a80(DAT_00801c9c,&DAT_00801cb4,0,0,&LAB_005272b0,"Select Editor Mode");
  FUN_00618e10(iVar2,uVar3);
  if ((*(int *)(DAT_009238e4 + 0x4868) != 0) &&
     (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) != 0)) {
    uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00525900,"Rename Node");
    FUN_00618e10(iVar2,uVar3);
  }
  uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00533060,"Select Path Network");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00538d60,"Save AI Data");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_005273c0,"Go To Player");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00527420,"Move Player");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00532f30,"Create Path Network");
  FUN_00618e10(iVar2,uVar3);
  if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
    if (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) != 0) {
      uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_005334f0,"Share node with...");
      FUN_00618e10(iVar2,uVar3);
    }
    if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
      if ((*(byte *)(*(int *)(DAT_009238e4 + 0x4868) + 0x2c) & 1) == 0) {
        uVar3 = FUN_00627a80(0,&DAT_00801cb4,0,0,&LAB_00538aa0,"Delete Path Network");
        FUN_00618e10(iVar2,uVar3);
      }
      if ((*(int *)(DAT_009238e4 + 0x4868) != 0) &&
         ((*(byte *)(*(int *)(DAT_009238e4 + 0x4868) + 0x2c) & 1) == 0)) {
        uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00525760,"Rename Path Network");
        FUN_00618e10(iVar2,uVar3);
      }
    }
  }
  uVar3 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x18) >> 0x1f,1,FUN_005271c0,
                       "Solid Path Display");
  FUN_00618e10(iVar2,uVar3);
  iVar8 = 2;
  if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
    iVar1 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    iVar7 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24);
    if ((iVar1 != 0) && (iVar7 != 0)) {
      iVar4 = 0;
      piVar5 = (int *)(iVar1 + 0x30);
      do {
        if (*piVar5 == iVar7) {
          iVar1 = iVar1 + (iVar4 * 3 + 0xc) * 4;
          if ((iVar1 != 0) && (DAT_00923914 != 0)) {
            uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,0,"=================");
            FUN_00618e10(iVar2,uVar3);
            iVar7 = 0;
            if (0 < DAT_00923914) {
              puVar6 = &DAT_00923918;
              do {
                uVar3 = FUN_00627bc0(iVar7,&DAT_00801cb4,(*puVar6 & *(uint *)(iVar1 + 4)) != 0,iVar8
                                     ,&LAB_00525a00,puVar6 + 2);
                FUN_00618e10(iVar2,uVar3);
                iVar7 = iVar7 + 1;
                iVar8 = iVar8 + 1;
                puVar6 = puVar6 + 0x13;
              } while (iVar7 < DAT_00923914);
            }
            uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,0,"=================");
            FUN_00618e10(iVar2,uVar3);
          }
          break;
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 3;
      } while (iVar4 < 8);
    }
    iVar1 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if (iVar1 != 0) {
      uVar3 = FUN_00627bc0(0x80,&DAT_00801cb4,*(byte *)(iVar1 + 0x92) >> 7,iVar8,FUN_00525ab0,
                           "Never On A Platform");
      FUN_00618e10(iVar2,uVar3);
      iVar8 = iVar8 + 1;
    }
  }
  uVar3 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x19) >> 0x1f,iVar8,FUN_00527200,
                       "Stop Platforms");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x16) >> 0x1f,iVar8 + 1,FUN_005259e0,
                       "Draw Wallsplines");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x1e) >> 0x1f,iVar8 + 2,FUN_00527180,
                       "Draw All Paths");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x1b) >> 0x1f,iVar8 + 3,FUN_005271a0,
                       "Snap Height");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627bc0(1,&DAT_00801cb4,(DAT_00921f50 << 0x1c) >> 0x1f,iVar8 + 4,FUN_00527220,
                       "Show Creatures");
  FUN_00618e10(iVar2,uVar3);
  uVar3 = FUN_00627bc0(1,&DAT_00801cb4,DAT_029130a8,iVar8 + 5,FUN_006238e0,"Near Clip At Cursor");
  FUN_00618e10(iVar2,uVar3);
  return iVar2;
}

