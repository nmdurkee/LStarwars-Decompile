/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x526800; label: FUN_00526800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x00526b9d) */
/* WARNING: Removing unreachable block (ram,0x00526bc2) */

void FUN_00526800(int *param_1,uint *param_2)

{
  size_t sVar1;
  undefined4 *puVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  ushort uVar10;
  uint uVar11;
  char *pcVar12;
  int in_ECX;
  int iVar13;
  uint uVar14;
  int in_EDX;
  byte *pbVar15;
  int iVar16;
  ushort *puVar17;
  void *_Dst;
  void *pvVar18;
  char *pcVar19;
  int iVar20;
  undefined8 uVar21;
  ushort *local_274;
  int local_270;
  int local_26c;
  int local_268;
  uint *local_264;
  int local_260;
  int local_25c;
  int local_258;
  int *local_254;
  undefined8 local_250;
  undefined4 local_248;
  uint local_244;
  undefined1 local_240 [60];
  byte local_204;
  undefined4 local_203;
  undefined4 local_1ff;
  undefined4 local_1fb;
  undefined4 local_1f7;
  undefined4 local_1f3;
  undefined4 local_1ef;
  undefined4 local_1eb;
  undefined2 local_1e7;
  undefined1 local_1e5;
  undefined1 local_1e4 [480];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_274;
  local_254 = param_1;
  local_264 = param_2;
  local_244 = 0;
  local_268 = in_ECX;
  local_260 = in_EDX;
  _memset(local_240,0,0x3c);
  local_204 = 0;
  local_203 = 0;
  local_1ff = 0;
  local_1fb = 0;
  local_1f7 = 0;
  local_1f3 = 0;
  local_1ef = 0;
  local_1eb = 0;
  local_1e7 = 0;
  local_1e5 = 0;
  _memset(local_1e4,0,0x1e0);
  iVar13 = 0;
  pbVar15 = (byte *)(in_EDX + 0x58);
  do {
    if ((*pbVar15 & 1) != 0) {
      bVar3 = *(byte *)(in_ECX + 0x14);
      *(uint *)(local_240 + iVar13 * 4 + -4) = (uint)bVar3;
      *(byte *)(in_ECX + 0x14) = bVar3 + 1;
    }
    iVar13 = iVar13 + 1;
    pbVar15 = pbVar15 + 0x20;
  } while (iVar13 < 0x10);
  if (*(byte *)(in_ECX + 0x14) != 0) {
    sVar1 = (uint)*(byte *)(in_ECX + 0x14) * 0x28;
    pvVar18 = (void *)0x0;
    if (((param_1 == (int *)0x0) || (param_2 == (uint *)0x0)) || (*param_2 <= *param_1 + sVar1)) {
      FUN_00512850();
    }
    else {
      uVar11 = *param_1 + 0xf;
      pvVar18 = (void *)(uVar11 & 0xfffffff0);
      *param_1 = (uVar11 & 0xfffffff0) + sVar1;
      _memset(pvVar18,0,sVar1);
    }
    *(void **)(in_ECX + 0x88) = pvVar18;
    _memset(pvVar18,0,(uint)*(byte *)(in_ECX + 0x14) * 0x28);
    local_270 = 0;
    pcVar19 = (char *)(local_260 + 0x40);
    do {
      piVar9 = local_254;
      if ((pcVar19[0x18] & 1U) != 0) {
        puVar2 = (undefined4 *)
                 (*(int *)(local_268 + 0x88) + *(int *)(local_240 + local_270 * 4 + -4) * 0x28);
        pcVar12 = pcVar19;
        do {
          cVar4 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar4 != '\0');
        if ((int)pcVar12 - (int)(pcVar19 + 1) != 0) {
          pvVar18 = (void *)0x0;
          sVar1 = ((int)pcVar12 - (int)(pcVar19 + 1)) + 1;
          if ((param_1 == (int *)0x0) || (local_264 == (uint *)0x0)) {
            FUN_00512850();
          }
          else if (*param_1 + sVar1 < *local_264) {
            uVar11 = *param_1 + 0xf;
            pvVar18 = (void *)(uVar11 & 0xfffffff0);
            *local_254 = (uVar11 & 0xfffffff0) + sVar1;
            _memset(pvVar18,0,sVar1);
            param_1 = piVar9;
          }
          else {
            FUN_00512850();
            param_1 = local_254;
          }
          *puVar2 = pvVar18;
          pcVar12 = pcVar19;
          do {
            cVar4 = *pcVar12;
            pcVar12[(int)pvVar18 - (int)pcVar19] = cVar4;
            pcVar12 = pcVar12 + 1;
          } while (cVar4 != '\0');
        }
        puVar2[6] = *(undefined4 *)(pcVar19 + 0x10);
        uVar11 = *(uint *)(pcVar19 + 0x14);
        puVar2[7] = uVar11;
        if ((uVar11 & 0x80000000) != 0) {
          puVar2[6] = 0xffffffff;
          puVar2[7] = 0xffffffff;
        }
        puVar2[8] = *(undefined4 *)(pcVar19 + 0x10);
        puVar2[9] = *(undefined4 *)(pcVar19 + 0x14);
      }
      local_270 = local_270 + 1;
      pcVar19 = pcVar19 + 0x20;
    } while (local_270 < 0x10);
    local_258 = local_260 + 0x18;
    iVar13 = FUN_004f1440(local_258);
    while (iVar13 != 0) {
      iVar16 = *(short *)(iVar13 + 0x90) * 0x5c + *(int *)(local_268 + 0x7c);
      local_270 = iVar16;
      local_25c = iVar13;
      if (*(short *)(iVar13 + 0x96) != 0) {
        iVar20 = 0;
        do {
          uVar10 = __allshl();
          if ((uVar10 & *(ushort *)(iVar13 + 0x96)) != 0) {
            uVar10 = __allshl();
            *(ushort *)(iVar16 + 0x5a) = *(ushort *)(iVar16 + 0x5a) | uVar10;
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 < 0x10);
      }
      local_274 = (ushort *)(iVar13 + 0x38);
      local_260 = 8;
      do {
        if (((*(int *)(local_274 + -4) != 0) && (*local_274 != 0)) &&
           (iVar13 = 0, *(char *)(local_270 + 0x28) != '\0')) {
          iVar16 = *(int *)(local_270 + 0x34);
          do {
            iVar20 = *(int *)(iVar16 + iVar13 * 4);
            if (((ushort)*(byte *)(iVar20 + 0x10) == *(ushort *)(*(int *)(local_274 + -4) + 0x90))
               || ((ushort)*(byte *)(iVar20 + 0x11) == *(ushort *)(*(int *)(local_274 + -4) + 0x90))
               ) {
              local_26c = 0;
              do {
                iVar20 = local_26c;
                uVar10 = __allshl();
                if ((uVar10 & *local_274) != 0) {
                  iVar6 = *(int *)(local_240 + iVar20 * 4 + -4);
                  uVar10 = __allshl();
                  iVar20 = local_26c;
                  if ((*(ushort *)(*(int *)(iVar16 + iVar13 * 4) + 0x14) & uVar10) == 0) {
                    puVar17 = (ushort *)(*(int *)(iVar16 + iVar13 * 4) + 0x14);
                    *puVar17 = *puVar17 | uVar10;
                    iVar16 = *(int *)(local_270 + 0x34);
                    iVar7 = *(int *)(iVar16 + iVar13 * 4);
                    bVar3 = *(byte *)(iVar7 + 0x10);
                    bVar5 = *(byte *)(iVar7 + 0x11);
                    (&local_204)[(uint)(bVar3 >> 3) + iVar6 * 0x20] =
                         (&local_204)[(uint)(bVar3 >> 3) + iVar6 * 0x20] | '\x01' << (bVar3 & 7);
                    (&local_204)[(uint)(bVar5 >> 3) + iVar6 * 0x20] =
                         (&local_204)[(uint)(bVar5 >> 3) + iVar6 * 0x20] | '\x01' << (bVar5 & 7);
                  }
                }
                local_26c = iVar20 + 1;
              } while (local_26c < 0x10);
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 < (int)(uint)*(byte *)(local_270 + 0x28));
        }
        local_274 = local_274 + 6;
        local_260 = local_260 + -1;
      } while (local_260 != 0);
      iVar13 = FUN_004f1460(local_258,local_25c);
    }
    local_270 = 0;
    local_25c = 0;
    if (*(char *)(local_268 + 0x14) != '\0') {
      local_25c = 0;
      local_260 = 0;
      uVar21 = local_250;
      do {
        iVar13 = local_268;
        iVar16 = *(int *)(local_268 + 0x88) + local_260;
        uVar11 = 0;
        if (*(char *)(local_268 + 0x10) != '\0') {
          local_250 = uVar21;
          uVar21 = __allshl();
          iVar20 = 0;
          do {
            uVar14 = uVar11 & 0x80000007;
            if ((int)uVar14 < 0) {
              uVar14 = (uVar14 - 1 | 0xfffffff8) + 1;
            }
            local_258 = 1 << ((byte)uVar14 & 0x1f);
            if (((&local_204)[((int)(uVar11 + ((int)uVar11 >> 0x1f & 7U)) >> 3) + local_25c] &
                (byte)local_258) != 0) {
              *(char *)(iVar16 + 0x10) = *(char *)(iVar16 + 0x10) + '\x01';
            }
            if (((uint)*(ushort *)(iVar20 + 0x5a + *(int *)(iVar13 + 0x7c)) & (uint)uVar21) != 0) {
              *(char *)(iVar16 + 0x11) = *(char *)(iVar16 + 0x11) + '\x01';
            }
            uVar11 = uVar11 + 1;
            iVar20 = iVar20 + 0x5c;
          } while ((int)uVar11 < (int)(uint)*(byte *)(iVar13 + 0x10));
        }
        piVar9 = local_254;
        local_250 = uVar21;
        if (*(byte *)(iVar13 + 0x10) != 0) {
          pvVar18 = (void *)0x0;
          uVar11 = (uint)*(byte *)(iVar13 + 0x10);
          if (((local_254 == (int *)0x0) || (local_264 == (uint *)0x0)) ||
             (*local_264 <= *local_254 + uVar11)) {
            FUN_00512850();
          }
          else {
            pvVar18 = (void *)(*local_254 + 0xfU & 0xfffffff0);
            *local_254 = (*local_254 + 0xfU & 0xfffffff0) + uVar11;
            _memset(pvVar18,0,uVar11);
          }
          *(void **)(iVar16 + 4) = pvVar18;
          _memset(pvVar18,0,(uint)*(byte *)(iVar13 + 0x10));
        }
        if (*(byte *)(iVar16 + 0x10) != 0) {
          pvVar18 = (void *)0x0;
          uVar11 = (uint)*(byte *)(iVar16 + 0x10);
          if (((piVar9 == (int *)0x0) || (local_264 == (uint *)0x0)) ||
             (*local_264 <= *piVar9 + uVar11)) {
            FUN_00512850();
          }
          else {
            uVar14 = *piVar9 + 0xf;
            pvVar18 = (void *)(uVar14 & 0xfffffff0);
            *piVar9 = (uVar14 & 0xfffffff0) + uVar11;
            _memset(pvVar18,0,uVar11);
          }
          *(void **)(iVar16 + 8) = pvVar18;
          _memset(pvVar18,0,(uint)*(byte *)(iVar16 + 0x10));
        }
        if (*(byte *)(iVar16 + 0x11) != 0) {
          pvVar18 = (void *)0x0;
          uVar11 = (uint)*(byte *)(iVar16 + 0x11);
          if (((piVar9 == (int *)0x0) || (local_264 == (uint *)0x0)) ||
             (*local_264 <= *piVar9 + uVar11)) {
            FUN_00512850();
          }
          else {
            uVar14 = *piVar9 + 0xf;
            pvVar18 = (void *)(uVar14 & 0xfffffff0);
            *piVar9 = (uVar14 & 0xfffffff0) + uVar11;
            _memset(pvVar18,0,uVar11);
          }
          *(void **)(iVar16 + 0xc) = pvVar18;
          _memset(pvVar18,0,(uint)*(byte *)(iVar16 + 0x11));
        }
        iVar13 = 0;
        uVar11 = 0;
        local_26c = 0;
        local_274 = (ushort *)0x0;
        if (*(char *)(local_268 + 0x10) != '\0') {
          do {
            uVar14 = uVar11 & 0x80000007;
            *(undefined1 *)(uVar11 + *(int *)(iVar16 + 4)) = 0xff;
            if ((int)uVar14 < 0) {
              uVar14 = (uVar14 - 1 | 0xfffffff8) + 1;
            }
            local_258 = 1 << ((byte)uVar14 & 0x1f);
            if (((&local_204)[((int)(uVar11 + ((int)uVar11 >> 0x1f & 7U)) >> 3) + local_25c] &
                (byte)local_258) != 0) {
              uVar21 = __allshl();
              local_250 = CONCAT44((int)((ulonglong)uVar21 >> 0x20),(undefined4)local_250);
              puVar17 = (ushort *)(iVar13 + 0x58 + *(int *)(local_268 + 0x7c));
              *puVar17 = *puVar17 | (ushort)uVar21;
              *(char *)(uVar11 + *(int *)(iVar16 + 4)) = (char)local_26c;
              *(char *)(local_26c + *(int *)(iVar16 + 8)) = (char)uVar11;
              if (((uint)*(ushort *)(iVar13 + 0x5a + *(int *)(local_268 + 0x7c)) & (uint)uVar21) !=
                  0) {
                *(char *)((int)local_274 + *(int *)(iVar16 + 0xc)) = (char)uVar11;
                local_274 = (ushort *)((int)local_274 + 1);
              }
              local_26c = local_26c + 1;
            }
            uVar11 = uVar11 + 1;
            iVar13 = iVar13 + 0x5c;
          } while ((int)uVar11 < (int)(uint)*(byte *)(local_268 + 0x10));
        }
        piVar9 = local_254;
        if (*(byte *)(iVar16 + 0x10) != 0) {
          sVar1 = (uint)*(byte *)(iVar16 + 0x10) * 4;
          pvVar18 = (void *)0x0;
          if (((local_254 == (int *)0x0) || (local_264 == (uint *)0x0)) ||
             (*local_264 <= *local_254 + sVar1)) {
            FUN_00512850();
          }
          else {
            uVar11 = *local_254 + 0xf;
            pvVar18 = (void *)(uVar11 & 0xfffffff0);
            *local_254 = (uVar11 & 0xfffffff0) + sVar1;
            _memset(pvVar18,0,sVar1);
          }
          *(void **)(iVar16 + 0x14) = pvVar18;
          _memset(pvVar18,0,(uint)*(byte *)(iVar16 + 0x10) * 4);
          local_274 = (ushort *)0x0;
          if (*(char *)(iVar16 + 0x10) != '\0') {
            do {
              puVar17 = local_274;
              uVar11 = (uint)*(byte *)(iVar16 + 0x10);
              pvVar18 = (void *)0x0;
              if ((piVar9 == (int *)0x0) || (local_264 == (uint *)0x0)) {
                FUN_00512850();
              }
              else if (*piVar9 + uVar11 < *local_264) {
                uVar14 = *piVar9 + 0xf;
                pvVar18 = (void *)(uVar14 & 0xfffffff0);
                *piVar9 = (uVar14 & 0xfffffff0) + uVar11;
                _memset(pvVar18,0,uVar11);
                puVar17 = local_274;
              }
              else {
                FUN_00512850();
                puVar17 = local_274;
              }
              *(void **)(*(int *)(iVar16 + 0x14) + (int)puVar17 * 4) = pvVar18;
              _memset(*(void **)(*(int *)(iVar16 + 0x14) + (int)puVar17 * 4),0,
                      (uint)*(byte *)(iVar16 + 0x10));
              local_274 = (ushort *)((int)puVar17 + 1);
            } while ((int)local_274 < (int)(uint)*(byte *)(iVar16 + 0x10));
          }
          local_26c = *piVar9;
          local_248 = __allshl();
          puVar8 = local_264;
          iVar13 = local_268;
          local_258 = FUN_00524df0(local_248,&local_26c,local_264);
          if (local_258 != 0) {
            sVar1 = (uint)*(byte *)(iVar13 + 0x10) * 4;
            pvVar18 = (void *)0x0;
            if ((puVar8 == (uint *)0x0) || (*puVar8 <= sVar1 + local_26c)) {
              FUN_00512850();
            }
            else {
              pvVar18 = (void *)(local_26c + 0xfU & 0xfffffff0);
              local_26c = (local_26c + 0xfU & 0xfffffff0) + sVar1;
              _memset(pvVar18,0,sVar1);
            }
            _memset(pvVar18,0,(uint)*(byte *)(iVar13 + 0x10) * 4);
            local_274 = (ushort *)0x0;
            if (*(char *)(iVar13 + 0x10) != '\0') {
              do {
                uVar11 = (uint)*(byte *)(iVar13 + 0x10);
                _Dst = (void *)0x0;
                if ((local_264 == (uint *)0x0) || (*local_264 <= local_26c + uVar11)) {
                  FUN_00512850();
                }
                else {
                  _Dst = (void *)(local_26c + 0xfU & 0xfffffff0);
                  local_26c = (local_26c + 0xfU & 0xfffffff0) + uVar11;
                  _memset(_Dst,0,uVar11);
                }
                *(void **)((int)pvVar18 + (int)local_274 * 4) = _Dst;
                _memset(_Dst,0,(uint)*(byte *)(iVar13 + 0x10));
                local_274 = (ushort *)((int)local_274 + 1);
              } while ((int)local_274 < (int)(uint)*(byte *)(iVar13 + 0x10));
            }
            FUN_00524f30(iVar13,local_248,local_258,pvVar18);
            iVar13 = 0;
            if (*(char *)(iVar16 + 0x10) != '\0') {
              do {
                iVar20 = 0;
                if (*(char *)(iVar16 + 0x10) != '\0') {
                  do {
                    *(undefined1 *)(iVar20 + *(int *)(*(int *)(iVar16 + 0x14) + iVar13 * 4)) =
                         *(undefined1 *)
                          ((uint)*(byte *)(*(int *)(iVar16 + 8) + iVar20) +
                          *(int *)((int)pvVar18 + (uint)*(byte *)(*(int *)(iVar16 + 8) + iVar13) * 4
                                  ));
                    iVar20 = iVar20 + 1;
                  } while (iVar20 < (int)(uint)*(byte *)(iVar16 + 0x10));
                }
                iVar13 = iVar13 + 1;
              } while (iVar13 < (int)(uint)*(byte *)(iVar16 + 0x10));
            }
          }
        }
        local_260 = local_260 + 0x28;
        local_25c = local_25c + 0x20;
        local_270 = local_270 + 1;
        uVar21 = local_250;
      } while (local_270 < (int)(uint)*(byte *)(local_268 + 0x14));
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_274);
  return;
}

