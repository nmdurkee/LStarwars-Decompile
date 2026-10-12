/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x4442b0; label: FUN_004442b0
 */

undefined4
FUN_004442b0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int iVar1;
  int iVar2;
  
  if (((param_6 != 0) && (iVar1 = **(int **)(param_3 + 0xd0), iVar1 != 0)) &&
     (iVar2 = *(int *)(iVar1 + 0xea4), iVar2 != 0)) {
    *(undefined4 *)(iVar1 + 0xea4) = 0;
    *(undefined4 *)(iVar2 + 0xea4) = 0;
  }
  return 1;
}

