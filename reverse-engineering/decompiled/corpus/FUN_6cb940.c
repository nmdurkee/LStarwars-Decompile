/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cb940; label: FUN_006cb940
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006cb940(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  undefined8 uVar4;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  local_48 = 1.0;
  if ((*(char *)((int)param_1 + 0x65) != '\0') && ((float)param_1[0x5b] != 0.0)) {
    local_48 = 3.0;
  }
  if ((*(char *)((int)param_1 + 0x5e) != '\0') && ((float)param_1[0x54] != 0.0)) {
    _DAT_0081f9b4 = (float)param_1[0x11] * local_48 + _DAT_0081f9b4;
  }
  if ((*(char *)((int)param_1 + 0x5f) != '\0') && ((float)param_1[0x55] != 0.0)) {
    if (_DAT_0081f9b4 <= 0.1) {
      _DAT_0081f9b4 = 0.1;
    }
    else {
      _DAT_0081f9b4 = _DAT_0081f9b4 - (float)param_1[0x11] * local_48;
    }
  }
  local_48 = 0.0;
  iVar2 = FUN_006ca2f0(&local_40);
  if (iVar2 != 0) {
    local_20 = local_40 - (float)param_1[8];
    local_1c = local_3c - (float)param_1[9];
    local_18 = local_38 - (float)param_1[10];
    fVar3 = (float10)FUN_005c0240(local_18 * local_18 + local_20 * local_20 + local_1c * local_1c);
    local_48 = (float)fVar3;
  }
  local_2c = (float)param_1[0xd];
  local_28 = (float)param_1[0xe];
  local_30 = (float)param_1[0xc];
  local_24 = param_1[0xf];
  FUN_005b3b30(&local_30,&local_30);
  local_24 = 0x3f800000;
  local_20 = local_48 * local_30;
  local_1c = local_2c * local_48;
  local_18 = local_48 * local_28;
  local_40 = (float)param_1[8] + local_20;
  local_3c = (float)param_1[9] + local_1c;
  local_38 = (float)param_1[10] + local_18;
  if ((*(char *)((int)param_1 + 0x7b) == '\0') || ((float)param_1[0x49] == 0.0)) {
    local_20 = local_40 - *(float *)(in_ECX + 0x40);
    local_1c = local_3c - *(float *)(in_ECX + 0x44);
    local_18 = local_38 - *(float *)(in_ECX + 0x48);
    *(float *)(in_ECX + 0x50) = local_20;
    *(float *)(in_ECX + 0x54) = local_1c;
    *(float *)(in_ECX + 0x58) = local_18;
    *(undefined4 *)(in_ECX + 0x5c) = local_14;
    *(float *)(in_ECX + 0x40) = local_40;
    *(float *)(in_ECX + 0x44) = local_3c;
  }
  else {
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0;
    *(undefined4 *)(in_ECX + 0x58) = 0;
    *(undefined4 *)(in_ECX + 0x5c) = 0x3f800000;
    *(float *)(in_ECX + 0x40) = local_40;
    *(float *)(in_ECX + 0x44) = local_3c;
  }
  *(float *)(in_ECX + 0x48) = local_38;
  *(undefined4 *)(in_ECX + 0x4c) = local_34;
  *(undefined4 *)(in_ECX + 0x60) = *param_1;
  *(undefined4 *)(in_ECX + 100) = param_1[1];
  *(undefined4 *)(in_ECX + 0x68) = param_1[2];
  *(undefined4 *)(in_ECX + 0x6c) = param_1[3];
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(in_ECX + 0x40);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(in_ECX + 0x44);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(in_ECX + 0x48);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(in_ECX + 0x4c);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x5c) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x6c) = 0x3f800000;
  if (*param_2 != 0) {
    uVar1 = *(undefined4 *)(in_ECX + 0x10);
    while( true ) {
      uVar4 = FUN_006c69a0(uVar1,1);
      if ((int)uVar4 != 0) break;
      if (*(int *)((ulonglong)uVar4 >> 0x20) == 0) {
        return 0;
      }
    }
    *(undefined4 *)(in_ECX + 0x14) = 1;
  }
  return 0;
}

