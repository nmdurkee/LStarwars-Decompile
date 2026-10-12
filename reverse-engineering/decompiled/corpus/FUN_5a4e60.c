/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a4e60; label: FUN_005a4e60
 */

undefined4 FUN_005a4e60(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_005a47c0(PTR_DAT_00802c54,param_1,0x40000000);
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 200) = *(uint *)(iVar1 + 200) | 1;
    *(int *)(iVar1 + 0x30) = param_1;
    FUN_004399e0(param_1,param_1 + 0x80);
    return 1;
  }
  *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  return 0;
}

