/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x7104e5; label: __ld12cvt
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __ld12cvt
   
   Library: Visual Studio 2005 Release */

undefined4 __ld12cvt(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  byte bVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  uint local_24 [4];
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_24[3] = param_1[5] & 0x8000;
  uVar9 = *(uint *)(param_1 + 3);
  local_24[0] = uVar9;
  uVar2 = *(uint *)(param_1 + 1);
  uVar1 = *param_1;
  uVar10 = param_1[5] & 0x7fff;
  iVar11 = uVar10 - 0x3fff;
  local_24[1] = uVar2;
  local_24[2] = (uint)uVar1 << 0x10;
  if (iVar11 == -0x3fff) {
    iVar11 = 0;
    iVar3 = 0;
    do {
      if (local_24[iVar3] != 0) goto LAB_00710655;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
LAB_007109cb:
    uVar5 = 0;
  }
  else {
    param_1 = (ushort *)0x0;
    uVar8 = param_3[2];
    iVar12 = uVar8 - 1;
    iVar3 = (int)(uVar8 + ((int)uVar8 >> 0x1f & 0x1fU)) >> 5;
    uVar8 = uVar8 & 0x8000001f;
    local_14 = iVar11;
    local_10 = iVar3;
    if ((int)uVar8 < 0) {
      uVar8 = (uVar8 - 1 | 0xffffffe0) + 1;
    }
    puVar4 = local_24 + iVar3;
    bVar6 = (byte)(0x1f - uVar8);
    local_c = 0x1f - uVar8;
    if ((*puVar4 & 1 << (bVar6 & 0x1f)) != 0) {
      uVar8 = local_24[iVar3] & ~(-1 << (bVar6 & 0x1f));
      while( true ) {
        if (uVar8 != 0) {
          iVar3 = (int)(iVar12 + (iVar12 >> 0x1f & 0x1fU)) >> 5;
          local_8 = 0;
          uVar8 = 1 << (0x1f - ((byte)iVar12 & 0x1f) & 0x1f);
          puVar7 = local_24 + iVar3;
          param_1 = (ushort *)(*puVar7 + uVar8);
          if (param_1 < *puVar7) goto LAB_0071060a;
          bVar13 = param_1 < uVar8;
          do {
            local_8 = 0;
            if (!bVar13) goto LAB_00710611;
LAB_0071060a:
            do {
              local_8 = 1;
LAB_00710611:
              iVar3 = iVar3 + -1;
              *puVar7 = (uint)param_1;
              if ((iVar3 < 0) || (local_8 == 0)) {
                param_1 = (ushort *)local_8;
                goto LAB_0071061f;
              }
              local_8 = 0;
              puVar7 = local_24 + iVar3;
              param_1 = (ushort *)(*puVar7 + 1);
            } while (param_1 < *puVar7);
            bVar13 = param_1 == (ushort *)0x0;
          } while( true );
        }
        iVar3 = iVar3 + 1;
        if (2 < iVar3) break;
        uVar8 = local_24[iVar3];
      }
    }
LAB_0071061f:
    *puVar4 = *puVar4 & -1 << ((byte)local_c & 0x1f);
    iVar3 = local_10 + 1;
    if (iVar3 < 3) {
      puVar4 = local_24 + iVar3;
      for (iVar12 = 3 - iVar3; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    if (param_1 != (ushort *)0x0) {
      iVar11 = uVar10 - 0x3ffe;
    }
    iVar3 = param_3[1];
    if (iVar11 < iVar3 - param_3[2]) {
LAB_00710655:
      local_24[0] = 0;
      local_24[1] = 0;
    }
    else {
      if (iVar3 < iVar11) {
        if (*param_3 <= iVar11) {
          local_24[1] = 0;
          local_24[2] = 0;
          local_24[0] = 0x80000000;
          uVar9 = param_3[3];
          iVar11 = (int)(uVar9 + ((int)uVar9 >> 0x1f & 0x1fU)) >> 5;
          uVar9 = uVar9 & 0x8000001f;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xffffffe0) + 1;
          }
          local_10 = 0;
          param_1 = (ushort *)0x0;
          local_8 = 0x20 - uVar9;
          do {
            uVar2 = local_24[(int)param_1];
            local_14 = uVar2 & ~(-1 << ((byte)uVar9 & 0x1f));
            local_24[(int)param_1] = uVar2 >> ((byte)uVar9 & 0x1f) | local_10;
            param_1 = (ushort *)((int)param_1 + 1);
            local_10 = local_14 << ((byte)(0x20 - uVar9) & 0x1f);
          } while ((int)param_1 < 3);
          iVar3 = 2;
          puVar4 = local_24 + (2 - iVar11);
          do {
            if (iVar3 < iVar11) {
              local_24[iVar3] = 0;
            }
            else {
              local_24[iVar3] = *puVar4;
            }
            iVar3 = iVar3 + -1;
            puVar4 = puVar4 + -1;
          } while (-1 < iVar3);
          iVar11 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_007109cd;
        }
        local_24[0] = local_24[0] & 0x7fffffff;
        uVar9 = param_3[3];
        iVar11 = param_3[5] + iVar11;
        iVar3 = (int)(uVar9 + ((int)uVar9 >> 0x1f & 0x1fU)) >> 5;
        uVar9 = uVar9 & 0x8000001f;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xffffffe0) + 1;
        }
        local_10 = 0;
        param_1 = (ushort *)0x0;
        local_8 = 0x20 - uVar9;
        do {
          local_14 = local_24[(int)param_1] & ~(-1 << ((byte)uVar9 & 0x1f));
          local_24[(int)param_1] = local_24[(int)param_1] >> ((byte)uVar9 & 0x1f) | local_10;
          param_1 = (ushort *)((int)param_1 + 1);
          local_10 = local_14 << ((byte)(0x20 - uVar9) & 0x1f);
        } while ((int)param_1 < 3);
        iVar12 = 2;
        puVar4 = local_24 + (2 - iVar3);
        do {
          if (iVar12 < iVar3) {
            local_24[iVar12] = 0;
          }
          else {
            local_24[iVar12] = *puVar4;
          }
          iVar12 = iVar12 + -1;
          puVar4 = puVar4 + -1;
        } while (-1 < iVar12);
        goto LAB_007109cb;
      }
      local_14 = iVar3 - local_14;
      local_24[0] = uVar9;
      local_24[1] = uVar2;
      iVar11 = (int)(local_14 + ((int)local_14 >> 0x1f & 0x1fU)) >> 5;
      uVar9 = local_14 & 0x8000001f;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xffffffe0) + 1;
      }
      local_10 = 0;
      param_1 = (ushort *)0x0;
      local_8 = 0x20 - uVar9;
      do {
        uVar2 = local_24[(int)param_1];
        local_14 = uVar2 & ~(-1 << ((byte)uVar9 & 0x1f));
        local_24[(int)param_1] = uVar2 >> ((byte)uVar9 & 0x1f) | local_10;
        param_1 = (ushort *)((int)param_1 + 1);
        local_10 = local_14 << ((byte)(0x20 - uVar9) & 0x1f);
      } while ((int)param_1 < 3);
      iVar3 = 2;
      puVar4 = local_24 + (2 - iVar11);
      do {
        if (iVar3 < iVar11) {
          local_24[iVar3] = 0;
        }
        else {
          local_24[iVar3] = *puVar4;
        }
        iVar3 = iVar3 + -1;
        puVar4 = puVar4 + -1;
      } while (-1 < iVar3);
      uVar9 = param_3[2];
      iVar3 = uVar9 - 1;
      iVar11 = (int)(uVar9 + ((int)uVar9 >> 0x1f & 0x1fU)) >> 5;
      uVar9 = uVar9 & 0x8000001f;
      local_10 = iVar11;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xffffffe0) + 1;
      }
      bVar6 = (byte)(0x1f - uVar9);
      puVar4 = local_24 + iVar11;
      local_14 = 0x1f - uVar9;
      if ((*puVar4 & 1 << (bVar6 & 0x1f)) != 0) {
        uVar9 = local_24[iVar11] & ~(-1 << (bVar6 & 0x1f));
        while (uVar9 == 0) {
          iVar11 = iVar11 + 1;
          if (2 < iVar11) goto LAB_007107c0;
          uVar9 = local_24[iVar11];
        }
        iVar11 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        bVar13 = false;
        uVar10 = 1 << (0x1f - ((byte)iVar3 & 0x1f) & 0x1f);
        uVar2 = local_24[iVar11];
        uVar9 = uVar2 + uVar10;
        if ((uVar9 < uVar2) || (uVar9 < uVar10)) {
          bVar13 = true;
        }
        local_24[iVar11] = uVar9;
        while ((iVar11 = iVar11 + -1, -1 < iVar11 && (bVar13))) {
          uVar2 = local_24[iVar11];
          uVar9 = uVar2 + 1;
          bVar13 = false;
          if ((uVar9 < uVar2) || (uVar9 == 0)) {
            bVar13 = true;
          }
          local_24[iVar11] = uVar9;
        }
      }
