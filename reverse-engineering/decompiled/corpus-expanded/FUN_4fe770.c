/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fe770; label: FUN_004fe770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fe770(char *param_1)

{
  _sprintf(&DAT_00920de8,"NuError - %s(%d) : ",DAT_009205bc,DAT_009209c0);
  _vsprintf(&DAT_009205c0,param_1,&stack0x00000008);
  FUN_004f1e80(&DAT_00920de8,&DAT_009205c0);
  FUN_004f1e80(&DAT_00920de8,&DAT_0075ec50);
  if (DAT_009209dc != (code *)0x0) {
    (*DAT_009209dc)(&DAT_00920de8);
  }
  FUN_006e0130(&DAT_02976078,&DAT_00758828,&DAT_00920de8);
  return;
}

