/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x427ec0; label: FUN_00427ec0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00427ec0(void)

{
  short sVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  int local_20;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined1 local_8 [4];
  int local_4;
  
  bVar2 = false;
  local_c = 0;
  FUN_004277d0();
  if (DAT_0087b738 != 0) {
    return 0;
  }
  local_10 = FUN_00574e20();
  if ((((DAT_0093b328 == 0) && (local_10 == -1)) && (0.0 < _DAT_00876ce4)) &&
     (_DAT_00876ce4 = _DAT_00876ce4 - _DAT_00925018, _DAT_00876ce4 < 0.0)) {
    iVar11 = 0;
    _DAT_00876ce4 = 0.0;
    do {
      iVar5 = (&DAT_0093d7f0)[iVar11];
      if ((iVar5 != 0) && ((*(byte *)(iVar5 + 0x1fc) & 0x80) == 0)) {
        if ((*(uint *)(iVar5 + 0xef0) & 0x200000) == 0) {
          if ((DAT_007f3964 != 3) || (iVar5 = FUN_004278c0(iVar5), iVar5 == 0)) goto LAB_00427f75;
        }
        else {
          iVar5 = FUN_004278c0(iVar5);
          if ((iVar5 == 0) && (1.0 <= *(float *)((&DAT_0093d7f0)[iVar11] + 0xc64))) break;
        }
        bVar2 = true;
        break;
      }
LAB_00427f75:
      iVar11 = iVar11 + 1;
    } while (iVar11 < 8);
  }
  local_20 = 0;
  do {
    iVar11 = (&DAT_0093d7f0)[local_20];
    if (iVar11 != 0) {
      uVar8 = 0;
      bVar12 = false;
      iVar5 = FUN_004f48e0(0);
      if (-1 < iVar5) {
        DAT_007f39d4 = (undefined2)iVar5;
      }
      iVar5 = FUN_004f48e0(1);
      if (-1 < iVar5) {
        _DAT_007f39d6 = (undefined2)iVar5;
      }
      iVar6 = FUN_00574e20();
      if (iVar6 == -1) {
        uVar7 = *(uint *)(iVar11 + 0x1fc) >> 7 & 1;
        if ((uVar7 == 0) && ((&DAT_007f39d0)[local_20] != '\0')) {
          sVar1 = (&DAT_007f39d4)[local_20];
          (&DAT_007f39d0)[local_20] = (&DAT_007f39d0)[local_20] + -1;
          if ((-1 < sVar1) &&
             (iVar5 = FUN_006d9120(~(1 << ((byte)sVar1 & 0x1f)),0x1a,local_8,&local_14,1),
             -1 < iVar5)) {
            (&DAT_007f39d0)[local_20] = 5;
          }
        }
        else if (uVar7 == 0) {
          local_4 = FUN_004f48e0(0);
          if (-1 < local_4) {
            uVar8 = 1 << ((byte)local_4 & 0x1f);
          }
          iVar6 = FUN_004f48e0(1);
          if (-1 < iVar6) {
            uVar8 = uVar8 | 1 << ((byte)iVar6 & 0x1f);
          }
          bVar3 = FUN_006d5040();
          iVar5 = FUN_006d9120(uVar8 & ~(1 << (bVar3 & 0x1f)),0x1a,local_8,&local_14,1);
          if (((-1 < iVar5) && (iVar5 != local_4)) && (iVar5 != iVar6)) {
            (&DAT_007f39d4)[local_20] = (short)iVar5;
            (&DAT_007f39d0)[local_20] = 5;
            bVar12 = true;
            iVar6 = FUN_006d67a0(iVar5);
            if (iVar6 != 0) {
              iVar5 = FUN_006d9510(iVar5,local_20);
              if (local_20 == 0) {
                bVar12 = local_14 == 0x3b;
              }
              else {
                bVar12 = local_14 == 0x3c;
              }
              if ((bVar12) && (cVar4 = FUN_006d95d0(iVar5,local_20), cVar4 == '\0')) {
                FUN_004f47f0(local_20,iVar5);
                FUN_0055c120(local_20);
                FUN_00423610(2,local_20,local_20,0);
                FUN_00509830(0x15,0,0xffffffff);
                bVar12 = false;
                DAT_007f396d = (undefined1)local_20;
              }
            }
          }
        }
      }
      if (local_20 == DAT_007f396c) {
        bVar12 = true;
        iVar5 = FUN_00421410(local_20);
        DAT_007f396c = -1;
LAB_004281ca:
        if (DAT_00855de0 != 0) goto LAB_004281d3;
      }
      else {
        if (bVar12) goto LAB_004281ca;
LAB_004281d3:
        if (((_DAT_00876ce4 <= 0.0) && (!bVar2)) && (local_20 != -1)) goto LAB_004285c5;
      }
      if (bVar12) {
        FUN_004f47f0(local_20,iVar5);
      }
      if (((DAT_0093b328 == 0) && (local_10 == -1)) && ((*(byte *)(iVar11 + 0x1fc) & 0x80) == 0)) {
        *(undefined1 *)(iVar11 + 0x288) = 1;
        iVar5 = iVar11;
        if ((DAT_00951288 != 0) && (*(char *)(iVar11 + 0x7b5) != '$')) goto LAB_00428332;
        if ((DAT_00951be0 != 0) ||
           ((((DAT_00855de0 == 2 || ((*(byte *)(iVar11 + 0x7c5) & 2) != 0)) ||
             ((*(uint *)(iVar11 + 0xeec) & 0x4000000) != 0)) ||
            ((*(char *)(iVar11 + 0x7b5) == '$' || (*(char *)(iVar11 + 0x7b5) == '\x1f')))))) {
LAB_00428419:
          piVar9 = &DAT_0093d7f8;
          do {
            iVar5 = *piVar9;
            if ((iVar5 != 0) &&
               ((((DAT_00951288 != 0 && (*(char *)(iVar11 + 0x7b5) != '$')) ||
                 ((((DAT_00951be0 == 0 &&
                    (((DAT_00855de0 != 2 && ((*(byte *)(iVar5 + 0x7c5) & 2) == 0)) &&
                     ((*(uint *)(iVar5 + 0xeec) & 0x4000000) == 0)))) &&
                   (((*(char *)(iVar5 + 0x7b5) != '$' && (*(char *)(iVar5 + 0x7b5) != '\x1f')) &&
                    (*(char *)(iVar5 + 0x288) != '\0')))) &&
                  (((*(char *)(iVar5 + 0x281) != '\0' ||
                    ((*(char *)(iVar5 + 0xe32) == '\x01' &&
                     (0.0 < *(float *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x28))))) &&
                   ((-0.85 < *(float *)(iVar5 + 0xc5c) &&
                    (((*(float *)(iVar5 + 0xc5c) < 0.85 && (-0.85 < *(float *)(iVar5 + 0xc60))) &&
                     (*(float *)(iVar5 + 0xc60) < 0.85)))))))))) &&
                (iVar6 = FUN_00487ca0(iVar11,iVar5,1), iVar6 != 0)))) goto LAB_00428332;
            piVar9 = piVar9 + 1;
          } while ((int)piVar9 < 0x93d810);
          if (DAT_00951288 == 0) {
            if ((_DAT_00876ce4 == 0.0) && (!bVar2)) {
              _DAT_00876ce4 = _DAT_007f6734;
            }
            *(uint *)(iVar11 + 0xef0) = *(uint *)(iVar11 + 0xef0) | 0x200000;
          }
          goto LAB_004285c5;
        }
        if (((*(float *)(iVar11 + 0xc5c) <= -0.85) ||
            ((0.85 <= *(float *)(iVar11 + 0xc5c) || (*(float *)(iVar11 + 0xc60) <= -0.85)))) ||
           (0.85 <= *(float *)(iVar11 + 0xc60))) {
          if (!bVar2) goto LAB_00428419;
        }
        else if ((((!bVar2) && (*(char *)(iVar11 + 0x281) == '\0')) &&
                 (*(short *)(iVar11 + 0x1064) != DAT_007f1948)) &&
                ((*(char *)(iVar11 + 0xe32) != '\x01' ||
                 (*(float *)(*(int *)(*(int *)(iVar11 + 0x54) + 0x24) + 0x28) <= 0.0))))
        goto LAB_00428419;
LAB_00428332:
        *(uint *)(iVar5 + 0x1fc) = *(uint *)(iVar5 + 0x1fc) | 0x80;
        *(undefined4 *)(iVar5 + 0xd60) = 0x40000000;
        *(undefined4 *)(iVar5 + 0xda4) = _DAT_00802be8;
        FUN_00698910();
        FUN_00548fb0(&DAT_00925044,0);
        local_c = 1;
        if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b160) {
          FUN_00414d10(iVar5,(&DAT_0093d518)[local_20 * 0x10]);
        }
        FUN_00466820(iVar5);
        *(uint *)(iVar5 + 0xef0) = *(uint *)(iVar5 + 0xef0) & 0xffe7ffff;
        *(undefined4 *)(iVar5 + 0xee4) = 0;
        *(undefined4 *)(iVar5 + 0xee8) = 0;
        if (DAT_00855de0 == 2) {
LAB_00428571:
          if (DAT_00951288 != 0) goto LAB_0042857e;
        }
        else {
          if (DAT_00951288 == 0) {
            FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
            goto LAB_00428571;
          }
LAB_0042857e:
          if (*(char *)(iVar5 + 0x7b5) != '$') {
            FUN_00427c10(iVar5);
          }
        }
        *(uint *)(iVar5 + 0xef0) = *(uint *)(iVar5 + 0xef0) | 0x80;
        FUN_00547930(0x1f,iVar5 + 0x80,0,0);
        _DAT_00876ce4 = 0.0;
        bVar2 = false;
      }
    }
LAB_004285c5:
    local_20 = local_20 + 1;
  } while (local_20 < 2);
  if (((DAT_00951288 == 0) && (DAT_00951be0 == 0)) &&
     (((DAT_00855de0 == 0 &&
       (((((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234 || (DAT_009253a4 != 0)) &&
          (local_10 != 0xd)) && ((local_10 != 0xc && (local_10 != 0xe)))) && (local_10 != 0xf)))) &&
      (((local_10 != 0x10 && (local_10 != 0x11)) && (local_10 != 8)))))) {
    iVar5 = 0;
    iVar11 = -1;
    do {
      iVar6 = (&DAT_0093d7f0)[iVar5];
      iVar10 = iVar11;
      if ((((iVar6 != 0) && (*(char *)(iVar6 + 0x28b) == '\0')) &&
          (cVar4 = *(char *)(iVar6 + 0x7b5), cVar4 != '+')) && ((cVar4 != 'Q' && (cVar4 != '\x1f')))
         ) {
        if ((*(uint *)(iVar6 + 0xef0) & 0x200000) == 0) {
          if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
              ((DAT_0093d7f4 != 0 &&
               ((((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0 &&
                 (iVar10 = iVar5,
                 2.0 < *(float *)(iVar6 + 0xda8) == (*(float *)(iVar6 + 0xda8) == 2.0))) &&
                (iVar10 = iVar11, *(char *)(iVar6 + 0x288) == '\0')))))) &&
             ((((iVar10 = iVar5, -1.0 <= *(float *)(iVar6 + 0xc5c) &&
                (*(float *)(iVar6 + 0xc5c) <= 1.0)) && (-1.0 <= *(float *)(iVar6 + 0xc60))) &&
              (*(float *)(iVar6 + 0xc60) <= 1.0)))) {
LAB_004288d1:
            iVar10 = iVar11;
          }
        }
        else if (((*(float *)(iVar6 + 0xc5c) <= -0.85) || (0.85 <= *(float *)(iVar6 + 0xc5c))) ||
                ((*(float *)(iVar6 + 0xc60) <= -0.85 ||
                 ((0.85 <= *(float *)(iVar6 + 0xc60) || (1.0 <= *(float *)(iVar6 + 0xc64))))))) {
          if (2.0 < *(float *)(iVar6 + 0xda8) == (*(float *)(iVar6 + 0xda8) == 2.0)) {
            if (*(char *)(iVar6 + 0x288) == '\0') {
              if (((*(float *)(iVar6 + 0xc5c) < -1.0) || (1.0 < *(float *)(iVar6 + 0xc5c))) ||
                 (*(float *)(iVar6 + 0xc60) < -1.0)) goto LAB_004288d1;
              if (1.0 < *(float *)(iVar6 + 0xc60)) goto LAB_004288d3;
            }
            if (((*(byte *)(iVar6 + 0x7c5) & 2) == 0) &&
               ((*(uint *)(iVar6 + 0xeec) & 0x4000000) == 0)) {
              _DAT_00876ce4 = 1e-06;
            }
          }
        }
        else {
          if (DAT_0093d7f0 != 0) {
            *(uint *)(DAT_0093d7f0 + 0xef0) = *(uint *)(DAT_0093d7f0 + 0xef0) & 0xffdfffff;
          }
          if (DAT_0093d7f4 != 0) {
            *(uint *)(DAT_0093d7f4 + 0xef0) = *(uint *)(DAT_0093d7f4 + 0xef0) & 0xffdfffff;
          }
          if (DAT_0093d7f8 != 0) {
            *(uint *)(DAT_0093d7f8 + 0xef0) = *(uint *)(DAT_0093d7f8 + 0xef0) & 0xffdfffff;
          }
          if (DAT_0093d7fc != 0) {
            *(uint *)(DAT_0093d7fc + 0xef0) = *(uint *)(DAT_0093d7fc + 0xef0) & 0xffdfffff;
          }
          if (DAT_0093d800 != 0) {
            *(uint *)(DAT_0093d800 + 0xef0) = *(uint *)(DAT_0093d800 + 0xef0) & 0xffdfffff;
          }
          if (DAT_0093d804 != 0) {
            *(uint *)(DAT_0093d804 + 0xef0) = *(uint *)(DAT_0093d804 + 0xef0) & 0xffdfffff;
          }
          if (DAT_0093d808 != 0) {
            *(uint *)(DAT_0093d808 + 0xef0) = *(uint *)(DAT_0093d808 + 0xef0) & 0xffdfffff;
          }
          if (DAT_0093d80c != 0) {
            *(uint *)(DAT_0093d80c + 0xef0) = *(uint *)(DAT_0093d80c + 0xef0) & 0xffdfffff;
          }
        }
      }
LAB_004288d3:
      iVar5 = iVar5 + 1;
      iVar11 = iVar10;
    } while (iVar5 < 2);
    if ((iVar10 != -1) && (DAT_007f3b14 == -1)) {
      _DAT_00876ce4 = _DAT_007f6734;
      FUN_00427cd0(iVar10,0,1,0);
      return local_c;
    }
  }
  return local_c;
}

