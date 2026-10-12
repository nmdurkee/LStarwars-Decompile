/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d52f0; label: FUN_005d52f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d52f0(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int unaff_EDI;
  
  iVar2 = 0;
  if (0 < unaff_EDI) {
    do {
      iVar1 = *(int *)(param_2 + iVar2 * 4);
      pbVar3 = (byte *)((iVar1 >> 2) + param_1);
      iVar2 = iVar2 + 1;
      *pbVar3 = *pbVar3 | param_3 << ((byte)iVar1 & 3) * '\x02';
    } while (iVar2 < unaff_EDI);
  }
  return;
}

