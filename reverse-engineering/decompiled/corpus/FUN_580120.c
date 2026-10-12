/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x580120; label: FUN_00580120
 */

void FUN_00580120(int *param_1,int param_2)

{
  code *pcVar1;
  
  *(undefined1 *)(param_1 + 0x40) = 0;
  if (((param_2 != 0) && (*param_1 != 0)) &&
     (pcVar1 = *(code **)(*param_1 + 0x4c), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1);
  }
  return;
}

