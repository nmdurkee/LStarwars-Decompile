/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x577060; label: FUN_00577060
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577060(int param_1)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if (param_1 == 0) {
    fVar1 = (float10)FUN_005becc0(&DAT_009518d4,&DAT_009518e0,local_c);
    _DAT_00951888 = (float)fVar1;
    FUN_0054ff40(local_c,&DAT_0095188c,&DAT_0095188e);
    DAT_0095188e = DAT_0095188e + -0x8000;
    _DAT_0095188c = CONCAT22(DAT_0095188e,-DAT_0095188c);
    DAT_00951882 = 0;
    return;
  }
  if (param_1 == 1) {
    DAT_00951882 = (char)param_1;
    return;
  }
  if (param_1 == 2) {
    DAT_00951882 = 2;
  }
  return;
}

