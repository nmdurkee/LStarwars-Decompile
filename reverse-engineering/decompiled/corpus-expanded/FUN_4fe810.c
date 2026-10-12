/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fe810; label: FUN_004fe810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fe810(char *param_1)

{
  if (DAT_00921224 == 0) {
    _sprintf(&DAT_00920de8,"NuWarning - %s(%d) : ",DAT_009205bc,DAT_009209c0);
    _vsprintf(&DAT_009205c0,param_1,&stack0x00000008);
    FUN_004f1e80(&DAT_00920de8,&DAT_009205c0);
    FUN_004f1e80(&DAT_00920de8,&DAT_0075ec50);
    if (DAT_009205b8 != (code *)0x0) {
      (*DAT_009205b8)(&DAT_00920de8);
    }
    FUN_006e01f0(&DAT_02976078,&DAT_00758828,&DAT_00920de8);
  }
  return;
}

