/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fe40; label: FUN_0051fe40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0051fe40(int param_1,int param_2)

{
  if (param_2 == 0) {
    return *(undefined4 *)(param_1 + 0xc4);
  }
  return *(undefined4 *)(param_2 + 0x2c);
}

