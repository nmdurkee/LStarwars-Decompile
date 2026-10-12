/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x503a50; label: FUN_00503a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00503a50(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = (*DAT_00921338)(param_1);
  if ((*(byte *)(iVar3 + 0x88) & 2) != 0) {
    iVar3 = FUN_004fff00();
  }
  puVar1 = DAT_00921340;
  puVar2 = DAT_00921340 + 4;
  *DAT_00921340 = param_1;
  DAT_00921340 = puVar2;
  puVar1[1] = *(undefined4 *)(iVar3 + 0x58);
  puVar1[2] = *(undefined4 *)(iVar3 + 0xe0);
  *(byte *)(puVar1 + 3) = -(param_2 != 0) & 7;
  DAT_009213d4 = DAT_009213d4 + 1;
  return;
}

