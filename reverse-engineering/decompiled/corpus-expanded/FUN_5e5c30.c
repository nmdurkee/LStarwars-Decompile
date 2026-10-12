/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e5c30; label: FUN_005e5c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5c30(int param_1,char param_2)

{
  byte *pbVar1;
  int in_ECX;
  byte bVar2;
  
  pbVar1 = (byte *)((param_1 >> 3) + 0x80 + in_ECX);
  bVar2 = '\x01' << ((byte)param_1 & 7);
  if (param_2 != '\0') {
    *pbVar1 = *pbVar1 | bVar2;
    return;
  }
  *pbVar1 = *pbVar1 & ~bVar2;
  return;
}

