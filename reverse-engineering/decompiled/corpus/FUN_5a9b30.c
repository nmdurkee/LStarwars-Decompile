/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5a9b30; label: FUN_005a9b30
 */

undefined4
FUN_005a9b30(undefined4 param_1,int param_2,int param_3,short *param_4,undefined4 param_5)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c [2];
  undefined4 local_44;
  
  local_60 = 1e+09;
  local_58 = *(undefined4 *)(param_3 + 0x14);
  local_54 = *(undefined4 *)(param_3 + 0x18);
  local_50 = *(undefined4 *)(param_3 + 0x1c);
  if (DAT_0095df2c == 0) {
    iVar2 = FUN_005a93b0(param_1,param_5,&local_60);
    if (1e+09 <= local_60) {
      return 0;
    }
    if (iVar2 == 0) {
      return 0;
    }
    if (local_60 == 1e+09) {
      return 0;
    }
    iVar2 = iVar2 + 0x44;
  }
  else {
    local_60 = 9999.0;
    local_5c = 9999.0;
    if ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0) {
      fVar4 = (float10)FUN_005becc0(DAT_0093d7f0 + 0x5c,&local_58,0);
      local_60 = (float)fVar4;
    }
    if ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0) {
      fVar4 = (float10)FUN_005becc0(DAT_0093d7f4 + 0x5c,&local_58,0);
      local_5c = (float)fVar4;
    }
    if (((local_5c <= local_60) || (iVar2 = DAT_0093d7f0, 60.0 <= local_60)) &&
       (iVar2 = DAT_0093d7f4, 60.0 <= local_5c)) {
      return 0;
    }
    iVar2 = iVar2 + 0x5c;
  }
  FUN_005b3800(local_4c,iVar2,&local_58);
  sVar1 = FUN_005be2d0(local_4c[0],local_44);
  iVar2 = FUN_0054fa60();
  *param_4 = (-0x38e - (short)(iVar2 / -0x6c000000)) + sVar1 + (short)(iVar2 / 0x25);
  FUN_0054ff40(local_4c,&param_3,param_4);
  FUN_005a8730();
  uVar3 = FUN_005a8880();
  iVar2 = FUN_00582e70(0,&local_58,uVar3,*(undefined4 *)(param_2 + 0x34),0);
  if (iVar2 != 0) {
    *(uint *)(&DAT_00951dd8 + (uint)*(byte *)(iVar2 + 0x103) * 0x138) =
         *(uint *)(&DAT_00951dd8 + (uint)*(byte *)(iVar2 + 0x103) * 0x138) & 0xfffffffb;
  }
  return 1;
}

