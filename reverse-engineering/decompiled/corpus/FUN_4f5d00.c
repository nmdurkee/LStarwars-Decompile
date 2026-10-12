/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f5d00; label: FUN_004f5d00
 */

void FUN_004f5d00(uint param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  DAT_0297e024 = DAT_0297e024 << ((byte)param_1 & 0x1f);
  iVar2 = DAT_02982724;
  pbVar3 = DAT_0297dc50;
  if (DAT_0090f79c < param_1) {
    do {
      param_1 = param_1 - DAT_0090f79c;
      DAT_0297e024 = DAT_0297e024 | DAT_008cf394 << ((byte)param_1 & 0x1f);
      if (iVar2 == 0) {
        DAT_008cf394 = 0;
      }
      else {
        iVar2 = iVar2 + -1;
        bVar1 = *pbVar3;
        pbVar3 = pbVar3 + 1;
        DAT_008cf394 = (uint)bVar1;
        DAT_0297dc50 = pbVar3;
        DAT_02982724 = iVar2;
      }
      DAT_0090f79c = 8;
    } while (8 < param_1);
  }
  DAT_0090f79c = DAT_0090f79c - param_1;
  DAT_0297e024 = DAT_0297e024 | DAT_008cf394 >> ((byte)DAT_0090f79c & 0x1f);
  return;
}

