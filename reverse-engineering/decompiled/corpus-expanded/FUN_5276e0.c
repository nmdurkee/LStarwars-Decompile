/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x5276e0; label: FUN_005276e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005276e0(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  
  if (*(int *)(DAT_009238e4 + 0x4381c) != 0) {
    if ((*(byte *)(param_2 + 0xc) & *(byte *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x48)) == 0) {
      pbVar1 = (byte *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x48);
      *pbVar1 = *pbVar1 | *(byte *)(param_2 + 0xc);
    }
    else {
      pbVar1 = (byte *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x48);
      *pbVar1 = *pbVar1 & ~*(byte *)(param_2 + 0xc);
    }
    iVar2 = *(int *)(DAT_009238e4 + 0x4381c);
    if ((*(byte *)(iVar2 + 0x48) & 0x80) != 0) {
      *(undefined4 *)(iVar2 + 0x20) = 0;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      *(undefined4 *)(iVar2 + 0x28) = 0;
    }
  }
  return;
}