LAB_007107c0:
      *puVar4 = *puVar4 & -1 << ((byte)local_14 & 0x1f);
      iVar11 = local_10 + 1;
      if (iVar11 < 3) {
        puVar4 = local_24 + iVar11;
        for (iVar3 = 3 - iVar11; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
      }
      uVar9 = param_3[3] + 1;
      iVar11 = (int)(uVar9 + ((int)uVar9 >> 0x1f & 0x1fU)) >> 5;
      uVar9 = uVar9 & 0x8000001f;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xffffffe0) + 1;
      }
      local_10 = 0;
      param_1 = (ushort *)0x0;
      local_8 = 0x20 - uVar9;
      do {
        uVar2 = local_24[(int)param_1];
        local_14 = uVar2 & ~(-1 << ((byte)uVar9 & 0x1f));
        local_24[(int)param_1] = uVar2 >> ((byte)uVar9 & 0x1f) | local_10;
        param_1 = (ushort *)((int)param_1 + 1);
        local_10 = local_14 << ((byte)(0x20 - uVar9) & 0x1f);
      } while ((int)param_1 < 3);
      iVar3 = 2;
      puVar4 = local_24 + (2 - iVar11);
      do {
        if (iVar3 < iVar11) {
          local_24[iVar3] = 0;
        }
        else {
          local_24[iVar3] = *puVar4;
        }
        iVar3 = iVar3 + -1;
        puVar4 = puVar4 + -1;
      } while (-1 < iVar3);
    }
    iVar11 = 0;
    uVar5 = 2;
  }
LAB_007109cd:
  local_24[0] = iVar11 << (0x1fU - (char)param_3[3] & 0x1f) | -(uint)(local_24[3] != 0) & 0x80000000
                | local_24[0];
  if (param_3[4] == 0x40) {
    param_2[1] = local_24[0];
    *param_2 = local_24[1];
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_24[0];
  }
  return uVar5;
}

