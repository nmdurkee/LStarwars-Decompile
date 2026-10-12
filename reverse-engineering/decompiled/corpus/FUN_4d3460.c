/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d3460; label: FUN_004d3460
 */

void FUN_004d3460(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 4) != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xcc4), iVar1 != 0))
  {
    FUN_004d2c40(param_1,iVar1);
    *(uint *)(param_1 + 0xf0) = *(uint *)(param_1 + 0xf0) & 0xfffffffb;
  }
  return;
}

