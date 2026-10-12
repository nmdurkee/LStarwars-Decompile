/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x525ab0; label: FUN_00525ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00525ab0(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
  if (iVar2 != 0) {
    if ((*(byte *)(param_2 + 0xc) & *(byte *)(iVar2 + 0x92)) == 0) {
      pbVar1 = (byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x92);
      *pbVar1 = *pbVar1 | *(byte *)(param_2 + 0xc);
    }
    else {
      pbVar1 = (byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x92);
      *pbVar1 = *pbVar1 & ~*(byte *)(param_2 + 0xc);
    }
    iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if ((*(byte *)(iVar2 + 0x92) & 0x80) != 0) {
      *(undefined4 *)(iVar2 + 0x98) = 0;
      *(undefined4 *)(iVar2 + 0x9c) = 0;
      *(undefined4 *)(iVar2 + 0xa0) = 0;
    }
  }
  return;
}

