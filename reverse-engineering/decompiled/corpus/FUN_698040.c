/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x698040; label: FUN_00698040
 */

void FUN_00698040(int param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_02973954 != 0) && (*(char *)(param_1 * 0x40c + 0x404 + DAT_02973954) != '\0')) {
    if (DAT_00810dd4 != 0x4000) {
      param_2 = DAT_00810dd4 * param_2 >> 0xf;
    }
    iVar1 = FUN_00697470(param_1,0);
    if (-1 < iVar1) {
      if (0x3fff < param_2) {
        param_2 = 0;
      }
      FUN_00697580(iVar1,0,(&DAT_02962bb0)[param_2],0);
    }
  }
  return;
}

