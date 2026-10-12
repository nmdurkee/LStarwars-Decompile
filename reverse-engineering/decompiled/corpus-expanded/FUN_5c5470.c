/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c5470; label: FUN_005c5470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005c5470(undefined4 param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint in_EAX;
  undefined2 extraout_var;
  undefined2 uVar13;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int *in_ECX;
  uint uVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  int local_a0;
  uint local_9c;
  int local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_78;
  uint local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int *local_5c;
  double local_58;
  float local_50;
  float local_4c;
  undefined1 local_40 [8];
  float local_38;
  undefined1 local_30 [16];
  undefined1 local_20 [28];
  
  if ((char)in_ECX[4] != '\0') {
    local_5c = in_ECX;
    FUN_005b3ec0(&local_90,param_1,in_ECX + 8);
    in_EAX = CONCAT22(extraout_var,
                      (ushort)(param_2 < local_84) << 8 |
                      (ushort)(NAN(param_2) || NAN(local_84)) << 10 |
                      (ushort)(param_2 == local_84) << 0xe);
    if (param_2 < local_84 || (param_2 == local_84) != 0) {
      in_EAX = in_ECX[3];
      fVar4 = local_90 / local_84;
      local_9c = 100;
      fVar5 = local_8c / local_84;
      local_88 = local_88 / local_84;
      fVar6 = param_2 / local_84;
      if ((int)in_EAX < 0x65) {
        local_9c = in_EAX;
      }
      local_74 = 0;
      fVar7 = local_84;
      local_90 = fVar4;
      local_8c = fVar5;
      local_78 = fVar6;
      if (local_9c != 0) {
        do {
          in_EAX = in_ECX[1];
          iVar16 = *(int *)(in_EAX + local_74 * 4);
          if (iVar16 != -1) {
            iVar16 = iVar16 * 0xa0 + *in_ECX;
            fVar2 = *(float *)(iVar16 + 0x94);
            fVar8 = (fVar7 - param_2) - 2.0;
            uVar13 = (undefined2)(in_EAX >> 0x10);
            in_EAX = CONCAT22(uVar13,(ushort)(fVar8 < fVar2) << 8 |
                                     (ushort)(NAN(fVar8) || NAN(fVar2)) << 10 |
                                     (ushort)(fVar8 == fVar2) << 0xe);
            if (fVar8 < fVar2) break;
            fVar8 = fVar4 - fVar6;
            fVar2 = *(float *)(iVar16 + 0x84);
            in_EAX = CONCAT22(uVar13,(ushort)(fVar2 < fVar8) << 8 |
                                     (ushort)(NAN(fVar2) || NAN(fVar8)) << 10 |
                                     (ushort)(fVar2 == fVar8) << 0xe);
            if (fVar2 >= fVar8) {
              fVar8 = fVar5 - fVar6;
              fVar2 = *(float *)(iVar16 + 0x8c);
              in_EAX = CONCAT22(uVar13,(ushort)(fVar2 < fVar8) << 8 |
                                       (ushort)(NAN(fVar2) || NAN(fVar8)) << 10 |
                                       (ushort)(fVar2 == fVar8) << 0xe);
              if (fVar2 >= fVar8) {
                fVar8 = fVar6 + fVar4;
                fVar2 = *(float *)(iVar16 + 0x80);
                in_EAX = CONCAT22(uVar13,(ushort)(fVar2 < fVar8) << 8 |
                                         (ushort)(NAN(fVar2) || NAN(fVar8)) << 10 |
                                         (ushort)(fVar2 == fVar8) << 0xe);
                if (fVar2 < fVar8 || (fVar2 == fVar8) != 0) {
                  fVar8 = fVar6 + fVar5;
                  fVar2 = *(float *)(iVar16 + 0x88);
                  in_EAX = CONCAT22(uVar13,(ushort)(fVar2 < fVar8) << 8 |
                                           (ushort)(NAN(fVar2) || NAN(fVar8)) << 10 |
                                           (ushort)(fVar2 == fVar8) << 0xe);
                  if (fVar2 < fVar8 || (fVar2 == fVar8) != 0) {
                    uVar9 = FUN_005c1e50(local_30,iVar16 + 0x40);
                    uVar10 = FUN_005c1e50(local_20,iVar16 + 0x40);
                    FUN_005b3920(local_40,uVar10,uVar9);
                    bVar3 = local_38 <= 0.0;
                    local_94 = 0;
                    local_a0 = 0x30;
                    local_58 = 0.0;
                    uVar14 = 1;
                    while( true ) {
                      local_64 = 0;
                      local_68 = 0;
                      uVar11 = uVar14 & 0x80000003;
                      if ((int)uVar11 < 0) {
                        uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
                      }
                      iVar15 = local_94;
                      if (bVar3) {
                        uVar11 = 3 - uVar11;
                        iVar15 = local_a0;
                      }
                      iVar12 = (uVar11 + 4) * 0x10;
                      local_70 = *(float *)(iVar12 + 4 + iVar16) -
                                 *(float *)(iVar15 + 0x44 + iVar16);
                      pfVar1 = (float *)(iVar15 + 0x44 + iVar16);
                      local_6c = -(*(float *)(iVar12 + iVar16) - *(float *)(iVar15 + 0x40 + iVar16))
                      ;
                      FUN_005b3b30(&local_70,&local_70);
                      local_64 = 0;
                      local_68 = 0;
                      local_50 = local_90 - *(float *)(iVar15 + 0x40 + iVar16);
                      local_4c = local_8c - *pfVar1;
                      fVar2 = (local_4c * local_6c + local_70 * local_50 + (float)local_58) -
                              local_78;
                      in_EAX = CONCAT22((short)((uint)pfVar1 >> 0x10),
                                        (ushort)(fVar2 < 0.0) << 8 | (ushort)NAN(fVar2) << 10 |
                                        (ushort)(fVar2 == 0.0) << 0xe);
                      in_ECX = local_5c;
                      fVar7 = local_84;
                      fVar5 = local_8c;
                      fVar4 = local_90;
                      fVar6 = local_78;
                      if (fVar2 < 0.0) break;
                      local_94 = local_94 + 0x10;
                      local_a0 = local_a0 + -0x10;
                      bVar17 = uVar14 == 4;
                      uVar14 = uVar14 + 1;
                      if (bVar17) {
                        return 1;
                      }
                    }
                  }
                }
              }
            }
          }
          local_74 = local_74 + 1;
        } while (local_74 != local_9c);
      }
    }
  }
  return in_EAX & 0xffffff00;
}

