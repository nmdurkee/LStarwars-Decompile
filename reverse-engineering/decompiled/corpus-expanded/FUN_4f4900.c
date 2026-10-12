/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f4900; label: FUN_004f4900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f4900(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((&DAT_00917000)[param_1 * 0x84] != '\0') {
    uVar1 = (&DAT_00917004)[param_1 * 0x21];
  }
  return uVar1;
}

