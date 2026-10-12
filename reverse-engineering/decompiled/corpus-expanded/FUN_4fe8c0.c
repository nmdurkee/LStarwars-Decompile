/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fe8c0; label: FUN_004fe8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fe8c0(char *param_1)

{
  char *pcVar1;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  if (DAT_00921224 == 0) {
    if (DAT_00921204 != '\0') {
      pcVar1 = _strstr(DAT_009205bc,&DAT_00921204);
      if (pcVar1 == (char *)0x0) goto LAB_004fe985;
    }
    _sprintf(local_404,"NuDebugMsg - %s(%d) :",DAT_009205bc,DAT_009209c0);
    _vsprintf(&DAT_009205c0,param_1,&stack0x00000008);
    FUN_004f1e80(local_404,&DAT_009205c0);
    FUN_004f1e80(local_404,&DAT_0075ec50);
    if (DAT_0091f1b0 != (code *)0x0) {
      (*DAT_0091f1b0)(local_404);
    }
    FUN_006e0030(&DAT_02976078,&DAT_00758828,local_404);
  }
LAB_004fe985:
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

