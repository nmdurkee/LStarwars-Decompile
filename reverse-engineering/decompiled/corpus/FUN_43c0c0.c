/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43c0c0; label: FUN_0043c0c0
 */

undefined4 FUN_0043c0c0(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_1,&DAT_00755d44);
  if (iVar1 == 0) {
    *param_2 = 0;
    return 1;
  }
  iVar1 = FUN_004f8b10(param_1,&DAT_00755d3c);
  if (iVar1 == 0) {
    *param_2 = 1;
    return 1;
  }
  iVar1 = FUN_004f8b10(param_1,"TIPTOE");
  if (iVar1 == 0) {
    *param_2 = 2;
    return 1;
  }
  return 0;
}

