/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f4020; label: FUN_004f4020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f4020(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_006de050();
  if (iVar1 != 0) {
    uVar2 = FUN_006de050();
    FUN_004f3f50(0xffffffff,uVar2);
  }
  return;
}

