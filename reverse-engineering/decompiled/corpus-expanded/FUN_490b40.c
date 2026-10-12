/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490b40; label: FUN_00490b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00490b40(int param_1)

{
  float fVar1;
  
  if ((((*(ushort *)(param_1 + 0x94) & 0x10) != 0) && ((*(ushort *)(param_1 + 0x94) & 2) != 0)) &&
     (fVar1 = *(float *)(param_1 + 0x78), !NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0))) {
    return 1;
  }
  return 0;
}

