/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x6285e0; label: FUN_006285e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006285e0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if (((*(byte *)(param_4 + 0x78) & 0x40) != 0) || (*(short *)(param_2 + 0x56) != 0)) {
    FUN_006193e0(param_1,param_2);
    FUN_00628230(param_2);
  }
  return 0;
}

