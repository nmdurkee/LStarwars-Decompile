/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42da10; label: FUN_0042da10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042da10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == DAT_008765ec) {
    iVar1 = FUN_005cfac0(&DAT_0087ad30);
    if (iVar1 != 0) {
      uVar2 = FUN_005cf9e0(&DAT_0087ad30);
      FUN_00571b60(*(undefined4 *)(PTR_DAT_00802c54 + 0x138),0x10,uVar2);
      FUN_005cfc00(&DAT_0087ad30,0);
    }
    iVar1 = FUN_005cfac0(&DAT_0087ad3c);
    if (iVar1 != 0) {
      uVar2 = FUN_005cf9e0(&DAT_0087ad3c);
      FUN_00571b60(*(undefined4 *)(PTR_DAT_00802c54 + 0x138),0x10,uVar2);
      FUN_005cfc00(&DAT_0087ad3c,0);
    }
  }
  return;
}

