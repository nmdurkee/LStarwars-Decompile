/* Ghidra pseudocode, not original source.
 * ev_c781f6f2f7d78097ae9ff869f9175a8231755f2e9224784a2b208dfae7521271
 * Entry: 0x605300; label: FUN_00605300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00605300(int param_1,char param_2)

{
  byte *pbVar1;
  int in_ECX;
  byte bVar2;
  
  pbVar1 = (byte *)((param_1 >> 3) + 0x300 + in_ECX);
  bVar2 = '\x01' << ((byte)param_1 & 7);
  if (param_2 != '\0') {
    *pbVar1 = *pbVar1 | bVar2;
    return;
  }
  *pbVar1 = *pbVar1 & ~bVar2;
  return;
}

