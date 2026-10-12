/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x568010; label: FUN_00568010
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00568010(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float10 fVar11;
  float local_4c;
  int local_48;
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  float local_8;
  
  if (param_1 != 0) {
    puVar9 = *(undefined4 **)(param_1 + 0x50c8);
    local_48 = 0;
    if (0 < *(int *)(param_1 + 0x50c0)) {
      do {
        if (0.0 < (float)puVar9[0x33]) {
          fVar1 = (float)puVar9[0x33] - _DAT_00925018;
          puVar9[0x33] = fVar1;
          if (fVar1 < 2.0 != (fVar1 == 2.0)) {
            puVar9[0x25] = puVar9[0x25] | 0x4000;
            if (0.0 < (float)puVar9[0x33]) {
              if (2 < DAT_00925068 % 6) {
                puVar9[0x25] = puVar9[0x25] & 0xffffbfff;
              }
            }
            else {
              FUN_00566c20(puVar9);
            }
            local_4c = ((float)puVar9[0x19] - (float)puVar9[0x16]) * 0.5;
            fVar1 = ((float)puVar9[0x1b] - (float)puVar9[0x18]) * 0.5;
            if (local_4c < fVar1) {
              local_4c = fVar1;
            }
            FUN_0055e660(puVar9 + 0x13,local_4c,puVar9 + 0x16,puVar9 + 0x19,0,0,0x3f800000,4);
          }
        }
        iVar4 = FUN_005d0420(puVar9[0x29] + 0x30);
        uVar8 = puVar9[0x25];
        uVar5 = uVar8 >> 0x17 & 1;
        if (((uVar5 == 0) || ((uVar8 & 1) != 0)) && ((uVar8 & 0x20000) == 0)) {
          if (((uVar5 == 0) && (iVar4 != 0)) && ((*(uint *)(iVar4 + 0x50) & 1) != 0)) {
            *(uint *)(iVar4 + 0x50) = *(uint *)(iVar4 + 0x50) & 0xfffffffe;
          }
        }
        else {
          if ((puVar9[0x26] & 0x400000) != 0) {
            puVar6 = (undefined4 *)FUN_005d0370(puVar9[0x29] + 0x30);
            puVar10 = puVar9;
            for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar10 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar10 = puVar10 + 1;
            }
            puVar9[0x25] = puVar9[0x25] | 0x10000;
          }
          if ((*(byte *)((int)puVar9 + 0x96) & 1) != 0) {
            FUN_00567da0(puVar9);
          }
          if (iVar4 != 0) {
            fVar11 = (float10)FUN_005ca4b0(*(undefined4 *)
                                            (*(int *)(*(int *)(puVar9[0x29] + 0x30) + 0x54) +
                                            (uint)*(ushort *)(iVar4 + 0x5c) * 4));
            fVar1 = (float)fVar11;
            if ((puVar9[0x25] & 0x80000) != 0) {
              iVar7 = puVar9[0x29];
              if (((*(byte *)(iVar7 + 0xfc) & 1) == 0) &&
                 (((*(uint *)(iVar7 + 0x7c) & 0x2000) != 0 || ((puVar9[0x25] & 0x400000) != 0)))) {
                *(float *)(iVar7 + 0x90) =
                     _DAT_00925018 * 60.0 * *(float *)(iVar4 + 0x40) + *(float *)(iVar7 + 0x90);
                puVar9[0x25] = puVar9[0x25] | 0x10000;
                fVar2 = *(float *)(puVar9[0x29] + 0x90);
                if (fVar1 < fVar2 != (fVar1 == fVar2)) {
                  if ((*(byte *)(iVar4 + 0x50) & 8) == 0) {
                    puVar9[0x25] = puVar9[0x25] | 0x1000000;
                  }
                  else {
                    *(undefined4 *)(puVar9[0x29] + 0x90) = 0x3f800000;
                  }
                }
                *(byte *)(puVar9[0x29] + 0xfc) = *(byte *)(puVar9[0x29] + 0xfc) | 1;
              }
              puVar9[0x25] = puVar9[0x25] | 0x10000;
              fVar2 = _DAT_00925018 * 60.0 * *(float *)(iVar4 + 0x40) + (float)puVar9[0x2f];
              puVar9[0x2f] = fVar2;
              FUN_005526c0(puVar9[0x29] + 0x30,fVar2,local_40,0);
              puVar9[0x13] = (float)puVar9[0xc] + local_10;
              puVar9[0x14] = (float)puVar9[0xd] + local_c;
              puVar9[0x15] = (float)puVar9[0xe] + local_8;
              if (fVar1 < (float)puVar9[0x2f] != (fVar1 == (float)puVar9[0x2f])) {
                if ((*(byte *)(iVar4 + 0x50) & 8) == 0) {
                  uVar3 = *(undefined4 *)(puVar9[0x29] + 0x88);
                  puVar9[0x25] = puVar9[0x25] | 0x1000000;
                }
                else {
                  uVar3 = 0;
                }
                puVar9[0x2f] = uVar3;
              }
            }
          }
          uVar8 = puVar9[0x25];
          if ((uVar8 & 0x40000) == 0) {
            if ((uVar8 & 0x20000) != 0) {
              if ((float)puVar9[0x2f] <= 0.0) {
                puVar9[0x25] = uVar8 & 0xfffdffff;
              }
              else {
                puVar9[0x2f] = (float)puVar9[0x2f] - _DAT_00925018;
              }
            }
          }
          else if (0.0 < (float)puVar9[0x2d]) {
            fVar1 = (float)puVar9[0x2d] - _DAT_00925018;
            puVar9[0x2d] = fVar1;
            if (fVar1 < 0.0 != (fVar1 == 0.0)) {
              if ((iVar4 == 0) || ((uVar8 & 0x80000) != 0)) {
                uVar8 = uVar8 | 0x1000000;
              }
              else {
                uVar8 = uVar8 | 0x80000;
              }
              puVar9[0x25] = uVar8;
              puVar9[0x25] = puVar9[0x25] & 0xfffbffff;
            }
          }
          if ((*(byte *)((int)puVar9 + 0x97) & 1) != 0) {
            FUN_00567800(puVar9,1,0xffffffff,1,0,1);
          }
          iVar4 = 0xae;
          do {
            if (*(short *)(iVar4 + puVar9[0x29]) != -1) {
              FUN_00684be0((int)*(short *)(iVar4 + puVar9[0x29]),puVar9 + 0x13,0x3c,_DAT_00925018,0,
                           0,0);
            }
            iVar4 = iVar4 + 2;
          } while (iVar4 < 0xb2);
        }
        local_48 = local_48 + 1;
        puVar9 = puVar9 + 0x45;
      } while (local_48 < *(int *)(param_1 + 0x50c0));
    }
  }
  return;
}

