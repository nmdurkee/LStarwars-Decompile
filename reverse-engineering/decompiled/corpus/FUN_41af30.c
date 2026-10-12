/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41af30; label: FUN_0041af30
 */

undefined4 FUN_0041af30(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0056e160(0x1c);
  if ((iVar1 == 0) && ((param_1 == 0 || (*(float *)(param_1 + 0xdec) <= 0.0)))) {
    return 0;
  }
  return 1;
}

