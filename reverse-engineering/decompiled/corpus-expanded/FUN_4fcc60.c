/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fcc60; label: FUN_004fcc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004fcebe) */

uint FUN_004fcc60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined *local_c;
  uint local_8;
  uint local_4;
  
LAB_004fcc70:
  while (0xfff < param_1) {
    iVar2 = FUN_006dee90(param_1 + -0x1000,0,0,0);
    iVar2 = iVar2 >> 0x1f;
LAB_004fcd2d:
    if ((0 < iVar2) || (-1 < iVar2)) goto LAB_004fcd4f;
    FUN_004ef7b0();
  }
  if (0x3ff < param_1) {
    if (param_1 < 0x800) {
      iVar2 = param_1 * 5 + -0x1400;
      *(undefined4 *)(&DAT_02983748 + iVar2 * 4) = *(undefined4 *)(&DAT_02983740 + iVar2 * 4);
      iVar2 = 0;
    }
    else {
      iVar2 = (param_1 * 3 + -0x1800) * 0x10;
      puVar5 = (undefined4 *)
               ((*(int *)(&DAT_0297dc80 + iVar2) + 3) * 0x10 + *(int *)(&DAT_0297dc60 + iVar2));
      uVar6 = FUN_004f6de0(*puVar5,*(undefined4 *)(&DAT_0297dc68 + iVar2),
                           *(undefined4 *)(&DAT_0297dc6c + iVar2),0);
      *(undefined8 *)(&DAT_0297dc70 + iVar2) = uVar6;
      puVar5[2] = (int)uVar6;
      puVar5[3] = *(undefined4 *)(&DAT_0297dc74 + iVar2);
      iVar2 = *(int *)(&DAT_0297dc74 + iVar2);
    }
    goto LAB_004fcd2d;
  }
  iVar2 = (param_1 + -1) * 0x40;
  if (*(int *)(&DAT_008ceb7c + iVar2) == 0) {
    FUN_004ff430(param_1 + -1,0,0,0);
    iVar2 = extraout_EDX;
    goto LAB_004fcd2d;
  }
  *(undefined4 *)(&DAT_008ceb58 + iVar2) = 0;
  *(undefined4 *)(&DAT_008ceb5c + iVar2) = 0;
