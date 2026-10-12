/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd1e0; label: FUN_004cd1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cd1e0(int param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x5078) != 0)) &&
     (iVar2 = 0, 0 < *(int *)(param_1 + 0x507c))) {
    pbVar1 = (byte *)(*(int *)(param_1 + 0x5078) + 0x3c);
    do {
      *pbVar1 = *pbVar1 & 0xfb;
      iVar2 = iVar2 + 1;
      pbVar1 = pbVar1 + 0x70;
    } while (iVar2 < *(int *)(param_1 + 0x507c));
  }
  return;
}

