/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bee90; label: FUN_006bee90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bee90(undefined4 param_1,int param_2)

{
  DAT_0081fde4 = DAT_0081fde4 ^ 1;
  *(byte *)(param_2 + 0x11) =
       *(byte *)(param_2 + 0x11) ^ (*(byte *)(param_2 + 0x11) ^ (byte)DAT_0081fde4) & 1;
  return;
}

