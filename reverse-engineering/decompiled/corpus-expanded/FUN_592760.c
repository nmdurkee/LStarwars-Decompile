/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x592760; label: FUN_00592760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00592760(short *param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  int *piVar3;
  short sVar4;
  int iVar5;
  int local_4;
  
  iVar2 = (int)param_1;
  if (param_1 != (short *)0x0) {
    param_1 = (short *)((int)param_1 + 0x6c);
    local_4 = 2;
    do {
      piVar3 = *(int **)(*param_1 * 0x4c + 0x10 + DAT_0093b274);
      if (piVar3 != (int *)0x0) {
        iVar5 = *piVar3;
        while (iVar5 != 0) {
          if (param_2 == 0) {
            piVar3[1] = piVar3[1] & 0xffff7fff;
          }
          else {
            piVar3[1] = piVar3[1] | 0x8000;
            psVar1 = *(short **)(iVar2 + 0xa68);
            if (psVar1 != (short *)0x0) {
              sVar4 = *psVar1;
              iVar5 = 0;
              if (sVar4 != -1) {
                do {
                  if (sVar4 == (short)piVar3[2]) {
                    piVar3[1] = piVar3[1] & 0xffff7fff;
                    break;
                  }
                  sVar4 = psVar1[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                } while (sVar4 != -1);
              }
            }
          }
          piVar3 = piVar3 + 0x13;
          iVar5 = *piVar3;
        }
      }
      param_1 = param_1 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

