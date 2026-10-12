/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54d820; label: FUN_0054d820
 */

void FUN_0054d820(int param_1,int param_2,undefined2 param_3,float param_4)

{
  byte bVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float10 fVar7;
  float10 extraout_ST0;
  int local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88 [6];
  undefined4 local_70;
  undefined4 local_64 [6];
  undefined4 local_4c;
  undefined1 local_40 [64];
  
  local_90 = 0;
  if (((param_1 != 0) && (param_2 != 0)) && (local_94 = in_EAX, 0 < in_EAX)) {
    do {
      if ((*(byte *)(param_2 + 0x1e) & 2) != 0) {
        iVar3 = FUN_005cfac0(param_2 + 0xec);
        if (((iVar3 == 0) && (DAT_00803ba8 != -1)) &&
           (*(char *)(DAT_00803ba8 * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) != '\0')) {
          FUN_005b45f0(local_40,*(undefined2 *)(param_2 + 0x22));
          FUN_005b4f70(local_40,*(undefined2 *)(param_2 + 0x20));
          FUN_005b4900(local_40,param_2 + 0x10);
          FUN_005f33b0(DAT_00803ba8 * 0x10 + *(int *)(param_1 + 0x2ac0),local_40);
        }
        bVar1 = *(byte *)(param_2 + 0x1e);
        if ((bVar1 & 1) != 0) {
          if ((((bVar1 & 4) != 0) && ((bVar1 & 8) == 0)) &&
             (iVar3 = FUN_0054d410(param_2,0,0), iVar3 == 0)) {
            local_88[0] = *(undefined4 *)(param_2 + 0x30);
            local_88[1] = *(undefined4 *)(param_2 + 0x34);
            local_88[2] = *(undefined4 *)(param_2 + 0x38);
            if (DAT_00802464 == 0) {
              local_70 = DAT_0080245c;
              local_4c = DAT_0080245c;
              puVar4 = (undefined4 *)(param_2 + 0x5c);
              local_98 = 6;
              do {
                local_64[0] = *puVar4;
                local_64[1] = puVar4[1];
                local_64[2] = puVar4[2];
                FUN_005dbed0(local_88,DAT_0093b108,0);
                puVar4 = puVar4 + 3;
                local_98 = local_98 + -1;
                puVar5 = local_64;
                puVar6 = local_88;
                for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
                  *puVar6 = *puVar5;
                  puVar5 = puVar5 + 1;
                  puVar6 = puVar6 + 1;
                }
              } while (local_98 != 0);
            }
            else {
              FUN_004eeb10(local_88,param_2 + 0x5c,6,0,0);
            }
          }
          if (((((*(byte *)(param_2 + 0x1e) & 4) == 0) || (DAT_0087b4d8 != 0)) &&
              (*(float *)(param_2 + 0x28) != 2e+06)) &&
             ((DAT_00803ba4 != -1 &&
              (*(char *)(DAT_00803ba4 * 0x10 + 0xe + *(int *)(param_1 + 0x2ac0)) != '\0')))) {
            FUN_005b4670(local_40,param_3);
            if (*(short *)(param_2 + 0x4a) != 0) {
              FUN_005b5160(local_40,*(short *)(param_2 + 0x4a));
            }
            if (*(short *)(param_2 + 0x48) != 0) {
              FUN_005b4cf0(local_40,*(short *)(param_2 + 0x48));
            }
            FUN_005b4ac0(local_40,0x3f4ccccd);
            FUN_005b4900(local_40,param_2 + 0x24);
            if (DAT_0087b4d8 == 0) {
              cVar2 = FUN_0055e970(param_2 + 0x24,&local_90,&local_8c,0,0);
              if (cVar2 == '\0') goto LAB_0054db17;
              iVar3 = FUN_006e6b90();
              fVar7 = extraout_ST0 - (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
            }
            else {
              fVar7 = (float10)param_4;
            }
            if (0.0 < (float)fVar7) {
              FUN_005ff7a0(DAT_00803ba4 * 0x10 + *(int *)(param_1 + 0x2ac0),local_40,(float)fVar7);
            }
          }
        }
      }
LAB_0054db17:
      param_2 = param_2 + 0xf8;
      local_94 = local_94 + -1;
    } while (local_94 != 0);
  }
  return;
}

