/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x6334d0; label: FUN_006334d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

