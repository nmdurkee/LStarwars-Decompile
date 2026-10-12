/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b570; label: FUN_0055b570
 */

void FUN_0055b570(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_0055b520(param_1,param_2);
  if (iVar1 != 0) {
    if (param_3 != 0) {
      FUN_005f33b0(iVar1,param_3);
    }
    if (param_4 != 0) {
      FUN_005f33b0(iVar1,param_4);
    }
  }
  return;
}