LAB_004fcd4f:
  iVar2 = FUN_004fb550(param_1,&local_c,0xc);
  if (iVar2 < 0) {
    FUN_004ef7b0();
    goto LAB_004fcc70;
  }
  if (local_c != &DAT_02434e52) {
    uVar4 = FUN_004f6b40(param_1);
    if (param_3 < (int)uVar4) {
      FUN_004ef790(param_3,uVar4);
    }
LAB_004fcf45:
    do {
      if (param_1 < 0x1000) {
        if (0x3ff < param_1) {
          if (param_1 < 0x800) {
            iVar2 = param_1 * 5 + -0x1400;
            *(undefined4 *)(&DAT_02983748 + iVar2 * 4) = *(undefined4 *)(&DAT_02983740 + iVar2 * 4);
            iVar2 = 0;
          }
          else {
            iVar2 = (param_1 * 3 + -0x1800) * 0x10;
            puVar5 = (undefined4 *)
                     ((*(int *)(&DAT_0297dc80 + iVar2) + 3) * 0x10 + *(int *)(&DAT_0297dc60 + iVar2)
                     );
            uVar6 = FUN_004f6de0(*puVar5,*(undefined4 *)(&DAT_0297dc68 + iVar2),
                                 *(undefined4 *)(&DAT_0297dc6c + iVar2),0);
            *(undefined8 *)(&DAT_0297dc70 + iVar2) = uVar6;
            puVar5[2] = (int)uVar6;
            puVar5[3] = *(undefined4 *)(&DAT_0297dc74 + iVar2);
            iVar2 = *(int *)(&DAT_0297dc74 + iVar2);
          }
          goto LAB_004fd002;
        }
        iVar2 = (param_1 + -1) * 0x40;
        if (*(int *)(&DAT_008ceb7c + iVar2) == 0) {
          FUN_004ff430(param_1 + -1,0,0,0);
          iVar2 = extraout_EDX_01;
          goto LAB_004fd002;
        }
        *(undefined4 *)(&DAT_008ceb58 + iVar2) = 0;
        *(undefined4 *)(&DAT_008ceb5c + iVar2) = 0;
      }
      else {
        iVar2 = FUN_006dee90(param_1 + -0x1000,0,0,0);
        iVar2 = iVar2 >> 0x1f;
LAB_004fd002:
        if ((iVar2 < 1) && (iVar2 < 0)) {
          FUN_004ef7b0();
          goto LAB_004fcf45;
        }
      }
      iVar2 = FUN_004fb550(param_1,param_2,uVar4);
      if (-1 < iVar2) {
        return uVar4;
      }
      FUN_004ef7b0();
    } while( true );
  }
  local_8 = (local_8 & 0xff0000 | local_8 >> 0x10) >> 8 | (local_8 & 0xff00 | local_8 << 0x10) << 8;
  local_4 = ((local_4 & 0xff0000 | local_4 >> 0x10) >> 8 | (local_4 & 0xff00 | local_4 << 0x10) << 8
            ) + 0x12;
  iVar2 = (local_8 - local_4) + 0x100 + param_2;
  while (FUN_004ef7b0(), 0xfff < param_1) {
    iVar3 = FUN_006dee90(param_1 + -0x1000,4,0,0);
    iVar3 = iVar3 >> 0x1f;
LAB_004fceb0:
    if ((0 < iVar3) || (-1 < iVar3)) {
LAB_004fcecd:
      FUN_004ef7b0();
      iVar3 = FUN_004fb550(param_1,iVar2,local_4 + -4);
      if (-1 < iVar3) {
        FUN_004f37c0(iVar2 + -4,param_2);
        FUN_004ef7b0(local_4,local_8,0);
        return local_8;
      }
      FUN_004ef7b0(iVar3);
    }
  }
  if (0x3ff < param_1) {
    if (param_1 < 0x800) {
      iVar1 = param_1 * 5 + -0x1400;
      iVar3 = *(int *)(&DAT_02983740 + iVar1 * 4) + 4;
      *(int *)(&DAT_02983748 + iVar1 * 4) = iVar3;
      iVar3 = iVar3 - *(int *)(&DAT_02983740 + iVar1 * 4) >> 0x1f;
    }
    else {
      iVar3 = (param_1 * 3 + -0x1800) * 0x10;
      puVar5 = (undefined4 *)
               ((*(int *)(&DAT_0297dc80 + iVar3) + 3) * 0x10 + *(int *)(&DAT_0297dc60 + iVar3));
      uVar6 = FUN_004f6de0(*puVar5,*(uint *)(&DAT_0297dc68 + iVar3) + 4,
                           *(int *)(&DAT_0297dc6c + iVar3) +
                           (uint)(0xfffffffb < *(uint *)(&DAT_0297dc68 + iVar3)),0);
      *(undefined8 *)(&DAT_0297dc70 + iVar3) = uVar6;
      puVar5[2] = (int)uVar6;
      puVar5[3] = *(undefined4 *)(&DAT_0297dc74 + iVar3);
      iVar3 = *(int *)(&DAT_0297dc74 + iVar3);
    }
    goto LAB_004fceb0;
  }
  iVar3 = (param_1 + -1) * 0x40;
  if (*(int *)(&DAT_008ceb7c + iVar3) == 0) {
    FUN_004ff430(param_1 + -1,4,0,0);
    iVar3 = extraout_EDX_00;
    goto LAB_004fceb0;
  }
  *(undefined4 *)(&DAT_008ceb58 + iVar3) = 4;
  *(undefined4 *)(&DAT_008ceb5c + iVar3) = 0;
  goto LAB_004fcecd;
}

