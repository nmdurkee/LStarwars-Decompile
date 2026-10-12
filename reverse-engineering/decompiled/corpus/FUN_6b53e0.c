/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b53e0; label: FUN_006b53e0
 */

int FUN_006b53e0(int param_1,int param_2,int param_3)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  float *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 0;
  local_c = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  local_8 = 0;
  iVar4 = 0;
  iVar5 = 0;
  *unaff_ESI = in_EAX;
  unaff_ESI[1] = param_2;
  if (in_ECX <= param_2) {
    param_2 = in_ECX + -1;
  }
  if (in_EAX <= param_2) {
    local_30 = (float *)(in_EDX + in_EAX * 4);
    do {
      iVar2 = FUN_006e6b90();
      if (iVar2 < 0x400) {
        if ((-1 < iVar2) && (iVar2 != 0)) goto LAB_006b5488;
      }
      else {
        iVar2 = 0x3ff;
LAB_006b5488:
        fVar1 = *(float *)((param_1 - in_EDX) + (int)local_30) + *(float *)(param_3 + 0x458);
        if (*local_30 < fVar1 == (*local_30 == fVar1)) {
          local_20 = local_20 + iVar2;
          local_28 = local_28 + in_EAX;
          local_18 = local_18 + in_EAX * in_EAX;
          local_10 = local_10 + iVar2 * iVar2;
          local_8 = local_8 + iVar2 * in_EAX;
          iVar5 = iVar5 + 1;
        }
        else {
          local_24 = local_24 + iVar2;
          local_2c = local_2c + in_EAX;
          local_1c = local_1c + in_EAX * in_EAX;
          local_14 = local_14 + iVar2 * iVar2;
          local_c = local_c + iVar2 * in_EAX;
          iVar4 = iVar4 + 1;
        }
      }
      local_30 = local_30 + 1;
      in_EAX = in_EAX + 1;
    } while (in_EAX <= param_2);
  }
  iVar3 = FUN_006e6b90();
  iVar2 = iVar3 + 1;
  unaff_ESI[2] = iVar2 * local_2c + local_28;
  unaff_ESI[3] = iVar2 * local_24 + local_20;
  unaff_ESI[4] = iVar2 * local_1c + local_18;
  unaff_ESI[7] = iVar3 * iVar4 + iVar5 + iVar4;
  unaff_ESI[5] = iVar2 * local_14 + local_10;
  unaff_ESI[6] = iVar2 * local_c + local_8;
  return iVar4;
}

