/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6334d0; label: FUN_006334d0
 */

void FUN_006334d0(undefined4 *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (int)(param_2 + -1 + (param_2 + -1 >> 0x1f & 0x1fU)) >> 5;
  *param_1 = *(undefined4 *)(in_ECX + 0x1c + iVar1 * 4);
  *(undefined4 **)(in_ECX + 0x1c + iVar1 * 4) = param_1;
  return;
}

