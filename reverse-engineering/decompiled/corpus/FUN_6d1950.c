/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d1950; label: FUN_006d1950
 */

void FUN_006d1950(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  int in_ECX;
  float fVar8;
  undefined4 uStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  piVar2 = *(int **)(in_ECX + 0x24);
joined_r0x006d1960:
  do {
    piVar4 = piVar2;
    if (piVar4 == (int *)0x0) {
      iVar3 = *(int *)(in_ECX + 0x24);
      if (iVar3 != 0) {
        fVar8 = 0.0;
        if ((*(char *)(param_1 + 0x8b) != '\0') && (*(float *)(param_1 + 0x164) != 0.0)) {
          fVar8 = *(float *)(iVar3 + 0xc);
          iVar5 = 0;
          do {
            iVar5 = iVar5 + 1;
            fVar8 = (float)(**(code **)(**(int **)(*(int *)(iVar3 + 8) + 0x14) + 0x14))(fVar8);
            if (fVar8 == 0.0) {
              fVar8 = (float)(**(code **)(**(int **)(*(int *)(iVar3 + 8) + 0x14) + 0x14))(0);
            }
            iVar6 = FUN_006c8b60(fVar8,*(undefined4 *)(iVar3 + 8),0xffffffff);
          } while ((iVar6 == 0) && (iVar5 < 0x1000));
        }
        fStack_8 = fVar8;
        if ((*(char *)(param_1 + 0x8c) != '\0') &&
           (fVar8 = *(float *)(param_1 + 0x168), fVar8 != 0.0)) {
          fVar7 = *(float *)(iVar3 + 0xc);
          iVar5 = 0;
          do {
            iVar6 = FUN_006c8b60(fVar7,*(undefined4 *)(iVar3 + 8),0xffffffff);
            if (iVar6 != 0) {
              fVar8 = fVar7;
            }
            fVar7 = (float)(**(code **)(**(int **)(*(int *)(iVar3 + 8) + 0x14) + 0x14))(fVar7);
            if (fVar7 == 0.0) {
              fVar7 = (float)(**(code **)(**(int **)(*(int *)(iVar3 + 8) + 0x14) + 0x14))(0);
            }
            iVar5 = iVar5 + 1;
          } while ((fVar7 != *(float *)(iVar3 + 0xc)) && (iVar5 < 0x1000));
          fStack_8 = fVar8;
          if (fVar8 == 0.0) {
            return;
          }
        }
        if (fStack_8 != 0.0) {
          uStack_c = *(undefined4 *)(iVar3 + 8);
          uStack_4 = 0;
          FUN_006c9bf0(&uStack_c,0);
          FUN_006cf350();
        }
      }
      return;
    }
    piVar1 = *(int **)(piVar4[2] + 0x14);
    piVar2 = (int *)*piVar4;
    iVar3 = piVar4[3];
    for (iVar5 = (**(code **)(*piVar1 + 0x14))(0); iVar5 != 0;
        iVar5 = (**(code **)(*piVar1 + 0x14))(iVar5)) {
      if (iVar5 == iVar3) {
        if (iVar5 != 0) goto joined_r0x006d1960;
        break;
      }
    }
    if (*piVar4 == 0) {
      *(int *)(in_ECX + 0x28) = piVar4[1];
    }
    else {
      *(int *)(*piVar4 + 4) = piVar4[1];
    }
    if ((int *)piVar4[1] == (int *)0x0) {
      *(int *)(in_ECX + 0x24) = *piVar4;
    }
    else {
      *(int *)piVar4[1] = *piVar4;
    }
    *piVar4 = 0;
    piVar4[1] = 0;
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
    FUN_006334d0(piVar4,0x14);
  } while( true );
}

