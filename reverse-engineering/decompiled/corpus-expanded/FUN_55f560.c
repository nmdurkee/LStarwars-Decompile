/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f560; label: FUN_0055f560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055f560(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0x2990) = 1;
  *(void **)(param_1 + 0x2a94) = (void *)(param_1 + 0x2991);
  _memset((void *)(param_1 + 0x2991),0,0x100);
  if (((param_2 == 0) && (iVar1 = *(int *)(param_1 + 0x13c), iVar1 != 0)) &&
     (iVar4 = *(int *)(iVar1 + 0x74), 0 < iVar4)) {
    pbVar3 = *(byte **)(param_1 + 0x2a94);
    pbVar2 = (byte *)(*(int *)(iVar1 + 0x78) + 0x10);
    do {
      *pbVar3 = *pbVar2 >> 2 & 1;
      pbVar2 = pbVar2 + 0x18;
      pbVar3 = pbVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

