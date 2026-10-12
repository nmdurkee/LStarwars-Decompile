/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dbce0; label: FUN_004dbce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dbce0(int param_1)

{
  _memset(&DAT_00882418,0,0x94);
  DAT_00882a58 = FUN_00578750(10);
  DAT_00882418 = (short *)FUN_005d0690(*(undefined4 *)(param_1 + 0x13c),"finish_line");
  if ((DAT_00882418 != (short *)0x0) && (*DAT_00882418 < 2)) {
    DAT_00882418 = (short *)0x0;
  }
  DAT_0088241c = (short *)FUN_005d0690(*(undefined4 *)(param_1 + 0x13c),"halfway");
  if ((DAT_0088241c != (short *)0x0) && (*DAT_0088241c < 2)) {
    DAT_0088241c = (short *)0x0;
  }
  DAT_00882480 = FUN_005aac00(DAT_0095df4c,&DAT_0075d6ac,0);
  *(undefined4 *)(DAT_00882480 + 0x28) = 0;
  DAT_00882484 = FUN_005aac00(DAT_0095df4c,"sebulba_max_speed",0);
  DAT_00882488 = FUN_005aac00(DAT_0095df4c,"sebulba_min_speed",0);
  DAT_0088248c = FUN_005aac00(DAT_0095df4c,"sebulba_speed_step",0);
  FUN_004dbbe0();
  FUN_004dbbe0();
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ad30,"bigrock_five",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ad3c,"bigrock_eight",1);
  return;
}

