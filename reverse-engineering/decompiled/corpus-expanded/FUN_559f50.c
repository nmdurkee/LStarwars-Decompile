/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559f50; label: FUN_00559f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00559f50(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) && (param_3 != 0)) {
    if ((param_2 < 0) || (*DAT_0093b268 < param_2)) {
      iVar5 = 0;
      if (0 < *DAT_0093b268) {
        piVar2 = (int *)(DAT_0093b268[2] + 0x44);
        piVar1 = (int *)(*param_1 + 4);
        do {
          if (*piVar2 != 0) {
            piVar3 = (int *)piVar1[2];
            iVar4 = 0;
            if (0 < *piVar1) {
              do {
                if (*piVar3 == param_3) {
                  return piVar3;
                }
                iVar4 = iVar4 + 1;
                piVar3 = piVar3 + 2;
              } while (iVar4 < *piVar1);
            }
          }
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 0x27;
          piVar1 = piVar1 + 5;
        } while (iVar5 < *DAT_0093b268);
      }
    }
    else {
      iVar5 = *param_1 + param_2 * 0x14;
      if (*(int *)(DAT_0093b268[2] + 0x44 + param_2 * 0x9c) != 0) {
        piVar1 = *(int **)(iVar5 + 0xc);
        iVar5 = *(int *)(iVar5 + 4);
        iVar4 = 0;
        if (0 < iVar5) {
          do {
            if (*piVar1 == param_3) {
              return piVar1;
            }
            iVar4 = iVar4 + 1;
            piVar1 = piVar1 + 2;
          } while (iVar4 < iVar5);
          return (int *)0x0;
        }
      }
    }
  }
  return (int *)0x0;
}

