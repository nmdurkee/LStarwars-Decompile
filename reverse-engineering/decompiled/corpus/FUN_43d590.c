/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43d590; label: FUN_0043d590
 */

void FUN_0043d590(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  float *pfVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c0 [48];
  
  iVar10 = 0;
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[4] = 0;
  local_c0[5] = 0;
  local_c0[6] = 0;
  local_c0[7] = 0;
  local_c0[8] = 0;
  local_c0[9] = 0;
  local_c0[10] = 0;
  local_c0[0xb] = 0;
  local_c0[0xc] = 0;
  local_c0[0xd] = 0;
  local_c0[0xe] = 0;
  local_c0[0xf] = 0;
  if (0 < DAT_0093d500) {
    local_d8 = 0;
    do {
      iVar7 = local_d8 + DAT_0093d504;
      if ((((iVar7 != 0) && ((*(uint *)(iVar7 + 0x1fc) & 1) != 0)) &&
          ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) &&
         ((piVar9 = *(int **)(iVar7 + 0x3ac), piVar9 != (int *)0x0 &&
          ((*(uint *)(iVar7 + 0xef4) & 0x2000) != 0)))) {
        if (*(byte *)(iVar7 + 0x1084) != 0xff) {
          uVar4 = (uint)*(byte *)(iVar7 + 0x1084);
          iVar5 = local_c0[uVar4 + 8];
          local_c0[uVar4 * 4 + iVar5 + 0x10] = iVar7;
          local_c0[uVar4 + 8] = iVar5 + 1;
        }
        *(undefined1 *)(iVar7 + 0x1084) = 0xff;
        iVar5 = 0;
        do {
          if (*piVar9 == (&DAT_0093d7f0)[iVar5]) {
            iVar2 = local_c0[iVar5];
            iVar11 = iVar5 * 0x11 + iVar2;
            (&DAT_00876858)[iVar11 * 2] = iVar7;
            fVar12 = (float10)FUN_005b3c50((&DAT_0093d7f0)[iVar5] + 0x80,iVar7 + 0x80,0);
            (&DAT_0087685c)[iVar11 * 2] = (float)fVar12;
            local_c0[iVar5] = iVar2 + 1;
            break;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 8);
      }
      iVar10 = iVar10 + 1;
      local_d8 = local_d8 + 0x10d8;
    } while (iVar10 < DAT_0093d500);
  }
  iVar10 = 0;
  piVar9 = local_c0;
  do {
    iVar7 = *piVar9 + iVar10;
    iVar10 = iVar10 + 0x11;
    piVar9 = piVar9 + 1;
    (&DAT_00876858)[iVar7 * 2] = 0;
    (&DAT_0087685c)[iVar7 * 2] = 0x4e6e6b28;
  } while (iVar10 < 0x88);
  local_d0 = 0;
  local_d4 = 0;
  local_cc = 0;
  piVar9 = local_c0 + 0x11;
  do {
    if ((&DAT_0093d7f0)[local_d0] != 0) {
      piVar6 = (int *)((int)&DAT_00876858 + local_cc);
      local_d8 = 0;
      if (*(int *)((int)&DAT_00876858 + local_cc) != 0) {
        iVar10 = local_c0[local_d0];
        iVar7 = local_cc;
        iVar5 = local_d4;
        do {
          iVar2 = *piVar6;
          if (piVar9[-1] == iVar2) {
            *(float *)((int)&DAT_0087685c + iVar7) = *(float *)((int)&DAT_0087685c + iVar7) * 0.75;
          }
          if (*piVar9 == iVar2) {
            *(float *)((int)&DAT_0087685c + iVar7) = *(float *)((int)&DAT_0087685c + iVar7) * 0.75;
          }
          if (piVar9[1] == iVar2) {
            *(float *)((int)&DAT_0087685c + iVar7) = *(float *)((int)&DAT_0087685c + iVar7) * 0.75;
          }
          if (piVar9[2] == iVar2) {
            *(float *)((int)&DAT_0087685c + iVar7) = *(float *)((int)&DAT_0087685c + iVar7) * 0.75;
          }
          if (0 < iVar10) {
            iVar7 = local_c0[local_d0] - local_d8;
            pfVar8 = (float *)((int)&DAT_0087685c + local_d4);
            do {
              if (pfVar8[2] < *pfVar8) {
                fVar1 = *pfVar8;
                fVar3 = pfVar8[-1];
                pfVar8[-1] = pfVar8[1];
                *pfVar8 = pfVar8[2];
                pfVar8[1] = fVar3;
                pfVar8[2] = fVar1;
              }
              pfVar8 = pfVar8 + 2;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          local_d8 = local_d8 + 1;
          iVar7 = iVar5 + 8;
          piVar6 = (int *)((int)&DAT_00876860 + iVar5);
          iVar10 = iVar10 + -1;
          iVar5 = iVar7;
        } while (*piVar6 != 0);
      }
      iVar10 = 0;
      if (0 < DAT_007f6718) {
        piVar6 = (int *)((int)&DAT_00876858 + local_d4);
        do {
          iVar5 = DAT_007f6718;
          iVar7 = *piVar6;
          if (iVar7 == 0) break;
          iVar10 = iVar10 + 1;
          piVar6 = piVar6 + 2;
          *(char *)(iVar7 + 0x1084) = (char)local_d0;
        } while (iVar10 < iVar5);
      }
    }
    local_cc = local_cc + 0x88;
    local_d0 = local_d0 + 1;
    local_d4 = local_d4 + 0x88;
    piVar9 = piVar9 + 4;
    if (0x43f < local_cc) {
      return;
    }
  } while( true );
}

