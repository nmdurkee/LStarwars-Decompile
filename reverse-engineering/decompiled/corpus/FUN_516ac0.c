/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x516ac0; label: FUN_00516ac0
 */

undefined4 FUN_00516ac0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return 1;
  }
  if (param_1 == 0) {
    return 1;
  }
  if ((DAT_00923908 == (code *)0x0) ||
     (puVar1 = (undefined4 *)(*DAT_00923908)(param_1,param_3), puVar1 == (undefined4 *)0x0)) {
    iVar2 = *(int *)(param_3 + 0xd0);
    if (iVar2 == 0) {
      return 1;
    }
    if ((*(uint *)(iVar2 + 0x1f8) & 0x400) == 0) {
      return 1;
    }
    if (*(byte *)(param_3 + 0x138) == 0xff) {
      return 1;
    }
    puVar1 = (undefined4 *)
             ((uint)*(byte *)(param_3 + 0x138) * 0xa4 + 0x20 + *(int *)(param_1 + 0x18));
  }
  else {
    iVar2 = *(int *)(param_3 + 0xd0);
  }
  *(undefined4 *)(iVar2 + 0x5c) = *puVar1;
  *(undefined4 *)(iVar2 + 0x60) = puVar1[1];
  *(undefined4 *)(iVar2 + 100) = puVar1[2];
  return 1;
}

