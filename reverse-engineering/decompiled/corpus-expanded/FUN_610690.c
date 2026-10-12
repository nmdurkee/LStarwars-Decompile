/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610690; label: FUN_00610690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00610690(byte *param_1,uint param_2,char *param_3)

{
  uint uVar1;
  byte *pbVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char cVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  undefined4 *puVar16;
  uint uVar17;
  byte *pbVar18;
  uint local_2c;
  byte *local_28;
  uint local_24;
  byte *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  puVar16 = DAT_028fec0c;
  for (iVar9 = 0x10000; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar16 = 0xffffffff;
    puVar16 = puVar16 + 1;
  }
  uVar13 = 0;
  local_20 = param_1;
  local_28 = param_1;
  local_2c = 0;
  pcVar15 = param_3;
  if (0 < (int)param_2) {
    do {
      uVar14 = 2;
      local_24 = 0;
      local_18 = 2;
      local_14 = param_2;
      if (0x403 < (int)param_2) {
        local_14 = 0x404;
      }
      uVar6 = *(uint *)(&DAT_0080ed78 + (uint)*local_20 * 4) >> 8 ^
              *(uint *)(&DAT_0080ed78 +
                       ((uint)local_20[1] ^ *(uint *)(&DAT_0080ed78 + (uint)*local_20 * 4) & 0xff) *
                       4);
      uVar7 = uVar6 >> 8 ^ *(uint *)(&DAT_0080ed78 + ((uint)local_20[2] ^ uVar6 & 0xff) * 4);
      uVar6 = DAT_028fec0c[uVar7];
      uVar17 = (int)local_20 - (int)param_1;
      uVar10 = ((int)(uVar17 - 0x3fff) < 1) - 1 & uVar17 - 0x3fff;
      local_1c = uVar6;
      if ((int)uVar6 < (int)uVar10) {
LAB_0061083c:
        *(uint *)(DAT_028fec08 + (uVar17 & 0x3fff) * 4) = uVar6;
        uVar13 = uVar13 + 1;
        local_20 = local_20 + 1;
        param_2 = param_2 - 1;
        DAT_028fec0c[uVar7] = uVar17;
        local_2c = uVar13;
      }
      else {
        do {
          pbVar18 = param_1 + local_1c;
          if ((local_20[uVar14] == pbVar18[uVar14]) && (uVar8 = 0, local_14 != 0)) {
            iVar9 = (int)local_20 - (int)pbVar18;
            do {
              pbVar2 = pbVar18 + iVar9;
              bVar3 = *pbVar18;
              pbVar18 = pbVar18 + 1;
              if (*pbVar2 != bVar3) break;
              uVar8 = uVar8 + 1;
            } while (uVar8 < local_14);
            uVar13 = local_2c;
            if (uVar14 < uVar8) {
              uVar1 = iVar9 - 1;
              if ((uVar1 < 0x400) && (uVar8 < 0xb)) {
                uVar11 = 2;
              }
              else if ((0x3fff < uVar1) || (uVar11 = 3, 0x43 < uVar8)) {
                uVar11 = 4;
              }
              if (((uVar14 - local_18) + 4 < (uVar8 - uVar11) + 4) &&
                 (uVar14 = uVar8, local_24 = uVar1, local_18 = uVar11, 0x403 < uVar8)) break;
            }
          }
          uVar8 = uVar14;
          local_1c = *(uint *)(DAT_028fec08 + (local_1c & 0x3fff) * 4);
          uVar14 = uVar8;
        } while ((int)uVar10 <= (int)local_1c);
        if (uVar8 <= local_18) goto LAB_0061083c;
        while (3 < uVar13) {
          uVar14 = uVar13 & 0xfffffffc;
          if (0x70 < uVar14) {
            uVar14 = 0x70;
          }
          *pcVar15 = (char)(uVar14 >> 2) + -0x21;
          FUN_004ef660(pcVar15 + 1,local_28,uVar14);
          local_28 = local_28 + uVar14;
          pcVar15 = pcVar15 + 1 + uVar14;
          uVar13 = uVar13 - uVar14;
          local_2c = uVar13;
        }
        cVar12 = (char)uVar13;
        cVar4 = (char)uVar8;
        if (local_18 == 2) {
          *pcVar15 = ((byte)(local_24 >> 3) & 0xe0) + (cVar4 + -3) * '\x04' + cVar12;
        }
        else {
          cVar5 = (char)(local_24 >> 8);
          if (local_18 == 3) {
            *pcVar15 = cVar4 + '|';
            pcVar15 = pcVar15 + 1;
            *pcVar15 = cVar5 + cVar12 * '@';
          }
          else {
            *pcVar15 = ((byte)(uVar8 - 5 >> 6) & 0xfc) + ((byte)(local_24 >> 0xc) & 0xf0) + cVar12 +
                       -0x40;
            pcVar15[1] = cVar5;
            pcVar15 = pcVar15 + 2;
            *pcVar15 = (char)local_24;
            local_24._0_1_ = cVar4 + -5;
          }
        }
        pcVar15[1] = (char)local_24;
        pcVar15 = pcVar15 + 2;
        if (uVar13 != 0) {
          FUN_004ef660(pcVar15,local_28,uVar13);
          pcVar15 = pcVar15 + local_2c;
          local_2c = 0;
        }
        uVar13 = 0;
        *(undefined4 *)(DAT_028fec08 + (uVar17 & 0x3fff) * 4) = DAT_028fec0c[uVar7];
        local_20 = local_20 + uVar8;
        param_2 = param_2 - uVar8;
        DAT_028fec0c[uVar7] = uVar17;
        local_28 = local_20;
      }
    } while (0 < (int)param_2);
    while (3 < uVar13) {
      uVar14 = uVar13 & 0xfffffffc;
      if (0x70 < uVar14) {
        uVar14 = 0x70;
      }
      *pcVar15 = (char)(uVar14 >> 2) + -0x21;
      FUN_004ef660(pcVar15 + 1,local_28,uVar14);
      local_28 = local_28 + uVar14;
      pcVar15 = pcVar15 + 1 + uVar14;
      uVar13 = uVar13 - uVar14;
      local_2c = uVar13;
    }
  }
  *pcVar15 = (char)uVar13 + -4;
  pcVar15 = pcVar15 + 1;
  if (uVar13 != 0) {
    FUN_004ef660(pcVar15,local_28,uVar13);
    pcVar15 = pcVar15 + local_2c;
  }
  return (int)pcVar15 - (int)param_3;
}

