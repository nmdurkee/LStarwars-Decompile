/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56b160; label: FUN_0056b160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056b160(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float10 fVar7;
  float local_9c;
  undefined4 *local_98;
  int local_94;
  int local_90;
  undefined4 *local_88;
  undefined4 local_80 [12];
  undefined4 local_50 [4];
  undefined4 local_40 [13];
  float local_c;
  
  local_88 = *(undefined4 **)(param_1 + 0x50c8);
  local_94 = 0;
  if (0 < *(int *)(param_1 + 0x50bc)) {
    do {
      iVar1 = local_88[0x29];
      puVar4 = local_88;
      if (iVar1 != 0) {
        local_90 = 0;
        if (*(short *)(iVar1 + 0xb2) != 0) {
          do {
            if ((puVar4[0x26] & 0x800000) == 0) {
              if ((puVar4[0x25] & 0x4000) != 0) {
                if ((puVar4[0x26] & 0x20000) == 0) {
                  FUN_00596920(0);
                }
                else {
                  thunk_FUN_005d05b0();
                }
                iVar3 = iVar1 + 0x30;
                iVar2 = FUN_005d0420(iVar3);
                if ((iVar2 == 0) || ((puVar4[0x25] & 0x80000) == 0)) {
                  iVar2 = FUN_005f33b0(iVar3,puVar4);
                  puVar4[0x25] = puVar4[0x25] ^ (iVar2 << 0xf ^ puVar4[0x25]) & 0x8000U;
                  puVar5 = puVar4;
                  puVar6 = local_40;
                  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
                    *puVar6 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar6 = puVar6 + 1;
                  }
                  if ((puVar4[0x25] & 0x8000) != 0) {
                    puVar5 = puVar4 + 0xc;
                    goto LAB_0056b3a2;
                  }
                }
                else {
                  fVar7 = (float10)FUN_005ca4b0(*(undefined4 *)
                                                 (*(int *)(*(int *)(puVar4[0x29] + 0x30) + 0x54) +
                                                 (uint)*(ushort *)(iVar2 + 0x5c) * 4));
                  local_9c = (float)puVar4[0x32] + *(float *)(puVar4[0x29] + 0x90);
                  if ((float)fVar7 < local_9c) {
                    local_9c = (local_9c - (float)fVar7) + *(float *)(iVar2 + 0x44);
                  }
                  if ((*(uint *)(puVar4[0x29] + 0x7c) & 0x2000) == 0) {
                    if ((puVar4[0x25] & 0x400000) == 0) {
                      local_9c = (float)puVar4[0x2f];
                    }
                    FUN_005526c0(iVar3,local_9c,local_80,0);
                    FUN_005c0500(local_80,local_80,puVar4);
                  }
                  else {
                    FUN_005526c0(iVar3,local_9c,local_80,1);
                  }
                  iVar2 = FUN_005f33b0(iVar3,local_80);
                  puVar4[0x25] = puVar4[0x25] ^ (iVar2 << 0xf ^ puVar4[0x25]) & 0x8000U;
                  puVar5 = local_80;
                  puVar6 = local_40;
                  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
                    *puVar6 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar6 = puVar6 + 1;
                  }
                  if ((puVar4[0x25] & 0x8000) != 0) {
                    puVar5 = local_50;
LAB_0056b3a2:
                    FUN_005d6430(puVar4 + 0x10,puVar5,1,0);
                  }
                }
                thunk_FUN_005d05b0();
                if (((((puVar4[0x25] & 0x800000) != 0) && ((puVar4[0x25] & 0x8000) != 0)) &&
                    ((*(byte *)(puVar4 + 0x26) & 0x10) != 0)) && (DAT_00950bc0 != (code *)0x0)) {
                  (*DAT_00950bc0)(puVar4);
                }
                if (((puVar4[0x26] & 0x40000000) != 0) &&
                   (iVar2 = FUN_00550490(local_40,2,local_c + (float)puVar4[0x35],puVar4[0x35],
                                         local_40), iVar2 != 0)) {
                  FUN_005d4690(0);
                  FUN_005f33b0(iVar3,local_40);
                  FUN_005d46b0();
                }
              }
            }
            else {
              puVar4[0x25] = puVar4[0x25] | 0x8000;
              FUN_005d6430(puVar4 + 0x10,puVar4 + 0xc,1,0);
            }
            local_90 = local_90 + 1;
            puVar4 = puVar4 + 0x45;
          } while (local_90 < (int)(uint)*(ushort *)(iVar1 + 0xb2));
        }
        iVar2 = FUN_005cfac0(iVar1 + 0x3c);
        if ((iVar2 != 0) && (iVar2 = 0, puVar5 = local_88, *(short *)(iVar1 + 0xb2) != 0)) {
          do {
            if (((puVar5[0x26] & 0x400) == 0) && ((*(byte *)(puVar5 + 0x25) & 1) != 0)) {
              FUN_00568890(puVar5,local_80,0);
              FUN_005f33b0(iVar1 + 0x3c,local_80);
            }
            iVar2 = iVar2 + 1;
            puVar5 = puVar5 + 0x45;
          } while (iVar2 < (int)(uint)*(ushort *)(iVar1 + 0xb2));
        }
        iVar2 = FUN_005cfac0(iVar1 + 0x48);
        if ((iVar2 != 0) && (iVar2 = 0, local_98 = local_88, *(short *)(iVar1 + 0xb2) != 0)) {
          do {
            if (((local_98[0x25] & 0x800000) != 0) && ((local_98[0x26] & 0x20000) == 0)) {
              FUN_00568950(local_98,local_80);
              FUN_005f33b0(iVar1 + 0x3c,local_80);
            }
            iVar2 = iVar2 + 1;
            local_98 = local_98 + 0x45;
          } while (iVar2 < (int)(uint)*(ushort *)(iVar1 + 0xb2));
        }
        iVar2 = FUN_005cfac0(iVar1 + 0x54);
        if ((iVar2 != 0) && (iVar2 = 0, *(short *)(iVar1 + 0xb2) != 0)) {
          do {
            if ((*(byte *)(local_88 + 0x25) & 1) != 0) {
              FUN_005f33b0(iVar1 + 0x54,local_88);
            }
            iVar2 = iVar2 + 1;
            local_88 = local_88 + 0x45;
          } while (iVar2 < (int)(uint)*(ushort *)(iVar1 + 0xb2));
        }
      }
      local_94 = local_94 + 1;
      local_88 = puVar4;
    } while (local_94 < *(int *)(param_1 + 0x50bc));
  }
  thunk_FUN_005d05b0();
  return;
}

