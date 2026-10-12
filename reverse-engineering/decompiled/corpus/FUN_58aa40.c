/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58aa40; label: FUN_0058aa40
 */

int FUN_0058aa40(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) && (param_1 = DAT_009553d4, DAT_009553d4 == 0)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
      param_2[1] = 0;
    }
    return 0;
  }
  iVar2 = FUN_0055ce20((int)**(short **)(param_1 + 4),0,0,1,0);
  if (param_2 != (undefined4 *)0x0) {
    if (iVar2 != 0) {
      uVar1 = *(undefined4 *)(iVar2 + 0x1ec);
      *param_2 = *(undefined4 *)(iVar2 + 0x1e8);
      param_2[1] = uVar1;
      return iVar2;
    }
    *param_2 = 0;
    param_2[1] = 0;
  }
  return iVar2;
}

