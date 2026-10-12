/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x5606d0; label: FUN_005606d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005606d0(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  short *psVar5;
  float10 fVar6;
  float local_14;
  undefined1 local_c [12];
  
  if (((((DAT_0087b51c == 0) && (DAT_007fac04 != 0)) && (*(int *)(param_1 + 300) != 0)) &&
      (((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 8) == 0 && (DAT_00951b80 == 0)))) &&
     (iVar2 = FUN_0058a900(0), iVar2 == 0)) {
    DAT_00802c5c = -1;
    iVar2 = DAT_00802c5c;
    if (DAT_0093d854 == 0) {
      if (DAT_00802c60 == -1) {
        if ((((DAT_00951be0 == 0) || (DAT_00951be8 == 0)) ||
            ((sVar1 = *(short *)(DAT_00951be8 + 0xec), sVar1 == -1 ||
             (iVar2 = (int)sVar1,
             *(char *)(sVar1 * 0x130 + 0xa3 + DAT_00951b78) !=
             *(char *)(*(int *)(param_1 + 0x11c) * 0x130 + 0xa3 + DAT_00951b78))))) &&
           ((iVar2 = DAT_00802c5c, (*(byte *)(*(int *)(param_1 + 0x128) + 100) & 0xe0) == 0 &&
            (iVar3 = FUN_0055e340(local_c,0), iVar2 = DAT_00802c5c, iVar3 != 0)))) {
          iVar2 = 0;
          local_14 = 1e+09;
          DAT_00802c5c = -1;
          if (0 < *(int *)(param_1 + 0x469c)) {
            iVar3 = 0;
            do {
              iVar4 = FUN_0055c690();
              if (iVar4 == 0) {
                iVar4 = *(int *)(param_1 + 0x4698);
                sVar1 = *(short *)(iVar3 + 0xf2 + iVar4);
                if (sVar1 == -1) goto LAB_0056081c;
              }
              else {
LAB_0056081c:
                iVar4 = *(int *)(param_1 + 0x4698);
                sVar1 = *(short *)(iVar4 + 0xf0 + iVar3);
              }
              if ((int)sVar1 != *(int *)(param_1 + 0x11c)) {
                fVar6 = (float10)FUN_005b3c50(iVar3 + iVar4 + 0xd4,local_c,0);
                if ((float)fVar6 < local_14) {
                  DAT_00802c5c = (int)*(short *)(iVar3 + 0xf0 + *(int *)(param_1 + 0x4698));
                  local_14 = (float)fVar6;
                }
              }
              iVar2 = iVar2 + 1;
              iVar3 = iVar3 + 0x128;
            } while (iVar2 < *(int *)(param_1 + 0x469c));
          }
          iVar2 = DAT_00802c5c;
          if (0 < DAT_0095127c) {
            iVar3 = 0;
            psVar5 = &DAT_00951018;
            if (0 < DAT_0095127c) {
              do {
                if (((int)*psVar5 == *(int *)(param_1 + 0x11c)) &&
                   ((((*(byte *)(psVar5 + 3) & 1) != 0 && (iVar2 = FUN_0055c690(), iVar2 != 0)) ||
                    (((*(byte *)(psVar5 + 3) & 2) != 0 && (iVar2 = FUN_0055c690(), iVar2 == 0))))))
                {
                  iVar2 = DAT_00802c5c;
                  if (iVar3 < DAT_0095127c) {
                    sVar1 = psVar5[1];
                    iVar2 = (int)sVar1;
                    if (sVar1 != psVar5[2]) {
                      FUN_0055f8a0((int)sVar1,(int)psVar5[2]);
                      iVar2 = DAT_00802c5c;
                    }
                  }
                  break;
                }
                iVar3 = iVar3 + 1;
                psVar5 = psVar5 + 4;
                iVar2 = DAT_00802c5c;
              } while (iVar3 < DAT_0095127c);
            }
          }
          DAT_00802c5c = iVar2;
          iVar2 = DAT_00802c5c;
          if (DAT_00802c5c != -1) {
            iVar2 = FUN_0055c690();
            if (((iVar2 == 0) &&
                ((*(byte *)(DAT_00802c5c * 0x130 + 100 + DAT_00951b78) & 0x80) != 0)) &&
               (iVar2 = FUN_00573520(*(undefined4 *)(param_1 + 300),0), iVar2 != 0)) {
              DAT_00802c5c = (int)*(short *)(iVar2 + 0x62);
            }
            iVar2 = DAT_00802c5c;
            if ((DAT_00802c5c != -1) &&
               (((iVar2 = FUN_0055c690(), iVar2 == 0 &&
                 ((*(byte *)(DAT_00802c5c * 0x130 + 100 + DAT_00951b78) & 0xe0) != 0)) ||
                ((iVar2 = DAT_00802c5c, DAT_00802c5c != -1 &&
                 ((iVar3 = FUN_0057e710(), iVar2 = DAT_00802c5c, iVar3 != 0 &&
                  ((*(uint *)(DAT_00802c5c * 0x130 + 100 + DAT_00951b78) & 0x400) != 0)))))))) {
              DAT_00802c5c = -1;
              iVar2 = DAT_00802c5c;
            }
          }
        }
      }
      else {
        DAT_00802c5c = DAT_00802c60;
        iVar2 = DAT_00802c5c;
      }
    }
    DAT_00802c5c = iVar2;
    if ((((DAT_0093d84c == -1) && (iVar2 = FUN_004feb90(), iVar2 == 0)) && (DAT_00802c5c != -1)) &&
       ((iVar2 = FUN_0055f500(param_1), extraout_ECX != iVar2 &&
        ((int)*(char *)(extraout_ECX * 0x130 + 0xa3 + DAT_00951b78) == *(int *)(param_1 + 0x120)))))
    {
      _DAT_0093d844 = 0;
      DAT_0093d840 = 0;
      DAT_0093d848 = extraout_ECX;
      DAT_0093d84c = extraout_ECX;
      FUN_004fecf0(FUN_00560630,0,0,0);
      return;
    }
    if (((DAT_0093d84c != -1) && (iVar2 = FUN_004feb90(), iVar2 != 0)) &&
       ((DAT_00802c5c != -1 &&
        ((DAT_00802c5c != DAT_0093d84c &&
         ((int)*(char *)(DAT_00802c5c * 0x130 + 0xa3 + DAT_00951b78) == *(int *)(param_1 + 0x120))))
        ))) {
      DAT_0093d840 = 1;
    }
  }
  return;
}

