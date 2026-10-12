/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x73eb27; label: FUN_0073eb27
 */

undefined4 FUN_0073eb27(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 < 0x80000000)) {
    uVar1 = FUN_007158bd();
    return uVar1;
  }
  return 0x80070057;
}

