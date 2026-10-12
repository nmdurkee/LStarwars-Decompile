/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43e1a0; label: FUN_0043e1a0
 */

void FUN_0043e1a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  param_3 = param_3 + 0x2af0;
  if ((param_3 != 0) && (iVar1 = 0, 0 < *(int *)(PTR_DAT_00802c54 + 0x2aec))) {
    do {
      FUN_00559ee0(param_1,param_2,0,param_3);
      iVar1 = iVar1 + 1;
      param_3 = param_3 + 0xdc;
    } while (iVar1 < *(int *)(PTR_DAT_00802c54 + 0x2aec));
  }
  return;
}

