/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a4e60; label: FUN_005a4e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

