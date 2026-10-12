/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d25b0; label: FUN_006d25b0
 */

undefined4 FUN_006d25b0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 < 0) || (DAT_02973bac <= param_1)) {
    iVar3 = 0;
  }
  else {
    iVar3 = DAT_02973b90 + param_1 * 0x18;
  }
  uVar2 = 0;
  puVar1 = DAT_0081fa94;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      if ((*(uint *)(iVar3 + 4) & 0x4000000) == 0) {
        uVar2 = FUN_006cf470(param_1);
      }
      return uVar2;
    }
    if (puVar1[2] == iVar3) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  uVar2 = FUN_006d2450(puVar1 + 2);
  return uVar2;
}

