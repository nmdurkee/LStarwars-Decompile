/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c5da0; label: FUN_006c5da0
 */

void FUN_006c5da0(undefined1 *param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5
                 ,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_LAB_0076f9d0;
  in_ECX[7] = 0;
  iVar1 = FUN_004f1ff0(param_1);
  if ((0 < iVar1) && (param_1[iVar1 + -1] == '*')) {
    FUN_004f1f10(local_24,param_1);
    in_ECX[7] = in_ECX[7] | 0x40000000;
    local_24[iVar1 + -1] = 0;
    param_1 = local_24;
  }
  iVar1 = FUN_006be670(param_1);
  in_ECX[3] = iVar1;
  if (iVar1 < 0) {
    uVar3 = FUN_006be730(param_1);
    in_ECX[7] = in_ECX[7] | 0x80000000;
    in_ECX[3] = uVar3;
  }
  else {
    if (iVar1 < DAT_02973ba4) {
      puVar2 = (undefined4 *)(DAT_02973b8c + iVar1 * 0xc);
    }
    else {
      puVar2 = (undefined4 *)0x0;
    }
    if (((int)puVar2[1] < 0) && (param_4 < 1)) {
      FUN_006b7c40(*puVar2);
    }
  }
  in_ECX[7] = in_ECX[7] | param_5;
  in_ECX[4] = param_2;
  in_ECX[5] = param_3;
  in_ECX[8] = param_6;
  in_ECX[6] = param_4;
  in_ECX[9] = param_7;
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

