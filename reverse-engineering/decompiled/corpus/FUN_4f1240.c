/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f1240; label: FUN_004f1240
 */

int * FUN_004f1240(void)

{
  undefined *_Dst;
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = DAT_0091eebc;
  if (DAT_0091eebc == (int *)0x0) {
    piVar3 = &DAT_00917850;
    DAT_0091eebc = &DAT_00917850;
    _memset(&DAT_00917850,0,0x1610);
    DAT_0091eec0 = &DAT_008cab50;
  }
  iVar2 = 0;
  piVar1 = piVar3;
  do {
    if (*piVar1 == 0) {
      piVar3 = piVar3 + iVar2 * 0x161;
      _memset(piVar3,0,0x584);
      _Dst = DAT_0091eec0 + iVar2 * 0x1000;
      *piVar3 = (int)_Dst;
      _memset(_Dst,0,0x1000);
      return piVar3;
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 0x161;
  } while (iVar2 < 4);
  return (int *)0x0;
}

