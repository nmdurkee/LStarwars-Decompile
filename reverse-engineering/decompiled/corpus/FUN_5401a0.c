/* Ghidra analysis pseudocode, not original source.
 * ev_3c859e02b972a8e60701cf54913e5d4895bfb87c225b3b379a359b744e8ff688
 * Entry: 0x5401a0; label: FUN_005401a0
 */

int FUN_005401a0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_1,&DAT_007614fc);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_004f8b10(param_1,&DAT_007614f8);
  return (-(uint)(iVar1 != 0) & 0xfffffffe) + 1;
}

