/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68cdb0; label: FUN_0068cdb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068cdb0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1;
  if ((&DAT_02924b5c)[DAT_029231a8 * 0x16] == param_1) {
    DAT_029231a8 = -1;
  }
  FUN_00655730(*(undefined4 *)(DAT_0296209c + param_1 * 4));
  iVar2 = FUN_00658330(*(undefined4 *)(DAT_0296209c + iVar1 * 4),1,iVar1);
  piVar3 = &DAT_02924b60;
  do {
    if (piVar3[-1] == iVar1) {
      iVar5 = *piVar3;
      if (iVar2 == -1) {
        if (iVar5 != -1) {
          if (iVar5 != 99999) {
            FUN_00684400(piVar3);
          }
          DAT_02962a2c = DAT_02962a2c + -1;
          *piVar3 = -1;
        }
      }
      else {
        if ((iVar5 != -1) && (iVar5 != 99999)) {
          *(short *)(iVar5 * 0x330 + 0x182 + DAT_029620a4) = (short)iVar2;
        }
        piVar3[-1] = iVar2;
      }
    }
    piVar3 = piVar3 + 0x16;
  } while ((int)piVar3 < 0x292fb60);
  iVar5 = 0;
  if (0 < DAT_02962094) {
    iVar4 = 0;
    do {
      if (*(short *)(iVar4 + 0x182 + DAT_029620a4) == iVar1) {
        if (iVar2 == -1) {
          param_1 = iVar5;
          FUN_00684400(&param_1);
        }
        else {
          *(short *)(iVar4 + 0x182 + DAT_029620a4) = (short)iVar2;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x330;
    } while (iVar5 < DAT_02962094);
  }
  *(undefined4 *)(DAT_0296209c + iVar1 * 4) = 0;
  DAT_02962a24 = DAT_02962a24 + -1;
  FUN_00661f60(0x3f800000);
  return;
}

