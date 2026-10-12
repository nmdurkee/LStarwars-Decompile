/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74af70; label: FUN_0074af70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0074af70(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  bool bVar3;
  
  if (((&DAT_0297daa0)[*param_1] & 4) == 0) {
    iVar1 = 8;
    bVar3 = true;
    pbVar2 = (byte *)"defined";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar3 = *param_1 == *pbVar2;
      param_1 = param_1 + 1;
      pbVar2 = pbVar2 + 1;
    } while (bVar3);
    if (!bVar3) {
      return 0;
    }
  }
  return 1;
}

