/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x4234b0; label: FUN_004234b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004234b0(int param_1,int param_2,int param_3,char param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  int *piVar6;
  
  if ((*(char *)(in_ECX + 10) != '\0') && (*(char *)(in_ECX + 9) == '\0')) {
    if (param_1 < 1) {
      *(undefined4 *)(in_ECX + 4) = 2;
    }
    else {
      *(int *)(in_ECX + 4) = param_1;
    }
    if (-1 < param_2) {
      *(int *)(in_ECX + 0x38) = param_2;
    }
    *(char *)(in_ECX + 8) = param_4;
    if (((param_4 != '\0') && (*(int *)(in_ECX + 4) == 1)) && (-1 < *(int *)(in_ECX + 0x60))) {
      *(undefined4 *)(in_ECX + 4) = 2;
    }
    *(undefined1 *)(in_ECX + 9) = 1;
    *(undefined1 *)(in_ECX + 0x70) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 1;
    piVar6 = (int *)(in_ECX + 0x3c);
    iVar5 = 0;
    *piVar6 = -1;
    *(undefined4 *)(in_ECX + 0x4c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x40) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x50) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x44) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x54) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x48) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x58) = 0xffffffff;
    if (0 < *(int *)(in_ECX + 4)) {
      do {
        iVar2 = FUN_004f48e0(iVar5);
        *piVar6 = iVar2;
        piVar6[4] = iVar2;
        if (iVar2 == -1) {
          *piVar6 = piVar6[8];
        }
        else {
          FUN_006d5d90(iVar2,1,iVar5);
          iVar2 = FUN_006d9370(*piVar6);
          piVar6[0xf] = (int)(float)iVar2;
          iVar2 = FUN_006d67a0(*piVar6);
          if (iVar2 != 0) {
            iVar2 = FUN_006d93a0(*piVar6);
            *(float *)(in_ECX + 0x98) = (float)iVar2;
          }
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar5 < *(int *)(in_ECX + 4));
    }
    uVar3 = FUN_00420330();
    *(undefined4 *)(in_ECX + 0x6c) = uVar3;
    FUN_00421430();
    puVar4 = (undefined4 *)(in_ECX + 0x1f8);
    iVar5 = 0xc;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 0x4a;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_006d6320(1);
    if (-1 < param_3) {
      FUN_006d9650(param_3,*(undefined4 *)(in_ECX + 4));
    }
    uVar1 = FUN_00420570();
    *(undefined1 *)(in_ECX + 0x70) = uVar1;
    *(undefined4 *)(in_ECX + 0x2c) = 3;
    *(undefined4 *)(in_ECX + 0x28) = 3;
    FUN_006d5db0();
  }
  return;
}

