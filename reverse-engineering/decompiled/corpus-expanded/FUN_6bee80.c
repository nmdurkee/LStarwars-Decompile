/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bee80; label: FUN_006bee80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bee80(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006bee85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x54))();
  return;
}

