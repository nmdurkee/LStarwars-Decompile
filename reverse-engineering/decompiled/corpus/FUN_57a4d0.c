/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a4d0; label: FUN_0057a4d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057a4d0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  float10 extraout_ST0;
  
  pcVar1 = *(code **)(*(int *)(param_1 + 0x128) + 0x74);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1);
  }
  if (0.0 < _DAT_00925040) {
    iVar2 = FUN_006e6b90();
    iVar3 = FUN_006e6b90();
    if (iVar3 != iVar2) {
      FUN_00547960(0x35,0,(float)extraout_ST0);
    }
  }
  if ((DAT_00951224 == 0) && (iVar2 = FUN_0056e0f0(0x2000), iVar2 != 0)) {
    DAT_00951224 = 1;
  }
  return;
}

