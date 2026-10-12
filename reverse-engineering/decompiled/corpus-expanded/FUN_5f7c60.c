/* Ghidra pseudocode, not original source.
 * ev_cf2ac3d06457ecccb228c84c214202b97dbe51dc177c28ee443aaf4c995f45e9
 * Entry: 0x5f7c60; label: FUN_005f7c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f7c60(int param_1,byte param_2,uint *param_3,uint *param_4)

{
  *param_3 = *(ushort *)(param_1 + 4) >> (param_2 & 0x1f) & 0xfffffffe;
  *param_4 = *(ushort *)(param_1 + 6) >> (param_2 & 0x1f) & 0xfffffffe;
  return;
}

