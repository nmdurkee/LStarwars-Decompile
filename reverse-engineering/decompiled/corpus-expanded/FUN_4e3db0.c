/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e3db0; label: FUN_004e3db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e3db0(int param_1)

{
  _memset(&DAT_008895c8,0,0x30);
  DAT_008895bc = FUN_00578750(8);
  DAT_008895ec = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),"Bigjump_0");
  DAT_008895c8 = FUN_005ab050(DAT_0095df4c,"InControlRoom",0,0);
  DAT_008895cc = FUN_005ab050(DAT_0095df4c,"ceiling_collapse",0,0);
  DAT_008895d0 = FUN_005ab050(DAT_0095df4c,"timer",0,0);
  return;
}

