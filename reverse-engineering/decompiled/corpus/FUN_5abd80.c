/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5abd80; label: FUN_005abd80
 */

int FUN_005abd80(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_1c = 1e+09;
  local_c = 0;
  local_8 = 0;
  local_4 = 0xbf800000;
  iVar3 = 0;
  FUN_005b3200(&local_c,&local_c,param_2);
  iVar5 = 0;
  iVar4 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((((*(uint *)(iVar4 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) &&
          (*(char *)(iVar4 + 0x28b) == '\0')) &&
         (((*(byte *)(iVar4 + 0x1f8) & 1) != 0 && (*(char *)(iVar4 + 0x288) != '\0')))) {
        fVar6 = (float10)FUN_005b3c50(iVar4 + 0x80,param_2 + 0x30,&local_18);
        fVar1 = (float)fVar6;
        if (fVar1 < local_1c) {
          fVar6 = (float10)FUN_005c0240(fVar1);
          if ((float)fVar6 <= 0.0) {
            fVar2 = 0.0;
          }
          else {
            fVar2 = 1.0 / (float)fVar6;
          }
          local_18 = fVar2 * local_18;
          local_14 = local_14 * fVar2;
          local_10 = fVar2 * local_10;
          fVar6 = (float10)FUN_005b39e0(&local_18,&local_c);
          if ((float)(&DAT_029899a0)[DAT_00805e2c + 0x4000 >> 1 & 0x7fff] < (float)fVar6) {
            iVar3 = iVar4;
            local_1c = fVar1;
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x10d8;
    } while (iVar5 < DAT_0093d500);
  }
  return iVar3;
}

