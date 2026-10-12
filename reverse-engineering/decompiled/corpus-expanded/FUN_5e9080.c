/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e9080; label: FUN_005e9080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005e9080(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_4;
  
  if (DAT_00973868 == 0) {
    FUN_005c9140();
  }
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + param_2;
  }
  if (*(int *)(param_1 + 4) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 4) + param_2;
  }
  *(int *)(param_1 + 4) = iVar3;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc) + param_2;
  }
  *(int *)(param_1 + 0xc) = iVar3;
  if ((iVar3 != 0) && (local_4 = 0, 0 < *(int *)(param_1 + 8))) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + local_4 * 4);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + param_2;
      }
      *(int *)(*(int *)(param_1 + 0xc) + local_4 * 4) = iVar3;
      if (*(int *)(*(int *)(param_1 + 0xc) + local_4 * 4) != 0) {
        piVar2 = *(int **)(*(int *)(param_1 + 0xc) + local_4 * 4);
        if (piVar2[2] == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = piVar2[2] + param_2;
        }
        piVar2[2] = iVar3;
        if ((iVar3 != 0) && (iVar3 = 0, 0 < *piVar2)) {
          do {
            piVar1 = (int *)(piVar2[2] + iVar3 * 4);
            iVar5 = *piVar1;
            if (iVar5 == 0) {
              iVar5 = 0;
            }
            else {
              iVar5 = iVar5 + param_2;
            }
            *piVar1 = iVar5;
            if (*(int *)(piVar2[2] + iVar3 * 4) != 0) {
              iVar5 = *(int *)(piVar2[2] + iVar3 * 4);
              if (*(int *)(iVar5 + 4) == 0) {
                iVar4 = 0;
              }
              else {
                iVar4 = *(int *)(iVar5 + 4) + param_2;
              }
              *(int *)(iVar5 + 4) = iVar4;
              if (*(int *)(iVar5 + 8) == 0) {
                iVar4 = 0;
              }
              else {
                iVar4 = *(int *)(iVar5 + 8) + param_2;
              }
              *(int *)(iVar5 + 8) = iVar4;
              if ((iVar4 != 0) && ('\0' < *(char *)(iVar5 + 0xc))) {
                iVar4 = 0;
                do {
                  iVar6 = *(int *)(*(int *)(iVar5 + 8) + iVar4 * 4);
                  if (iVar6 == 0) {
                    iVar6 = 0;
                  }
                  else {
                    iVar6 = iVar6 + param_2;
                  }
                  *(int *)(*(int *)(iVar5 + 8) + iVar4 * 4) = iVar6;
                  if (*(int *)(*(int *)(iVar5 + 8) + iVar4 * 4) != 0) {
                    iVar6 = *(int *)(*(int *)(iVar5 + 8) + iVar4 * 4);
                    iVar7 = *(int *)(iVar6 + 4);
                    if (iVar7 == 0) {
                      iVar7 = 0;
                    }
                    else {
                      iVar7 = iVar7 + param_2;
                    }
                    *(int *)(iVar6 + 4) = iVar7;
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar4 < *(char *)(iVar5 + 0xc));
              }
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < *piVar2);
        }
      }
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(param_1 + 8));
  }
  return param_1;
}

