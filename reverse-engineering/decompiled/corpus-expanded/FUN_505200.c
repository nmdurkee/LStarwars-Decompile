/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505200; label: FUN_00505200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00505200(int param_1,float *param_2,float param_3)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  if ((((*param_2 - param_3 <= *(float *)(param_1 + 0x20)) &&
       (*(float *)(param_1 + 0x14) <= *param_2 + param_3)) &&
      (param_2[1] - param_3 <= *(float *)(param_1 + 0x24))) &&
     (((*(float *)(param_1 + 0x18) <= param_2[1] + param_3 &&
       (param_2[2] - param_3 <= *(float *)(param_1 + 0x28))) &&
      (*(float *)(param_1 + 0x1c) <= param_3 + param_2[2])))) {
    local_1c = param_3;
    iVar5 = 0;
    local_20 = param_3;
    local_24 = param_3;
    if (0 < *(short *)(param_1 + 0x2c)) {
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x30) + iVar5 * 8);
        iVar1 = *(int *)(param_1 + 0x30) + iVar5 * 8;
        if (iVar2 == 1) {
          iVar1 = *(int *)(iVar1 + 4);
          fVar6 = (float10)FUN_005b3c50(param_2,iVar1,local_c);
          fVar4 = param_3 + *(float *)(iVar1 + 0xc);
          if ((float)fVar6 < fVar4 * fVar4) {
            return 1;
          }
        }
        else if (iVar2 == 2) {
          iVar1 = *(int *)(iVar1 + 4);
          FUN_005b30a0(&local_18,param_2,iVar1);
          FUN_005b30a0(&local_30,&local_24,iVar1);
          FUN_005b3800(&local_30,&local_30,iVar1 + 0x30);
          local_30 = ABS(local_30);
          local_28 = ABS(local_28);
          local_2c = ABS(local_2c);
          if (((((local_18 - local_30 <= *(float *)(iVar1 + 0x4c)) &&
                (*(float *)(iVar1 + 0x40) <= local_30 + local_18)) &&
               (local_14 - local_2c <= *(float *)(iVar1 + 0x50))) &&
              ((*(float *)(iVar1 + 0x44) <= local_2c + local_14 &&
               (local_10 - local_28 <= *(float *)(iVar1 + 0x54))))) &&
             (*(float *)(iVar1 + 0x48) <= local_28 + local_10)) {
            return 1;
          }
        }
        else if (((iVar2 == 3) &&
                 (pfVar3 = *(float **)(iVar1 + 4), pfVar3[1] - param_3 <= param_2[1])) &&
                ((param_2[1] <= pfVar3[3] + pfVar3[1] + param_3 &&
                 ((*param_2 - *pfVar3) * (*param_2 - *pfVar3) +
                  (param_2[2] - pfVar3[2]) * (param_2[2] - pfVar3[2]) <
                  (pfVar3[4] + param_3) * (pfVar3[4] + param_3))))) {
          return 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(param_1 + 0x2c));
    }
    return 0;
  }
  return 0;
}

