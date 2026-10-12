/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6940; label: FUN_006d6940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006d6940(uint *param_1)

{
  byte bVar1;
  
  if (DAT_029755a3 != DAT_029755a2) {
    bVar1 = (&DAT_029755f8)[DAT_029755a2];
    if (param_1 != (uint *)0x0) {
      *param_1 = (uint)(byte)(&DAT_029756f8)[DAT_029755a2];
    }
    DAT_029755a2 = DAT_029755a2 + 1;
    return (uint)bVar1;
  }
  return 0xffffffff;
}

