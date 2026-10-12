/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6ce2b0; label: FUN_006ce2b0
 */

void FUN_006ce2b0(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int *in_ECX;
  float local_50;
  float local_4c;
  float local_48;
  int local_44;
  float local_40;
  float local_3c;
  float local_38;
  int local_34;
  float local_2c;
  float local_1c;
  
  iVar1 = in_ECX[1];
  local_50 = 0.0;
  iVar2 = *in_ECX;
  local_4c = 0.0;
  local_48 = 0.0;
  local_40 = 0.0;
  local_3c = 0.0;
  local_38 = 0.0;
  if (iVar1 == 0) {
    if (iVar2 != 0) {
      local_50 = *(float *)(iVar2 + 0x10);
      local_4c = *(float *)(iVar2 + 0x14);
      local_48 = *(float *)(iVar2 + 0x18);
      local_40 = (float)in_ECX[4];
      local_3c = (float)in_ECX[5];
      local_38 = (float)in_ECX[6];
    }
LAB_006ce333:
    if (iVar1 == 0) goto LAB_006ce360;
    local_50 = (float)in_ECX[4];
    local_4c = (float)in_ECX[5];
    local_48 = (float)in_ECX[6];
  }
  else {
    if (iVar2 == 0) goto LAB_006ce333;
    local_50 = *(float *)(iVar2 + 0x10);
    local_4c = *(float *)(iVar2 + 0x14);
    local_48 = *(float *)(iVar2 + 0x18);
  }
  local_40 = *(float *)(iVar1 + 0x10);
  local_3c = *(float *)(iVar1 + 0x14);
  local_38 = *(float *)(iVar1 + 0x18);
LAB_006ce360:
  fVar3 = (local_50 - local_40) * 0.1;
  local_2c = (local_4c - local_3c) * 0.1;
  fVar4 = (local_48 - local_38) * 0.1;
  local_1c = (float)in_ECX[5] + local_2c;
  local_2c = (float)in_ECX[5] - local_2c;
  if ((in_ECX[0x10] != 0) && (*(int *)(in_ECX[0x10] + 0x50) != 0)) {
    local_1c = local_1c - 10.0;
    local_2c = local_2c - 10.0;
  }
  in_ECX[0xc] = (int)((float)in_ECX[4] + fVar3);
  in_ECX[0xd] = (int)local_1c;
  in_ECX[0xe] = (int)((float)in_ECX[6] + fVar4);
  in_ECX[0xf] = local_34;
  in_ECX[8] = (int)((float)in_ECX[4] - fVar3);
  in_ECX[9] = (int)local_2c;
  in_ECX[10] = (int)((float)in_ECX[6] - fVar4);
  in_ECX[0xb] = local_44;
  return;
}

