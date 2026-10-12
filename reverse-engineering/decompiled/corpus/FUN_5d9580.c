/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5d9580; label: FUN_005d9580
 */

char FUN_005d9580(float *param_1,undefined4 *param_2,int param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_60 = *param_1;
  local_5c = param_1[1];
  local_58 = param_1[2];
  iVar6 = 0;
  iVar4 = 0;
  local_54 = *param_2;
  local_50 = param_1[1];
  local_4c = param_1[2];
  local_48 = *param_1;
  local_44 = param_2[1];
  local_40 = param_1[2];
  local_3c = *param_2;
  local_38 = param_2[1];
  local_34 = param_1[2];
  local_30 = *param_1;
  local_2c = param_1[1];
  local_28 = param_2[2];
  local_24 = *param_2;
  local_20 = param_1[1];
  local_1c = param_2[2];
  local_18 = *param_1;
  local_14 = param_2[1];
  local_10 = param_2[2];
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  if (0 < param_4) {
    pfVar1 = (float *)(param_3 + 8);
    do {
      iVar5 = 0;
      pfVar2 = &local_60;
      iVar3 = 2;
      do {
        if (0.0 <= pfVar2[2] * *pfVar1 + pfVar1[-2] * *pfVar2 + pfVar2[1] * pfVar1[-1] + pfVar1[1])
        {
          iVar6 = iVar6 + 1;
        }
        else {
          iVar5 = iVar5 + 1;
        }
        if (0.0 <= pfVar2[5] * *pfVar1 + pfVar2[3] * pfVar1[-2] + pfVar2[4] * pfVar1[-1] + pfVar1[1]
           ) {
          iVar6 = iVar6 + 1;
        }
        else {
          iVar5 = iVar5 + 1;
        }
        if (0.0 <= pfVar2[8] * *pfVar1 + pfVar2[6] * pfVar1[-2] + pfVar2[7] * pfVar1[-1] + pfVar1[1]
           ) {
          iVar6 = iVar6 + 1;
        }
        else {
          iVar5 = iVar5 + 1;
        }
        if (0.0 <= pfVar2[0xb] * *pfVar1 + pfVar2[9] * pfVar1[-2] + pfVar2[10] * pfVar1[-1] +
                   pfVar1[1]) {
          iVar6 = iVar6 + 1;
        }
        else {
          iVar5 = iVar5 + 1;
        }
        pfVar2 = pfVar2 + 0xc;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (iVar5 == 8) {
        return '\0';
      }
      iVar4 = iVar4 + 1;
      pfVar1 = pfVar1 + 4;
    } while (iVar4 < param_4);
  }
  return (iVar6 != param_4 * 8) + '\x01';
}

