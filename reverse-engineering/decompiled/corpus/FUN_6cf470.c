/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6cf470; label: FUN_006cf470
 */

undefined4 FUN_006cf470(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_02974644 == -1) {
    FUN_006d1d10(param_1);
    return 1;
  }
  DAT_02973aa0 = DAT_02974644;
  if ((((-1 < param_1) && (param_1 < DAT_02973bac)) &&
      (iVar1 = DAT_02973b90 + param_1 * 0x18, iVar1 != 0)) &&
     ((*(uint *)(iVar1 + 4) & 0x4000000) == 0)) {
    uVar2 = FUN_006cf3b0();
    return uVar2;
  }
  return 0;
}

