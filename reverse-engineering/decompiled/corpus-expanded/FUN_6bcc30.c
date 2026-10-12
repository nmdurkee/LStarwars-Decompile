/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bcc30; label: FUN_006bcc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bcc30(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_c;
  undefined4 local_8;
  undefined *local_4;
  
  local_8 = 0x3dcccccd;
  local_c = 0x3f666666;
  if (*(int *)(in_ECX + 0x10a8) != 0) {
    if (((DAT_02974644 != 0xff) && ((uint)(int)DAT_02974644 < 10)) &&
       (&DAT_02973e9c + DAT_02974644 * 0xa8 != (undefined *)0x0)) {
      local_4 = &DAT_02973e9c + DAT_02974644 * 0xa8;
      FUN_006bca90(&local_4,1,0x40,0x193,*(undefined4 *)(in_ECX + 0xef0),
                   *(undefined4 *)(in_ECX + 0xef4),*(undefined4 *)(in_ECX + 0xef8),
                   *(undefined4 *)(in_ECX + 0xefc));
    }
    iVar1 = FUN_00617e70();
    if (iVar1 != 0) {
      FUN_0061f400();
    }
    if (*(int *)(in_ECX + 0x28) != 0) {
      iVar1 = FUN_00617e20();
      fVar4 = (float10)FUN_00621050();
      local_4 = (undefined *)(float)fVar4;
      if (DAT_00973734 < (float)local_4 + (float)local_4) {
        *(float *)(iVar1 + 0x4c) = (float)local_4 + (float)local_4;
      }
      FUN_00621140();
      FUN_006ba6a0(0);
      FUN_006ba8a0(in_ECX + 0x10,0x3f800000,0xff000000);
      if (DAT_02973a60 != 0) {
        if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
          FUN_006009c0();
        }
        DAT_02973a60 = 0;
      }
    }
    if (*(int *)(in_ECX + 0x948) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x948) + 0x2c))();
    }
    FUN_005fecb0();
    FUN_0061f7e0(&local_8,&local_c);
    uVar8 = *(undefined4 *)(in_ECX + 0xefc);
    uVar7 = *(undefined4 *)(in_ECX + 0xef8);
    uVar6 = *(undefined4 *)(in_ECX + 0xef4);
    uVar5 = *(undefined4 *)(in_ECX + 0xef0);
    uVar2 = FUN_006e6b90(uVar5,uVar6,uVar7,uVar8);
    uVar3 = FUN_006e6b90(uVar2);
    FUN_006bca90(in_ECX + 0xe68,0x20,uVar3,uVar2,uVar5,uVar6,uVar7,uVar8);
    if (DAT_02973a7c != 0) {
      FUN_005d1740(DAT_02973a78);
      FUN_005d1750(DAT_0081f99c,DAT_0081f99c);
      FUN_00626b50(DAT_02973a7c);
    }
    if (DAT_02973a80 != 0) {
      FUN_005d1740(DAT_02973a78);
      FUN_005d1750(DAT_0081f99c,DAT_0081f99c);
      FUN_00626b50(DAT_02973a80);
    }
    FUN_0061f940(*(undefined4 *)(in_ECX + 0x2c));
    iVar1 = FUN_00617e70();
    if (iVar1 != 0) {
      FUN_0061f950();
    }
  }
  return;
}

