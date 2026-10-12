/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x4432a0; label: FUN_004432a0
 */

undefined4 FUN_004432a0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((((param_2 != 0) && (param_1 != 0)) && (DAT_00923904 != (code *)0x0)) &&
     (puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2), puVar1 != (undefined4 *)0x0)) {
    return *puVar1;
  }
  return 0;
}

