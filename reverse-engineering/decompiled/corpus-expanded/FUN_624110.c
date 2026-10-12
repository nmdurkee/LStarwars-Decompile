/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x624110; label: FUN_00624110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00624110(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0080f7ec;
  DAT_0080f538 = *(byte *)(param_2 + 0x11) & 1;
  if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
    *(undefined4 *)(PTR_DAT_0080f7ec + 0x80) = 0x3e19999a;
    *(undefined4 *)(puVar1 + 0x84) = 0x3e4ccccd;
    *(undefined4 *)(puVar1 + 0x88) = 0x3c23d70a;
    *(undefined4 *)(puVar1 + 0x8c) = 0x3dcccccd;
    return;
  }
  *(undefined4 *)(PTR_DAT_0080f7ec + 0x80) = 0;
  *(undefined4 *)(puVar1 + 0x84) = 0;
  *(undefined4 *)(puVar1 + 0x88) = 0;
  *(undefined4 *)(puVar1 + 0x8c) = 0;
  return;
}

