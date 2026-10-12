/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d1ff0; label: FUN_006d1ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d1ff0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10a8) != 0) {
    uVar1 = *param_1;
    uVar2 = *(undefined4 *)param_1[2];
    *(undefined4 *)(in_ECX + 0xe64) = 0;
    _memset((void *)(in_ECX + 0xe68),0,0x80);
    _memset((void *)(in_ECX + 0xf00),0,0x80);
    _memset((void *)(in_ECX + 0xf80),0,0x80);
    *(undefined4 *)(in_ECX + 0x2c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x2a4) = 0;
    if ((*(byte *)(in_ECX + 0x350) & 2) != 0) {
      *(undefined4 *)(in_ECX + 0x2a4) = 1;
    }
    if ((*(byte *)(in_ECX + 0x3f8) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x4a0) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x548) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x5f0) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x698) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x740) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x7e8) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x890) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((*(byte *)(in_ECX + 0x938) & 2) != 0) {
      *(int *)(in_ECX + 0x2a4) = *(int *)(in_ECX + 0x2a4) + 1;
    }
    if ((((DAT_02973a7c == 0) && (*(int *)(in_ECX + 0x38) != 0)) &&
        (*(char *)(in_ECX + 0xbc) != '\0')) && (*(float *)(in_ECX + 0x168) != 0.0)) {
      FUN_0061e5d0(0);
      uVar4 = FUN_0061f000();
      FUN_0061eff0(uVar4);
      FUN_006d0830();
    }
    if (DAT_02973a88 != 0) {
      FUN_00624220(DAT_02973a7c);
      DAT_02973a7c = 0;
      DAT_02973a88 = 0;
    }
    if (DAT_02973a8c != 0) {
      FUN_00624220(DAT_02973a8c);
      DAT_02973a8c = 0;
    }
    if (DAT_02973a90 != 0) {
      FUN_00624220(DAT_02973a90);
      DAT_02973a90 = 0;
    }
    if (DAT_02973a84 != 0) {
      if (DAT_02973a7c != 0) {
        FUN_00624220(DAT_02973a7c);
      }
      DAT_02973a7c = DAT_02973a84;
      DAT_02973a84 = 0;
    }
    if (*(int *)(in_ECX + 0x28) == 0) {
      puVar5 = &DAT_009736e8;
    }
    else {
      puVar5 = (undefined4 *)FUN_00617e20();
    }
    FUN_006c3240(puVar5,uVar2,uVar1,DAT_0081fcfc != 0);
    iVar6 = FUN_00617e70();
    if (iVar6 != 0) {
      FUN_00627650(0,uVar2);
    }
    if ((*(int *)(in_ECX + 0x28) != 0) && (iVar6 = FUN_0061e5c0(), iVar6 != 0)) {
      uVar4 = uVar2;
      if (DAT_02973a98 != 0) {
        uVar4 = 0;
      }
      FUN_00620ef0(uVar4);
      FUN_00620fa0(in_ECX + 0x10,in_ECX + 0x20,in_ECX + 0x24);
    }
    if ((*(char *)(in_ECX + 0xc9) != '\0') && (*(float *)(in_ECX + 0x19c) != 0.0)) {
      fVar3 = *(float *)(in_ECX + 0x34) + 0.1;
      *(float *)(in_ECX + 0x34) = fVar3;
      FUN_0061f9b0(fVar3,fVar3);
    }
    if (((*(char *)(in_ECX + 0xca) != '\0') && (*(float *)(in_ECX + 0x1a0) != 0.0)) &&
       (0.1 < (float)DAT_0081f99c)) {
      fVar3 = *(float *)(in_ECX + 0x34) - 0.1;
      *(float *)(in_ECX + 0x34) = fVar3;
      FUN_0061f9b0(fVar3,fVar3);
    }
    if (DAT_02973a7c == 0) {
      if ((DAT_02973a80 != 0) && (DAT_0081fcfc == 0)) {
        FUN_005d1740(DAT_02973a78);
        FUN_005d1750(DAT_0081f99c,DAT_0081f99c);
        iVar6 = FUN_0062a400(DAT_02973a80,uVar1,uVar2);
        if (iVar6 != 0) {
          return;
        }
      }
    }
    else {
      FUN_005d1740(DAT_02973a78);
      FUN_005d1750(DAT_0081f99c,DAT_0081f99c);
      iVar6 = FUN_0062a400(DAT_02973a7c,uVar1,uVar2);
      if (iVar6 != 0) {
        *(undefined1 *)(in_ECX + 0x133) = 1;
        *(undefined4 *)(in_ECX + 0x164) = 0;
      }
      if ((DAT_02973a7c != DAT_02973a80) && (iVar6 == 0)) {
        if ((*(char *)(in_ECX + 0xbb) != '\0') && (*(float *)(in_ECX + 0x164) != 0.0)) {
          FUN_0061e5d0(1);
          FUN_00624220(DAT_02973a7c);
          DAT_02973a7c = 0;
          FUN_0061eff0(0);
        }
        if ((*(char *)(in_ECX + 0xbc) != '\0') && (*(float *)(in_ECX + 0x168) != 0.0)) {
          FUN_00624220(DAT_02973a7c);
          DAT_02973a7c = 0;
          FUN_006d0830();
        }
      }
    }
    if (*(int **)(in_ECX + 0x948) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x948) + 0x28))(in_ECX + 0x40);
    }
    if ((*(char *)(in_ECX + 0xcf) != '\0') && (*(float *)(in_ECX + 0x1b4) != 0.0)) {
      FUN_006d0240();
    }
  }
  return;
}

