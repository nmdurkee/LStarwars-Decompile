/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59b840; label: FUN_0059b840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0059b840(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  bool bVar10;
  int local_c;
  
  local_c = 0;
  _DAT_00956254 = 0;
  DAT_0095628c = 0;
  DAT_00956250 = 0;
  DAT_00956264 = 0;
  DAT_00956288 = 0;
  DAT_00956284 = 0;
  DAT_00956274 = 0;
  DAT_00956268 = 0;
  DAT_00956270 = 0;
  DAT_00956278 = 0;
  DAT_00956260 = 0;
  DAT_00956280 = 0;
  DAT_0095627c = 0;
  DAT_0095626c = 0;
  DAT_0095625c = 0;
  DAT_00956258 = 0;
  if (param_1 == (char *)0xffffffff) {
    return 0;
  }
  if (((DAT_0093b31c != 0) && (DAT_0095625c = 1, DAT_00956298 != 0)) &&
     (*(char *)(DAT_00956298 + 8 + (int)param_1 * 0xc) != '\0')) {
    DAT_00956258 = 1;
  }
  iVar1 = DAT_00956290 + (int)param_1 * 0x1c;
  iVar9 = 0;
  if (*(char *)(iVar1 + 0x18) != '\0') {
    param_1 = (char *)(param_3 + 1);
    psVar8 = (short *)(iVar1 + 4);
    do {
      iVar5 = DAT_00956274;
      iVar4 = DAT_0095625c;
      iVar6 = (int)*psVar8;
      if (((param_2 == -1) || (iVar6 == param_2)) &&
         ((iVar7 = DAT_00951354 + iVar6 * 0x9c, iVar7 != DAT_00951364 &&
          (uVar3 = *(ushort *)(iVar7 + 0x7a), (uVar3 & 0x22) == 0)))) {
        if ((uVar3 & 0x100) == 0) {
          if ((uVar3 & 4) == 0) {
            _DAT_00956254 = _DAT_00956254 + 1;
            DAT_00956250 = DAT_00956250 + 10;
            iVar2 = param_3 + iVar6 * 0xc;
            if (*(char *)(param_3 + iVar6 * 0xc) != '\0') {
              local_c = local_c + 1;
            }
            DAT_0095625c = DAT_0095625c + 1;
            if (*(char *)(iVar2 + 1) != '\0') {
              DAT_0095628c = DAT_0095628c + 1;
              DAT_00956258 = DAT_00956258 + 1;
            }
            if ((*(byte *)(iVar7 + 0x7a) & 0x10) != 0) {
              if (*(char *)(iVar2 + 4) != '\0') {
                DAT_00956258 = DAT_00956258 + 1;
              }
              DAT_00956264 = DAT_00956264 + (uint)*(byte *)(iVar2 + 5);
              DAT_00956274 = DAT_00956274 + 1;
              DAT_0095625c = iVar4 + 3;
              if (DAT_0093b314 == 0) {
                if ((*(char *)(iVar2 + 2) != '\0') || (*(char *)(iVar2 + 3) != '\0')) {
                  DAT_00956268 = DAT_00956268 + 1;
                  DAT_00956258 = DAT_00956258 + 1;
                }
              }
              else {
                if (*(char *)(iVar2 + 2) != '\0') {
                  DAT_00956268 = DAT_00956268 + 1;
                  DAT_00956258 = DAT_00956258 + 1;
                  DAT_00956278 = DAT_00956278 + 1;
                }
                DAT_00956274 = iVar5 + 2;
                DAT_0095625c = iVar4 + 4;
                if (*(char *)(iVar2 + 3) != '\0') {
                  DAT_00956268 = DAT_00956268 + 1;
                  DAT_00956258 = DAT_00956258 + 1;
                  DAT_00956280 = DAT_00956280 + 1;
                }
              }
              DAT_0095627c = DAT_0095627c + 1;
              if (*(char *)(iVar2 + 6) != '\0') {
                DAT_0095626c = DAT_0095626c + 1;
              }
              DAT_00956288 = DAT_00956288 + 1;
              if (DAT_0093b320 != 0) {
                DAT_0095625c = DAT_0095625c + 1;
              }
              if (*(char *)(iVar2 + 7) != '\0') {
                DAT_00956284 = DAT_00956284 + 1;
                bVar10 = DAT_0093b320 == 0;
                goto LAB_0059bac0;
              }
            }
          }
          else {
            DAT_0095625c = DAT_0095625c + 1;
            if (*(float *)(param_3 + 8 + iVar6 * 0xc) < (float)*(ushort *)(iVar7 + 0x84))
            goto LAB_0059bac2;
          }
        }
        else if (DAT_0093b318 != 0) {
          DAT_0095625c = DAT_0095625c + 1;
          bVar10 = *param_1 == '\0';
LAB_0059bac0:
          if (!bVar10) {
LAB_0059bac2:
            DAT_00956258 = DAT_00956258 + 1;
          }
        }
      }
      param_1 = param_1 + 0xc;
      iVar9 = iVar9 + 1;
      psVar8 = psVar8 + 1;
    } while (iVar9 < (int)(uint)*(byte *)(iVar1 + 0x18));
  }
  return local_c;
}

