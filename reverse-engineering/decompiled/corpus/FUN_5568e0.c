/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x5568e0; label: FUN_005568e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005568e0(int param_1)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40 [16];
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x46e0) != 0)) &&
     (local_54 = 0, *(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0')) {
    local_5c = 0;
    do {
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0x46e0) + local_5c);
      if ((*(byte *)(puVar7 + 0x2b) & 1) != 0) {
        if (*(byte *)((int)puVar7 + 0x8b) == 0) {
          local_60 = (undefined4 *)0x0;
        }
        else {
          local_60 = (undefined4 *)
                     ((uint)(0x10000 / (ulonglong)(longlong)(int)(uint)*(byte *)((int)puVar7 + 0x8b)
                            ) & 0xffff);
        }
        puVar4 = local_60;
        FUN_005b4670(local_40,0);
        FUN_005b4f70(local_40,(uint)*(ushort *)((int)puVar7 + 0x82) +
                              (uint)*(ushort *)(puVar7 + 0x1f));
        FUN_005b4900(local_40,puVar7 + 0x17);
        cVar1 = *(char *)((int)puVar7 + 0x8b);
        puVar8 = local_40;
        puVar9 = puVar7;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        local_58 = 0;
        if (cVar1 != '\0') {
          iVar5 = 0;
          local_60 = puVar7 + 0x2d;
          do {
            FUN_005b4670(local_40,0);
            FUN_005b4f70(local_40,(uint)*(ushort *)((int)puVar7 + 0x82) +
                                  (uint)*(ushort *)(puVar7 + 0x1f));
            FUN_005b4f70(local_40,iVar5);
            FUN_005b4900(local_40,puVar7 + 0x17);
            iVar5 = iVar5 + (int)puVar4;
            puVar8 = local_40;
            puVar9 = local_60;
            for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar9 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            local_58 = local_58 + 1;
            local_60 = local_60 + 0x11;
          } while (local_58 < (int)(uint)*(byte *)((int)puVar7 + 0x8b));
        }
        iVar5 = FUN_005a1590(puVar7[0x1a]);
        if (iVar5 == 0) {
          *(byte *)(puVar7 + 0x2b) = *(byte *)(puVar7 + 0x2b) | 0x20;
        }
        else if ((*(byte *)(puVar7 + 0x2b) & 0x20) != 0) {
          *(byte *)(puVar7 + 0x2b) = *(byte *)(puVar7 + 0x2b) & 0xdf;
        }
        if ((((*(byte *)(puVar7 + 0x2b) & 0x22) != 0) &&
            (puVar7[0x21] = puVar7[0x21] & 0xffffffbf | 0x20, (*(byte *)(puVar7 + 0x2b) & 4) == 0))
           && (iVar5 = FUN_0054fa60(), iVar5 < 0x800)) {
          local_4c = puVar7[0x17];
          local_48 = (float)puVar7[0x18] + 0.3;
          local_44 = puVar7[0x19];
          if (DAT_008025bc != -1) {
            FUN_00684c90(*(undefined4 *)
                          (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + DAT_008025bc * 0x14),
                         &local_4c,2,0,0);
          }
          if (DAT_008025c0 != -1) {
            FUN_00684c90(*(undefined4 *)
                          (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + DAT_008025c0 * 0x14),
                         &local_4c,2,0,0);
          }
        }
        if (((*(byte *)(puVar7 + 0x2b) & 8) != 0) && (DAT_0087baf0 == 0)) {
          puVar7[0x21] = puVar7[0x21] & 0xffffffbf | 0x20;
          iVar5 = FUN_00553910();
          if (iVar5 != 0) {
            *(undefined1 *)((&DAT_0093d7f0)[local_54] + 0x7b5) = 0xff;
            *(undefined4 *)((&DAT_0093d7f0)[local_54] + 0x798) = 0;
          }
        }
        if (0.0 < (float)puVar7[0xb5]) {
          uVar2 = puVar7[0x21];
          fVar3 = (float)puVar7[0xb5] - _DAT_00925018;
          puVar7[0x21] = uVar2 & 0xffffffbf | 0x20;
          puVar7[0xb5] = fVar3;
          if ((float)puVar7[0xb5] <= 0.0) {
            puVar7[0xb5] = 0;
            puVar7[0x21] = uVar2 & 0xffffff9f;
          }
        }
        FUN_00556190(puVar7);
        iVar5 = FUN_005549e0();
        if ((*(byte *)(puVar7 + 0x2b) & 0x40) == 0) {
          if (iVar5 != -1) {
            if (0.0 < (float)puVar7[0xb6]) {
              puVar7[0xb5] = puVar7[0xb6];
              *(byte *)(puVar7 + 0x2b) = *(byte *)(puVar7 + 0x2b) | 0x40;
              iVar6 = FUN_00553910();
              if (iVar6 != 0) {
                FUN_0054a850(**(undefined4 **)(iVar6 + 0xca4),0x3f4ccccd,0);
              }
            }
            goto LAB_00556c4b;
          }
        }
        else {
LAB_00556c4b:
          if (iVar5 != -1) {
            if (((((float)puVar7[0x24] == 0.0) && ((*(byte *)(puVar7 + 0x2b) & 0x32) == 0)) &&
                ((puVar7[0x21] & 8) != 0)) &&
               (((puVar7[0x21] & 0x400) == 0 || (*(int *)(puVar7[0x1a] + 0xc) != 2)))) {
              FUN_00554ac0(iVar5);
            }
            goto LAB_00556c96;
          }
        }
        *(byte *)(puVar7 + 0x2b) = *(byte *)(puVar7 + 0x2b) & 0xbf;
      }
LAB_00556c96:
      local_5c = local_5c + 0x304;
      local_54 = local_54 + 1;
    } while (local_54 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
  }
  return;
}

