/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6740; label: FUN_006d6740
 */

void FUN_006d6740(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(DAT_02975144 + 0x4e13);
  *puVar1 = 0;
  if (param_1 != 0) {
    FUN_004f1f10(puVar1,param_1);
  }
  return;
}

