/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x485030; label: FUN_00485030
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00485030(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      uVar3 = 0xa5;
      fVar2 = -_DAT_007fc31c;
    }
    else {
      uVar3 = 0xa6;
      fVar2 = _DAT_007fc31c;
    }
    if (*(char *)(param_1 + 0xa4 + iVar4) == '\0') {
      fVar1 = 0.25;
    }
    else {
      fVar1 = 1.0;
    }
    FUN_0055b830((int)*(short *)(param_1 + 0x9c + iVar4 * 2),fVar2,param_2,0,_DAT_007fc318,uVar3,
                 fVar1 * param_3,fVar1 * param_3,1,0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  return;
}

