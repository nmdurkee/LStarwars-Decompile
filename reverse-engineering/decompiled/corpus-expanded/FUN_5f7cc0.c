/* Ghidra pseudocode, not original source.
 * ev_cf2ac3d06457ecccb228c84c214202b97dbe51dc177c28ee443aaf4c995f45e9
 * Entry: 0x5f7cc0; label: FUN_005f7cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f7cc0(int param_1,uint param_2,uint param_3)

{
  *(uint *)(param_1 + 0x20) =
       (param_3 & 0xf) << 4 | *(uint *)(param_1 + 0x20) & 0xffffff00 | param_2 & 0xf;
  return;
}

