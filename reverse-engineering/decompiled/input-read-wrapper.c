/* Ghidra pseudocode; not original source. ev_ea595d4ca5e235950ff013117e04d5105894c54ff2f4b0acc6da209a028a10bb */

int FUN_006daa40(int param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
                undefined1 *param_5,undefined1 *param_6,undefined1 *param_7,undefined1 *param_8,
                undefined1 *param_9,undefined4 *param_10,undefined1 *param_11,undefined4 *param_12)

{
  undefined1 *puVar1;
  byte bVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  float10 fVar7;
  int local_c;
  
  fVar3 = DAT_02976588;
  local_c = 0;
  if ((param_1 - 10U < 4) && (*(char *)(param_1 * 0x17c + 0x4e5c + in_ECX) == '\0')) {
    return 0;
  }
  if (*(char *)(in_ECX + 0x4e10) == '\0') {
    if (0 < DAT_02976584) {
      fVar7 = (float10)FUN_004f3bb0();
      DAT_02976588 = (float)((float10)fVar3 - fVar7);
      if (DAT_02976588 < 0.0 != (DAT_02976588 == 0.0)) {
        DAT_02976588 = DAT_02976588 + DAT_02976580;
        DAT_02976584 = DAT_02976584 + -1;
        FUN_006da200();
      }
    }
    if (*(char *)(in_ECX + 0x4e10) == '\0') {
      *(undefined1 *)(in_ECX + 0x4e10) = 1;
      uVar4 = FUN_006d5990();
      *(undefined4 *)(in_ECX + 0x68b0) = uVar4;
    }
  }
  FUN_006d7990();
  uVar6 = 1 << ((byte)param_1 & 0x1f);
  puVar1 = (undefined1 *)(param_1 * 0x17c + 0x4fa4 + in_ECX);
  if ((uVar6 & *(uint *)(in_ECX + 0x4e04)) != 0) goto LAB_006dabdf;
  *(uint *)(in_ECX + 0x4e04) = *(uint *)(in_ECX + 0x4e04) | uVar6;
  local_c = FUN_006d74e0(param_1,in_ECX + 0x671c);
  if (((*(uint *)(in_ECX + 0x4e08) & uVar6) != 0) && (local_c != 0)) {
    FUN_006d8490(param_1);
  }
  FUN_006d7d80(param_1,puVar1,local_c,in_ECX + 0x671c,in_ECX + 0x62fc,in_ECX + 0x68b0);
  if ((param_1 == 10) || (param_1 == 0xc)) {
    if (*(char *)(in_ECX + 0x67e0) == '\0') {
      FUN_006d6460(puVar1);
      goto LAB_006dab90;
    }
  }
  else {
LAB_006dab90:
    if (*(char *)(in_ECX + 0x67e0) == '\0') goto LAB_006dabdf;
  }
  if (local_c != 0) {
    if (param_1 - 10U < 4) {
      *(undefined4 *)(puVar1 + 8) = 0;
    }
    iVar5 = FUN_004f48e0((int)DAT_029758f9);
    if ((param_1 == iVar5) || ((iVar5 == -1 && (param_1 - 10U < 4)))) {
      uVar4 = FUN_006d8370(param_1,*(undefined4 *)(puVar1 + 8));
      *(undefined4 *)(puVar1 + 8) = uVar4;
    }
  }
LAB_006dabdf:
  bVar2 = DAT_029755a8 & 4;
  *param_10 = *(undefined4 *)(puVar1 + 8);
  if ((bVar2 == 0) && (DAT_00827610 != 0)) {
    *param_2 = *puVar1;
    *param_3 = puVar1[1];
    *param_4 = puVar1[2];
    *param_5 = puVar1[3];
    *param_6 = puVar1[4];
    *param_7 = puVar1[5];
    *param_8 = puVar1[6];
    *param_9 = puVar1[7];
  }
  else {
    *param_2 = 0x80;
    *param_3 = 0x80;
    *param_4 = 0x80;
    *param_5 = 0x80;
    *param_6 = 0;
    *param_7 = 0;
    *param_8 = 0;
    *param_9 = 0;
    *param_10 = 0;
  }
  *param_11 = 0;
  *param_12 = 0;
  return local_c;
}

