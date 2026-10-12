/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x664800; label: FUN_00664800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00664800(undefined4 param_1,int param_2)

{
  undefined4 uStack0000000c;
  
  *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) & 0xfe;
  uStack0000000c = 0;
  param_1 = &DAT_0292fcdc;
  FUN_00620f60();
  return;
}

