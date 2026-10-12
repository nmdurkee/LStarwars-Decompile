/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6a9e30; label: FUN_006a9e30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a9e30(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int local_20;
  int local_1c;
  int *local_18;
  int local_10;
  int local_c;
  
  iVar5 = 0;
  iVar3 = -1;
  iVar7 = 0;
  iVar8 = param_1;
  do {
    do {
      iVar3 = iVar3 + 1;
      if (iVar3 < 4) {
        iVar5 = *(int *)(&DAT_00817028 + iVar3 * 4);
      }
      else {
        iVar5 = iVar5 + 2;
      }
    } while (iVar8 != (iVar8 / iVar5) * iVar5);
    iVar2 = iVar8 / iVar5;
    piVar4 = param_3 + iVar7;
    local_c = iVar7;
    do {
      iVar8 = iVar2;
      iVar7 = local_c + 1;
      piVar4[2] = iVar5;
      if ((iVar5 == 2) && (iVar7 != 1)) {
        piVar1 = piVar4 + 1;
        iVar2 = local_c;
        if (1 < iVar7) {
          do {
            piVar1[1] = *piVar1;
            iVar2 = iVar2 + -1;
            piVar1 = piVar1 + -1;
          } while (iVar2 != 0);
        }
        param_3[2] = 2;
      }
      if (iVar8 == 1) {
        param_3[1] = iVar7;
        *param_3 = param_1;
        local_20 = 0;
        local_1c = 1;
        if ((local_c != 0) && (0 < local_c)) {
          local_18 = param_3 + 2;
          do {
            local_1c = *local_18 * local_1c;
            iVar5 = param_1 / local_1c;
            local_10 = *local_18 + -1;
            if (0 < local_10) {
              do {
                if (2 < iVar5) {
                  pfVar6 = (float *)(param_2 + local_20 * 4);
                  iVar8 = (iVar5 - 3U >> 1) + 1;
                  do {
                    fVar9 = (float10)FUN_006ebcb0();
                    *pfVar6 = (float)fVar9;
                    fVar9 = (float10)FUN_006e8e80();
                    pfVar6[1] = (float)fVar9;
                    pfVar6 = pfVar6 + 2;
                    iVar8 = iVar8 + -1;
                  } while (iVar8 != 0);
                }
                local_20 = local_20 + iVar5;
                local_10 = local_10 + -1;
              } while (local_10 != 0);
            }
            local_18 = local_18 + 1;
            local_c = local_c + -1;
          } while (local_c != 0);
        }
        return;
      }
      iVar2 = iVar8 / iVar5;
      piVar4 = piVar4 + 1;
      local_c = iVar7;
    } while (iVar8 == (iVar8 / iVar5) * iVar5);
  } while( true );
}

