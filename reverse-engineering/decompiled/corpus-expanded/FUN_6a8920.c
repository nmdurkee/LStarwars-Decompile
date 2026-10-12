/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a8920; label: FUN_006a8920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006a8920(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  void *pvVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  size_t asStackY_3c [3];
  int local_10;
  uint *local_c;
  int local_8;
  
  puVar5 = param_2;
  puVar4 = param_1;
  iVar16 = 0;
  asStackY_3c[2] = 0x6a8937;
  _memset(param_1,0,0x2c);
  iVar11 = param_2[1];
  if (0 < iVar11) {
    piVar9 = (int *)param_2[2];
    iVar13 = iVar11;
    do {
      if (0 < *piVar9) {
        iVar16 = iVar16 + 1;
      }
      piVar9 = piVar9 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  param_1[1] = iVar11;
  param_1[2] = iVar16;
  *param_1 = *param_2;
  if (0 < iVar16) {
    asStackY_3c[2] = 0x6a8980;
    puVar6 = (uint *)FUN_006a7fd0();
    iVar11 = iVar16 * -4;
    if (puVar6 == (uint *)0x0) {
      *(undefined4 **)(&stack0xffffffd8 + iVar11) = param_1;
      *(undefined4 *)(&stack0xffffffd4 + iVar11) = 0x6a89a7;
      FUN_006a87e0();
      return 0xffffffff;
    }
    if (0 < iVar16) {
      puVar14 = puVar6;
      param_1 = (undefined4 *)iVar16;
      do {
        uVar12 = *puVar14 << 0x10 | *puVar14 >> 0x10;
        uVar12 = (uVar12 >> 8 ^ uVar12 << 8) & 0xff00ff ^ uVar12 << 8;
        uVar12 = (uVar12 >> 4 ^ uVar12 << 4) & 0xf0f0f0f ^ uVar12 << 4;
        uVar12 = (uVar12 >> 2 ^ uVar12 * 4) & 0x33333333 ^ uVar12 * 4;
        *puVar14 = (uVar12 >> 1 ^ uVar12 * 2) & 0x55555555 ^ uVar12 * 2;
        *(uint **)(&stack0xffffffdc + (iVar11 - (int)puVar6) + (int)puVar14) = puVar14;
        puVar14 = puVar14 + 1;
        param_1 = (undefined4 *)((int)param_1 + -1);
      } while (param_1 != (undefined4 *)0x0);
    }
    *(code **)(&stack0xffffffd8 + iVar11) = FUN_006a8900;
    *(undefined4 *)(&stack0xffffffd4 + iVar11) = 4;
    *(int *)(&stack0xffffffd0 + iVar11) = iVar16;
    asStackY_3c[2 - iVar16] = (size_t)(&stack0xffffffdc + iVar11);
    asStackY_3c[1 - iVar16] = 0x6a8a46;
    _qsort((void *)asStackY_3c[2 - iVar16],*(size_t *)(&stack0xffffffd0 + iVar11),
           *(size_t *)(&stack0xffffffd4 + iVar11),*(_PtFuncCompare **)(&stack0xffffffd8 + iVar11));
    iVar13 = iVar16 * -8;
    piVar9 = (int *)(&stack0xffffffdc + iVar13);
    *(undefined4 *)(&stack0xffffffd8 + iVar11) = 0x6a8a51;
    *(int *)(&stack0xffffffd8 + iVar16 * -8) = iVar16 * 4;
    *(undefined4 *)(&stack0xffffffd4 + iVar16 * -8) = 0x6a8a5d;
    pvVar7 = _malloc(*(size_t *)(&stack0xffffffd8 + iVar16 * -8));
    puVar4[5] = pvVar7;
    iVar8 = 0;
    if (0 < iVar16) {
      do {
        *(int *)(&stack0xffffffdc +
                (*(int *)(&stack0xffffffdc + iVar8 * 4 + iVar11) - (int)puVar6 >> 2) * 4 + iVar13) =
             iVar8;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar16);
      if (0 < iVar16) {
        local_10 = iVar16;
        do {
          iVar11 = *piVar9;
          puVar2 = (undefined4 *)(((int)puVar6 - (int)(&stack0xffffffdc + iVar13)) + (int)piVar9);
          piVar9 = piVar9 + 1;
          local_10 = local_10 + -1;
          *(undefined4 *)(puVar4[5] + iVar11 * 4) = *puVar2;
        } while (local_10 != 0);
      }
    }
    *(uint **)(&stack0xffffffd8 + iVar16 * -8) = puVar6;
    *(undefined4 *)(&stack0xffffffd4 + iVar16 * -8) = 0x6a8ac3;
    _free(*(void **)(&stack0xffffffd8 + iVar16 * -8));
    *(undefined1 **)(&stack0xffffffd4 + iVar16 * -8) = &stack0xffffffdc + iVar13;
    *(int *)(&stack0xffffffd0 + iVar16 * -8) = iVar16;
    asStackY_3c[iVar16 * -2 + 2] = (size_t)param_2;
    asStackY_3c[iVar16 * -2 + 1] = 0x6a8ace;
    uVar10 = FUN_006a81d0();
    asStackY_3c[iVar16 * -2 + 1] = iVar16 * 4;
    puVar4[4] = uVar10;
    asStackY_3c[iVar16 * -2] = 0x6a8ada;
    pvVar7 = _malloc(asStackY_3c[iVar16 * -2 + 1]);
    puVar4[6] = pvVar7;
    iVar11 = 0;
    iVar8 = 0;
    if (0 < (int)param_2[1]) {
      do {
        if (0 < *(int *)(param_2[2] + iVar11 * 4)) {
          *(int *)(puVar4[6] + *(int *)(&stack0xffffffdc + iVar8 * 4 + iVar13) * 4) = iVar11;
          iVar8 = iVar8 + 1;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < (int)param_2[1]);
    }
    *(int *)(&stack0xffffffd8 + iVar16 * -8) = iVar8;
    *(undefined4 *)(&stack0xffffffd4 + iVar16 * -8) = 0x6a8b0f;
    pvVar7 = _malloc(*(size_t *)(&stack0xffffffd8 + iVar16 * -8));
    iVar11 = 0;
    puVar4[7] = pvVar7;
    piVar9 = param_2 + 1;
    param_2 = (undefined4 *)0x0;
    if (0 < *piVar9) {
      do {
        iVar8 = puVar5[2];
        if (0 < *(int *)(iVar8 + iVar11 * 4)) {
          iVar1 = (int)param_2 * 4;
          param_2 = (undefined4 *)((int)param_2 + 1);
          *(undefined1 *)(*(int *)(&stack0xffffffdc + iVar1 + iVar13) + puVar4[7]) =
               *(undefined1 *)(iVar8 + iVar11 * 4);
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < (int)puVar5[1]);
    }
    iVar13 = 0;
    iVar11 = 0;
    for (uVar12 = puVar4[2]; uVar12 != 0; uVar12 = uVar12 >> 1) {
      iVar11 = iVar11 + 1;
    }
    puVar4[9] = iVar11 + -4;
    if (iVar11 + -4 < 5) {
      puVar4[9] = 5;
    }
    if (8 < (int)puVar4[9]) {
      puVar4[9] = 8;
    }
    iVar11 = 1 << ((byte)puVar4[9] & 0x1f);
    *(undefined4 *)(&stack0xffffffd8 + iVar16 * -8) = 4;
    *(int *)(&stack0xffffffd4 + iVar16 * -8) = iVar11;
    *(undefined4 *)(&stack0xffffffd0 + iVar16 * -8) = 0x6a8b8e;
    pvVar7 = _calloc(*(size_t *)(&stack0xffffffd4 + iVar16 * -8),
                     *(size_t *)(&stack0xffffffd8 + iVar16 * -8));
    puVar4[8] = pvVar7;
    puVar4[10] = 0;
    if (0 < (int)param_2) {
      do {
        iVar16 = (int)*(char *)(puVar4[7] + iVar13);
        if ((int)puVar4[10] < iVar16) {
          puVar4[10] = iVar16;
        }
        cVar3 = *(char *)(puVar4[7] + iVar13);
        if ((int)cVar3 <= (int)puVar4[9]) {
          uVar12 = *(uint *)(puVar4[5] + iVar13 * 4);
          uVar12 = uVar12 << 0x10 | uVar12 >> 0x10;
          uVar12 = (uVar12 >> 8 ^ uVar12 << 8) & 0xff00ff ^ uVar12 << 8;
          uVar12 = (uVar12 >> 4 ^ uVar12 << 4) & 0xf0f0f0f ^ uVar12 << 4;
          uVar12 = (uVar12 >> 2 ^ uVar12 * 4) & 0x33333333 ^ uVar12 * 4;
          param_1 = (undefined4 *)0x0;
          if (0 < 1 << ((char)puVar4[9] - cVar3 & 0x1fU)) {
            do {
              *(int *)(puVar4[8] +
                      ((int)param_1 << (*(byte *)(iVar13 + puVar4[7]) & 0x1f) |
                      (uVar12 >> 1 ^ uVar12 * 2) & 0x55555555 ^ uVar12 * 2) * 4) = iVar13 + 1;
              param_1 = (undefined4 *)((int)param_1 + 1);
            } while ((int)param_1 < 1 << ((char)puVar4[9] - *(char *)(iVar13 + puVar4[7]) & 0x1fU));
          }
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < (int)param_2);
    }
    uVar10 = puVar4[9];
    param_1 = (undefined4 *)0x0;
    local_8 = 0;
    local_10 = 0;
    if (0 < iVar11) {
      do {
        uVar17 = local_10 << (0x20U - (char)puVar4[9] & 0x1f);
        uVar15 = uVar17 << 0x10 | uVar17 >> 0x10;
        uVar12 = (uVar15 >> 8 ^ uVar15 << 8) & 0xff00ff ^ uVar15 << 8;
        uVar12 = (uVar12 >> 4 ^ uVar12 << 4) & 0xf0f0f0f ^ uVar12 << 4;
        uVar12 = (uVar12 >> 2 ^ uVar12 * 4) & 0x33333333 ^ uVar12 * 4;
        if (*(int *)(puVar4[8] + ((uVar12 >> 1 ^ uVar12 * 2) & 0x55555555 ^ uVar12 * 2) * 4) == 0) {
          iVar16 = (int)param_1 + 1;
          if (iVar16 < (int)param_2) {
            local_c = (uint *)(puVar4[5] + 4 + (int)param_1 * 4);
            do {
              if (uVar17 < *local_c) break;
              param_1 = (undefined4 *)((int)param_1 + 1);
              local_c = local_c + 1;
              iVar16 = iVar16 + 1;
            } while (iVar16 < (int)param_2);
          }
          if (local_8 < (int)param_2) {
            local_c = (uint *)(puVar4[5] + local_8 * 4);
            do {
              if (uVar17 < (*local_c & -2 << (0x1fU - (char)uVar10 & 0x1f))) break;
              local_c = local_c + 1;
              local_8 = local_8 + 1;
            } while (local_8 < (int)param_2);
          }
          uVar17 = (int)param_2 - local_8;
          uVar12 = (uint)param_1;
          if (0x7fff < param_1) {
            uVar12 = 0x7fff;
          }
          if (0x7fff < uVar17) {
            uVar17 = 0x7fff;
          }
          uVar15 = (uVar15 >> 8 ^ uVar15 << 8) & 0xff00ff ^ uVar15 << 8;
          uVar15 = (uVar15 >> 4 ^ uVar15 << 4) & 0xf0f0f0f ^ uVar15 << 4;
          uVar15 = (uVar15 >> 2 ^ uVar15 * 4) & 0x33333333 ^ uVar15 * 4;
          *(uint *)(puVar4[8] + ((uVar15 >> 1 ^ uVar15 * 2) & 0x55555555 ^ uVar15 * 2) * 4) =
               (uVar12 | 0xffff0000) << 0xf | uVar17;
        }
        local_10 = local_10 + 1;
      } while (local_10 < iVar11);
    }
  }
  return 0;
}

