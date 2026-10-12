/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x5518a0; label: FUN_005518a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005518a0(int *param_1,float param_2)

{
  int iVar1;
  short sVar2;
  short sVar3;
  short *psVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  float10 fVar8;
  undefined1 local_c [12];
  
  if (((param_1 != (int *)0x0) && ((short *)*param_1 != (short *)0x0)) &&
     (sVar2 = *(short *)*param_1, 1 < sVar2)) {
    if (*(char *)((int)param_1 + 6) == '\0') {
      iVar6 = (int)sVar2;
    }
    else {
      iVar6 = sVar2 + 1;
    }
    iVar1 = iVar6 + -1;
    if ((short)param_1[1] < iVar1) {
      if (param_2 < 0.0) {
        if (-1 < (short)param_1[1]) {
          while (param_2 < 0.0) {
            param_2 = param_2 + (float)param_1[2];
            param_1[2] = (int)param_2;
            if (0.0 <= param_2) {
              psVar4 = (short *)*param_1;
              iVar6 = (int)psVar4[1] * (int)(short)param_1[1] + *(int *)(psVar4 + 4);
              FUN_005b3800(local_c,(((short)param_1[1] + 1) % (int)*psVar4) * (int)psVar4[1] +
                                   *(int *)(psVar4 + 4),iVar6);
              if ((float)param_1[3] == 0.0) {
                fVar5 = 0.0;
              }
              else {
                fVar5 = (float)param_1[2] / (float)param_1[3];
              }
              FUN_005b3830(local_c,local_c,fVar5);
              FUN_005b37d0(param_1 + 4,iVar6,local_c);
              break;
            }
            *(short *)(param_1 + 1) = (short)param_1[1] + -1;
            if ((short)param_1[1] < 0) {
              if (*(char *)((int)param_1 + 6) == '\0') {
                *(undefined1 *)((int)param_1 + 7) = 1;
                piVar7 = *(int **)(*param_1 + 8);
                param_1[4] = *piVar7;
                param_1[5] = piVar7[1];
                iVar6 = piVar7[2];
                param_1[7] = 0;
                param_1[2] = 0;
                param_1[6] = iVar6;
                *(short *)(param_1 + 1) = (short)param_1[1] + 1;
                return;
              }
              *(short *)(param_1 + 1) = (short)iVar6 + -2;
            }
            psVar4 = (short *)*param_1;
            piVar7 = (int *)((((short)param_1[1] + 1) % (int)*psVar4) * (int)psVar4[1] +
                            *(int *)(psVar4 + 4));
            fVar8 = (float10)FUN_005becc0(piVar7,(int)psVar4[1] * (int)(short)param_1[1] +
                                                 *(int *)(psVar4 + 4),local_c);
            param_1[3] = (int)(float)fVar8;
            param_1[2] = (int)(float)fVar8;
            if (param_2 == 0.0) {
              param_1[4] = *piVar7;
              param_1[5] = piVar7[1];
              param_1[6] = piVar7[2];
            }
          }
        }
      }
      else {
        while (0.0 < param_2) {
          param_2 = param_2 + (float)param_1[2];
          param_1[2] = (int)param_2;
          if ((float)param_1[3] < param_2 == ((float)param_1[3] == param_2)) {
            psVar4 = (short *)*param_1;
            iVar6 = (int)psVar4[1] * (int)(short)param_1[1] + *(int *)(psVar4 + 4);
            FUN_005b3800(local_c,(((short)param_1[1] + 1) % (int)*psVar4) * (int)psVar4[1] +
                                 *(int *)(psVar4 + 4),iVar6);
            if ((float)param_1[3] == 0.0) {
              fVar5 = 0.0;
            }
            else {
              fVar5 = (float)param_1[2] / (float)param_1[3];
            }
            FUN_005b3830(local_c,local_c,fVar5);
            FUN_005b37d0(param_1 + 4,iVar6,local_c);
            break;
          }
          *(short *)(param_1 + 1) = (short)param_1[1] + 1;
          param_2 = param_2 - (float)param_1[3];
          sVar2 = (short)param_1[1];
          if (iVar1 <= sVar2) {
            if (*(char *)((int)param_1 + 6) == '\0') {
              *(undefined1 *)((int)param_1 + 7) = 1;
              piVar7 = (int *)((int)*(short *)(*param_1 + 2) * (int)sVar2 + *(int *)(*param_1 + 8));
              param_1[4] = *piVar7;
              param_1[5] = piVar7[1];
              iVar6 = piVar7[2];
              param_1[7] = 0x3f800000;
              param_1[2] = param_1[3];
              param_1[6] = iVar6;
              *(short *)(param_1 + 1) = sVar2 + -1;
              return;
            }
            *(undefined2 *)(param_1 + 1) = 0;
          }
          psVar4 = (short *)*param_1;
          sVar2 = psVar4[1];
          iVar6 = *(int *)(psVar4 + 4);
          sVar3 = *psVar4;
          param_1[2] = 0;
          piVar7 = (int *)((int)sVar2 * (int)(short)param_1[1] + iVar6);
          fVar8 = (float10)FUN_005becc0((((short)param_1[1] + 1) % (int)sVar3) * (int)sVar2 + iVar6,
                                        piVar7,local_c);
          param_1[3] = (int)(float)fVar8;
          if (param_2 == 0.0) {
            param_1[4] = *piVar7;
            param_1[5] = piVar7[1];
            param_1[6] = piVar7[2];
          }
        }
      }
      param_1[7] = (int)(((float)(int)(short)param_1[1] + (float)param_1[2] / (float)param_1[3]) /
                        (float)iVar1);
    }
  }
  return;
}

