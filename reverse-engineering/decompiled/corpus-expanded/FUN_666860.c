/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x666860; label: FUN_00666860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00666860(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar2 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
      pbVar1 = (byte *)(iVar2 + 0x2f2);
      *pbVar1 = *pbVar1 | *(byte *)(param_2 + 0xc);
      return;
    }
    pbVar1 = (byte *)(iVar2 + 0x2f2);
    *pbVar1 = *pbVar1 & ~*(byte *)(param_2 + 0xc);
  }
  return;
}

