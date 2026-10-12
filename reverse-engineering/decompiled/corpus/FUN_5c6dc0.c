/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c6dc0; label: FUN_005c6dc0
 */

undefined2 FUN_005c6dc0(float *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float local_80;
  undefined4 local_7c;
  float local_78;
  undefined4 local_70;
  undefined4 local_6c;
  float local_68;
  undefined4 local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  
  local_80 = *param_1;
  iVar3 = param_3 * 0x380 + in_ECX;
  iVar1 = *(int *)(iVar3 + 0x260);
  local_7c = param_2[1];
  iVar5 = 0;
  local_78 = param_1[2];
  local_70 = *param_2;
  local_6c = param_2[1];
  local_68 = param_1[2];
  local_60 = *param_2;
  local_5c = param_1[1];
  local_58 = param_1[2];
  local_50 = *param_1;
  local_4c = param_1[1];
  local_48 = param_2[2];
  local_40 = *param_1;
  local_3c = param_2[1];
  local_38 = param_2[2];
  local_30 = *param_2;
  local_2c = param_2[1];
  local_28 = param_2[2];
  local_20 = *param_2;
  local_1c = param_1[1];
  local_18 = param_2[2];
  if (0 < iVar1) {
    pfVar4 = (float *)(iVar3 + 0x1a8);
    do {
      iVar3 = 0;
      pfVar2 = &local_80;
      do {
        if (0.0 < *pfVar4 * pfVar2[-2] + pfVar2[-3] * pfVar4[-1] + pfVar4[-2] * pfVar2[-4] +
                  pfVar4[1]) break;
        if (0.0 < *pfVar4 * pfVar2[2] + pfVar2[1] * pfVar4[-1] + pfVar4[-2] * *pfVar2 + pfVar4[1]) {
          iVar3 = iVar3 + 1;
          break;
        }
        if (0.0 < *pfVar4 * pfVar2[6] + pfVar2[5] * pfVar4[-1] + pfVar4[-2] * pfVar2[4] + pfVar4[1])
        {
          iVar3 = iVar3 + 2;
          break;
        }
        if (0.0 < *pfVar4 * pfVar2[10] + pfVar2[9] * pfVar4[-1] + pfVar4[-2] * pfVar2[8] + pfVar4[1]
           ) {
          iVar3 = iVar3 + 3;
          break;
        }
        iVar3 = iVar3 + 4;
        pfVar2 = pfVar2 + 0x10;
      } while (iVar3 < 8);
      if (iVar3 == 8) {
        return 0;
      }
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 4;
    } while (iVar5 < iVar1);
  }
  return 1;
}

