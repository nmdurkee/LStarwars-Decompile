/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59ab00; label: FUN_0059ab00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059ab00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  byte local_10;
  byte local_f;
  byte local_e;
  byte local_d;
  int local_c;
  undefined4 *local_8;
  float local_4;
  
  if (param_1 != 0) {
    _memset(&DAT_00956050,0,0x200);
    if (0 < DAT_0093d500) {
      puVar7 = (undefined4 *)(DAT_0093d504 + 0xffc);
      local_4 = (float)DAT_0093d500;
      do {
        if (((puVar7[-0x380] & 0x1000) != 0) && (*(char *)((int)puVar7 + -0xd71) == '\0')) {
          local_8 = puVar7;
          FUN_0059a720(*(undefined4 *)(param_1 + 0xc),puVar7 + -0x3df,*puVar7,*puVar7,&local_f,
                       &local_10,&local_e,&local_d);
          iVar1 = ((uint)local_e - (uint)local_f) + 1;
          if (0 < iVar1) {
            iVar4 = ((uint)local_d - (uint)local_10) + 1;
            puVar5 = (uint *)(&DAT_00956050 + (uint)local_f * 8);
            local_c = iVar1;
            do {
              iVar1 = iVar4;
              if (0 < iVar4) {
                do {
                  uVar8 = __allshl();
                  *puVar5 = *puVar5 | (uint)uVar8;
                  puVar5[1] = puVar5[1] | (uint)((ulonglong)uVar8 >> 0x20);
                  iVar1 = iVar1 + -1;
                  puVar7 = local_8;
                } while (iVar1 != 0);
              }
              puVar5 = puVar5 + 2;
              local_c = local_c + -1;
            } while (local_c != 0);
            local_c = 0;
          }
        }
        puVar7 = puVar7 + 0x436;
        local_4 = (float)((int)local_4 + -1);
        local_8 = puVar7;
      } while (local_4 != 0.0);
    }
    iVar1 = FUN_0040aa50();
    if (iVar1 != 0) {
      uVar2 = FUN_0040aa70();
      FUN_0059a720(*(undefined4 *)(param_1 + 0xc),uVar2,0x3dcccccd,0x3dcccccd,&local_f,&local_10,
                   &local_e,&local_d);
      local_4 = (float)(((uint)local_e - (uint)local_f) + 1);
      if (0 < (int)local_4) {
        iVar1 = ((uint)local_d - (uint)local_10) + 1;
        puVar5 = (uint *)(&DAT_00956050 + (uint)local_f * 8);
        do {
          iVar4 = iVar1;
          if (0 < iVar1) {
            do {
              uVar8 = __allshl();
              *puVar5 = *puVar5 | (uint)uVar8;
              puVar5[1] = puVar5[1] | (uint)((ulonglong)uVar8 >> 0x20);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          puVar5 = puVar5 + 2;
          local_4 = (float)((int)local_4 + -1);
        } while (local_4 != 0.0);
      }
    }
    local_8 = (undefined4 *)*(int *)(param_1 + 4);
joined_r0x0059acce:
    iVar1 = (int)local_8;
    if (iVar1 != 0) {
      local_8 = *(undefined4 **)(iVar1 + 0x38);
      if (0.0 < *(float *)(iVar1 + 0x20)) {
        local_4 = *(float *)(iVar1 + 0x20) - _DAT_00925018;
        *(float *)(iVar1 + 0x20) = local_4;
        if (local_4 < 0.0 != (local_4 == 0.0)) {
          FUN_0059a6b0(param_1,iVar1);
          goto joined_r0x0059acce;
        }
      }
      iVar3 = (uint)*(byte *)(iVar1 + 0x35) - (uint)*(byte *)(iVar1 + 0x33);
      iVar4 = 0;
      local_c = 0;
      local_4 = 0.0;
      if (iVar3 != -1 && -1 < iVar3 + 1) {
        puVar5 = (uint *)(&DAT_00956050 + (uint)*(byte *)(iVar1 + 0x33) * 8);
        do {
          if (iVar4 != 0) goto LAB_0059adb7;
          iVar3 = (uint)*(byte *)(iVar1 + 0x36) - (uint)*(byte *)(iVar1 + 0x34);
          iVar6 = 0;
          if (iVar3 != -1 && -1 < iVar3 + 1) {
            do {
              if (iVar4 != 0) break;
              uVar8 = __allshl();
              if (((uint)uVar8 & *puVar5) != 0 ||
                  ((uint)((ulonglong)uVar8 >> 0x20) & puVar5[1]) != 0) {
                local_c = 1;
              }
              iVar6 = iVar6 + 1;
              iVar4 = local_c;
            } while (iVar6 < (int)(((uint)*(byte *)(iVar1 + 0x36) - (uint)*(byte *)(iVar1 + 0x34)) +
                                  1));
          }
          local_4 = (float)((int)local_4 + 1);
          puVar5 = puVar5 + 2;
        } while ((int)local_4 <
                 (int)(((uint)*(byte *)(iVar1 + 0x35) - (uint)*(byte *)(iVar1 + 0x33)) + 1));
        if (iVar4 != 0) {
LAB_0059adb7:
          iVar4 = FUN_005185e0(iVar1,*(undefined4 *)(iVar1 + 0xc));
          if (iVar4 != 0) {
            *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(iVar1 + 0x18);
            *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(iVar1 + 0x1c);
            *(undefined1 *)(iVar4 + 0x4a) = *(undefined1 *)(iVar1 + 0x32);
            *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
            *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar1 + 0x14);
            *(uint *)(iVar4 + 0x38) = (uint)*(ushort *)(iVar1 + 0x30);
            *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar1 + 0x28);
            *(undefined4 *)(iVar4 + 0x54) = *(undefined4 *)(iVar1 + 0x2c);
          }
        }
      }
      goto joined_r0x0059acce;
    }
  }
  return;
}

