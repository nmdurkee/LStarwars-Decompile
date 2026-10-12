/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545c80; label: FUN_00545c80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545c80(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar8 = 0;
  local_8 = 0;
  if ((DAT_00802028 != 0) && (psVar10 = DAT_00924840, 0 < DAT_00924838)) {
    do {
      if ((*psVar10 != 0) && (*(char *)((int)psVar10 + 0x29) != '\0')) {
        fVar1 = *(float *)(psVar10 + 0x18);
        iVar11 = *(int *)(psVar10 + 10);
        _DAT_00924844 = psVar10;
        *(undefined1 *)(psVar10 + 0x14) = 0;
        fVar2 = *(float *)(psVar10 + 0x1a);
        if ((iVar11 != 0) && (iVar9 = 0, 0 < psVar10[0x15])) {
          do {
            fVar4 = *(float *)(iVar11 + 0x34) - DAT_0097371c;
            fVar6 = *(float *)(iVar11 + 0x30) - DAT_00973718;
            fVar5 = *(float *)(iVar11 + 0x38) - DAT_00973720;
            fVar4 = fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4;
            if (fVar4 < fVar2 * fVar2) {
              if (fVar1 * fVar1 <= fVar4) {
                uVar3 = 0x2d2febff;
              }
              else {
                uVar3 = 0;
              }
              *(undefined4 *)(iVar11 + 0x2c) = uVar3;
              local_c = *(undefined4 *)(psVar10 + 2);
              local_4 = *(undefined4 *)(psVar10 + 4);
              iVar7 = FUN_005f33b0(&local_c,iVar11);
              if (iVar7 != 0) {
                *(undefined1 *)(psVar10 + 0x14) = 1;
              }
            }
            iVar9 = iVar9 + 1;
            iVar11 = iVar11 + 0x40;
          } while (iVar9 < psVar10[0x15]);
        }
      }
      iVar8 = iVar8 + 1;
      psVar10 = psVar10 + 0x20;
    } while (iVar8 < DAT_00924838);
  }
  return;
}

